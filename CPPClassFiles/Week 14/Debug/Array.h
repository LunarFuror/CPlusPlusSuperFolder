// Fig. 10.10: Array.h
// Array class definition with overloaded operators.
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <deque>
#include <exception>
#include <stdexcept>

template <typename elementType>
class Array
{
public:
   // default constructor
   explicit Array( int arraySize )
      : size( arraySize > 0 ? arraySize : 
           throw std::invalid_argument( "Array size must be greater than 0" ) ),
        ptr( new elementType[ size ] )
   {
      for ( size_t i = 0; i < size; ++i )
         ptr[ i ] = elementType(); // default initialize element
   } // end Array default constructor

   // copy constructor for class Array;
   // must receive a reference to an Array
   Array( const Array<elementType> &arrayToCopy ) 
      : size( arrayToCopy.size ),
        ptr( new elementType[ size ] )
   {
      for ( size_t i = 0; i < size; ++i )
         ptr[ i ] = arrayToCopy.ptr[ i ]; // copy into object
   } // end Array copy constructor

   // destructor
   ~Array()
   {
      delete [] ptr; // release pointer-based array space
   } // end destructor

   // return number of elements of Array
   size_t getSize() const
   {
      return size; // number of elements in Array
   } // end function getSize

   // overloaded assignment operator;
   // const return avoids: ( a1 = a2 ) = a3
   const Array operator=( const Array<elementType> &right )
   {
      if ( &right != this ) // avoid self-assignment
      {
         // for Arrays of different sizes, deallocate original
         // left-side Array, then allocate new left-side Array
         if ( size != right.size() )
         {
            delete [] ptr; // release space
            size = right.size; // resize this object
            ptr = new elementType[ size ]; // create space for Array copy
         } // end inner if

         for ( size_t i = 0; i < size; ++i )
            ptr[ i ] = right.ptr[ i ]; // copy array into object
      } // end outer if

      return *this; // enables x = y = z, for example
   } // end function operator=

   // determine if two Arrays are equal and
   // return true, otherwise return false
   bool operator==( const Array<elementType> &right ) const
   {
      if ( size != right.size )
         return false; // arrays of different number of elements

      for ( size_t i = 0; i < size; ++i )
         if ( ptr[ i ] != right.ptr[ i ] )
            return false; // Array contents are not equal

      return true; // Arrays are equal
   } // end function operator==

   // inequality operator; returns opposite of == operator
   bool operator!=( const Array<elementType> &right ) const  
   { 
      return ! ( *this == right ); // invokes Array::operator==
   } // end function operator!=
   
   // overloaded subscript operator for non-const Arrays;
   // reference return creates a modifiable lvalue
   elementType &operator[]( int subscript )
   {
      // check for subscript out-of-range error
      if ( subscript < 0 || subscript >= static_cast<int>(size) )
         throw std::out_of_range( "Subscript out of range" );

      return ptr[ subscript ]; // reference return
   } // end function operator[]

   // overloaded subscript operator for const Arrays
   // const reference return creates an rvalue
   elementType operator[]( int subscript ) const
   {
      // check for subscript out-of-range error
      if ( subscript < 0 || subscript >= static_cast<int>(size) )
         throw std::out_of_range( "Subscript out of range" );

      return ptr[ subscript ]; // returns copy of this element
   } // end function operator[]
private:
   size_t size; // pointer-based array size
   elementType *ptr; // pointer to first element of pointer-based array
}; // end class Array

#endif
