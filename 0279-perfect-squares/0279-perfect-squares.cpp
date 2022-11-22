class Solution {
public:
    
    int recurr(int n, int count, vector<vector<int>>&dp){
        if(n == 0){
            return count;
        }
        if(n<0){
            return INT_MAX;
        }
        
        if(dp[n][count]!=-1) return dp[n][count];
        
        int mini = INT_MAX;
        
        for(int i=1;i<=n;i++){
            if(n>=(i*i))
                mini = min(mini,recurr(n-(i*i),count+1,dp));
        }
        return dp[n][count] = mini;
    }
    
    int numSquares(int n) {
        
        vector<int>dp(n+1,0);
        
        for(int i=0;i<=n;i++){
            int mini = INT_MAX;
            for(int j=1;j*j<=i;j++){
                mini = min(mini,1+dp[i-j*j]);
                dp[i] = mini;
            }
        }
        
        return dp[n];
    }
};