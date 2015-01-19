// Exercise 18.4 Solution: Ex18_04.cpp
#include <iostream>
#include <string>
#include "Array.h"
using namespace std;

int main()
{
   Array< int > intArray( 5 ); // create intArray object

   // initialize intArray with user input values
   cout << "Enter " << intArray.getSize() << " integer values:\n";
   for ( size_t i = 0; i < intArray.getSize(); ++i )
      cin >> intArray[ i ];

   // output intArray
   cout << "\nThe values in intArray are:\n";
   for ( size_t i = 0; i < intArray.getSize(); ++i )
      cout << intArray[ i ] << " ";
   cout << endl;

   Array< string > stringArray( 3 ); // create stringArray

   // initialize stringArray with user input values
   cout << "\nEnter " << stringArray.getSize()
      << " one-word string values:\n";
   for ( size_t i = 0; i < stringArray.getSize(); ++i )
      cin >> stringArray[ i ];

   // output stringArray
   cout << "\nThe values in the stringArray are:\n";
   for ( size_t i = 0; i < stringArray.getSize(); ++i )
      cout << stringArray[ i ] << " ";
   cout << endl;

   system("pause");
} // end main
