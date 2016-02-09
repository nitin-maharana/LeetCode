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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        ListNode *head, *ptr;

        head = new ListNode(0);
        ptr = head;

        int carry = 0;
        int sum;

        while(l1 && l2)
        {
            sum = l1->val + l2->val + carry;

            ptr->next = new ListNode(sum % 10);
            ptr =  ptr->next;

            carry = sum / 10;

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1)
        {
            sum = l1->val + carry;

            ptr->next = new ListNode(sum % 10);
            ptr = ptr->next;

            carry = sum / 10;

            l1 = l1->next;
        }

        while(l2)
        {
            sum = l2->val + carry;

            ptr->next = new ListNode(sum % 10);
            ptr = ptr->next;

            carry = sum / 10;

            l2 = l2->next;
        }

        if(carry)
            ptr->next = new ListNode(carry);

        return head->next;
    }
};