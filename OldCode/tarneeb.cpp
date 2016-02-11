#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <stdlib.h>

using namespace std;

void exit (void);
void fill_deck (void);
void shuffle_and_deal(void);
int round_1(void);
int round_2(int a);

class Player{

	int Hand[13];
	char referenceDeck[53][3];
	int cardsPlayed[4];

public:
	Player();
	Player(int * hand){ set(hand); }
	void set(int * hand);

	int evaluateBestCard(int * played);
	
	void clear();
};

struct deck
{
	int value;
	char suit;
};

struct player
{
	int hand[13];
};

player p1, p2, p3, p4;
/*class player
{
	public:
		//fixed the shuffle function issue by introducing a "swap" array that is an identical copy to the deck.
		//having trouble ordering player 1's hands without crashing the laptop.  
		player();
		int hand[13];
};*/

deck card[52];
deck swp[52];
//int player_1[13], player_2[13], player_3[13], player_4[13];

int main()
{
	cout<<"\t\t\tWelcome to Tarneeb 1.0\n\n";
	//deck card[52];
	fill_deck();
	//player p1;
	
	/*for (int i = 0; i < 52; i++)
	{
		cout<< "\nCard " << (i + 1) << " = " << card[i].value << " and the suit is " << card[i].suit;
	}*/
	
	shuffle_and_deal();
	Player player1(p1.hand), player2(p2.hand), player3(p3.hand), player4(p4.hand);	
	round_1();
	cout<<"\n\nRight before exit";
	//exit();
}

/*void exit (void)
{
	cin.get();
}*/

void fill_deck (void)
{
	//cout<<"\nIn fill_deck";
	char a = 'S';
	
	while (a == 'S')
	{
		//cout<<"\n In while loop";
		for (int i = 0; i < 13; i++)
		{
			card[i].suit = a;
			swp[i].suit = a;
			card[i].value = (i + 1);
			swp[i].value = (i + 1);
			//cout<< "\nCard Suit " << (i + 1) << " = " << card[i].suit;
		}
		a = 'H';
	}
	
	while (a == 'H')
	{
		//cout<<"\n In while loop";
		for (int i = 13; i < 26; i++)
		{
			card[i].suit = a;
			swp[i].suit = a;
			card[i].value = (i - 12);
			swp[i].value = (i - 12);
			//cout<< "\nCard Suit " << (i + 1) << " = " << card[i].suit;
		}
		a = 'D';
	}
	
	while (a == 'D')
	{
		//cout<<"\n In while loop";
		for (int i = 26; i < 39; i++)
		{
			card[i].suit = a;
			swp[i].suit = a;
			card[i].value = (i - 25);
			swp[i].value = (i - 25);
			//cout<< "\nCard Suit " << (i + 1) << " = " << card[i].suit;
		}
		a = 'C';
	}
	
	while (a == 'C')
	{
		//cout<<"\n In while loop";
		for (int i = 39; i < 52; i++)
		{
			card[i].suit = a;
			swp[i].suit = a;
			card[i].value = (i - 38);
			swp[i].value = (i - 38);
			//cout<< "\nCard Suit " << (i + 1) << " = " << card[i].suit;
		}
		a = 'q';
	}		
}

void shuffle_and_deal()
{
	int temp = 0;
	/*player_1[0] = (rand()%52);
	cout<<"\n\nNumber is " << player_1[0];*/
	
	/*p1.hand[3]= (rand()%52);	
	cout<< "\n\nHand number 3 for player 1 is = " << p1.hand[3];*/
	
	/*for (int i = 0; i < 13; i++)
	{
		p1.hand[i] = (rand()%52);
		cout<< "\nHand number " << (i + 1) << " for player 1 is = " << p1.hand[i];
	}*/
	
	
	
	for (int i = 0; i < 13; i++)
	{
		temp = (rand()%52);
		
		while (swp[temp].value == 0)
		{
			temp = (rand()%52);
		}
		
		/*for (int j = 0; j < 52; j++)
		{
			while (swp[j].value == p1.hand[temp])
			{
				temp = (rand()%52);
			}
		}*/
		p1.hand[i] = temp;
		cout<< "\nHand number " << (i + 1) << " for player 1 is = " << p1.hand[i];
		swp[temp].value = 0;
		//Player player(p1.hand);		
	}
	
	for (int i = 13; i < 26; i++)
	{
		temp = (rand()%52);
		
		while (swp[temp].value == 0)
		{
			temp = (rand()%52);
		}
		
		
		p2.hand[i] = temp;
		cout<< "\nHand number " << (i + 1) << " for player 2 is = " << p2.hand[i];
		swp[temp].value = 0;		
	}
	
	for (int i = 26; i < 39; i++)
	{
		temp = (rand()%52);
		
		while (swp[temp].value == 0)
		{
			temp = (rand()%52);
		}
						
		p3.hand[i] = temp;
		cout<< "\nHand number " << (i + 1) << " for player 3 is = " << p3.hand[i];
		swp[temp].value = 0;		
	}
	
	for (int i = 39; i < 52; i++)
	{
		temp = (rand()%52);
		
		while (swp[temp].value == 0)
		{
			temp = (rand()%52);
		}
		
		p4.hand[i] = temp;
		cout<< "\nHand number " << (i + 1) << " for player 4 is = " << p4.hand[i];
		swp[temp].value = 0;		
	}
	
	for (int i = 0; i < 13; i++)
	{
		card[i].suit = 'S';	
	}
	
	for (int i = 13; i < 26; i++)
	{
		card[i].suit = 'H';	
	}
	
	for (int i = 26; i < 39; i++)
	{
		card[i].suit = 'D';	
	}
	
	for (int i = 39; i < 52; i++)
	{
		card[i].suit = 'C';	
	}
	
	cout<<"\n\n";
	
	for (int i = 0; i < 52; i++)
	{
		cout<< "\nswp " << (i + 1) << " = " << swp[i].value << " and the suit is " << swp[i].suit;
	}		
}

int round_1()
{
	cout<<"\n\n\n\t\t\tPlayer 3\n\n\n\nPlayer 4\t\t\t\t\tPlayer 2\n\n\n\n\t\t\tPlayer 1\n\t";
	
	//for (int i = 0; i < 13; i++)
	//{
		/*while (card[p1.hand[i]].suit == 'S')
		{
			cout<< card[p1.hand[i]].value << card[p1.hand[i]].suit << " ";
		}
		
		while (card[p1.hand[i]].suit == 'S')
		{
			cout<< card[p1.hand[i]].value << card[p1.hand[i]].suit << " ";
		}*/
	//	cout<< card[p1.hand[i]].value << card[p1.hand[i]].suit << " ";
	//}
	
	//int check;
	char input[2];
	
	/*
	for (int i = 0; i < 13; i++)
	{
		if(card[p1.hand[i]].suit == 'S')
		{
			cout<< card[p1.hand[i]].value << card[p1.hand[i]].suit << " ";
		}
	}
	
	for (int i = 0; i < 13; i++)
	{
		if(card[p1.hand[i]].suit == 'H')
		{
			cout<< card[p1.hand[i]].value << card[p1.hand[i]].suit << " ";
		}
	}
	
	for (int i = 0; i < 13; i++)
	{
		if(card[p1.hand[i]].suit == 'D')
		{
			cout<< card[p1.hand[i]].value << card[p1.hand[i]].suit << " ";
		}
	}
	
	for (int i = 0; i < 13; i++)
	{
		if(card[p1.hand[i]].suit == 'C')
		{
			cout<< card[p1.hand[i]].value << card[p1.hand[i]].suit << " ";
		}
	}*/
	
	cout<<"\n\nEnter card: ";
	cin.getline(input, 3, '\n');
	
	
	//cin.ignore();
	//cout<<"\nYou entered: " << input << endl;
	//cout<<"\n" << input[0] << input[1] << input[2];
	
	//Need a check function to make sure input is correct
	
	
	
	
	
	
	
	
	return 0;
}
