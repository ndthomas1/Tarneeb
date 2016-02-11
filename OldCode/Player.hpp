#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <stdlib.h>
#include <algorithm>
#include <cstring>

using namespace std;

class Player{

	int Hand[13];
	char referenceDeck[54][3];
	int cardsPlayed[4];

public:
	Player();
	Player(int * hand){ set(hand); }
	void set(int * hand);

	int evaluateBestCard(int * played);

	void organize();
	void organize_for_suit();
	void display();
	void clear();
};


