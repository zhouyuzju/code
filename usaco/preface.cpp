/*
ID:jwjzy10201
TASK:preface
LANG:C++
*/
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream fin ("preface.in");
	ofstream fout ("preface.out");
	int N;
	int i = 0,v = 0,x = 0,l = 0,c = 0,d = 0,m = 0;
	fin >> N;
	for(int j = 1;j <= N;j++)
	{
		int k = j;
		while(k)
		{
			if(k >= 1000) {k -= 1000;m++;}
			if(k >= 900 && k < 1000) {k -= 900;c++;m++;}
			if(k >= 500 & k < 900) {k -= 500;d++;}
			if(k >= 400 && k < 500) {k -= 400;c++;d++;}
            	      	if(k >= 100 && k < 400) {k -= 100;c++;}
                 	if(k >= 90 && k < 100) {k -= 90;x++;c++;}
                  	if(k >= 50 && k < 90) {k -= 50;l++;}
                  	if(k >= 40 && k < 50) {k -= 40;x++;l++;}
                 	if(k >= 10 && k < 40) {k -= 10;x++;}
                  	if(k >= 9 && k < 10) {k -= 9;i++;x++;}
                  	if(k >= 5 && k < 9) {k -= 5;v++;}
                  	if(k >= 4 && k < 5) {k -= 4;i++;v++;}
                  	if(k >= 1 && k < 4) {k -= 1;i++;}
			
		}
	}
	if(i != 0) fout << "I " << i << endl;
	if(v != 0) fout << "V " << v << endl;
	if(x != 0) fout << "X " << x << endl;
	if(l != 0) fout << "L " << l << endl;
	if(c != 0) fout << "C " << c << endl;
	if(d != 0) fout << "D " << d << endl;
	if(m != 0) fout << "M " << m << endl;
	return 0;
}
