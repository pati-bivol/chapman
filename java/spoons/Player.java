package cpsc231.week13;
import java.util.LinkedList;
import java.util.HashMap;
import java.util.Random;

public class Player {
   private int num; 
   private LinkedList<Card> cards = new LinkedList<>();
   public boolean hasSpoon;
   private HashMap<Integer, Integer> cardCount = new HashMap<>();

   // overloaded constructor
   public Player(int pn, Dealer dealer) {
      num = pn;
      // referencing Dealer and adding 4 cards to the Player's hand 
      for (Card card: dealer.deals(4)) {
         addCard(card);
      }
   }

   // method receiving a card and passing a chosen card to another player
   public Card takeTurn(Card card) {
      // if the player already has a spoon, give the next player the card they received
      if (hasSpoon) {
         return card;
      // player takes a spoon if they have 4 matches
      } else if (addCard(card) == 4 ) {
         stealSpoon();
      // if another player has already stolen a spoon
      } else if (Game.spoonsAvailable != Game.players.length - 1) {
         Random random = new Random();
         int probability = random.nextInt(100);
         // there is a 33% chance that the player will notice a spoon is missing
         if (probability < 33) {
            stealSpoon();
         }
      }

      // if cardCount does not contain the value of the card return the card
      // the player does have any cards of the same value
      if (!cardCount.containsKey(card.getValue())) {
         return card;
      }

      // finding the card value with the smallest number of matches
      int minCount = 5;
      Card minCard = null;
      for (Card c: cards) {
         int count = cardCount.get(c.getValue());
         if (minCount > count) {
            minCard = c;
            minCount = count;
         }
      }
      
      // remove the card with the smallest number of matches from the player's hand
      return removeCard(minCard);
   }

   // method stealing a spoon if any are available 
   public void stealSpoon() {
      // checks if there are still spoons available
      if (Game.spoonsAvailable > 0) {
         hasSpoon = true;
         // decreases the number of spoons available by 1 because one has been stolen
         Game.spoonsAvailable -= 1;
      }
   }

   // returns true if the player has a spoon
   public boolean hasSpoon() {
      return hasSpoon;
   }

   // getter
   public int getNum() {
      return num;
   }

   // toString for printing
   public String toString() {
      String s = "";
      s += "Player " + getNum() + "\n";
      s += "Has spoon: " + hasSpoon() + "\n";
      s += "Player's cards: " + "\n" + cards + "\n";
      return s;
   }

   // private method adding a card to the player's hand and checking matches
   private int addCard(Card card) {
      // adding a card
      cards.add(card);
      
      // checking how matches a card has
      Integer count = cardCount.getOrDefault(card.getValue(), 0); 
      cardCount.put(card.getValue(), ++count);
      // return the number of matches
      return count;
   }

   // private method removing a card from the player's hand
   // used when a player gives a card to the next player
   private Card removeCard(Card card) {
      // removes a card from the player's hand
      cards.remove(card);
      
      // gets the number of matches for the value of the card
      Integer count = cardCount.get(card.getValue()); 
      // removes card from cardCount if there are none left of that value and adjusts the number of matches for the card
      if (--count == 0) {
         cardCount.remove(card.getValue());
      } else {
         cardCount.put(card.getValue(), count);
      }
      // returns the card so it can be passed to the next player
      return card;
   }
}
