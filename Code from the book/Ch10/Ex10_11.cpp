// Ex10_11.cpp
// A simple word collocation
#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using std::cout;
using std::cin;
using std::endl;
using std::string;


int main()
{
  typedef std::map<string, int>::const_iterator Iter;
  
  std::map<string, int> words;           // Map to store words and word counts
  cout << "Enter some text and press Enter followed by Ctrl+Z to end:" 
       << endl << endl;

  std::istream_iterator<string> begin(cin); // Stream iterator 
  std::istream_iterator<string> end;        // End stream iterator
  while(begin != end )                      // Iterate over words in the stream 
    words[*begin++]++;                      // Increment and store a word count

  // Output the words and their counts
  cout << endl << "Here are the word counts for the text you entered:" << endl;
  for(Iter iter = words.begin() ; iter != words.end() ; ++iter) 
    cout << std::setw(5) << iter->second << " " << iter->first << endl;

  return 0;
} 
