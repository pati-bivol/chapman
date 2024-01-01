package cpsc231.week14;
public class Song extends Content {
    // default constructor
    public Song() {
        // using the overloaded constructor
        this("Unkown Song Title", "Unknown Artist");
    }

    // overloaded constructor
    public Song(String t, String a) {
        // calling Content's member varibales
        super(t, a, 0);
    }
}
