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
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        
        ListNode *evenhead, *oddptr, *evenptr, *oddlast;
        
        evenhead = head->next;
        head->next = head->next->next;
        evenhead->next = NULL;
        
        oddlast = head;
        oddptr = head->next;
        evenptr = evenhead;
        
        while(oddptr)
        {
            evenptr->next = oddptr->next;
            evenptr = evenptr->next;
            
            if(evenptr)
            {
                oddptr->next = evenptr->next;
                evenptr->next = NULL;
            }
            
            oddlast = oddptr;
            oddptr = oddptr->next;
        }
        
        oddlast->next = evenhead;
        return head;
    }
};
