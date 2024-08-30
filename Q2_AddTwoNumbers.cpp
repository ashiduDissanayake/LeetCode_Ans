
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* lout1 = nullptr;
        ListNode* lout2 = nullptr;
        while(l1!= nullptr || l2!=nullptr){
            int val1 = (l1==nullptr)?0:l1->val;
            int val2 = (l2==nullptr)?0:l2->val;
            int sum = val1 + val2 + carry;
            carry = 0;
            if(sum>9){
                sum = sum-10;
                carry=1;
            }
            l1=(l1==nullptr)?nullptr:l1->next;
            l2=(l2==nullptr)?nullptr:l2->next;
            lout1 = new ListNode(sum, lout1);
        }
        if (carry == 1) {
            lout1 = new ListNode(1, lout1);
        }

        while(lout1!= nullptr){
            lout2 = new ListNode(lout1->val, lout2);
            lout1 = lout1->next;
        }

        return lout2;
    }
};