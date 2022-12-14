class Solution {
public:
    int climbStairs(int n) {
        int first=0;
        int second=1,curr=0;
        for(int i=0;i<n;i++){
            curr = first+second;
            first = second;
            second = curr;
        }
        return curr;
    }
};