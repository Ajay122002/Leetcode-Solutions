class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        int n = piles.size();
        for(int i=0;i<n;i++){
            pq.push(piles[i]);
        }
        
        while(k--){
            int temp = pq.top();
            pq.pop();
            int val = temp-floor(temp/2);
            pq.push(val);
        }
        int ans = 0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};