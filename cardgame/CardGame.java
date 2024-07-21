package cardgame;

import java.util.ArrayList;
import java.util.Arrays;
// Cardgame
// author: @Dilara Mandıracı
// date: 20.02.2022
public class CardGame
{
    // properties
    Cards             fullPack;
    ArrayList<Player> players;
    ScoreCard         scoreCard;
    Cards[]           cardsOnTable;
    int               roundNo;
    int               turnOfPlayer;  
    
    // constructors
    /**
     * This is the constructor of the cardgame class which takes four players as a parameter.
     * It creates a fullpack of cards, then shuffle them.
     * Adds all players to the player arraylist.
     * Distrubute cards to the each player.
     * Crreates an array of cards on the table which has no cards at the beginning.
     * @param p1
     * @param p2
     * @param p3
     * @param p4
     */
    public CardGame( Player p1, Player p2, Player p3, Player p4)
    {
        this.fullPack = new Cards(true);
        fullPack.shuffle();
        
        this.players = new ArrayList <Player>();
        players.add(p1);
        players.add(p2);
        players.add(p3);
        players.add(p4);

        int i = 0;
        while(i < 52)
        {
            p1.add(fullPack.getTopCard());
            i++;
            p2.add(fullPack.getTopCard());
            i++;
            p3.add(fullPack.getTopCard());
            i++;
            p4.add(fullPack.getTopCard());
            i++;
        }

        this.scoreCard = new ScoreCard(players.size());

        this.roundNo = 1;

        this.cardsOnTable = new Cards[players.size()]; 
        cardsOnTable[0] = new Cards(false);
        cardsOnTable[1] = new Cards(false);
        cardsOnTable[2] = new Cards(false);
        cardsOnTable[3] = new Cards(false);

        this.turnOfPlayer = 0;
        // ToDo
    }
    
    // methods

    /**This is the playturn method whic is connected to the play method in MyCardGame class.
     * When all players play their turns it add 1 point to the winner of round and updates round no 
     * and set 0 to the turn of player to start round again.
     * 
     * @param p player is given in play() method 
     * @param c is given in play() method
     * @return true if the card is played succesfully
     */
    public boolean playTurn(Player p, Card c)
    {
        if (!isGameOver() && isTurnOf(p))
        {
            cardsOnTable[turnOfPlayer].addTopCard(c);
            turnOfPlayer ++;
            if (turnOfPlayer == 4)
            {
                addScoresToWinnerOfRound();
                turnOfPlayer = 0;
                roundNo++;
            }
            return true;
        }
        else 
        {
            return false;
        }
        
    }
    
    /**
     * checks if the players turn is over or not. 
     * @param p
     * @return true if the players turn off
     */
    public boolean isTurnOf(Player p)
    {
        if (players.get(getTurnOfPlayerNo()-1).getName().equals(p.getName()))
        {
            return true;
        }
        return false;
    }
    
    /**
     * if the round number bigger than 13 it means game is over because there are 52 cards and 4 players 
     * @return true if the game is over
     */
    public boolean isGameOver()
    {
        boolean result = false;
        if (roundNo > 13)
        {
            return true;
        }
        return result;
    }
    
    /**
     * returns player's score according to its number
     * @param playerNumber
     * @return
     */
    public int getScore( int playerNumber)
    {
        // ToDo
        return scoreCard.getScore(playerNumber);
    }
    
    /**
     * returns player's name according to its number
     * @param playerNumber
     * @return
     */
    public String getName( int playerNumber)
    {
        // ToDo
        return players.get(playerNumber).getName();
    }
    
    /**
     * returns current round no
     * @return
     */
    public int getRoundNo()
    {
        // ToDo
        return this.roundNo;
    }
    
    /**
     * return which players turn currently
     * @return
     */
    public int getTurnOfPlayerNo()
    {
        // ToDo
        return this.turnOfPlayer+1;
    }
    
    /**
     * It is an array includes winners name it takes the indexes of winners and returns their name
     * @return
     */
    public Player[] getWinners()
    {
        // ToDo
        int [] indexesOfWinners = scoreCard.getWinners();
        Player[] winnerPlayers = new Player[indexesOfWinners.length];
        for (int i = 0; i<indexesOfWinners.length; i++)
        {
            winnerPlayers[i] = players.get(indexesOfWinners[i]);
        }
        return winnerPlayers;
    }
    
    /**
     * It shows score card
     * @return
     */
    public String showScoreCard()
    {
        return scoreCard.toString();
    }
    
    /**
     * This is the very important method. When all players play their cards in the same round, It checks all their values of cards played.
     * Then determine which one is higher and gives the point to the player with card with the high value.
     * I used justLookTopCard() method here because i need to access top card for 3 times but when i used getTopCard() method once, it
     * removes the top card so i cannot use its value again in a different line.
     */
    public void addScoresToWinnerOfRound ()
    {
        Card max = cardsOnTable[0].justLookTopCard();

        //determine which card has the highest value.
        for(int i = 0; i<4; i++) 
        {
            if(cardsOnTable[i].justLookTopCard().compareTo(max) == 1)
            {
                max = cardsOnTable[i].justLookTopCard();
            }
        }

        //determine whose card is and add point to the player.
        for(int i = 0; i<4; i++) 
        {
            if(cardsOnTable[i].getTopCard().compareTo(max) == 0)
            {
                scoreCard.update(i, 1);
            }
        }
        
    }
}
