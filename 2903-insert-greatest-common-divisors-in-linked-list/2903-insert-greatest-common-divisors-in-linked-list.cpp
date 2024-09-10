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
private:
    int gcd(int a, int b)
    {
        int minimum = min(a,b);

        for(int i = minimum; i>=1; i--)
            if(a%i == 0 && b%i == 0)
                return i;

        return a%b;
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next)
            return head;

        ListNode *node = head;
        while(node->next){
            int res = gcd(node->val, node->next->val);
            ListNode *temp = new ListNode(res);
            temp->next = node->next;
            node->next = temp;
            node = temp->next;
        }
        return head;
    }
};