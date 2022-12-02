class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        //we dont care about the word2 after rearranging,since there can be many ways ,many operations to get word2 from word1
        //all we care about is frequencies of characters
        //look at operation 1
        //if two characters are swapped then their freq are not gonna change anyway
        //look at the operation 2
        //if two char are replaced in the entire string then there frequencies are gonna interchange right ? :) 
        //from the above we can conclude that when we arrange the frequencies of all char in word1 and word2 in sorted order they must be same
        //and also no new character should be introduced in the word2
        //let's code
        
        if(word1.length()!=word2.length())
        {
            //impossible to attain
            return false;
        }
        vector<int> freq1(26,0); //char freq of word1
        vector<int> freq2(26,0); //char freq of word2
        
        for(int i=0;i<word1.length();++i)
        {
            freq1[word1[i]-'a']++; 
        }
        
        for(int i=0;i<word2.length();++i)
        {
            //if it does not exists in word1 return false
            if(freq1[word2[i]-'a']==0)
                return false;
            freq2[word2[i]-'a']++; 
        }
        
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        
        return freq1==freq2;
        
    }
};