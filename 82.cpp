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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        
        ListNode dummy(0);
        ListNode *newHead;
        
        newHead = &dummy;
        newHead->next = head;
        
        ListNode *prev, *curr;
        int currVal;
        
        prev = newHead;
        curr = head;
        
        while(curr)
        {
            if(curr->next && curr->val == curr->next->val)
            {
                currVal = curr->val;
                curr = curr->next;
                
                while(curr)
                {
                    curr = curr->next;
                    
                    if(curr == NULL || curr->val != currVal)
                        break;
                }

                prev->next = curr;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        
        return newHead->next;
    }
};