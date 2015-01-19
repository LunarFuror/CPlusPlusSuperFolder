// Exercise 12.15 Solution: Account.h
// Definition of Account class.
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
   explicit Account( double ); // constructor initializes balance
   virtual void credit( double ); // add an amount to the account balance
   virtual bool debit( double ); // subtract an amount from the balance
   void setBalance( double ); // sets the account balance
   double getBalance(); // return the account balance
   virtual ~Account();
private:
   double balance; // data member that stores the balance
}; // end class Account

#endif
