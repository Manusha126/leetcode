class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points)
     {
        int n=points.size();
        int dist=0;
        for(int i=0;i<n-1;i++)
        {
            
            {
                dist+=max(abs(points[i+1][1]-points[i][1]),abs(points[i+1][0]-points[i][0]));
                
            }
        }
        return dist;
        
    }
};