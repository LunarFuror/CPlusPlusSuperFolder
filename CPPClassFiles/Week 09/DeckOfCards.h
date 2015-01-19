/*
 * DeckOfCards.h
 *  week 9: 9.23
 *   Created on: Mar 12, 2014
 *    Author: Grayson Lorenz
 */

#ifndef DECKOFCARDS_H_
#define DECKOFCARDS_H_
#include "Card.h"
#include <cstdlib>
#include <iostream>

class DeckOfCards{
	public:
		DeckOfCards();
		void shuffle();
		Card dealCard();
		bool moreCards();
	private:
		Card card;
		int currentCard;
		std::array<Card, 52> deck;
};

#endif /* DECKOFCARDS_H_ */
