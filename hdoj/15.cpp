#include <cstdio>
#include <string>
using namespace std;
int main(){
	char input[256];
	while(true){
		gets(input);
		if(input[0] == '#')
			break;
		int sum = 0;
		for(int i = 0;input[i] != '\0';i++){
			if(input[i] >= 'A' && input[i] <= 'Z')
				sum += (i + 1) * (input[i] - 'A' + 1);
		}
		printf("%d\n",sum);
	}
	return 0;
}
