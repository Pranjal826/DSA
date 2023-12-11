// [11/26, 9:01 PM] Pranjal Shukla: Standard playing card deck

// There are 52 cards. Each card has a suit (Spades, Clubs, Diamonds and Hearts) and a value (2,3,4,5,6,7,8,9,10,J,Q,K.Α). The 52 cards are each a unique combination of the two (4 suits x 13 values = 52). Within cards of the same suit, a 'bigger' card is determined by the value as listed in ascending order. Thus, 5 is bigger than 2, K is bigger than 10, A is bigger than J and so on

// Rules of the game
// [11/26, 9:02 PM] Pranjal Shukla: Before playing the game one suit is designated as the trump suit. The game is played by 4 people using a standard deck of playing cards. Alternate people are in the same team. The game is played in rounds. Each round is started by the winner of the previous round. In a round, each person plays exactly one card. The suit of the round is the suit of the card played by the first person. A person may only play a card of the suit of the round Only if the person does NOT have any card of the suit, the person may play a card of some other suit.

// Scoring

// Once all the cards have been played, scoring is as follows. If trumps have been played, biggest card of the trump suit is considered the highest. If not, the biggest card of the suit of the round (i.e. the suit of the card played by the person who started the round) is considered the highest. The round is won by the team whose member played the biggest card
// [11/26, 9:02 PM] Pranjal Shukla: Optimal strategy

// Once three cards have been played, the fourth person plays the cards as per the following optimal strategy

// If the current biggest card is of the fourth person's teammate, the person aims to play the smallest card overall Else, if the person can win the suit, he aims to play the smallest card that will enable him to win the suit. Else, the person aims to play the smallest card overall

// Choosing smallest card to win

// If nobody has played the trump card, and the player has cards of the suit of the round, it will be the smallest card of the suit that is larger than the largest card played

// If nobody has played the trump card, and the player does not have cards of the suit of the round, it is the smallest trump card

// If someone has already played the trump card, it is the smallest trump card greater than the greatest trump card already played
// [11/26, 9:03 PM] Pranjal Shukla: Choosing smallest card overall

// If the person has cards of the suit of the round, it is the card with the smallest value within cards of that suit

// If the person does not have any card of the suit of the round, and the person does not have any cards other than trump cards, it will be the smallest trump card

// If the person does not have any card of the suit of the round, and the person has cards other than the trump card, it will be card with the smallest number with a suit preference of clubs, diamonds, hearts and spades in that order (only suits that are neither the suit of the round nor trump are considered) Thus, 3 of diamonds is considered smaller than 3 of spades but considered larger than 2 of spades

// Input format

// The input will be a single line of text with various components. Each component has a key, followed by colon() followed by the value. Different components are separated by. Each component comes exactly once
// [11/26, 9:03 PM] Pranjal Shukla: The various components are

// Players The value is a list of 4 player names separated by comma (.) The player names are provided in order, so player 1 and player 3 are in a team and player 2 and player 4 are in another team.

// Self The name of the player who is playing last in this round (ie the person who will select the optimal strategy

// Cards played by each of the other players. There will be 3 such components and the key for each component will be the name of the player

// Cards This is a comma separated list of cards of the last player (ie 'Self")

// Trump This is the suit of the trump

// When cards are mentioned, they will have the suit (s.h.d.c) followed by the value (2,3,4,5,6,7,8,9,10j.q.k.a) Thus sa is Ace of Spades and so on

// Please note that the components can be in any order. In
// [11/26, 9:04 PM] Pranjal Shukla: When cards are mentioned, they will have the suit (s,h,d,c) followed by the value (2.3,4,5,6,7,8,9,10j,q,k,a) Thus sa is Ace of Spades and so on

// Please note that the components can be in any order. In particular, the player who played first does not necessarily come before all other players The first player as will as the other team member will need to be determined from the order of the players in the "Players" component

// Output format

// The optimum card to be played

// Sample input
// players:tom, dick, harry, john;self:john;Trump:s;dick:S10;Tom:S2;Harry:ca;cards:S3,sk,ha
// Sample output
// s3
// ? code in cpp
#include <iostream>
using namespace std;
int main()
{
    string players[4];
    int i = 0;
    while (cin >> players[i])
    {
        if (players[i].find(":"))
            break;
        i++;
    }
    cout << "Players : ";
    for (int i = 0; i < 4; i++)
        cout << players[i] << " ";
    cout << endl;
    cin >> players[i];
    cout << "Your name : " << players[i] << endl;
    string trump_suit;
    cin >> trump_suit;
    cout << "Trump Suit : " << trump_suit << endl;
    string cards[52];
    int k = 0;
    while (cin >> cards[k])
    {
        if (cards[k].find(",") == -1)
            break;
        else
            k++;
    }
    // cout<<k<<endl;
    int max_card = 0;
    int min_card = 999;
    int count_max = 0;
    int count_min = 0;
    bool flag = false;
    for (int i = 0; i <= k - 1; i++)
    {
        char temp[6];
        strncpy(temp, &cards[i][0], 2);
        temp[2] = '\0';
        // cout<<temp<<endl;
        if (temp[0] == trump_suit[0])
        {
            if (temp[1] == 'a')
                max_card = 14;
            else if (temp[1] == 'k')
                max_card = 13;
            else if (temp[1] == 'q')
                max_card = 12;
            else if (temp[1] == 'j')
                max_card = 11;
            else if (temp[1] == '1')
                max_card = 10;
            else
                max_card = temp[1] - '0';
            if (max_card > count_max)
            {
                count_max = max_card;
                flag = true;
            }
        }
    }
    if (flag == true)
    {
        for (int i = 0; i <= k - 1; i++)
        {
            char temp[6];
            strncpy(temp, &cards[i][0], 2);
            temp[2] = '\0';
            if (temp[0] == trump_suit[0])
            {
                if (temp[1] == 'a')
                    max_card = 14;
                else if (temp[1] == 'k')
                    max_card = 13;
                else if (temp[1] == 'q')
                    max_card = 12;
                else if (temp[1] == 'j')
                    max_card = 11;
                else if (temp[1] == '1')
                    max_card = 10;
                else
                    max_card = temp[1] - '0';
                if (max_card < count_min)
                {
                    count_min = max_card;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i <= k - 1; i++)
        {
            char temp[6];
            strncpy(temp, &cards[i][0], 2);
            temp[2] = '\0';
            if (temp[1] == 'a')
                max_card = 14;
            else if (temp[1] == 'k')
                max_card = 13;
            else if (temp[1] == 'q')
                max_card = 12;
            else if (temp[1] == 'j')
                max_card = 11;
            else if (temp[1] == '1')
                max_card = 10;
            else
                max_card = temp[1] - '0';
            if (max_card < count_min)
            {
                count_min = max_card;
            }
        }
    }
    // cout<<count_min<<endl;
    // cout<<count_max<<endl
    for (int i = 0; i <= k - 1; i++)
    {
        char temp[6];
        strncpy(temp, &cards[i][0], 2);
        temp[2] = '\0';
        if (temp[1] == 'a')
            max_card = 14;
        else if (temp[1] == 'k')
            max_card = 13;
        else if (temp[1] == 'q')
            max_card = 12;
        else if (temp[1] == 'j')
            max_card = 11;
        else if (temp[1] == '1')
            max_card = 10;
        else
            max_card = temp[1] - '0';
        if (max_card == count_min)
        {
            cout << cards[i] << endl;
            break;
        }
    }
    return 0;
}
// output should be s
