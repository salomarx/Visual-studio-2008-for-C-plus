// Name.cpp – Implementation of the Name class
#include "Name.h"                                // Name class definitions
#include "DebugStuff.h"                          // Debugging code control
#include <cstring>                               // For C-style string functions
#include <cassert>                               // For assertions
#include <iostream>
using namespace std;

// Default constructor
Name::Name()
{
#ifdef CONSTRUCTOR_TRACE
  // Trace constructor calls
  cout << "\nDefault Name constructor called.";
#endif

  // Allocate array of 1 for empty strings
  pFirstname = new char[1];
  pSurname = new char[1];

  pFirstname[0] = pSurname[0] = '\0';           // Store null character
}

// Constructor
Name::Name(const char* pFirst, const char* pSecond)
{
  // Verify that arguments are not null
  assert(pFirst != 0);
  assert(pSecond != 0);

#ifdef CONSTRUCTOR_TRACE
  // Trace constructor calls
  cout << "\nName constructor called.";
#endif
  pFirstname = new char[strlen(pFirst)+1];
  strcpy(pFirstname, pFirst);
  pSurname = new char[strlen(pSecond)+1];
  strcpy(pSurname, pSecond);
}


// Return a complete name as a string containing first name, space, surname
// The argument must be the address of a char array sufficient to hold the name
char* Name::getName(char* pName) const
{
  assert(pName != 0);                                 // Verify non-null argument

#ifdef FUNCTION_TRACE
  // Trace function calls
  cout << "\nName::getName() called.";
#endif

  strcpy(pName, pFirstname);                          // copy first name
  strcat(pName, " ");                  // Append a space
  return strcat(pName, pSurname);      // Append second name and return total
} 

// Returns the total length of a name
size_t Name::getNameLength() const
{
#ifdef FUNCTION_TRACE
  // Trace function calls
  cout << "\nName::getNameLength() called.";
#endif
  return strlen(pFirstname)+strlen(pSurname)+1;
}

// Less than operator
bool Name::operator<(const Name& name) const
{
  int result = strcmp(pSurname, name.pSurname);
  if(result < 0)
    return true;
  if(result == 0 && strcmp(pFirstname, name.pFirstname) < 0)
    return true;
  else
    return false;
}

// Greater than operator
bool Name::operator>(const Name& name) const
{
  return name < *this;
}

// Equal to operator
bool Name::operator==(const Name& name) const
{
  if(strcmp(pSurname, name.pSurname) == 0 &&
                                         strcmp(pFirstname, name.pFirstname) == 0)
    return true;
  else
    return false;
}

Name:: Name(const Name& rName)
{
  pFirstname = new char[strlen(rName.pFirstname)+1]; // Allocate space for 1st name
  strcpy(pFirstname, rName.pFirstname);              // and copy it.
  pSurname = new char[strlen(rName.pSurname)+1];     // Same for the surname...
  strcpy(pSurname, rName.pSurname);
}

Name::~Name()
{
  delete[] pFirstname;
  delete[] pSurname;
}

Name& Name::operator=(const Name& rName)
{
  if(this == &rName)                                 // If lhs equals rhs
    return *this;                                    // just return the object

  delete[] pFirstname;
  pFirstname = new char[strlen(rName.pFirstname)+1]; // Allocate space for 1st name
  strcpy(pFirstname, rName.pFirstname);              // and copy it.
  delete[] pSurname;
  pSurname = new char[strlen(rName.pSurname)+1];     // Same for the surname...
  strcpy(pSurname, rName.pSurname);
  return *this;
}
