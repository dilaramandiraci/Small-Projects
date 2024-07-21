package cardgame;

import java.util.Random;

// Cards - Maintains a collection of zero or more playing cards.
//         Provides facilities to create a full pack of 52 cards
//         and to shuffle the cards.
// author: Dilara Mandıracı 
// date: 19.02.2022
public class Cards
{
    final int NOOFCARDSINFULLPACK = 52;
    
    // properties
    Card[] cards;
    int    valid;  // number of cards currently in collection
    
    // constructors 
    /**
     * This is the constructor of the cards class it creates full pack of cards if the boolean "fulpack" is true.
     * @param fullPack
     */
    public Cards( boolean fullPack)
    {
        cards = new Card[ NOOFCARDSINFULLPACK ];
        valid = 0;
        
        if (fullPack)
            createFullPackOfCards();
    }
    
    // methods
    public int getNoOfCardsInFullPack() //this method was added to used in cardgame class
    {
        return NOOFCARDSINFULLPACK;
    }

    /**
     * gives the value of the top card and removes it from the deck.
     * @return the top card.
     */
    public Card getTopCard()
    {
        Card tmp;

        if ( valid <= 0)
            return null;
        else
        {
            valid--;
            tmp = cards[valid];
            cards[valid] = null;
            return tmp;
        }
    }
    
    /**
     * This method is implemented because when i use getTopCard() method, top card is removed but sometimes 
     * i just need to know the top card without remove it.
     * @return the value of the top card.
     */
    public Card justLookTopCard() 
    {
        Card temp = getTopCard();
        addTopCard(temp);
        return temp;
    }

    /**
     * Adds given card c to the top of the cards.
     * @param c given card
     * @return true if the card is added succesfully.
     */
    public boolean addTopCard(Card c)
    {
        if ( valid < cards.length)
        {
            cards[valid] = c;   // should this be cloned?
            valid++;
            return true;
        }
        return false;
    }
    
    /**
     * creates full pack of cards.
     */
    private void createFullPackOfCards()
    {
        // Todo
        for(int i = 0; i<NOOFCARDSINFULLPACK; i++) //i have changed the creating way because it is much easier.
        {
            addTopCard(new Card(i));
        }
        //provided
        /* addTopCard( new Card(0) );
        addTopCard( new Card(25) );
        addTopCard( new Card(13) ); */
    }

    /**
     * This method enables to shuffle the cards at the beginning of the game.
     */
    public void shuffle()
    {
        // Todo
        Random rand = new Random();
       
        for(int i = cards.length-1; i>0; i--)
        {
            int randomIndex = rand.nextInt(cards.length);
            Card temp = cards[i];
            cards[i] = cards[randomIndex];
            cards[randomIndex] = temp;
        }

    }
    
} // end class Cards
