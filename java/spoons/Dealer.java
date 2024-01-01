package cpsc231.week13;
import java.util.LinkedList;

public class Dealer {
    private Deck m_deck;

    // default constructor
    public Dealer() {
        // initializing a new Deck of 52 cards
        m_deck = new Deck(); 
    }

    public LinkedList<Card> deals(int n) {
        // creating a new LinkedList
        LinkedList<Card> d = new LinkedList<Card>();
        // iterating through the deck and adding n cards to d
        for (int i = 0; i < n && m_deck.size() > 0; i++) {
            d.add(m_deck.deal());
        }
        // will return 0 if the LinkedList is empty
        return d;
    }

    // method returning the size of m_deck as an int
    public int size() {
       return m_deck.size();
    }

    // method printing m_deck
    public String toString() {
        return m_deck.toString();
    }

    //added
    public Deck getDeck() {
        return m_deck;
    }
}
