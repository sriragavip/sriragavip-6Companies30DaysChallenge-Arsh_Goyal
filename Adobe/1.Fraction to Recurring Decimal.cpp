class Solution {
public:
    string fractionToDecimal(int num1, int num2) {
    string res ="";    
    if (num1==0) return "0";
    if (num2==0) return "NaN";  
    long int n1 = num1;
    long int n2 = num2;
    if (n1>0 ^ n2>0) res+='-';
    n1 = abs(n1);
    n2 = abs (n2);
    res += to_string(n1/n2);  
    if (n1%n2==0)
        return res;
    res+='.';   
    map <int, int> h;
    n1 = n1 %n2;
    n1*=10;
    int idx=0;
    string frac = ""; 
    while (n1!= 0 )  {
        if (h.find(n1)!=h.end()) {
            frac.insert(h[n1], "(");
            frac.append(")");
            break;
        }
        frac+= to_string(n1/n2);     
        h[n1] = idx;  
        n1 = n1 %n2;
        n1*=10;
        idx++;
    }
    res+=frac;
    return res;    
}
};