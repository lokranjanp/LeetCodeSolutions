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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2)
            return nullptr;

        if(!list1 && list2)
            return list2;

        if(list1 && !list2)
            return list1;

        ListNode *res = new ListNode(0);
        ListNode *ptr = res;

        while(list1 && list2)
        {
            if(list1->val > list2->val)
            {
                ptr->next = list2;
                list2 = list2->next;
            }
            else
            {
                ptr->next = list1;
                list1 = list1->next;
            }

            ptr = ptr->next;
        }

        if(list1)
            ptr->next = list1;
        else
            ptr->next = list2;

        return res->next;
    }
};