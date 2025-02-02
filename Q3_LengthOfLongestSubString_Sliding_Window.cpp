#include <unordered_map>
#include <algorithm>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> last_seen;
        int max_length = 0;

        int left = 0;

        for(int right = 0; right < s.size(); ++right){
            char current_char = s[right];

            if(last_seen.find(current_char) != last_seen.end() && last_seen[current_char] >= left){
                left = last_seen[current_char]+1;
            }

            last_seen[current_char] = right;

            max_length = std::max(max_length, right-left + 1);
        }
        return max_length;
    }
};

/* 
Literally this is From

    SLIDING WINDOW ALGORITHM

It simply use the form current window 
has left side and right side where it shows the window size.
*/

// Best solution I've seen is the following one

/*
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int i = 0, j = 0, N = s.size(), cnt[128] = {}, dup = 0;
        for (; j < N; ++j) {
            dup += ++cnt[s[j]] == 2;
            if (dup) dup -= --cnt[s[i++]] == 1;
        }
        return j - i;
    }
};
*/