class Solution {
public:
    int magicalString(int n) {
        int a = 1^2;
        string magic = "122";
        int i = 2, j = 2;
        while(j < n) {
            char ch = a^(magic[j]-'0')+'0';
            int times = magic[i]-'0';
            for(int k = 0; k < times; k++) {
                magic += ch;
                j++;
            }
            
            i++;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) 
            if(magic[i] == '1') cnt++;
        
        return cnt;
    }
};