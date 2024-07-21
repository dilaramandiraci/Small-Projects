package cardgame;

// Player - Simple card game player with name and hand of cards
// author: Dilara Mandıracı
// date: 19.02.2022
public class Player
{
    // properties
    String name;
    Cards hand;
    
    // constructors
    public Player(String name)
    {
        // ToDo
        this.name = name;
        this.hand = new Cards(false);
    }
    
    // methods
    /**
     * This method is an accessor method for the  player name.
     * @return
     */
    public String getName()
    {
        return this.name;
    }
    
    /**
     * this method adds the card c at the top of the players deck.
     * @param c
     */
    public void add(Card c)
    {
        // ToDo
        hand.addTopCard(c);
    }
    
    /**
     * This is a playcard method for the player
     * @return
     */
    public Card playCard()
    {
        // ToDo
        return hand.getTopCard();
    }

    /**
     * This is a toString method for the player class.
     */
    public String toString()
    {
        return this.name;
    }
    
} // end class Player
