#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	string status;
	cin >> n >> status;
	int count = 0;
	if(status.find('I') == -1){
		for(int i = 0;i < status.length();i++)
			if(status[i] == 'A')
				count++;
	}
	else{
		if(status.find('I') == status.rfind('I'))
			count = 1;
		else
			count = 0;
	}
	cout << count << endl;
	return 0;
}
