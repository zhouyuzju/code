/**
 *The problem is about transform excel column and row remark into anther form
 *(R23C55 ==> BC23)
 *R23C55 means row 23,column 55
 *BC equal to 2 * 26 + 3
 *2012/3/12
**/
#include <iostream>
#include <string>
using namespace std;

int isRC(string x){
	bool hasdigit = false,result = false;
	if(x[0] != 'R')
		return false;
	for(int i = 1;i < x.length();i++){
		if(x[i] >= '0' && x[i] <= '9')
			hasdigit = true;
		else if(hasdigit)
			result = true;
	}
	return result;
}

int toInt(string x){
	int result = 0;
	for(int i = 0;i < x.length();i++)
		result = result * 10 + int(x[i] - '0');
	return result;
}

string toStr(int x){
	string reverse = "",result = "";
	while(x > 0){
		x -= 1;
		reverse += 'A' + x % 26;
		x /= 26;
	}
	for(int i = reverse.length() - 1;i >= 0;i--)
		result += reverse[i];
	return result;
}

int pow(int base,int n){
	long result = 1;
	for(int i = 0;i < n;i++)
		result *= base;
	return result;
}

int getCol(string x){
	string str = "";
	for(int i = 0;i < x.length();i++)
		if(x[i] >= 'A' && x[i] <= 'z')
			str += x[i];
		else
			break;
	int result = 0;
	for(int i = 0;i < str.length();i++)
		result += int(str[i] - 'A' + 1) * pow(26,str.length() - 1 - i);
	return result;
}

string getDig(string x){
	string result = "";
	for(int i = 0;i < x.length();i++)
		if(x[i] >= '0' && x[i] <= '9')
			result += x[i];
	return result;
}

int main(){
	int x,i = 0;
	cin >> x;

	while(i < x){
		string line;
		cin >> line;
		if(isRC(line)){
			string row = line.substr(line.find('R') + 1,line.find('C') - line.find('R') - 1);
			string column = line.substr(line.find('C') + 1,line.length() - line.find('C') - 1);
			int r = toInt(row);
			int c = toInt(column);
			cout << toStr(c) << r << endl;
		}	
		else{
			cout <<'R' << getDig(line) << 'C' << getCol(line) << endl;		
		}
		i++;
	}
}
