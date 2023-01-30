class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        
        long weight=mass;
        for(int i=0;i<asteroids.size();i++){
            if(weight<long(asteroids[i]))return false;
            else{
                weight+=asteroids[i];
            }
        }
        return true;
    }
};