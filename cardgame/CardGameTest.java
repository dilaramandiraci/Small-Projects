package cardgame;

import java.util.Scanner;
import cardgame.*;

// CardGameTest
// author: Dilara Mandıracı
// date: 20.02.2022
public class CardGameTest
{
    public static void main( String[] args)
    {
        Scanner scan = new Scanner( System.in);
        
        System.out.println( "Start of CardGameTest\n");
        
        // CONSTANTS
        
        // VARIABLES
        Card       c;
        Cards      cards;
        ScoreCard  scores;
        Player     p;
        CardGame   game;
        
        // PROGRAM CODE
        
        // test Card class
        c = new Card( 1);
        System.out.println( c);
        System.out.println();
        
        // test Cards class
        cards = new Cards( true);
        cards.addTopCard( c);
        
        // test ScoreCard class
        scores = new ScoreCard( 4);
        scores.update( 3, 1);
        scores.update( 1, 2);
        System.out.println( "\n" + scores );
        
        // test Player class
        System.out.println("test for player class");
        Player p1 = new Player("Dilara");
        System.out.println(p1);
        Player p2 = new Player("Zeynep");
        System.out.println(p2);
        Player p3 = new Player("Ali");
        Player p4 = new Player("Emre");
        System.out.println(p4);
        System.out.println(p3.getName());
        System.out.println();

        // ToDo
        
        // test CardGame class too?
        System.out.println("test for the card game class");
        game = new CardGame(p1, p2, p3, p4);
        System.out.println(game.roundNo);
        game.playTurn(p1, c);
        game.playTurn(p2, c);
        game.playTurn(p3, c);
        game.playTurn(p4, c);
        System.out.println(game.roundNo); 

        // Todo
        
        // Once you have all the bits working, complete the MyCardGame program
        // that provides a menu allowing any of the players to play their card,
        // an option to see the score card, and one to quit the game at any time.
        // When the game is over it should print out the winners.
        
        System.out.println( "\nEnd of CardGameTest\n" );
    }
    
} // end of class CardGameTest
