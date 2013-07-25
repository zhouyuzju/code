#include <iostream>
#include <cstdio>
using namespace std;
class Solution {
public:
    int sqrt(int x) {
        if(x <= 1)
            return x;
        int start = 0, end = x;
        int mid;
        while(start <= end){
            mid = start + (end - start) / 2;
            if(INT_MAX / mid < mid)
	    	    end = mid - 1;
	        else if(mid * mid == x)
                return mid;
            else if(mid * mid > x)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return (start + end) / 2;
    }
};

int main(){
	Solution* s = new Solution();
	printf("%d\n",s->sqrt(2147483647));
	return 0;
}
