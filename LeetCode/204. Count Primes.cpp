/*

Count the number of prime numbers less than a non-negative number, n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
*/

class Solution {
public:
    int countPrimes(int n) {
        
        // Sieve of Eratosthenes
        vector<bool> mat(n, true);
        
        for(int i=2; i*i <n; i++) {
            
            //all are true at first
            if(mat[i] == true) {
                for(int j=i*i; j<n; j=j+i) {
                    mat[j]=false;
                }
            }
        }
        
        int count =0;
        for(int i=2; i<n; i++) { //dont forget it start with 2
            if(mat[i] == true) count++;
        }  
        return count;
    }
};
