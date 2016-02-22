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
    int len;
    
    void findLength(ListNode* head)
    {
        len = 0;
        
        while(head)
        {
            len++;
            head = head->next;
        }
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return NULL;

        findLength(head);

        if(len == n)
            return head->next;
            
        len = len - n - 1;
        ListNode *ptr = head;
        
        while(len--)
            ptr = ptr->next;
        
        ptr->next = ptr->next->next;
        
        return head;
    }
};