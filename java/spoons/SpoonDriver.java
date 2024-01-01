package cpsc231.week13;
public class SpoonDriver {
    public static void main(String[] args) {
        // testing a 3 person game
        Game game = new Game();
        game.play();
        System.out.print(game);

        // testing if we can play a game with less than three players
        Game game2 = new Game(2);
        game2.play();
        System.out.print(game2);

        // testing a game with 10 players
        Game game3 = new Game(10);
        game3.play();
        System.out.print(game3);
    }
}
