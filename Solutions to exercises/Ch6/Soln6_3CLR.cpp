// Ex6_3CLR.cpp : main project file.
// A CLR calculator supporting parentheses

#include "stdafx.h"
#include <cstdlib>                          // For exit()

using namespace System;
String^ eatspaces(String^ str);             // Function to eliminate blanks
double expr(String^ str);                   // Function evaluating an expression
double term(String^ str, int^ index);       // Function analyzing a term
double number(String^ str, int^ index);     // Function to recognize a number
String^ extract(String^ str, int^ index);   // Function to extract a substring
void error(String^ str, int index);         // Function to identify an error

int main(array<System::String ^> ^args)
{
  String^ buffer;    // Input area for expression to be evaluated
 
  Console::WriteLine(L"Welcome to your friendly calculator.");
  Console::WriteLine(L"Enter an expression, or an empty line to quit.");

  for(;;)
  {
    buffer = eatspaces(Console::ReadLine());         // Read an input line

    if(String::IsNullOrEmpty(buffer))                // Empty line ends calculator
      return 0;

    Console::WriteLine(L"  = {0}\n\n",expr(buffer)); // Output value of expression
  }
  return 0;
}

// Function to eliminate spaces from a string
String^ eatspaces(String^ str)
{
  // Array to hold string without spaces  
  array<wchar_t>^ chars = gcnew array<wchar_t>(str->Length);
  int length = 0;                      // Number of chars in array

  // Copy non-space characters to chars array
  for each(wchar_t ch in str)
    if(ch != ' ')
      chars[length++] = ch;

  // Return chars array as string
  return gcnew String(chars, 0, length);
}

// Function to evaluate an arithmetic expression
double expr(String^ str)
{
  int^ index = 0;                      // Keeps track of current character position

  double value = term(str, index);     // Get first term

  while(*index < str->Length)
  {
    switch(str[*index])                // Choose action based on current character
    {
      case '+':                        // + found so 
         ++(*index);                   // increment index and add
         value += term(str, index);    // the next term
         break;

      case '-':                        // - found so
          ++(*index);                  // decrement index and add
        value -= term(str, index);     // the next term
         break;

      default:                         // If we reach here the string is junk
        Console::WriteLine(L"Arrrgh!*#!! There's an error.\n");
        error(str, *index-1);
        exit(1);
    }
  }
  return value;
}

// Function to get the value of a term
double term(String^ str, int^ index)
{
  double value = number(str, index);        // Get the first number in the term

  // Loop as long as we have characters and a good operator
  while(*index < str->Length)
  {
    if(str[*index] == L'*')                 // If it's multiply,
    {
      ++(*index);                           // increment index and
      value *= number(str, index);          // multiply by next number
    }
    else if( str[*index] == L'/')           // If it's divide
    {
      ++(*index);                           // increment index and
      value /= number(str, index);          // divide by next number
    }
    else
      break;                                // Exit the loop
 }
  // We've finished, so return what we've got
  return value;                             
}

// Function to recognize a number
double number(String^ str, int^ index)
{
  double value = 0.0;                       // Store for the resulting value

  // Check for expression between parentheses
  if(str[*index] == L'(' )                  // Start of parentheses
  {
    ++(*index);
    String^ substr = extract(str, index);   // Extract substring in brackets
    return expr(substr);                    // Return substring value
  }

  // Loop accumulating leading digits
  while((*index < str->Length) && Char::IsDigit(str, *index))
  {
    value = 10.0*value + Char::GetNumericValue(str[(*index)]);
    ++(*index);
  }

  // Not a digit when we get to here
  if((*index == str->Length) || str[*index] != '.')   // so check for decimal point
    return value;                                     // and if not, return value

  double factor = 1.0;                 // Factor for decimal places
  ++(*index);                          // Move to digit

  // Loop as long as we have digits
  while((*index < str->Length) && Char::IsDigit(str, *index))   
  {
    factor *= 0.1;                     // Decrease factor by factor of 10
    value = value + Char::GetNumericValue(str[*index])*factor; // Add decimal place
    ++(*index);
  }

  return value;                        // On loop exit we are done
}

// Function to extract a substring between parentheses 
String^ extract(String^ str, int^ index)
{
  // Temporary space for substring
  array<wchar_t>^ buffer = gcnew array<wchar_t>(str->Length); 
  String^ substr;                      // Substring to return
  int numL = 0;                        // Count of left parentheses found
  int bufindex = *index;               // Save starting value for index

  while(*index < str->Length)
  {
    buffer[*index - bufindex] = str[*index];
    switch(str[*index])
    {
      case ')':
        if(numL == 0)
        {
          array<wchar_t>^ substrChars = gcnew array<wchar_t>(*index - bufindex);
          str->CopyTo(bufindex, substrChars, 0, substrChars->Length);
          substr = gcnew String(substrChars);
          ++(*index);

          return substr;               // Return substring in new memory
        }
        else
          numL--;                      // Reduce count of '(' to be matched
        break;

      case '(':
        numL++;                        // Increase count of '(' to be 
                                       // matched
        break;
      }
    ++(*index);
  }

  Console::WriteLine(L"Ran off the end of the expression, must be bad input.");
  exit(1);
  return substr;
}

// Function to identify an error
void error(String^ str, int index)
{
   Console::WriteLine(str);
   Console::Write(gcnew String(' ',index));
   Console::WriteLine(" ^");
}
