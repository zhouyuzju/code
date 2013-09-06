class Solution {
public:
    void compute_prefix(char* T, int m, vector<int>& pi) {
        int i = 0;
        int j = pi[0] = -1;
        while (i < m) {
            while (j > -1 && T[i] != T[j]) {
                j = pi[j];
            }
            ++i;
            ++j;
            pi[i] = (T[i] == T[j]) ? (pi[j]) : (j);
        }
    }

    char *strStr(char *haystack, char *needle) {
        int n = strlen(haystack);
        int m = strlen(needle);
        if (m == 0) {
            return haystack;
        }

        vector<int> pi(m+1);
        compute_prefix(needle, m, pi);

        int i = 0;
        int j = 0;
        while (i < n) {
            while (j > -1 && haystack[i] != needle[j]) {
                j = pi[j];
            }
            ++i;
            ++j;
            if (j >= m) {
                return haystack+i-j;
            }
        }
        return 0;
    }
};

