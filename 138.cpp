/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *result = nullptr;
        
        if(head == nullptr)
            return result;
        
        RandomListNode *ptr1, *ptr2;
        
        ptr1 = head;
        
        while(ptr1)
        {
            ptr2 = new RandomListNode(ptr1->label);
            ptr2->next = ptr1->next;
            ptr1->next = ptr2;
            ptr1 = ptr2->next;
        }
        
        ptr1 = head;
        
        while(ptr1)
        {
            if(ptr1->random)
                ptr1->next->random = ptr1->random->next;
            ptr1 = ptr1->next->next;
        }
        
        result = head->next;

        ptr1 = head;
        ptr2 = result;
        
        while(ptr1)
        {
            ptr1->next = ptr2->next;
            
            if(ptr2->next)
                ptr2->next = ptr2->next->next;
            
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return result;
    }
};