#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct deck
{
	int value;
	char suit;
};

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

deck card[52];

int round_1();

int main()
{
	Player p1, p2, p3, p4;
	fill_deck();
	//int an_array[13] = {3, 50, 24, 37, 13, 9, 11, 36, 48, 12, 4, 8, 10};
	p1.set(an_array);
	//an_array = {1, 14, 17, 19, 20, 21, 22, 47, 22,}
	round_1();
	
	
	
	
	
	
	
}

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

int round_1()
{
	int turn=0;
	int played[3] = {54, 54, 54};
	
	
	turn++;
	played[0] = 3;
	played[1] = p2.evaluateBestCard(played);
	played[2] = p3.evaluateBestCard(played);
	played[3] = p4.evaluateBestCard(played);
	
}

void shuffle_and_deal()
{}
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

