class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (!*s && !*p) 
            return true;
        const char* ps = NULL, *pp = NULL;
        while(*s){
            if(*s == *p || *p == '?'){
                s++;p++;
            }
            else if(*p == '*'){
                while(*p == '*')
                    p++;
                if(!*p) 
                    return true;
                pp = p;
                ps = s;
            }
            else if((!*p || *p != *s) && pp){
                s = ++ps;
                p = pp;
            }
            else
                return false;
        }
        while(*p)
            if(*p++ != '*')
                return false;

        return true;
    }
};

