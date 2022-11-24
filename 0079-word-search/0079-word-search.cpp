class Solution {
public:
    int dir_x[4]={1,-1,0,0};
    int dir_y[4]={0,0,-1,1};
    
    bool is_valid(int x,int y, int row, int col){
        return (x>=0 && x<row && y>=0 && y<col);
    }
    
    bool flag;
    bool dfs(vector<vector<char>>& board, string word,int count,int i,int j,int row,int col,int len){
        if(count==len)
            return true;
        if(!is_valid(i,j,row,col) || board[i][j]!=word[count])
            return false;
        char temp=board[i][j];
        board[i][j]=' ';
        for(int k=0;k<4;k++){
            int X=i+dir_x[k];
            int Y=j+dir_y[k];
            flag=flag || dfs(board,word,count+1,X,Y,row,col,len);
        }
        board[i][j]=temp;
        return flag;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size(),col=board[0].size(),len=word.size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(word[0]==board[i][j] && dfs(board,word,0,i,j,row,col,len)){
                    return true;
                }
            }
        }
        return false;
    }
};