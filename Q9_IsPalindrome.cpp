class Solution {
public:
    int reverseInt(int x){
        int res = 0;
        while(x != 0){
            if (res > INT_MAX / 10 || res < INT_MIN / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }

    bool isPalindrome(int x) {
        return x == reverseInt(x) && x >= 0;
    }
};

// With a best Time compexity I completed this problem (log(x))