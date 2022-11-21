class Solution {
public:
    
    int dir_x[4] = {0,0,-1,1};
    int dir_y[4] = {-1,1,0,0};
    
    bool is_valid(int x, int y, int n,int m){
        return (x>=0 && x<n && y>=0 && y<m);
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});       
        vector<vector<int>>visited(n,vector<int>(m,-1));
        visited[entrance[0]][entrance[1]]=1;
        int level = 1;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                pair<int,int>temp = q.front();
                int x = temp.first;
                int y = temp.second;
                q.pop();
                for(int i=0;i<4;i++){
                    int new_x = x+dir_x[i];
                    int new_y = y+dir_y[i];
                    if(is_valid(new_x,new_y,n,m) && visited[new_x][new_y] == -1 && maze[new_x][new_y]!='+'){
                        //cout<<new_x<<" "<<new_y<<endl;
                        if(new_x == 0 || new_y == 0 || new_x == n-1 || new_y == m-1)
                            return level;
                        q.push({new_x,new_y});
                        visited[new_x][new_y] = 1;
                    }   
                }
            }
            level++;
        }
        return -1;
    }
};