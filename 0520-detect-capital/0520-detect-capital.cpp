class Solution {
public:
    bool detectCapitalUse(string word) {
        int allcntr=0;
        int twoscntr=0;
        int n=word.length();
        for(int i=0;i<n;i++){
            if(i!=0 && islower(word[i]))
                twoscntr++;
            if(isupper(word[i]))
                allcntr++;
        }
        if(allcntr==n)
            return true;
        else if(twoscntr==(n-1))
            return true; 
        return false;
    }
};