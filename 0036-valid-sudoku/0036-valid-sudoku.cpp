class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char,bool>mprow;
        map<char,bool>mpcol;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                
                // checking rows
                if(mprow[board[i][j]]==true)
                    return false;
                if(board[i][j]!='.')
                    mprow[board[i][j]]=true;
                
                // checking columns
                if(mpcol[board[j][i]]==true)
                    return false;
                if(board[j][i]!='.')
                    mpcol[board[j][i]]=true;
            }
            mprow.clear();
            mpcol.clear();
        }
        
        // checking boxes
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                map<char,bool>mpbox;
                for(int r=i; r<i+3; r++)
                {
                    for(int c=j; c<j+3; c++)
                    {
                        if(mpbox[board[r][c]]==true) return false;
                        if(board[r][c] != '.') mpbox[board[r][c]]=true;
                    }
                }
            }
        }
        return true;
    }
};