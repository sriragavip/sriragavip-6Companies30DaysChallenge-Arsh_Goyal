class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> count, end;
        for (int it:nums){
			count[it]++;
		}
        for (int it: nums) {
            if (count[it]==0){
				continue;
			}
			
            count[it]--;
            
            if (end[it-1]>0){
                end[it-1]--;
                end[it]++;
            }
			else if (count[it+1]>0 && count[it+2]>0){
                count[it+1]--;
                count[it+2]--;
                end[it+2]++;
            }
			else{
                return false;
            }
        }
        return true;
    }
};