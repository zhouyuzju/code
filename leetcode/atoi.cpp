class Solution {
public:
    int atoi(const char *str) {
        if(str == NULL)
            return 0;   //invalid
        long long num = 0;
        bool flag = false;
        while((*str == ' ' || *str == '\t') && (*str) != '\0')
            str++;
        if(*str == '+'){
            flag = false;
            str++;
        }
        else if(*str == '-'){
            flag = true;
            str++;
        }
        else if((*str) >= '0' && (*str) <= '9')
            ;
        else
            return 0;   //invalid
        while((*str) >= '0' && (*str) <= '9' && (*str) != '\0'){
            num = num * 10 + (*str - '0');
            if(!flag && num > INT_MAX)
                return INT_MAX;
            else if(flag && -num < INT_MIN)
                return INT_MIN;
            str++;
        }
        while((*str == ' ' || *str == '\t') && (*str) != '\0')
            str++;

        return flag ? -num : num;
    }
};

