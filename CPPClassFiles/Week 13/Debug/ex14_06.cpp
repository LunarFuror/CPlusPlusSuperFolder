// Exercise 14.6 Solution: Ex14_06.cpp
#include <iostream> 
#include <iomanip> 
#include <fstream>
#include <string>
#include <cstdlib> // exit function prototype
using namespace std;

void printOutput( ofstream&, int, string, string, double ); // prototype

int main()
{
   int masterAccount; // holds account from old master file
   int transactionAccount; // holds account from transactions file
   double masterBalance; // holds balance from old master file
   double transactionBalance; // holds balance from transactions file
   string masterFirstName; // first name from master file
   string masterLastName; // last name from master file

   // file streams for input and output files
   ifstream inOldMaster( "oldmast.dat" );
   ifstream inTransaction( "trans.dat" );
   ofstream outNewMaster( "newmast.dat" );

   // terminate application if old master file cannot be opened
   if ( !inOldMaster )
   {
      cerr << "Unable to open oldmast.dat\n";
	  system("pause");
      exit( 1 );
   } // end if
   
   // terminate application if transactions file cannot be opened
   if ( !inTransaction ) 
   {
      cerr << "Unable to open trans.dat\n";
	  system("pause");
      exit( 1 );
   } // end if

   // terminate application if new master file cannot be opened
   if ( !outNewMaster )
   {
      cerr << "Unable to open newmast.dat\n";
	  system("pause");
      exit( 1 );
   } // end if

   // display account currently being processed
   cout << "Processing...\n";
   inTransaction >> transactionAccount >> transactionBalance;

   // read from master file until end of transactions file reached
   while ( !inTransaction.eof() )
   {
      inOldMaster >> masterAccount >> masterFirstName
         >> masterLastName >> masterBalance;
      
      // display accounts from master file until 
      // number of new account is reached
      while ( masterAccount < transactionAccount && !inOldMaster.eof() ) 
      {
         printOutput( outNewMaster, masterAccount, masterFirstName,
            masterLastName, masterBalance );
         inOldMaster >> masterAccount >> masterFirstName
            >> masterLastName >> masterBalance;
      } // end while

      // tell user if account from transactions file does not match 
      // account from master file
      if ( masterAccount > transactionAccount )
      {
         cout << "Unmatched transaction record for account "
            << transactionAccount << '\n';

         // get account and balance from transactions file
         inTransaction >> transactionAccount >> transactionBalance;
      } // end if 

      // if matching account found, update balance and output account info
      if ( masterAccount == transactionAccount ) 
      {
         masterBalance += transactionBalance;
         printOutput( outNewMaster, masterAccount, masterFirstName,
            masterLastName, masterBalance );
      } // end if

      // get next account and balance from transactions file
      inTransaction >> transactionAccount >> transactionBalance;
   } // end while

   // output remaining accounts to new master file
   while ( !inOldMaster.eof() ) 
   {
      inOldMaster >> masterAccount >> masterFirstName
         >> masterLastName >> masterBalance;

      if (!inOldMaster.eof())
         printOutput( outNewMaster, masterAccount, masterFirstName,
            masterLastName, masterBalance );
   } // end while
   system("pause");
} // end main

// function to display output
void printOutput( ofstream &oRef, int mAccount, string mfName,
   string mlName, double mBalance )
{
   // set output format
   cout << fixed << showpoint;
   oRef << fixed << showpoint;

   // display account number, name and balance
   oRef << mAccount << ' ' << mfName << ' ' << mlName << ' '
      << setprecision( 2 ) << mBalance << '\n';
   cout << mAccount << ' ' << mfName << ' ' << mlName << ' '
      << setprecision( 2 ) << mBalance << '\n';
   
} // end function printOutput
