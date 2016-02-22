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

    int removeNodeFromEnd1(ListNode* head, int n)
    {
        if(!head)
            return 0;
            
        int num;
        
        num = removeNodeFromEnd1(head->next, n);
        
        if(num == n)
            head->next = head->next->next;
            
        return num+1;
    }
    
    void removeNodeFromEnd2(ListNode* head, int n)
    {
        ListNode *ptr1, *ptr2;
        
        ptr1 = head;
        
        for(int i = 0; i < n; i++)
            ptr1 = ptr1->next;
            
        ptr2 = head;
        
        while(ptr1->next)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        ptr2->next = ptr2->next->next;
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

    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        ListNode newHead(1);
        newHead.next = head;
        head = &newHead;
        
        if(random() % 2)
            removeNodeFromEnd1(head, n);
        else
            removeNodeFromEnd2(head, n);
            
        return head->next;
    }
};