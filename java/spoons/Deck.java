package cpsc231.week13;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

public class Deck {
    // a linked list that holds cards
    private LinkedList<Card> m_cards;

    // default constructor
    public Deck() {
        // initialzing m_cards
        m_cards = new LinkedList<Card>();
        // iterating through the suits
        for (int i = 0; i < 4; i++) {
            // iterating through the values
            for (int j = 2; j < 15; j++) {
                // adding a card of each suit and value to the deck
                Card newC = new Card(j,i);
                m_cards.add(newC);
            }
        }
    }

    // copy constructor
    public Deck(Deck d) {
        // creating a deep copy of the existing Deck
        m_cards = new LinkedList<Card>();
        
        // iterating through and copying each Card individually 
        for (Card c: d.m_cards) {
            Card newC = new Card(c);
            m_cards.add(newC);
        }
    }

    // method printing out m_cards
    public String toString() {
        return m_cards.toString();
    }

    // method returning the size of the deck as an int 
    public int size() {
        return m_cards.size();
    }

    // method removing a random card from the deck and returning it
    public Card deal() {
        Random random = new Random();
        int randCard = random.nextInt(size());
        return m_cards.remove(randCard);
    }

    // added method
    public void addCards(List<Card> cards) {
        m_cards.addAll(cards);
    }
}
