class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        map<int,int>col,row;
      
        int r=mat.size();
        int c=mat[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==0){
                    col[j]=1;
                    row[i]=1;
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(col[j]==1 || row[i]==1){
                    mat[i][j]=0;
                }
            }   
        }
    }
};