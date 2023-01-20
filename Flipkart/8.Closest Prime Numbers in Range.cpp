class Solution {
	public:
		vector<int> closestPrimes(int left, int right) {
			vector<bool> p(1e6+1,true);
			p[0]=p[1]=false;
			for(int i=2;i*i<=1e6;i++){
				for(int j=2;i*j<=1e6;j++) p[i*j]=false;
			}
			vector<int> ans;
			vector<int> temp;
			int diff=1e9;
			for(int i=left;i<=right;i++){
				if(p[i]){
					temp.push_back(i);
					if(temp.size()==2){
						if(temp[1]-temp[0]<diff){
							diff=temp[1]-temp[0];
							ans=temp;
						}
						temp.clear();
						temp.push_back(i);
					}
				}    
			}
			if(ans.size()==0) return {-1,-1};
			return ans;
		}
	};