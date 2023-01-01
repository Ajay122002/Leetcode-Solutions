class Solution {
public:
    bool wordPattern(string p, string s) 
    {
        int n=p.size();
        int i=0;
        stringstream ss(s);
        string token;
        vector<string>vec;
        while(ss>>token)
        {
            vec.push_back(token);
        }
        if(vec.size()!=p.size())
        {
            return false;
        }
        unordered_map<char,string>mp;
        set<string>sets;
        for(i=0;i<n;i++)
        {
            char ch = p[i];
            // if current character is present in the 
            // map 
            if(mp.find(ch)!=mp.end())
            {
                // check for the value of that character 
                if(mp[ch]!=vec[i])
                {
                    return false;
                }
            }
            else
            {
                 // "abba"
                //"dog dog dog dog"
                // for this test case we need to take care of the strings also 
                // so we use the set , to know whether is the string repeated or                   //not 
            
                // if string repeated then return false;
                if(sets.count(vec[i])>0)
                {
                    return false;
                }
                // else just map the string with the given character and
                // insert it into the set 
                mp[ch]=vec[i];
                sets.insert(vec[i]);
            }
        }
        return true;
    }
};