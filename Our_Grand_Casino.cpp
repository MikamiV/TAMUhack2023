#include <iostream> //allows use of cout and cin
#include <ctime> //allows use of time function    
#include <string> //allows use of strings  
#include <stdlib.h> //allows use of rand and srand  
#include <cstdlib>


using namespace std;


void introduction(double& balance, string& game);
void slotMachines(double& balance);
void blackJack(double& balance);
void blackJackRules();
void drawingCards(int& playerCards, int& cardDrawn, bool& ace);
void dealerDraw(int& dealer);


int main()
{
    double balance = 0;
    string game;
    introduction(balance, game); //just an introduction duh
    if(balance <= 0)
        return 0;
   
    //games are slot machines and  blackjack
    while(game != "leave")
    {
        if(game == "slots") //plays on the slot machines
        {
            slotMachines(balance);
        }
        else if(game == "blackjack") // plays blackjack
        {
            blackJack(balance);
        }
        else
        {
            cout << "Invalid Input. Please try again \n";
        }
       
        cout << "Your balance is: $" << balance << endl
        << "What do you want to play?" << endl << "Type \"slots\" to play on the slot machine,\n"
        << "\"blackjack\" to play blackjack, \n"
        << "or \"leave\" to leave the casino(But did you know that 90% of gamblers leave before they make it big? Just a reminder...) \n \n";
        cin >> game;
        cout << endl;
    }
   
    if(balance == 0)
        cout << "Get your money up not your funny up fool \n";
    else
        cout << "Why are you leaving? You can still win millions!\n\n\n5";
   
    return 0;
}


void introduction(double& balance, string& game)//introduction
{
    cout << "Hi, welcome to the GBSS Casino! \n";
    cout << "How much money do you have?\n$";
    cin >> balance;
    cout << endl;

    if(balance <= 0)
    {
        cout << "Dude you have no money. Leave!";
        return;
    }
   
    cout << "What do you want to play?" << endl << "Type \"slots\" to play on the slot machine,\n"
    << "\"blackjack\" to play blackjack, \n"
    << "or \"leave\" to leave the casino(But did you know that 90% of gamblers leave before they make it big? You should reconsider...) \n";
   
    cin >> game;
    cout << endl;
}


void slotMachines(double& balance)//slot machines
{
    // Seed the random number generator
    srand(time(0));
    // Variables to store the reels
    int reel1, reel2, reel3;
    balance -= 20;

    // Spin the reels
    reel1 = rand() % 10;
    reel2 = rand() % 10;
    reel3 = rand() % 10;


    // Display the results
    cout << "Reel 1: " << reel1 << endl;
    cout << "Reel 2: " << reel2 << endl;
    cout << "Reel 3: " << reel3 << endl;


    // Check for winning combination
    if ((reel1 == reel2) and (reel2 == reel3))
    {
        cout << "JACKPOT!" << endl;
        balance += 500;
        cout << "You won 500! \n\n";
        
    }
    else
    {
        cout << "Sorry, try again." << endl << endl;
    }
}




void blackJack(double& balance) //blackjack yeh
{
    double bet;
    bool playerAce = false;
    bool playerDeath = false;
    int cardDrawn = (rand() % 52) + 1;
    int playerCards = (rand() % 10) + 1;
    int dealer = (rand() % 10) + 1;
    char hitOrStand;
   
    if(playerCards == 1)
    {
        playerCards += 10;
        playerAce = true;
    }
   
    //introduction to rules
    blackJackRules();
   
    cin >> bet;
    cout << endl;
    if(balance >= bet)
    {
        balance -= bet; //subtracts bet from balance
       
        //dealer's cards
        cout << "The dealer has " << dealer<< endl;
       
        //shows player's cards
        cout << "You have " << playerCards << endl
                << "Do you hit or stand?\n"
                << "h for hit and s for stand\n";
        cin >> hitOrStand;
       
        //if you dont stand, do the while loop
        while(hitOrStand != 's')
        {
            if(hitOrStand != 'h')
                cout << "dude thats not valid"; //not a valid input
            else
            {
                cardDrawn = (rand() % 52) + 1;
                drawingCards(playerCards, cardDrawn, playerAce);
            }
           
            if(playerCards > 21)
            {
                if((playerAce = true) && (playerDeath == false))
                {
                    playerCards -= 10;
                    playerDeath = true;
                }
                else
                {
                    cout << "Dude you have "<< playerCards << ". You lost! Get better! \n";
                    return;
                }
            }
            cout << "You have " << playerCards << endl
                << "Do you wanna hit or stand? \n"
                << "h for hit and s for stand\n";
            cin >> hitOrStand;
        }
       
        while (dealer < 17)
        {
            dealerDraw(dealer);
            cout << "Dealer now has " << dealer << endl;
            if(dealer > 21)
            {
                cout << "THE DEALER BROKE LETS GO!!!\n\n";
                balance += 2*bet;
                return;
            }
        }
       
        if(dealer > playerCards)
            cout << "You lost! You're not very good at this are you? \n\n";
        else if (dealer < playerCards)
        {
            cout << "You won. You're one step closer to addiction \n\n";
            balance += 2*bet;
        }
        else
        {
            cout << "You pushed! Unlucky buddy \n";
            balance += bet;
        }
    }
    else
    {
        cout << "You know you can't afford that\n\n";
        return;
    }
}


void blackJackRules()
{
    cout << "Welcome to the blackJack table! Where I can promise you'll win millions\n\n";
    cout << "Here are the rules: \n"
    << "You will be playing against a dealer. The person who gets the closest to 21 without going over wins\n"
    << "The dealer must stand if they are at 17 or higher, otherwise they will get another card.\n"
    << "It is not a standard 52 card deck. So you can't count cards. Cheater \n";
    cout << "How much would you like to bet? \n$";
}


void drawingCards(int& playerCards, int&cardDrawn, bool& ace)
{
    //we drawing cards here
    string suit;
    if(cardDrawn % 4 == 0)
        suit = "Spades";
    else if (cardDrawn % 4 == 1)
        suit = "Clubs";
    else if (cardDrawn % 4 == 2)
        suit = "Hearts";
    else
        suit = "Diamonds";
    if(cardDrawn > 48)
    {
        cout << "You drew a King of " << suit << "! ";
        playerCards += 10;
    }
    else if(cardDrawn > 44)
    {
        cout << "You drew a Queen of " << suit << "! ";
        playerCards += 10;
    }
    else if(cardDrawn > 40)
    {
        cout << "You drew a Jack of " << suit << "! ";
        playerCards += 10;
    }
    else if(cardDrawn > 36)
    {
        cout << "You drew a 10 of " << suit << "! ";
        playerCards += 10;    
    }
    else if (cardDrawn > 32)
    {
        cout << "You drew a 9 of " << suit << "! ";
        playerCards += 9;    
    }
    else if (cardDrawn > 28)
    {
        cout << "You drew a 8 of " << suit << "! ";
        playerCards += 8;    
    }            
    else if (cardDrawn > 24)
    {
        cout << "You drew a 7 of " << suit << "! ";
        playerCards += 7;    
    }            
    else if (cardDrawn > 20)
    {
        cout << "You drew a 6 of " << suit << "! ";
        playerCards += 6;    
    }
    else if (cardDrawn > 16)
    {
        cout << "You drew a 5 of " << suit << "! ";
        playerCards += 5;
    }
    else if (cardDrawn > 12)
    {
        cout << "You drew a 4 of " << suit << "! ";
        playerCards += 4;    
    }
    else if (cardDrawn > 8)
    {
        cout << "You drew a 3 of " << suit << "! ";
        playerCards += 3;    
    }
    else if (cardDrawn > 4)
    {
        cout << "You drew a 2 of " << suit << "! ";
        playerCards += 2;    
    }
    else
    {
        cout << "You drew an Ace of " << suit << "! ";
        playerCards += 11;
        ace = true;
    }
}


void dealerDraw(int& dealer)
{
    int cardDrawn = (rand() % 52) + 1;
    string suit;
    if(cardDrawn % 4 == 0)
        suit = "Spades";
    else if (cardDrawn % 4 == 1)
        suit = "Clubs";
    else if (cardDrawn % 4 == 2)
        suit = "Hearts";
    else
        suit = "Diamonds";
   
    if (cardDrawn > 48)
    {
        cout << "Dealer drew a King of " << suit << "!";
        dealer += 10;
    }
    else if (cardDrawn > 44)
    {
        cout << "Dealer drew a Queen of " << suit << "! ";
        dealer += 10;
    }
    else if(cardDrawn > 40)
    {
        cout << "Dealer drew a Jack of " << suit << "! ";
        dealer +=10;
    }
    else if(cardDrawn > 36)
    {
        cout << "Dealer drew a 10 of " << suit << "! ";
        dealer += 10;
    }
    else if (cardDrawn > 32)
    {
        cout << "Dealer drew a 9 of " << suit << "! ";
        dealer += 9;    
    }
    else if (cardDrawn > 28)
    {
        cout << "Dealer drew a 8 of " << suit << "! ";
        dealer += 8;    
    }            
    else if (cardDrawn > 24)
    {
        cout << "Dealer drew a 7 of " << suit << "! ";
        dealer += 7;    
    }            
    else if (cardDrawn > 20)
    {
        cout << "Dealer drew a 6 of " << suit << "! ";
        dealer += 6;    
    }
    else if (cardDrawn > 16)
    {
        cout << "Dealer drew a 5 of " << suit << "! ";
        dealer += 5;
    }
    else if (cardDrawn > 12)
    {
        cout << "Dealer drew a 4 of " << suit << "! ";
        dealer += 4;    
    }
    else if (cardDrawn > 8)
    {
        cout << "Dealer drew a 3 of " << suit << "! ";
        dealer += 3;    
    }
    else if (cardDrawn > 4)
    {
        cout << "Dealer drew a 2 of " << suit << "! ";
        dealer += 2;    
    }
    else
    {
        cout << "Dealer drew an Ace of " << suit << "! ";
        dealer += 1;
    }
}
