#include <iostream>
#include <string>
#define NPOS -1
using namespace std;

int main(){
	string x,y;
	cin >> x >> y;
	if(x.length() != y.length())
		cout << "NO" << endl;
	else{
		if(x.find('1') == NPOS && y.find('1') == NPOS)
			cout << "YES" << endl;
		else if(x.find('1') != NPOS && y.find('1') != NPOS)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
