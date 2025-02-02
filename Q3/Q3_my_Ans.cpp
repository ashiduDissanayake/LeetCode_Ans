#include <vector>
#include <algorithm> 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<char> v;
        for (char a : s){
            auto it = std::find(v.begin(), v.end(), a);
            if(it != v.end()){
                break;
            }
            v.push_back(a);
        }
        return v.size();
    }
};