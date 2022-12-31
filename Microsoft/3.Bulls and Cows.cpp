class Solution {
public:
string getHint(string secret, string guess) {
int a[10]={0},b[10]={0};
for(int i=0;i<secret.length();i++)
a[secret[i]-'0']++;
for(int i=0;i<guess.length();i++)
b[guess[i]-'0']++;
int c=0;
for(int i=0;i<10;i++)
c+=min(a[i],b[i]);
int c1=0;
for(int i=0;i<secret.length();i++)
if(secret[i]==guess[i])
c1++;
c=c-c1;
string s="";
s+=to_string(c1);
s+="A";
s+=to_string(c);
s+="B";
return s;
}
};