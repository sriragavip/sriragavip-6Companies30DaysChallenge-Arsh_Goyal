class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
       int n = points.size();
             if(n <= 2) 
             return points.size();
        
        int res = -1e9;
        for(int i=0; i<n; i++)
        {
            unordered_map<double,int> mp;
              int duplicate = 0;
              double slope = 0.0;
            for(int j=0; j<n; j++)
            {
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];
                
                int dy = y2 - y1; 
                int dx = x2 - x1; 
                if(dy == 0 && dx == 0)
                {
                    duplicate++;
                    continue;
                }
                else if(dx!=0 || dy!=0)
                {
                    slope = dy*1.0/dx;
                }
                else 
                {
                    slope = 1e9;
                }
                
                mp[slope]++;
            }
          
            for(auto slope: mp)
            {
               
                res = max(res, slope.second + duplicate);
            }
        }
        return res; 
    }
};