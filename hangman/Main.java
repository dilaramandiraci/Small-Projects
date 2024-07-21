package hangman;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println("WELCOME TO THE NEW HANGMAN GAME PLEASE ENTER 1 TO START THE GAME *** 0 for quit");
        Scanner in = new Scanner(System.in);
        int shouldStartGame = in.nextInt();
        if(shouldStartGame == 1)
        {
            Hangman newgame = new Hangman();
            newgame.allUnknown(newgame.getSecretWord());
            System.out.println("There are 12 fruit names in this game. Good LUCK !");
            System.out.println(newgame.getKnownSoFar()); 

            Scanner scan = new Scanner(System.in);
            do {
                System.out.println();
                System.out.println("TRY A LETTER FROM THE ENGLISH ALPABETH");
                String aLetter = scan.nextLine();
                System.out.println("The letter " + aLetter + " has found " + newgame.tryThis(aLetter.charAt(0)) + " times in that word.");
                System.out.println(newgame.getKnownSoFar());
                newgame.displayHangman();
                System.out.println("You have used " + newgame.getUsedLetters() + " so far.");
                System.out.println("Take a new try!");
            } while(!newgame.isGameOver());

            if (newgame.hasLost())
            {
                System.out.println("You lost...");
            }
            else
            {
                System.out.println("YOU WON!!! CONGRATULATIONS!!!");
            }
            scan.close();
        }

        if(shouldStartGame == 0)
        {
            System.out.println("Good Bye...");
        }

        in.close();
        
    }
    
}
