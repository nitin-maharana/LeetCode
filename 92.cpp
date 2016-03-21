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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m >= n || head == NULL || head->next == NULL)
            return head;

        ListNode dummyNode(0);
        ListNode *newHead = &dummyNode;
        
        newHead->next = head;

        ListNode *first, *prev, *curr, *next;
        
        prev = newHead;
        curr = head;
        next = curr->next;
        
        n = n - m + 1;
        m--;
        
        while(m-- && next)
        {
            prev = curr;
            curr = next;
            next = next->next;
        }
        
        first = prev;
        
        while(n--)
        {
            curr->next = prev;
            prev = curr;
            curr = next;
            
            if(next)
                next = next->next;
        }
        
        first->next->next = curr;
        first->next = prev;
        
        return newHead->next;
    }
};