/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    void findSum(string &a, string &b)
    {
        int ptrA, ptrB, carry;
        char temp;
        
        ptrA = a.length() - 1;
        ptrB = b.length() - 1;
        carry = 0;
        
        while(ptrA >= 0 && ptrB >= 0)
        {
            temp = a[ptrA];

            a[ptrA] = ((a[ptrA]-'0') ^ (b[ptrB]-'0') ^ carry) + '0';
            
            if((temp == '1' && b[ptrB] == '1') || (temp == '1' && carry) || (b[ptrB] == '1' && carry))
                carry = 1;
            else
                carry = 0;
                
            ptrA--;
            ptrB--;
        }

        while(ptrA >= 0)
        {
            temp = a[ptrA];

            a[ptrA] = ((a[ptrA]-'0') ^ carry) + '0';

            if(temp == '1' && carry)
                carry = 1;
            else
                carry = 0;

            ptrA--;
        }

        if(carry)
            a = '1' + a;
    }
public:
    string addBinary(string a, string b) {
        if(a.length() < b.length())
            a.swap(b);
        
        findSum(a, b);
        
        return a;
    }
};