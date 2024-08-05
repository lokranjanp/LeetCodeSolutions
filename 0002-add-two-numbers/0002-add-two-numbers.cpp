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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *l3 = new ListNode(0);
        ListNode *node = l3;

        while(l1!=NULL || l2!=NULL || carry != 0)
        {
            int sum = 0;

            if(l1!=nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2!=nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            sum += carry;
            int digit = sum%10;
            carry = sum/10;

            ListNode *newnode = new ListNode(digit);
            node->next = newnode;
            node = node->next;
        }

        ListNode *res = l3->next;
        delete l3;
        return res;
    }
};