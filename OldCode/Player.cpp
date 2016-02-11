#include "Player.hpp"

using namespace std;


Player::Player(){
	int SetHand[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	set(SetHand);
}
void Player::set(int * hand){
	for (int i = 0; i < 13; i++)
		Hand[i] = hand[i];
	
	char reference[54][3] = { "","D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "DX", "DJ", "DQ", "DK", "DA",
		"C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "CX", "CJ", "CQ", "CK", "CA",
		"H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "HX", "HJ", "HQ", "HK", "HA",
		"S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "SX", "SJ", "SQ", "SK", "SA" };
	for (int i = 0; i < 53; i++){
		strcpy(referenceDeck[i], reference[i]);
	}
}

void Player::organize(){
	int test[13];
	int counter = 0;
	for (int i = 0; i < 13; i++){
		if (referenceDeck[Hand[i]][0] == 'D'){
			test[counter] = Hand[i];
			counter++;
		}
	}
	for (int k = 0; k < 13; k++){
		if (referenceDeck[Hand[k]][0] == 'C'){
			test[counter] = Hand[k];
			counter++;
		}
	}
	for (int l = 0; l < 13; l++){
		if (referenceDeck[Hand[l]][0] == 'H'){
			test[counter] = Hand[l];
			counter++;
		}
	}
	for (int m = 0; m < 13; m++){
		if (referenceDeck[Hand[m]][0] == 'S'){
			test[counter] = Hand[m];
			counter++;
		}
	}
	for (int j = 0; j < 13; j++){
		Hand[j] = test[j];
	}
}

void Player::organize_for_suit(){
	sort(Hand, Hand + 13);

}
void Player::display(){
	for (int i = 0; i < 13; i++){
		cout << referenceDeck[Hand[i]] << " ";
	}
}
void Player::clear(){
	for (int i = 0; i < 13; i++)
		Hand[i] = 0;
}

