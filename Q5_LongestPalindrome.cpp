#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        string result = "";
        for (int i = 0; i < n; ++i) {
            // Expand around the center for odd-length palindromes
            string odd = expandAroundCenter(s, i, i);
            if (odd.size() > result.size()) {
                result = odd;
            }

            // Expand around the center for even-length palindromes
            string even = expandAroundCenter(s, i, i + 1);
            if (even.size() > result.size()) {
                result = even;
            }
        }
        return result;
    }

private:
    string expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the longest palindromic substring centered at (left, right)
        return s.substr(left + 1, right - left - 1);
    }
};

/*
This code can simply implement using Manacher's Algorithm
add # to every character
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // Preprocess the string
        string T = preprocess(s);
        int n = T.size();
        vector<int> P(n, 0); // Array to store palindrome lengths

        int C = 0; // Center of the current palindrome
        int R = 0; // Right boundary of the current palindrome

        for (int i = 1; i < n - 1; ++i) {
            int mirror = 2 * C - i; // Mirror of i around C

            // Use previously computed palindrome lengths
            if (i < R) {
                P[i] = min(R - i, P[mirror]);
            }

            // Attempt to expand palindrome centered at i
            while (T[i + (1 + P[i])] == T[i - (1 + P[i])]) {
                P[i]++;
            }

            // Update center and right boundary if palindrome expands beyond R
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }

        // Find the maximum element in P
        int maxLen = 0;
        int centerIndex = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }

        // Extract the longest palindromic substring
        int start = (centerIndex - maxLen) / 2;
        return s.substr(start, maxLen);
    }

private:
    // Preprocess the string by adding special characters
    string preprocess(const string& s) {
        string result = "^";
        for (char c : s) {
            result += "#";
            result += c;
        }
        result += "#$";
        return result;
    }
};*/