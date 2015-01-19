/*
 * Driver.cpp
 *  week 9: 9.23
 *   Created on: Mar 12, 2014
 *    Author: Grayson Lorenz
 */

#include "DeckOfCards.h"
#include <iostream>

int main(){
	Card card;
	DeckOfCards deck;
	deck.shuffle();

	while(deck.moreCards()){
		std::cout << deck.dealCard().toString() << std::endl;
	}

	return 0;
}
