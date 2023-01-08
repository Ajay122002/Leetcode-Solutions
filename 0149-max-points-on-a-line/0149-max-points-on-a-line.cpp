class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n=points.size();
        if(n<2)return n;
        int maxCounter=0;
        
        for(int i=0;i<n-1;i++){
            map<pair<int,int>,int>slopeMap;
            int overlappingPoints=0,verticalPoints=0,counter=0;
            for(int j=i+1;j<n;j++){
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    overlappingPoints++;
                else if(points[i][0] == points[j][0])
                    verticalPoints++;
                else{
                    int yDiff=points[j][1] - points[i][1];
                    int xDiff=points[j][0] - points[i][0];
                    
                    int hcf=__gcd(yDiff,xDiff);
                    yDiff=yDiff/hcf;
                    xDiff=xDiff/hcf;
                    
                    pair<int,int>slope=make_pair(xDiff,yDiff);
                    slopeMap[slope]++;
                    counter=max(counter,slopeMap[slope]);
                }
                counter=max(counter,verticalPoints);
            }
            maxCounter=max(maxCounter,counter+overlappingPoints+1);
        }
        return maxCounter;
    }
};