package cpsc231.week13;
public class TestCards {
    public static void main(String[] args) {
        // creating a new Card object using the deault constructor  
        Card c = new Card();
        System.out.println(c);

        // creating a new Card object using the overloaded constructor 
        Card c2 = new Card(2, 0);
        System.out.println(c2);

        // creating a deep copy of c
        Card cCopy = new Card(c);
        // changing the value of c making sure cCopy is a deep copy 
        c.setValue(11);
        System.out.println(cCopy);

        // testing the equals method
        System.out.println(cCopy.equals(c));

        // creating a new Deck object using the default constructor 
        Deck d = new Deck(); 
        // creatign a deep copy of d
        Deck dCopy = new Deck(d);
        // testing the toString method 
        System.out.print(d.toString());
        // testing the deal method
        System.out.println(d.deal());
        // testing the size method and if dCopy is a deep copy
        System.out.println(d.size());
        // testing if dCopy is a deep copy 
        System.out.println(dCopy.size());

        // creating a new Dealer object using the default constructor
        Dealer dlr = new Dealer();
        // testing the toString method
        System.out.println(dlr.toString());
        // testing the deals method
        System.out.println(dlr.deals(12).size());
        // returns 40 because that is the number of cards left
        System.out.println(dlr.deals(50).size());
        // returns 0 because the deck is out of cards
        System.out.println(dlr.deals(1).size());
    }
}
