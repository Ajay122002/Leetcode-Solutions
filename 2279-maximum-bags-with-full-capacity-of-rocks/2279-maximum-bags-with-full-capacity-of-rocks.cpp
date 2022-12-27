class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int ar) {
        int n = capacity.size();
        vector<int>temp(n);
        for(int i=0;i<n;i++){
            int val = capacity[i]-rocks[i];
            temp[i] = val;
        }
        sort(temp.begin(),temp.end());
        int ans=0;
        for(int i=0;i<n;i++){    
            if(temp[i]<=ar){
                ar-=temp[i];
                ans++;
            }
        }
        return ans;
    }
};