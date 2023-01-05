class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int ans=1;
        sort(points.begin(), points.end(), compare);
        int pre=points[0][1];
        for(int i=1;i<points.size();i++){
            if(pre>=points[i][0]){
                continue;
            }
            pre=points[i][1];
            ans++;
        }
        return ans;
    }
};