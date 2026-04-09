
// que
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

// soln
#include<bits/stdc++.h>
using namespace std;


vector<int> twoSum(vector<int>& numbers, int target) {
    int left = 0;
    int n = numbers.size();
    int right = n - 1;

    vector<int> result;
    while(left < right) {
        int curSum = numbers[left] + numbers[right];

        if(curSum == target) {
            result.push_back(left+1);
            result.push_back(right+1);
            break;
        }else if(curSum > target) {
            right--;
        }else{
            left++;
        }
    }
        return result;
}


int main() {
    vector<int> ip = {2,7,11,15};
    vector<int> result = twoSum(ip,9);
    cout<<result[0]<<" "<<result[1];

    return 0;
}