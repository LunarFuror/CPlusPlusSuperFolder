// Exercise 8.17 Solution: Ex08_17.cpp
#include <iostream> 
#include <random>
#include <ctime>
#include <array>
using namespace std;

enum Direction { DOWN, RIGHT, UP, LEFT };
const int MAX_DOTS = 100; // maximum possible dots for maze
const size_t SIZE = 12;

// function prototypes
void mazeTraversal( array< array< char, 12 >, 12 > &, size_t, size_t, size_t, size_t, Direction );
void printMaze( const array< array< char, 12 >, 12 > & );
bool validMove( const array< array< char, 12 >, 12 > &, size_t, size_t );
void mazeGenerator( array< array< char, 12 >, 12 > &, size_t &, size_t & );
bool coordsAreEdge( size_t, size_t );

int main()
{
   array< array< char, 12 >, 12 > maze;
   size_t xStart = 0; // starting X and Y coordinates for maze
   size_t yStart = 0;
   size_t x = 0; // current X and Y coordinates
   size_t y = 0;

   // loop to generate hashes (#)
   for ( auto &row : maze )
      for ( auto &element : row )
         element = '#';

   mazeGenerator( maze, xStart, yStart ); // generate the maze

   x = xStart; // initialize x
   y = yStart; // initialize y

   mazeTraversal( maze, xStart, yStart, x, y, RIGHT ); // traverse maze
} // end main

// Assume that there is exactly 1 entrance and exactly 1 exit to the maze.
void mazeTraversal( array< array< char, 12 >, 12 > &maze, size_t xStart, size_t yStart,
   size_t xCoord, size_t yCoord, Direction direction )
{
   static bool flag = false;

   maze[ xCoord ][ yCoord ] = 'x';
   printMaze( maze );

   if ( coordsAreEdge( xCoord, yCoord ) && xCoord != xStart && 
        yCoord != yStart ) 
   {
      cout << "\nMaze successfully exited!\n\n";
      return; // maze is complete
   } // end if
   else if ( xCoord == xStart && yCoord == yStart && flag ) 
   {
      cout << "\nArrived back at the starting location.\n\n";
      return;
   } // end else if
   else 
   {
      flag = true;

      int move = direction;

      // for loop uses switch to determine appropriate move   
      for ( int count = 0; count < 4; ++count )
      {
         switch( move ) 
         {
            case DOWN: // move down
               if ( validMove( maze, xCoord + 1, yCoord ) ) 
               {
                  mazeTraversal( 
                     maze, xStart, yStart, xCoord + 1, yCoord, LEFT );
                  return;
               } // end if
               break;
            case RIGHT: // move right
               if ( validMove( maze, xCoord, yCoord + 1 ) ) 
               {
                  mazeTraversal( 
                     maze, xStart, yStart, xCoord, yCoord + 1, DOWN );
                  return;
               } // end if
               break;
            case UP: // move up
               if ( validMove( maze, xCoord - 1, yCoord ) )  
               {
                  mazeTraversal( 
                     maze, xStart, yStart, xCoord - 1, yCoord, RIGHT );
                  return;
               } // end if
               break;
            case LEFT: // move left
               if ( validMove( maze, xCoord, yCoord - 1 ) )  
               {
                  mazeTraversal( 
                     maze, xStart, yStart, xCoord, yCoord - 1, UP );
                  return;
               } // end if
               break;
         } // end switch

         ++move;
         move %= 4;
      } // end for
   } // end else
} // end function mazeTraversal

// validate move
bool validMove( const array< array< char, 12 >, 12 > &maze, size_t r, size_t c )
{
   return 
      ( r >= 0 && r <= 11 && c >= 0 && c <= 11 && maze[ r ][ c ] != '#' );
} // end function validate

// function to check coordinates
bool coordsAreEdge( size_t x, size_t y )
{
   if ( ( x == 0 || x == SIZE - 1 ) && ( y >= 0 && y <= SIZE - 1 ) )
      return true;
   else if ( ( y == 0 || y == SIZE - 1 ) && ( x >= 0 && x <= SIZE - 1 ) )
      return true;
   else
      return false;
} // end function coordsAreEdge

// print the current state of the maze
void printMaze( const array< array< char, 12 >, 12 > &maze )
{
   // nested for loops to iterate through maze
   for ( size_t x = 0; x < maze.size(); ++x ) 
   {
      for ( size_t y = 0; y < maze[ x ].size(); ++y )
         cout << maze[ x ][ y ] << ' ';

      cout << '\n';
   } // end for

   cout << "\nHit return to see next move\n";
   cin.get();
} // end function printMaze

// random feature of making a maze
void mazeGenerator( array< array< char, 12 >, 12 > &maze, size_t &xRef, size_t &yRef )
{
   default_random_engine engine( static_cast<unsigned int>( time(0) ) );
   uniform_int_distribution<size_t> randomInt0to3( 0, 3 ); 
   uniform_int_distribution<size_t> randomInt1to10( 1, 10 ); 

   size_t entry = 0;
   size_t exit = 0;
   size_t x = 0;
   size_t y = 0;

   do 
   {
      entry = randomInt0to3( engine );
      exit = randomInt0to3( engine );
   } while ( entry == exit );

   // Determine entry position
   if ( entry == 0 ) 
   {
      xRef = randomInt1to10( engine ); // avoid corners
      yRef = 0;
      maze[ xRef ][ 0 ] = '.';
   } // end if
   else if ( entry == 1 ) 
   {
      xRef = 0;
      yRef = randomInt1to10( engine );
      maze[ 0 ][ yRef ] = '.';
   } // end else if
   else if ( entry == 2 ) 
   {
      xRef = randomInt1to10( engine );
      yRef = 11;
      maze[ xRef ][ 11 ] = '.';
   } // end if
   else 
   {
      xRef = 11;
      yRef = randomInt1to10( engine );
      maze[ 11 ][ yRef ] = '.';
   } // end else

   // Determine exit location
   if ( exit == 0 ) 
   {
      size_t a = randomInt1to10( engine );
      maze[ a ][ 0 ] = '.';
   } // end if
   else if ( exit == 1 ) 
   {
      size_t a = randomInt1to10( engine );
      maze[ 0 ][ a ] = '.';
   } // end else if
   else if ( exit == 2 ) 
   {
      size_t a = randomInt1to10( engine );
      maze[ a ][ 11 ] = '.';
   } // end else if
   else 
   {
      size_t a = randomInt1to10( engine );
      maze[ 11 ][ a ] = '.';
   } // end else

   for ( int loop = 1; loop < MAX_DOTS; ++loop ) // add dots randomly
   {
      x = randomInt1to10( engine );
      y = randomInt1to10( engine );
      maze[ x ][ y ] = '.';
   } // end for
} // end mazeGenerator
