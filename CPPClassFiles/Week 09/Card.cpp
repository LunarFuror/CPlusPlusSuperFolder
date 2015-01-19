/*
 * Card.cpp
 *  week 9: 9.23
 *   Created on: Mar 12, 2014
 *    Author: Grayson Lorenz
 */
#include "Card.h"
Card::Card(){
	setSuit(0);
	setFace(0);
}
Card::Card(int suit, int face){
	setSuit(suit);
	setFace(face);
}

const std::array<std::string, 4> Card::suits = {"Hearts","Clubs", "Diamonds", "Spades"};
const std::array<std::string, 13> Card::faces = {"Ace", "2","3","4","5","6","7","8","9","10","Jack","Queen","King"};

void Card::setSuit(int theSuit){
	suit = theSuit;
}

int Card::getSuit(){
	return suit;
}

void Card::setFace(int theFace){
	face = theFace;
}

int Card::getFace(){
	return face;
}

std::string Card::toString(){
	return faces[getFace()] + " of " + suits[getSuit()];
}


