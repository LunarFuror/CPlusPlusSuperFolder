/*
 * Card.cpp
 *  week 9: 9.23
 *   Created on: Mar 12, 2014
 *    Author: Grayson Lorenz
 */

#ifndef CARD_H_
#define CARD_H_
#include <string>
#include <array>

class Card{
	public:
		Card(int, int);
		Card();
		void setSuit(int);
		int getSuit();
		void setFace(int);
		int getFace();
		std::string toString();
		static const std::array<std::string, 4> suits;
		static const std::array<std::string, 13> faces;
	private:
		int face;
		int suit;

};
#endif /* CARD_H_ */
