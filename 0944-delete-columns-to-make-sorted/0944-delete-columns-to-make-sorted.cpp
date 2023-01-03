class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        int n = strs[0].length();
        for(int i=0;i<n;i++){
            string str="", temp="";
            for(int j=0;j<strs.size();j++){
                str+=strs[j][i];   
            }
            temp = str;
            sort(str.begin(),str.end());
            if(str!=temp) ans++;
        }
        return ans;
    }
};