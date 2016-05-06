// Person.h
// A class defining a person
#pragma once
#include <iostream>
#include <string>
#include <functional>
using std::cout;
using std::endl;
using std::string;

class Person
{
public:
  Person(string first = "", string second = "")
  {
    firstname = first;
    secondname = second;
  }
/*
  // Copy constructor
  Person(const Person& p)
  {
    firstname = p.firstname;
    secondname = p.secondname;
  }
  // Assignment operator
  Person& operator=(const Person& p)
  {
    if(this == &p)
      return *this;
    firstname = p.firstname;
    secondname = p.secondname;
    return *this;
  }
*/
  // Less-than operator
  bool operator<(const Person& p)const
  {
    if(secondname < p.secondname ||
      ((secondname == p.secondname) && (firstname < p.firstname)))
      return true;

    return false;
  }


  // Get the name 
  string getName()const
  {
    return firstname + " " + secondname;
  }

private:
  string firstname;
  string secondname;
};
