//
// Created by Elias Tovar on 2/3/2025.
//

#ifndef PROJ3_MYSTRING_H
#define PROJ3_MYSTRING_H

#include <iostream>
#include <string>

using namespace std;

class MyString {
private:
    int size;     // The number of characters currently stored in the string
    // object. Do NOT count the NULL character.
    int capacity; // The number of bytes currently allocated. This should always be at least
    // size + 1. The extra byte is needed to store the NULL character.
    char *data;   // Character pointer that points to an array of characters.

public:
    // Default Constructor
    MyString( ){
      size = 0;
      capacity = 10;
      data = new char[capacity];
      }

    // Constructor with an initialization character string
    MyString(const char *){
      size = 0;
      capacity = 10;
      data = new char[capacity];
      }

    // Destructor
    ~MyString( ){
      delete[] data;
      }

    // Copy constructor
    MyString(const MyString &that){
    size = that.size;
    capacity = that.capacity;
    data = new char[capacity];
    for(int i = 0; i < size; i++){
      data[i] = that.data[i];
    }
      }

    // Overloaded assignment operator, make a copy of MyString object
    MyString& operator = (const MyString& that){
      if(this != &that){
        delete[] data;
        size = that.size;
        capacity = that.capacity;
        data = new char[capacity];
        for(int i = 0; i < size; i++){
          data[i] = that.data[i];
        }
      }
      return *this;
      }

    // Overloaded equivalence relational operator
    bool operator == (const MyString& that) const{
      if(size != that.size){
        return false;
      }
      for(int i = 0; i < size; i++){
        if(data[i] != that.data[i]){
          return false;
      }
    }
  }

    // Overloaded [ ] should return a char by reference
    char& operator [ ] (int index){
      return data[index];
    }

    // Overloaded += operator, use to concatenate two MyStrings
    void operator += (const MyString& that){
      if(size + that.size > capacity){
        capacity *= 2;
        data = new char[capacity];
        for(int i = 0; i < size; i++){
          data[i] = that.data[i];
        }
      }
    }

    // Create a new MyString object that is the concatenation of two MyString objects
    MyString operator + (const MyString& that) const{
      }

    // Reads an entire line from a istream. Lines are terminated with delimit which is newline
    // ‘\n’ by default
    void getline(istream& in, char delimit = '/n'){

      }

    // Return the length of the string
    int length( ) const;

    // Overloaded insertion operator
    friend ostream& operator<< (ostream&, MyString&);
};
