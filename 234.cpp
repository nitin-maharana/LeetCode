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
    
    bool isPalindrome(ListNode *l, ListNode *r)
    {
        for(int i = 0; i < (len/2); i++)
        {
            if(l->val != r->val)
                return false;
            
            l = l->next;
            r = r->next;
        }
        
        return true;
    }
    
    ListNode* reverseList(ListNode *head)
    {
        if(!head->next)
            return head;
        
        ListNode* h = reverseList(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return h;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        findLength(head);
        
        if(!len || (len == 1))
            return true;
        
        ListNode *ptr = head;
        
        for(int i = 0; i < (len/2)-1; i++)
            ptr = ptr->next;
            
        ptr->next = reverseList(ptr->next);
        
        return isPalindrome(head, ptr->next);
    }
};