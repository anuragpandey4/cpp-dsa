//q
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int right = 1;

        while(right < nums.size()){
            if(nums[left] != nums[right]) {
                swap(nums[left+1],nums[right]);
                left++;
            }
            right++;
        }

        return left+1;
    }
};