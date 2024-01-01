package cpsc231.week13;
public class Card {
    // member variables 
    private int m_value;
    private int m_suit;
    public static final int JACK = 11;
    public static final int QUEEN = 12;
    public static final int KING = 13;
    public static final int ACE = 14;
    public static final int HEARTS = 0;
    public static final int SPADES = 1;
    public static final int CLUBS = 2;
    public static final int DIAMONDS = 3;

    // default constructor 
    public Card() {
        // using the overloaded constructor 
        this(ACE, SPADES);
    }

    // overloaded constructor
    public Card(int v, int s) {
        setValue(v);
        setSuit(s);
    }

    // copy constructor 
    public Card(Card c) {
        // creating a deep copy
        setValue(c.getValue());
        setSuit(c.getSuit());
    }

    // toString method
    public String toString() {
        String s = "";
        s += getValueAsString() + " of " + getSuitAsString() + "\n";
        return s;
    }

    // getters
    public int getValue() {
        return m_value;
    }
    public int getSuit() {
        return m_suit;
    }
    public String getValueAsString() {
        switch (m_value) {
            case JACK:
                return "Jack";
            case QUEEN:
                return "Queen";
            case KING:
                return "King";
            case ACE:
                return "Ace"; 
            default:
                return String.valueOf(m_value);
        }
    }
    public String getSuitAsString() {
        switch (m_suit) {
            case HEARTS:
                return "Hearts";
            case SPADES:
                return "Spades";
            case CLUBS:
                return "Clubs";
            case DIAMONDS:
                return "Diamonds";
            default:
                return "Invalid suit";
        }
    }

    // setters 
    public void setValue(int v) {
        m_value = v;
    }
    public void setSuit(int s) {
        m_suit = s;
    }

    // equals method 
    public boolean equals(Object o) {
        // they are the same object
        if (this == o) {
            return true;
        }
        // the object is not a Card
        if (!(o instanceof Card)) {
            return false;
        }
        
        // type casting into a Card object
        Card c = (Card) o;
        // two cards are equal if their values are equal
        return getValue() == c.getValue();
    }

    public static void main (String[] args){
        Card card = new Card(11, 1);
        System.out.println(card);
    }
    
}

    