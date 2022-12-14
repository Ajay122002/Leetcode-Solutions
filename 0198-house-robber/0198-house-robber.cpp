class Solution {
public:
    int rob(vector<int>& nums) {
        int curr = 0, prev1 = nums[0],prev2 =0;
        int n = nums.size();
        for(int i=1;i<n;i++){
            curr = max(nums[i]+prev2,prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return max(curr,prev1);
    }
};