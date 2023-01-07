class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) 
    {
        int cnt=0;
        for(int i=0;i<points.size();i++)
        {
            map<long ,int>m;
            for(int j=0;j<points.size();j++)
            {
                        long d1=pow((points[j][0]-points[i][0]),2)+pow((points[i][1]-points[j][1]),2);
                        m[d1]++;
            }
            for(auto it:m)
            {
                int val=it.second;
                cnt+=((val-1)*val);
            }
        }
        return cnt;
    }
};