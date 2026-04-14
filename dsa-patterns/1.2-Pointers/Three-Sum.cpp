// https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>> result;

        for(int i = 0; i < nums.size() - 2; i++) {
            if(i != 0 && nums[i] == nums[i-1]) continue;

            int target = -nums[i];

            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right) {
                int curSum = nums[left] + nums[right];
                
                if(curSum == target){
                    result.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;

                    while(left < right && nums[left] == nums[left-1]) {
                        left++;
                    }

                    while(left < right && nums[right] == nums[right+1]){
                        right--;
                    }

                }else if(curSum > target) {
                    right--;
                }else {
                    left++;
                }

            }

        }

        return result;
    }
};