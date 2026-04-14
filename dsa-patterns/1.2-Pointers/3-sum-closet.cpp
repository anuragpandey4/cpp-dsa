// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        double minDiff = INFINITY;
        int closeSum;

        sort(nums.begin(),nums.end());

        for(int i = 0; i < nums.size()-2; i++){
            int left = i+1;
            int right = nums.size() - 1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                int diff = abs(sum - target);

                if(diff < minDiff) {
                    minDiff = diff;
                    closeSum = sum;
                }

                if(sum == target) {
                    return sum;
                }else if(sum > target) {
                    right--;
                }else{
                    left++;
                }
            }
        }

        return closeSum;
    }
};