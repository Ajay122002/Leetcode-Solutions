class Solution {
public:
    bool wordPattern(string p, string s) {
        map<char,string>mp;
        set<string>st;
        vector<string>vec;
        stringstream ss(s);
        string word;
        while(ss>>word){
            vec.push_back(word);
        }
        if(vec.size()!=p.size())
            return false;
        for(int i=0;i<p.size();i++){
            if(mp[p[i]]==""){
                if(st.count(vec[i])>0)
                    return false;
                st.insert(vec[i]);
                mp[p[i]]=vec[i];
            }else{
                if(mp[p[i]]!=vec[i])
                    return false;
            }
        }
        return true;
    }
};