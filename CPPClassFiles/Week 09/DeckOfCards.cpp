/*
 * DeckOfCard.cpp
 *  week 9: 9.23
 *   Created on: Mar 12, 2014
 *    Author: Grayson Lorenz
 */
#include "DeckOfCards.h"

DeckOfCards::DeckOfCards(){
	int d = 0;
	for(int s = 0; s < 4; s++){
		for(int f = 0; f < 13; f ++){
			deck[d] = Card(s, f);
			d++;
		}
	}
	card = Card(0,0);
	currentCard = 0;
}

void DeckOfCards::shuffle(){
	srand(time(0));
	Card buffer;
	int r;
	for(int i = 0; i < 52; i ++){
		r = rand() % 52;
		buffer = deck[r];
		deck[r] = deck[i];
		deck[i] = buffer;
	}
}

Card DeckOfCards::dealCard(){
	card = deck[currentCard];
	currentCard ++;
	return card;
}

bool DeckOfCards::moreCards(){
	if (currentCard < 52)
		return true;
	else
		return false;
}




