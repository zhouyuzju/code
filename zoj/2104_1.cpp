#include <iostream>
#include <map>
#include <string>
using namespace std;


int main()
{
    int count;
    cin>>count;
    while(count != 0)
    {
                map< string, int > si;
                while(count)
                {
                            string temp;
                            cin>>temp;
                            si[temp]++;
                            --count;
                }
               int maxnumber = 0;
               string s;
               for(map< string, int >::iterator it = si.begin(); it != si.end(); it++) 
               { 
                            if(it->second > maxnumber)
                            {
                                          maxnumber = it->second;
                                          s = it->first;
                            }
               } 
               cout<<s<<endl;
                cin>>count;
    }
    return 0;
}
