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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return NULL;
        
        ListNode *slow, *fast;
        
        slow = fast = head;

        while(1)
        {
            if(slow->next == NULL)
                return NULL;
            
            slow = slow->next;
            
            if(fast->next == NULL || fast->next->next == NULL)
                return NULL;

            fast = fast->next->next;
            
            if(slow == fast)
                break;
        }
        
        slow = head;
        
        while(1)
        {
            if(slow == fast)
                return slow;
            
            slow = slow->next;
            fast = fast->next;
        }
    }
};