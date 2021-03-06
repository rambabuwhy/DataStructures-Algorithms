/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
Example 3:

Input: nums = [0]
Output: [0]
Example 4:

Input: nums = [1]
Output: [1]
*/
class Solution {
public:
    void swap(vector<int> &nums, int a, int b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
        
    }
    void sortColors(vector<int>& nums) {
        
        if(nums.size() < 1 )  return;
       
        int left = 0;
        int mid = 0;
        int right = nums.size() -1;
        
        //compare nums[mid]
        while( mid <= right ) {
            
            if(nums[mid] == 0){
                swap(nums, left, mid);
                left++;
                mid++;
            } else if(nums[mid] == 1){
                mid++;
            } else if(nums[mid] == 2){
                swap(nums, mid, right);
                right--;
            }
        }
    }
};
