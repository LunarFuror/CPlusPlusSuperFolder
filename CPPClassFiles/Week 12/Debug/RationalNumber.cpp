/*
 * RationalNumber.cpp
 *
 *  Created on: Apr 2, 2014
 *      Author: lunarfuror
 */

#include "RationalNumber.h"
std::ostream &operator<<( std::ostream & output, const RationalNumber & ration){
	RationalNumber rationIn = ration;
	rationIn.simplify();
	output << rationIn.getNumerator() << '/' << rationIn.getDenominator();
	return output;
}

RationalNumber::RationalNumber(){
	setDenominator(1);
	setNumerator(0);
}

RationalNumber::RationalNumber(int denom, int numer){
 setDenominator(denom);
 setNumerator(numer);
}

RationalNumber RationalNumber::operator+( const RationalNumber & rationIn) const{
	RationalNumber ration = rationIn;
	RationalNumber rn = *this;
	int denom = ration.getDenominator();

	ration.setDenominator(ration.getDenominator() * rn.getDenominator());
	ration.setNumerator(ration.getNumerator() * rn.getDenominator());
	rn.setDenominator(rn.getDenominator() * denom);
	rn.setNumerator(rn.getNumerator() * denom);

	ration.setNumerator(ration.getNumerator() + rn.getNumerator());
	ration.simplify();
	return ration;
}

RationalNumber RationalNumber::operator-( const RationalNumber & rationIn) const{
	RationalNumber ration = rationIn;
	RationalNumber rn = *this;
	int denom = ration.getDenominator();

	ration.setDenominator(ration.getDenominator() * rn.getDenominator());
	ration.setNumerator(ration.getNumerator() * rn.getDenominator());
	rn.setDenominator(rn.getDenominator() * denom);
	rn.setNumerator(rn.getNumerator() * denom);

	ration.setNumerator(ration.getNumerator() - rn.getNumerator());
	ration.simplify();
	return ration;
}

RationalNumber RationalNumber::operator/( const RationalNumber & rationIn) const{
	RationalNumber ration = rationIn;
	RationalNumber rn = *this;

	ration.setDenominator(ration.getDenominator() * rn.getNumerator());
	ration.setNumerator(ration.getNumerator() * rn.getDenominator());

	ration.simplify();
	return ration;
}

RationalNumber RationalNumber::operator*( const RationalNumber & rationIn) const{
	RationalNumber ration = rationIn;
	RationalNumber rn = *this;

	ration.setDenominator(ration.getDenominator() * rn.getDenominator());
	ration.setNumerator(ration.getNumerator() * rn.getNumerator());

	ration.simplify();
	return ration;
}

bool RationalNumber::operator== ( const RationalNumber & rationIn) const{
	RationalNumber ration = rationIn;
	RationalNumber rn = *this;

	ration.simplify();
	rn.simplify();

	if(rn.getDenominator() == ration.getDenominator()){
		if(rn.getNumerator() == ration.getNumerator()){
			return true;
		}
	}

	return false;
}

bool RationalNumber::operator>=( const RationalNumber & rationIn) const{
	RationalNumber ration = rationIn;
	RationalNumber rn = *this;
	int denom = ration.getDenominator();

	ration.setDenominator(ration.getDenominator() * rn.getDenominator());
	ration.setNumerator(ration.getNumerator() * rn.getDenominator());
	rn.setDenominator(rn.getDenominator() * denom);
	rn.setNumerator(rn.getNumerator() * denom);

	if(rn.getNumerator() >= ration.getNumerator())
		return true;

	return false;
}

bool RationalNumber::operator<=( const RationalNumber & rationIn) const{
	RationalNumber ration = rationIn;
	RationalNumber rn = *this;
	int denom = ration.getDenominator();

	ration.setDenominator(ration.getDenominator() * rn.getDenominator());
	ration.setNumerator(ration.getNumerator() * rn.getDenominator());
	rn.setDenominator(rn.getDenominator() * denom);
	rn.setNumerator(rn.getNumerator() * denom);

	if(rn.getNumerator() <= ration.getNumerator())
		return true;

	return false;
}

bool RationalNumber::operator>( const RationalNumber & rationIn) const{
	RationalNumber ration = rationIn;
	RationalNumber rn = *this;
	int denom = ration.getDenominator();

	ration.setDenominator(ration.getDenominator() * rn.getDenominator());
	ration.setNumerator(ration.getNumerator() * rn.getDenominator());
	rn.setDenominator(rn.getDenominator() * denom);
	rn.setNumerator(rn.getNumerator() * denom);

	if(rn.getNumerator() > ration.getNumerator())
		return true;

	return false;
}

bool RationalNumber::operator<( const RationalNumber & rationIn) const{
	RationalNumber ration = rationIn;
	RationalNumber rn = *this;
	int denom = ration.getDenominator();

	ration.setDenominator(ration.getDenominator() * rn.getDenominator());
	ration.setNumerator(ration.getNumerator() * rn.getDenominator());
	rn.setDenominator(rn.getDenominator() * denom);
	rn.setNumerator(rn.getNumerator() * denom);

	if(rn.getNumerator() < ration.getNumerator())
		return true;

	return false;
}

void RationalNumber::setNumerator(int numer){
	numerator = numer;
}

int RationalNumber::getNumerator() const{
	return numerator;
}

void RationalNumber::setDenominator(int denom){
	if(denom < 1){
		denom = 1;
	}
	denominator = denom;
}

int RationalNumber::getDenominator() const{
	return denominator;
}

void RationalNumber::simplify(){
	int greatest = gcd(getDenominator(), getNumerator());
	setNumerator(getNumerator() / greatest);
	setDenominator(getDenominator() / greatest);
}

int RationalNumber::gcd(int denom, int numer){
	return (numer == 0 ? denom : gcd(numer, denom%numer));
}
