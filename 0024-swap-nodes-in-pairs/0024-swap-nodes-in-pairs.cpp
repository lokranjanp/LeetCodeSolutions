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
    ListNode * helper(ListNode * ptr)
    {
        if(ptr == nullptr)
            return nullptr;

        if(ptr->next == nullptr)
            return ptr;

        if(ptr->next->next == nullptr)
        {
            ListNode * temp = ptr->next;
            ptr->next->next = ptr;
            ptr->next = NULL;
            return temp;
        }

        ListNode * n = ptr->next;
        ptr->next = helper(ptr->next->next);
        n->next = ptr;
        return n;
        
    }

    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode * ptr = head;
        return helper(ptr);
    }
};