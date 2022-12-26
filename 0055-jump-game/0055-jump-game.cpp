class Solution {
public:
    bool canJump(vector<int>& nums) {
      int maxreach=0;
        int n=nums.size();
        for(int i=0;i<=maxreach&&i<n;i++){
            int currentreach=i+nums[i];
            maxreach=max(maxreach,currentreach);
            if(maxreach>=n-1){
                return true;
            }
        }
        return false; 
        
    }
};