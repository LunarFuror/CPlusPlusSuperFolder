// Ex. 8.13: ex08_13.cpp
// What does this program do?
#include <iostream>
using namespace std;

void addString2toString1( char *, const char * ); // prototype

int main()
{
   char string1[ 80 ];
   char string2[ 80 ];

   cout << "Enter two strings: ";
   cin >> string1 >> string2;
   addString2toString1( string1, string2 );
   addString2toString1( string1, string2 );
   cout << string1 << endl;
   system("pause");
} // end main


void addString2toString1( char *s1, const char *s2 ) // made pointers to match prototype
{
   while ( *s1 != '\0' )
      ++s1;

   for ( ; ( *s1 = *s2 ); ++s1, ++s2 ) //derefference s1
      ; // empty statement
} // end function mystery1
