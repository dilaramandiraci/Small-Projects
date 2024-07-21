package hangman;

import java.util.Random;
/**
 * This is a Hangman Class with vairous methods and properties
 * @author Dilara Mandıracı
 */
public class Hangman {

    private int numberOfIncorrectTries;
    private final int maxAllowedIncorrectTries = 6;
    private StringBuffer secretWord;
    private StringBuffer allLetters;
    private StringBuffer usedLetters;
    private StringBuffer knownSoFar;
    private String[] fruits = {"göztepe", "crystalpalace", "fcbarcelona", "atalanta", "inter", "spartakmoskova", "dinamozagreb", "watfordfc"};  
    //"strawberry", "cherry", "apple" , "pomegranate" , "peach" ,"melon" , "watermelon" ,
    //"pear" , "kiwi" , "banana" , "mango", "grapes"
    /**
     * This is the constructor for Hangman Class which is chooses secret word and initalizes other intstance variables.
     */
    public Hangman()
    {
        this.secretWord = new StringBuffer(chooseSecretWord(fruits));
        this.knownSoFar = new StringBuffer();
        this.allLetters = new StringBuffer("abcdefghijklmnopqrstuvwxyz");
        this.usedLetters = new StringBuffer();
        this.numberOfIncorrectTries = 0;
    }

    //getters

    /**
     *  This method returns the max allowed in correct tries.
     * @return (int) Maximum In Correct Tries
     */
    public int getMaxAllowedIncorrectTries() {
        return maxAllowedIncorrectTries;
    }

    /**
     * This method is the getter for secret word.
     * @return secret word as a String
     */
    public String getSecretWord() {
        return secretWord.toString();
    }

    /**
     * This method is the getter for fruits array.
     * @return fruits array
     */
    public String[] getFruits() {
        return fruits;
    }

    /**
     * This method is the getter current number of incorrect tries.
     * @return integer of current incorrect tries
     */
    public int getNumberOfIncorrectTries() {
        return this.numberOfIncorrectTries;
    }

    /**
     * This method is the getter for all letters.
     * @return all letters as a String.
     */
    public String getAllLetters() {
        return allLetters.toString();
    }

    /**
     * This method is the getter for used letters so far.
     * @return used letters so far
     */
    public String getUsedLetters() {
        return usedLetters.toString();
    }

    /**
     * This methos allows us to know "known letters so far  "
     * @return current condition of word
     */
    public String getKnownSoFar() {
        return knownSoFar.toString();
    }

    
    //setters

    /**
     * This is the setter of number of incorrect tries manually.
     * @param numberOfIncorretcTries
     */
    public void setNumberOfIncorrectTries(int numberOfIncorretcTries) {
        this.numberOfIncorrectTries = numberOfIncorretcTries;
    }
    /**
     * This is the setter of used letters manually.
     * @param letterUsed
     */
    public void setUsedLetters(String letterUsed) {
        this.usedLetters = this.usedLetters.append(letterUsed);
    }

    /**
     * This is the setter of known so far manually.
     * @param knownSoFar
     */
    public void setKnownSoFar(StringBuffer knownSoFar) {
        this.knownSoFar = knownSoFar;
    }

    //other methods

    /**
     * This is a random word chooser from the given array
     * @param array
     * @return the secret word
     */
    public static String chooseSecretWord(String[] array) {
        Random rand = new Random();
        int randomNumber = rand.nextInt(array.length-1);
        return array[randomNumber];
    }

    /**
     * This method tries the given letter to the cencored (secret) word
     * @param letter
     * @return How many times the letter has been found
     */
    public int tryThis(char letter)
    {
        int times = 0;
        Boolean theLetterIsFound = false;
        usedLetters.append(letter);
        for(int j=0;j<secretWord.length();j++)
        {
            if(secretWord.charAt(j)==letter)
            {
                theLetterIsFound = true;
                knownSoFar.setCharAt(j,letter);
                times++;
            }
        }
        if (theLetterIsFound == false)
        {
            this.numberOfIncorrectTries ++;
        }
        return times;  
    }

    /**
     * This is a method for cencore the secret word with "_" in order to play the game.
     * @param word
     */
    public void allUnknown(String word){
        for (int i = 0; i < word.length(); i++) { 

            this.knownSoFar = this.knownSoFar.append('_');
        }    
    } 

    /**
     * This method checks if the game is over. Difference between hasLost() method is that if game has been won the game is over too.
     * @return boolean the game is over or not
     */
    public boolean isGameOver() {
        return(numberOfIncorrectTries == 6 || knownSoFar.indexOf("_") == -1);
    }

    /**
     * This method checks if the game has lost or not
     * @return boolean for the game has lost
     */
    public boolean hasLost() {
        return(getNumberOfIncorrectTries() == 6);
    }

    /**
     * This is a method for displaying the hangman.
     */
    public void displayHangman() //This part is inspired by the Sadra M. group (section 3). Minor changes were made to integrate it into my own code.
    {   
        String Hangman = "";
        if(numberOfIncorrectTries ==0){
        Hangman = "______ \n |   | \n |    \n | \n |  \n";
        }
        if(numberOfIncorrectTries == 1){
        Hangman = "______ \n |   | \n |   O  \n |   \n |  \n";
        }
        else if(numberOfIncorrectTries == 2){
        Hangman = "______ \n |   | \n |   O  \n |   | \n |  \n";
        }
        else if(numberOfIncorrectTries == 3){
        Hangman = "______ \n |   | \n |   O  \n |  /|\n |  \n";
        }
        else if(numberOfIncorrectTries == 4){
        Hangman = "______ \n |   | \n |   O  \n |  /|\\ \n |  \n";
        }
        else if(numberOfIncorrectTries == 5){
        Hangman = "______ \n |   | \n |   O  \n |  /|\\ \n |  / \n";
        }
        else if(numberOfIncorrectTries == 6){
        Hangman = "______ \n |   | \n |   O  \n |  /|\\ \n |  / \\ \n";
        }
    System.out.println(Hangman);
    }
        
}