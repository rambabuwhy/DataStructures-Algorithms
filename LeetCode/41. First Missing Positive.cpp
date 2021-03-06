/*
Given an unsorted integer array nums, find the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3
Example 2:

Input: nums = [3,4,-1,1]
Output: 2
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1

*/

// *********SWAP METHOD************
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        // swap numbers into its right place
        int n = nums.size();
        for(int i = 0; i < n; ++ i){
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
                swap(nums[i], nums[nums[i] - 1]);
            }    
        }
            
        //return if number is not in its right place
        for(int i = 0; i < n; ++ i){
            if(nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};

//*********SIGN METHOD*********
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();

        //verify '1' exists or not
        bool oneExist = false;
        for (int i = 0; i < n; i++){
             if (nums[i] == 1) {
                oneExist = true;
                break;
            }
        }
           
        //if '1'  does not  exist then '1'  is answer
        if (oneExist == false) return 1;
        
        //replace all  negetives and zeros and greater than n to '1'
        for (int i = 0; i < n; i++){
            if ((nums[i] <= 0) || (nums[i] > n)) nums[i] = 1;
        }
        
        //add negetive sign
        //if positive means number does not exist
        for (int i = 0; i < n; i++) {
            int a = abs(nums[i]);
            if (a == n) nums[0] = -abs(nums[0]);
            else nums[a] = -abs(nums[a]);
        }
  
        //finally iterate and chwck for positive number
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) return i;
        }

        if (nums[0] > 0) return n;

        return n + 1;
    }
};
