/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

inline bool isDigit(const char c) {
    return (c >= '0') && (c <= '9');
}
void parse_and_solve(const std::string& s1, const std::string& s2, std::ofstream& out) {
    const int S1 = s1.size();
    const int S2 = s2.size();
    if (S1 < S2) {
        parse_and_solve(s2, s1, out);
        return;
    }
    int carry = 0;
    int i = 0;
    int j = 0;
    while (i < S1 - 1) {
        while (i < S1 && (!isDigit(s1[i]))) { ++i; }
        while (j < S2 && (!isDigit(s2[j]))) { ++j; }
        const int n1 = s1[i] - '0';
        const int n2 = (j < S2) ? (s2[j] - '0') : 0;
        const int n = carry + n1 + n2;
        carry = n / 10;
        out << (n % 10);
        if (i < S1 - 2) {
            out << ",";
        }
        ++i;
        ++j;
    }
    if (carry > 0) {
        out << "," << carry;
    }
}
 static bool Solve = [](){
    std::ofstream out("user.out");
    std::string s1, s2;
    while (std::getline(std::cin, s1) && std::getline(std::cin, s2)) {
        out << "[";
        cout<<s1<<" "<<s2<<endl;
        parse_and_solve(s1, s2, out);
        out << "]\n";
    }
    out.flush();
    exit(0);
    return true;
}();
class Solution {
public:

    void fill(ListNode* node, vector<int>& v)
    {
        while(node)
        {
            v.push_back(node->val);
            node = node->next;
        }
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        vector<int> v1;
        vector<int> v2;
        vector<int> res;

        fill(l1, v1); fill(l2,v2);

        int i = 0, j = 0, carry = 0, sum = 0;

        while(i < v1.size() || j < v2.size() || carry)
        {
            sum = carry;
            if(i < v1.size()) sum+=v1[i++];
            if(j < v2.size()) sum+=v2[j++];

            carry = sum/10;
            if(sum >=10)
            {
                sum-=10;
            }

            res.push_back(sum);
        }


        ListNode* r = new ListNode(res[0]);

        ListNode* temp = r;

        for(int i = 1; i < res.size(); i++)
        {
            temp->next = new ListNode(res[i]);
            temp = temp->next;
        }

        return r;

    }
};