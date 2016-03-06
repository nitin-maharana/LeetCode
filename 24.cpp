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
    void swapPairsUtil(ListNode *head)
    {
        ListNode *temp;
        
        while(head->next && head->next->next)
        {
            temp = head->next;
            head->next = temp->next;
            temp->next = head->next->next;
            head->next->next = temp;
            head = temp;
        }
    }
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        
        swapPairsUtil(newHead);
        
        return newHead->next;
    }
};