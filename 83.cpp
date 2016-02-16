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
        if(!head)
            return head;
        
        ListNode *ptr, *nodeToDelete;
        ptr = head;
            
        while(ptr->next)
        {
            if(ptr->val == ptr->next->val)
            {
                nodeToDelete = ptr->next;
                ptr->next = ptr->next->next;
                delete nodeToDelete;
            }
            else
                ptr = ptr->next;
        }
        
        return head;
    }
};
