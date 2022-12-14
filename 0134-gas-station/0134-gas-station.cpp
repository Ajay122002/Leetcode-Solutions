class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start(0),total(0),tank(0);
        int n=gas.size();
        for(int i=0;i<n;i++){
            if((tank=tank+gas[i]-cost[i])<0){
                start=i+1;
                total+=tank;
                tank=0;
            }
        }
        if(total+tank<0)
            return -1;
        else
            return start;
    }
};