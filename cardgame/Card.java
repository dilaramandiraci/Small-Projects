package cardgame;

/**
 * Card - a single playing card
 * @author Dilara Mandıracı
 * @version 19.02.2022
 */
public class Card implements Comparable <Card>
{
    final String[] SUITS = { "Hearts", "Diamonds", "Spades", "Clubs"};
    final String[] FACES = { "A", "2", "3", "4", "5",
                             "6", "7", "8", "9", "10",
                             "J", "Q", "K"};
    
    final int NOOFCARDSINSUIT = 13;
    
    // properties
    int  cardNo;
    
    // constructors
    /**
     * This is the class constructor with two parameters
     * @param faceValue 
     * @param suit
     */
    public Card(int faceValue, int suit )
    {
        cardNo = faceValue + suit * NOOFCARDSINSUIT;
    }
    /**
     * This is another constructor which takes card number as a parameter
     * @param cardNumber
     */

    public Card( int cardNumber)//0-12 HEART 13-26 DİAMOND
    {
        cardNo = cardNumber;
    }
    
    /**
     * gives us the face value of a card
     * @return face value 
     */
    public int getFaceValue()
    {
        return cardNo % NOOFCARDSINSUIT;
    }
    
    /**
     * gives us the suit of a card
     * @return suit
     */
    public int getSuit()
    {
        return cardNo / NOOFCARDSINSUIT;
    }
    
    /**
     * This is the toString() method of the card class
     */
    public String toString()
    {
        return FACES[ getFaceValue() ] + " of " + SUITS[ getSuit() ];
    }
    
    /**
     * Checks if the cards are equal or not
     * @param c given card
     * @return true if cards are equal else returns false.
     */
    public boolean equals(Card c)
    {
        // ToDo
        if (this.getFaceValue() == c.getFaceValue())
        {
            return true;
        }
        else {return false;}
    }
    
    /**
     * Compares two cards according to their face values.
     */
    public int compareTo(Card c)
    {
        // ToDo
        if (this.getFaceValue() > c.getFaceValue())
        {
            return 1;
        }
        if (this.getFaceValue() < c.getFaceValue())
        {
            return -1;
        }
        else 
        {return 0;}
    }
}