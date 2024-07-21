package cardgame;

import java.util.Arrays;

// ScoreCard - Maintains one integer score per player, for any number of players
//             Caution: invalid playernumbers result in run-time exception!
// author: Dilara Mandıracı
// date: 19.02.2022
public class ScoreCard
{
    // properties
    int[] scores;
    
    // constructors
    public ScoreCard( int noOfPlayers)
    {
        scores = new int[noOfPlayers];
        
        // init all scores to zero
        for ( int i = 0; i < scores.length; i++)
            scores[i] = 0;
    }
    
    // methods
    /**
     * This methods enables to get score with the player no.
     * @param playerNo 
     * @return scores
     */
    public int getScore( int playerNo)
    {
        return scores[ playerNo];
    }
    
    /**
     * This is an update method with player no and the given amount
     * @param playerNo
     * @param amount updated amount
     */
    public void update(int playerNo, int amount)
    {
        scores[playerNo] += amount;
    }
    
    /**
     * This is a toString() method to print the scores
     */
    public String toString()
    {
        String s;
        s = "\n"
            + "_____________\n"
            + "\nPlayer\tScore\n"
            + "_____________\n";
        
        for ( int playerNo = 0; playerNo < scores.length; playerNo++)
        {
            s = s + playerNo + "\t" + scores[playerNo] + "\n";
        }
        
        s += "_____________\n";
        return s;
    }
    
    /**
     * This is an array of getting winners at the end of the game
     * It creates a new array for the winners indexes.
     * @return
     */
    public int[] getWinners()
    {
        // ToDo
        int [] winners = new int[4]; 
        int max = 0;
        int a = 0;
        for(int element : scores)
        {
            if (element > max)
            {
                max = element;
            }
        }
        for (int i = 0; i < scores.length; i++)
        {
            if(scores[i] == max)
            {
                winners[a] = i;
                a++;
            }
        }
        return Arrays.copyOf(winners, a);
    }
    
} // end class ScoreCard
