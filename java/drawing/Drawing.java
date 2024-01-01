import java.util.Scanner;

public class Drawing{
    // modifying original array
    public static void createCanvas(char[][] a) {
        // find length of rows and colums
        int r = a.length;
        int c = a[0].length;
        
        // iterate through the rows and colums
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c ; j++){
                // make first and last row all '='
                if (i == 0 || i == r - 1 ){
                    a[i][j] = '=';
                // make first and last column all '|'
                } else if (j == 0 || j == c - 1){
                    a[i][j] = '|';
                // add a ' ' where no characters have been added
                } else {
                    a[i][j] = ' ';
                }
            }
        }
        // add a '+' at each corner
        a[0][0] = '+';
        a[r - 1][0] = '+';
        a[0][c-1] = '+';
        a[r-1][c-1] = '+';
    }
    
    public static void addCharacter(char[][] a, char ch , int point1, int point2){
        // add in a character at desired points
        a[point1][point2] = ch;
    }

    public static void printCanvas(char[][] a){
        // iterate through the rows and colums to print the canvas
        for (int i = 0; i < a.length; i++){
            for (int j = 0; j < a[0].length; j++){
                System.out.print(a[i][j] + " ");
            }       
            System.out.println();
        }
    }

    public static void main(String[] args) {
        try (//ask for size input of arr
        Scanner scnr = new Scanner (System.in)) {
            System.out.println("Enter the number of rows:");
            int l = scnr.nextInt();
            System.out.println("Enter the number of columns:");
            int h = scnr.nextInt();
            // create 2D array using inputs
            char[][] a = new char [l][h];
            
            // call methods
            createCanvas(a);
            addCharacter(a, ';', 2, 2);
            addCharacter(a, ')', 2, 3);
            printCanvas(a);
        }
        }
    }
