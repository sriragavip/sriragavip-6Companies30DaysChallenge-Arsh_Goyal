class Solution {
public:
	int numberOfSubstrings(string s) {
		int n = s.size(), ans = 0;
		map<char,int> mp;
		int left = 0, right = 0;
		while(left<n && right<n){
			mp[s[right]]++;
			while(mp.size()==3){
				ans+=(n-right);
				if(mp[s[left]]>1){
					mp[s[left]]--;
				}
				else{
					mp.erase(s[left]);
				}
				left++;
			}
			right++;
		} 
		return ans;
	}
};