#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <stdlib.h>
#include "Player.hpp"
#include <time.h>

using namespace std;

void exit(void);
void fill_deck(void);
void shuffle_and_deal(void);
int round_1(void);

struct deck
{
	int value;
	char suit;
};

struct player
{
	int hand[13];
};

player p1, p2, p3, p4; //Iitializes Hands 
Player P1, P2, P3, P4; //Initializes Player objects -- Note the capital P. 

deck card[52];
deck swp[52];
int intDeck[52]; //Used your idea to create my own fill deck function that simplified yours <- might be a problem with 52nd care here..
                 //Working on it though.
int intSwp[52]; //Same as deck swp[52]

int main()
{
	cout << "\t\t\tWelcome to Tarneeb 1.0\n\n";
	//deck card[52];
	fill_deck();
	//player p1;

	/*for (int i = 0; i < 52; i++)
	{
	cout<< "\nCard " << (i + 1) << " = " << card[i].value << " and the suit is " << card[i].suit;
	}*/

	shuffle_and_deal();
	round_1();
	cout << "\n\nRight before exit";
	//exit();
}

void exit(void)
{
	cin.get();
}

void fill_deck(void){
	for (int i = 0; i < 52; i++){
		intDeck[i] = i + 1;
		intSwp[i] = intDeck[i];
	}

}

void shuffle_and_deal(){
	int temp = 0;
	int counter = 1;
	for (int i = 0; i < 52; i++){
		srand(time(0));
		temp = (rand() % 52);
		
		while (intSwp[temp] == 0)
			temp = (rand() % 52);

		if (counter % 4 == 1)
			p1.hand[i /4] = intSwp[temp];
		if (counter % 4 == 2)
			p2.hand[i/4] = intSwp[temp];
		if (counter % 4 == 3)
			p3.hand[i/4] = intSwp[temp];
		if (counter % 4 == 0)
			p4.hand[i / 4] = intSwp[temp];

		counter++;
		intSwp[temp] = 0;
	}
	P1.set(p1.hand);
	P2.set(p2.hand);
	P3.set(p3.hand);
	P4.set(p4.hand);
}


int round_1()
{
	cout << "\n\n\n\t\t\tPlayer 3\n\n\n\nPlayer 4\t\t\t\t\tPlayer 2\n\n\n\n\t\t\tPlayer 1\n";

	char input[2], in_suit, in_value;
	
	P1.organize_for_suit();
	P1.display();
	cout << endl;
	cout << endl;
	P2.organize_for_suit();
	P2.display();
	cout << endl;
	cout << endl;
	P3.organize_for_suit();
	P3.display();
	cout << endl;
	cout << endl;
	P4.organize_for_suit();
	P4.display();
	cout << endl;
	cout << endl;

	cout << "\n\nEnter card: ";
	cin.getline(input, 3, '\n');
	
	return 0;
}
