#ifndef PROJ1_PERSON_H
#define PROJ1_PERSON_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX_PERSONS = 25;

struct Person {
  string name;
  int age;
};

istream &getAPersonFromStream(istream &, Person *); // reads a single Person from the stream
void sortPersonArrayByAge(Person **, int); // implements selection sort ascending order
void sortPersonArrayByName(Person **, int); // implements bubble sort ascending order
Person * findAPerson(Person **, int, string); // implements linear search
void displayAPerson(ostream &, const Person *); // writes a single Person to the stream

#endif
