class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        //sort(intervals.begin(),intervals.end());
        int count=0;
       for(int i=0;i<intervals.size();i++){
        auto y=intervals[i];
        for(int j=0;j<intervals.size();j++){
            if(j==i) continue;
            auto z=intervals[j];
            if(y[0]>=z[0] && y[1]<=z[1]){ count ++;
            break;}
        }
       }
       cout<<count;
       return intervals.size()-count;
        

    }
};