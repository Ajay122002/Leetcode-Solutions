string vowels = "aeiouAEIOU";

class Solution {
public:
    bool halvesAreAlike(string S) {
        int mid = S.size() / 2, ans = 0;
        for (int i = 0, j = mid; i < mid; i++, j++) {
            if (~vowels.find(S[i])) ans++;
            //cout<<(~vowels.find(S[i]))<<" "<<(~vowels.find(S[j]))<<endl;
            if (~vowels.find(S[j])) ans--;
        }
        cout<<(vowels.find(S[2]))<<endl;
        return ans == 0;
    }
};