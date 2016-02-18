/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if((!l1 && !l2) || (l1 && l2 == NULL))
            return l1;
            
        if(l2 && l1 == NULL)
            return l2;
            
        ListNode *newHead, *temp;
        
        if(l1->val <= l2->val)
        {
            newHead = l1;
            l1 = l1->next;
        }
        else
        {
            newHead = l2;
            l2 = l2->next;
        }
        
        temp = newHead;
        
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }
            
            temp = temp->next;
        }
        
        if(l1)
            temp->next = l1;

        if(l2)
            temp->next = l2;

        return newHead;
    }
};
