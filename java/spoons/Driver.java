package cpsc231.week13;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

import cpsc231.week14.Album;
import cpsc231.week14.ArtistAccount;
import cpsc231.week14.Content;
import cpsc231.week14.ContentCollection;
import cpsc231.week14.ListenerAccount;
import cpsc231.week14.Playlist;
import cpsc231.week14.Podcast;
import cpsc231.week14.Song;



// testing the classes and having the user select choices for what they want to do
public class Driver {
    private static List<ArtistAccount> artists; 
    private static List<Song> songs = new ArrayList<>(); 
    private static List<Podcast> podcasts = new ArrayList<>(); 
    private static List<Album> albums = new ArrayList<>();
    private static List<Playlist> playlists = new ArrayList<>();

    private static List<Content> songsAndPodcasts = new ArrayList<>(); 
    private static List<ContentCollection> albumsAndPlaylists = new ArrayList<>();

    private static ListenerAccount account; 
    private static Scanner scanner = new Scanner(System.in);
    

    public static void main(String[] args) {
        populateWithDefaults();

        while (true) {
            printMenu();

            int choice = scanner.nextInt();
            switch (choice) {
                case 1: createListenerAccount(); break;
                case 2: listAlbumsAndPlaylists(); break;
                case 3: addSongs(); break;
                case 4: play(); break;
                case 5: addToFavorites(); break;
                case 6: exportFavorites(); break;
                case 7: System.exit(0);
                default: System.out.println("Invalid choice. Try again.");
            }
        }
    }

    private static void populateWithDefaults() {
        artists = Arrays.asList(
            new ArtistAccount("artist1"), 
            new ArtistAccount("artist2")
        );

        Song song1 = new Song("Summertime Sadness", "Lana Del Rey");
        Song song2 = new Song("Flowers", "Miley Cyrus");
        Song song3 = new Song("Part of Me", "Katy Perry");
        Song song4 = new Song("Disturbia", "Rihanna");
        Song song5 = new Song("Style", "Taylor Swift");
        Song song6 = new Song("Firework", "Katy Perry");
        
        Podcast podcast1 = new Podcast("Call Her Daddy", "Alex Cooper", 1);
        Podcast podcast2 = new Podcast("TedTalks", "TuneIn", 56);
        Podcast podcast3 = new Podcast("True Crime Podcast", "Adam Degli", 12);

        songs = Arrays.asList(song1, song2, song3, song4, song5, song6);
        podcasts = Arrays.asList(podcast1, podcast2, podcast3);

        albums = Arrays.asList(
            new Album("Born To Die", Arrays.asList(song1, song2, song3)),
            new Album("When The Party's Over", Arrays.asList(song4, song5, song6))
        );

        playlists = Arrays.asList(
            new Playlist("car playlist", Arrays.asList(song1, song2, song3, podcast1, podcast2)),
            new Playlist("summer playlist", Arrays.asList(song1, song2, song3, podcast1, podcast2))
        );

        albumsAndPlaylists.addAll(albums);
        albumsAndPlaylists.addAll(playlists);

        songsAndPodcasts.addAll(songs);
        songsAndPodcasts.addAll(podcasts);
    }

    private static void printMenu() {
        System.out.println("Selct an option ");
        System.out.println("1. Create a listener account");
        System.out.println("2. List all Playlists and Albums and their contents");
        System.out.println("3. Add songs to an existing playlist");
        System.out.println("4. Shuffle an existing Playlist or listen to an Album");
        System.out.println("5. Add a song or podcast to favorites");
        System.out.println("6. Export all of a listener’s favorites out to a file in ascending order by times streamed");
        System.out.println("7. Exit");
    }

    private static void createListenerAccount() {
        System.out.print("Provide an ID for the account: ");
        String id = scanner.next();
        account = new ListenerAccount(id);
    }

    private static void listAlbumsAndPlaylists() {
        System.out.println("Available albums and playsts:");
        System.out.println(albums);
        System.out.println(playlists);
    }

    private static void addSongs() {
        System.out.println("Available playlists: ");
        int i = 0;
        for (Playlist playlist : playlists) {
            System.out.println(i++ + ": " + playlist.getTitle());
        }

        int index = -1; 
        while (index < 0 || index >= playlists.size()) {
            System.out.println("Choose playlist: ");
            index = scanner.nextInt();
        }

        Playlist playlist = playlists.get(index); 
        playlist.add(getSong());
    }

    private static void play() {
        System.out.println("Which Playlist or Album would you like to play?");

        int i = 0;
        for (ContentCollection c : albumsAndPlaylists) {
            System.out.println(i++ + ": " + c.getTitle());
        }

        int index = -1; 
        while (index < 0 || index >= i) {
            System.out.println("Your choice: ");
            index = scanner.nextInt();
        }

        albumsAndPlaylists.get(index).play();
    }

    private static Song getSong() {
        System.out.println("Available songs: ");

        int i = 0;
        for (Song song : songs) {
            System.out.println(i++ + ": " + song);
        }

        int index = -1; 
        while (index < 0 || index >= i) {
            System.out.println("Choose song: ");
            index = scanner.nextInt();
        }

        return songs.get(index);
    }

    private static void addToFavorites() {
        if (account == null) {
            System.out.println("Create a listencer account first.");
            return;
        }

        System.out.println("Available songs and podcasts: ");

        int i = 0;
        for (Content c : songsAndPodcasts) {
            System.out.println(i++ + ": " + c);
        }

        int index = -1; 
        while (index < 0 || index >= i) {
            System.out.println("Choose song: ");
            index = scanner.nextInt();
        }

        account.favorite(songsAndPodcasts.get(index));
    }

    private static void exportFavorites() {
        if (account == null) {
            System.out.println("You need an account first.");
            return;
        }

        System.out.println("Provide file name: ");
        PrintWriter pw = null;
        try{
            pw = new PrintWriter(new FileWriter(scanner.next())); 
            pw.write(account.toString());
        } catch(IOException ioe){
            System.err.println("something went wrong when writing to file cpsc231_text.txt");
            ioe.printStackTrace();
        } finally {
            if (pw != null) pw.close();
        }
    }

}

