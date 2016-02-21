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
    int findLength(ListNode* head)
    {
        int len = 0;
        
        while(head)
        {
            len++;
            head = head->next;
        }
        
        return len;
    }
    
    void advancePointer(ListNode **ptr, int len)
    {
        while(len--)
            (*ptr) = (*ptr)->next;
    }
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(!headA || !headB)
            return NULL;

        int lenA, lenB;
        
        lenA = findLength(headA);
        lenB = findLength(headB);
        
        ListNode *ptrA, *ptrB;
        
        ptrA = headA;
        ptrB = headB;
        
        (lenA < lenB) ? advancePointer(&ptrB, lenB-lenA) : advancePointer(&ptrA, lenA-lenB);
        
        while(ptrA && ptrB)
        {
            if(ptrA == ptrB)
                return ptrA;
                
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        
        return NULL;
    }
};