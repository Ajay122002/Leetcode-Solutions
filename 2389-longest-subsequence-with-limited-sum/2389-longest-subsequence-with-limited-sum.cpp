class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        vector<int>ans;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto it : nums)
        {
            pq.push(it);
        }
        
        int n = queries.size();
        for(int i=0;i<n;i++)
        {
            priority_queue<int,vector<int>,greater<int>>temp = pq;
            int len = 0;
            int val = queries[i];
            while(!temp.empty() and temp.top()<=val)
            {
                len++;
                val-=temp.top();
                temp.pop();
            }
            ans.push_back(len);
        }
        return ans;
    }
};