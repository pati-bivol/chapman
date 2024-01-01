package cpsc231.week13;
import java.util.LinkedList;
import java.util.List;

public class Game {
    public static int spoonsAvailable;
    public static Player[] players;
    private Dealer dealer; 
    private List<Card> discard;

    // default constructor defaulting the number of players to 3
    public Game() {
        this(3);
    }

    // overloaded constructor
    public Game(int numPlayers) {
        // if the number of players is < 3, throw an exception
        if (numPlayers < 3) {
            throw new IllegalArgumentException("You must have at least 3 players");
        } 

        // initializing a new Dealer and creating a Player[] of the input size
        dealer = new Dealer();
        players = new Player[numPlayers];
        // assigning each player with a number and giving them each 4 cards 
        for (int i = 0; i < numPlayers; i++) {
            players[i] = new Player(i + 1, dealer);
        }
    }

    // method carrying out the rules of the game
    public void play() {
        // method will carry out until the Player[] only has one person left
        while (players.length > 1) {
            // the number of spoons must be one less than the number of players to start off each round
            setSpoonsAvailable(players.length - 1);
            // initializing a discard pile
            discard = new LinkedList<>();

            // executing the round while there are still spoons available to take
            while (spoonsAvailable > 0) {
                // the first player gets one card from the deck
                Card card = dealOne();
                // players take turns giving each other one chosen card
                for (Player player: players) {
                    card = player.takeTurn(card);
                } 
                // the last player adds their chosen card to the discard pile
                discard.add(card);
            }

            // for indexing
            int i = 0;
            // initializing a new Dealer for the next round
            dealer = new Dealer();
            // creating a new array of players 1 less than players 
            Player[] nextPlayers = new Player[players.length - 1];

            // iterating through the old array of players to add them to the new array
            // the player that lost will not be added to the new array
            for (Player player: players) {
                if (player.hasSpoon()) {
                    nextPlayers[i++] = new Player(player.getNum(), dealer);
                }
            }
            // setting players = nextPlayers so the method will continue to work until all but one player is out of the game
            players = nextPlayers;
        }
    }

    // toString method for printing
    // only shows the last loser of the game
    public String toString() {
        String s = "\n";
        s += "Spoons available in game: " + spoonsAvailable + "\n";
        s += "Loser: " + players[0]  + "\n";
        return s;
     }

     // private method dealing one card
    private Card dealOne() {
        // if there are no cards left in the deck the discard pile will be used
        if (dealer.size() == 0) {
            // adding discard to the regular deck and clearing it 
            dealer.getDeck().addCards(discard);
            discard.clear();
        }
        return dealer.deals(1).getFirst();
    }

    // getters
    public int getSpoonsAvailable() {
        return spoonsAvailable;
    }

    // setters
    public void setSpoonsAvailable(int sa) {
        spoonsAvailable = sa;
    }
}
