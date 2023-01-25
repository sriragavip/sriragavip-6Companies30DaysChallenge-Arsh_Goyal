class Solution {
public:
bool hasAllCodes(string s, int k) {
    if (k > 15)
        return false;
    vector<bool> found(1 << k);
    int num = 0, mask = (1 << k) - 1, cnt = 0;
    for (auto i = 0; i < s.size(); ++i) {
        num = mask & ((num << 1) + s[i] - '0');
        if (i >= k - 1) {
            if (found[num] == false)
                ++cnt;
            found[num] = true;
        }
    }
    return cnt == found.size();
}
};