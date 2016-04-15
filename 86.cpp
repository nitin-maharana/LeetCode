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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *ptr, *prev, *temp;
        
        ptr = head;
        
        if(head->val >= x)
        {
            while(ptr->next && ptr->next->val >= x)
                ptr = ptr->next;
            
            if(ptr->next == nullptr)
                return head;
            
            prev = ptr->next;
            ptr->next = prev->next;
            prev->next = head;
            head = prev;
        }
        else
        {
            while(ptr->next && ptr->next->val < x)
                ptr = ptr->next;
            
            if(ptr->next == nullptr)
                return head;
            
            prev = ptr;
        }
        
        while(ptr->next)
        {
            if(ptr->next->val >= x)
                ptr = ptr->next;
            else
            {
                temp = ptr->next;
                ptr->next = temp->next;
                temp->next = prev->next;
                prev->next = temp;
                prev = prev->next;
            }
        }
        
        return head;
    }
};