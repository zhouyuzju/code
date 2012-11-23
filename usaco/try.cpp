#include <iostream>
#include <fstream>
using namespace std;

int main() {
  int n, max=0, current, state, i, j;
  string s;
  char c;
  
  cin >> n >> s;
  s = s+s;
  for(i=0; i<n; i++) {
    c = (char) s[i];
    if(c == 'w')
      state = 0;
    else
      state = 1;
    j = i;
    current = 0;
    while(state <= 2) { 
      // dont go further in second string than starting position in first string
      while(j<n+i && (s[j] == c || s[j] == 'w')) { 
        current++;
        j++;
      } // while
      state++;
      c = s[j];
    } // while
    if(current > max)
      max = current;
    if(current == 11)
	    cout << "J:" << j << endl;
  } // for
  cout << max << endl;
  return 0;
} // main

