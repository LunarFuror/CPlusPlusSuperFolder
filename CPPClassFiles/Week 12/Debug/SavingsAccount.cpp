// Exercise 12.15 Solution: SavingsAccount.cpp
// Member-function definitions for class SavingsAccount.
#include <stdexcept>
#include "SavingsAccount.h" // SavingsAccount class definition
using namespace std;

// constructor initializes balance and interest rate
SavingsAccount::SavingsAccount( double initialBalance, double rate )
   : Account( initialBalance ) // initialize base class
{
   if ( rate >= 0.0 )
      interestRate = rate;
   else
      throw invalid_argument( "Interest rate must be >= 0.0" );
} // end SavingsAccount constructor

// return the amount of interest earned
double SavingsAccount::calculateInterest()
{
   return getBalance() * interestRate;
} // end function calculateInterest
