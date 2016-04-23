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
        if(head == nullptr)
            return nullptr;
        
        ListNode *slow, *fast;
        
        slow = fast = head;

        while(1)
        {
            if(slow->next == nullptr)
                return nullptr;
            
            slow = slow->next;
            
            if(fast->next == nullptr || fast->next->next == nullptr)
                return nullptr;

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
