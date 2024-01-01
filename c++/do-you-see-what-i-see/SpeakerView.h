/*
Patricia Bivol
2421265
bivol@chapman.edu
CPSC 350 Section 04
PA3
*/
#ifndef SPEAKER_VIEW_H
#define SPEAKER_VIEW_H

#include "AudienceColumn.h"

class SpeakerView {
    public:
        SpeakerView(std::string inputFile);
        ~SpeakerView();
    private:
        AudienceColumn<float>* columns;
    };

#endif