class Solution {
public:
    
    int recurr(int i,int j, int n, int m, vector<vector<int>>&matrix,vector<vector<int>>&dp){
        if(j<0 || j>m-1)
            return 1e9;
        
        if(i==0) return matrix[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int up = matrix[i][j] + recurr(i-1,j,n,m,matrix,dp);
        int ul = matrix[i][j] + recurr(i-1,j-1,n,m,matrix,dp);
        int ur = matrix[i][j] + recurr(i-1,j+1,n,m,matrix,dp);
        
        return dp[i][j] = min(ur,min(up,ul));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<m;i++){
            ans = min(ans,recurr(n-1,i,n,m,matrix,dp));
        }
        return ans;
    }
};