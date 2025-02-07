// class Solution {
// public:
//     string convert(string s, int nrows) {
//         int start=0, index, maxdifference;
//         string r="";
//         bool differenceind = true;

//         for(int i=nrows; i>=1 && start<s.length(); i--) {
//             if(i==nrows || i==1) {
//                 maxdifference = 2*nrows-2;

//                 if(maxdifference<=0) maxdifference=1;

//                 start = nrows-i;
//                 index = start;

//                 while(index<s.length()) {
//                     r+=s[index];
//                     index+=maxdifference;
//                 }
//             }
//             else {
//                 start = nrows-i;
//                 index = start;

//                 while(index<s.length()) {
//                     r+=s[index];

//                     if(differenceind) {
//                         index+=2*i-2;   
//                     }
//                     else {
//                         index+=2*(nrows-i);
//                     }

//                     differenceind=!differenceind;
//                 }

//                 differenceind = true;
//             }
//         }

//         return r;
//     }
// };

// In the above there is the best code that I found for the above code

#include <vector>

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        
        // Using vector instead of map to store rows
        vector<string> dict(numRows);  
        string result;

        for (int j = 0; j < s.size(); j += 2 * (numRows - 1)) {
            int count = 0;
            int i = 0;

            while (i < numRows && j + count < s.size()) {
                dict[i] += s[j + count];
                ++i;
                ++count;
            }

            --i;
            --count;

            while (i > 1 && j + count + 1 < s.size()) {
                --i;
                ++count;
                dict[i] += s[j + count];
                cout << "This" << s[j + count] << endl;
            }
        }

        // Concatenate all rows stored in the vector
        for (const string& row : dict) {
            result += row;
        }

        return result;
    }
};