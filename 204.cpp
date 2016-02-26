/*
 * Written by Nitin Kumar Maharana
 * nitin.maharana@gmail.com
 */

class Solution {
    int countPrimes(bool *primes, int n)
    {
        int count = 0;
        
        for(int i = 2; i < sqrt(n); i++)
        {
            if(primes[i])
            {
                count++;
                
                for(int j = i*i; j < n; j += i)
                    primes[j] = false;
            }
        }

        for(int i = ceil(sqrt(n)); i < n; i++)
            if(primes[i])
                count++;
                
        return count;
    }
public:
    int countPrimes(int n) {
        bool primes[n];
        
        memset(primes, true, sizeof primes);
        
        primes[0] = primes[1] = false;
        primes[2] = true;
        
        return countPrimes(primes, n);
    }
};