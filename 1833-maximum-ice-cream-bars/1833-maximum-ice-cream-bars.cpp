class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans = 0;
        sort(costs.begin(),costs.end());
        int n = costs.size();
        for(int i=0;i<n;i++){
            if(costs[i]>coins){
                break;
            }
            coins-=costs[i];
            ans++;
        }
        return ans;
    }
};