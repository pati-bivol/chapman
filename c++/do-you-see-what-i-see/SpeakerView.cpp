/*
Patricia Bivol
2421265
bivol@chapman.edu
CPSC 350 Section 04
PA3
*/
#include "SpeakerView.h"
#include "SeatingArea.h"
#include "AudienceColumn.h"

#include <string>

using std::string;
using std::stringstream;

SpeakerView::SpeakerView(string inputFile) {
    SeatingArea seatingArea = SeatingArea(inputFile);

    columns = new AudienceColumn<float>[seatingArea.getColumnCount()];

    int n = seatingArea.getRowCount();
    int p = seatingArea.getColumnCount();

// Iterate over the audience rows from the back of the conference room to the front so that we can use a decreasing
// stack in the most optimal way. The tallest person at the back of the room will not obstruct the view of the
// people in front (will not be popped by shorter people / smaller values iterated over next).
    for (int i=n-1; i>=0; i--) {
        float* rowHeight = seatingArea.getRowHeights(i);
        for (int j=0; j<p; j++) {
            columns[j].push(rowHeight[j]);
        }
    }

    for (int i=0; i<p; i++) {
        columns[i].print(i);
    }
}

SpeakerView::~SpeakerView() {
    delete[] columns;
}

