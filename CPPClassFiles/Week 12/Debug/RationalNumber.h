/*
 * RationalNumber.h
 *
 *  Created on: Apr 2, 2014
 *      Author: lunarfuror
 */

#ifndef RATIONALNUMBER_H_
#define RATIONALNUMBER_H_

#include<iostream>

class RationalNumber{
		friend std::ostream &operator<<( std::ostream &, const RationalNumber & );

	public:
		RationalNumber();
		RationalNumber(int, int);
		RationalNumber operator+( const RationalNumber & ) const;
		RationalNumber operator-( const RationalNumber & ) const;
		RationalNumber operator/( const RationalNumber & ) const;
		RationalNumber operator*( const RationalNumber & ) const;

		bool operator==( const RationalNumber & ) const;
		bool operator>=( const RationalNumber & ) const;
		bool operator<=( const RationalNumber & ) const;
		bool operator>( const RationalNumber & ) const;
		bool operator<( const RationalNumber & ) const;

		void setNumerator(int);
		int getNumerator() const;
		void setDenominator(int);
		int getDenominator() const;

		void simplify();
		int gcd(int, int);

	private:
		int numerator;
		int denominator;
		int whole;
};


#endif /* RATIONALNUMBER_H_ */
