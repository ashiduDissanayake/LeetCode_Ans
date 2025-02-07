#include <string>

class Solution {
public:
    int reverse(int x) {
        string input = to_string(x);  
        cout << input ;
        string result;
        for(int i = input.size()-1; i > 0; --i){
            result += input[i];
        }    
        input[0] == '-' ? result = '-'+result : result += input[0];
        int res;
        try{
            res = stoi(result);
        }catch(out_of_range){
            res = 0;
        }

        return res;
    }
};
/*
This is not that much better but did some good work
Also more importantly int can only handle 32 bit more than that we need to store on long in c++

The following code had more imapct than mine
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        for (; x; x /= 10) {
            if (ans < INT_MIN / 10 || ans > INT_MAX / 10) {
                return 0;
            }
            ans = ans * 10 + x % 10;
        }
        return ans;
    }
};

In here they just use mathematical operations rather having the string such thing
that makes this more speed than mine
*/