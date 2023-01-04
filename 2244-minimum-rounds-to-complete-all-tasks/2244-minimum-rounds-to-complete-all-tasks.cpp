class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>mp;
        int n = tasks.size();
        for(int i=0;i<n;i++){
            mp[tasks[i]]++;
        }
        int ans = 0;
        for(auto i:mp){
            int curr = i.second;
            if(curr == 1) return -1;
            if(curr == 2 ) ans++;
            if(curr%3 == 0){
                ans+=curr/3;
            }else if(curr==4){
                ans+=2;
            }else if(curr>4 && curr%3 == 2){
                ans+=curr/3;
                ans+=1;
            }else if(curr>4 && curr%3 == 1){
                curr-=4;
                ans+=curr/3;
                ans+=2;
            }
            //cout<<i.first<<" "<<i.second<<" "<<ans<<endl;
        }
        return ans;
    }
};