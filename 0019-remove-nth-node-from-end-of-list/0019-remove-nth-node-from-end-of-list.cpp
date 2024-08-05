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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *ptr = head;

        while(ptr)
        {
            len++;
            ptr = ptr->next;
        }

        if(len == n)
            return head->next;

        ListNode *preptr;
        ptr = head;

        int k = len - n;

        while(ptr->next && k)
        {
            preptr = ptr;
            ptr = ptr->next;
            k--;
        }

        preptr->next = ptr->next;
        delete ptr;
        return head;
    }
};