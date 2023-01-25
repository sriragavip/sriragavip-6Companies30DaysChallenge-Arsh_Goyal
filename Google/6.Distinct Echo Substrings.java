class Solution {
    public int distinctEchoSubstrings(String str) {
        HashSet<String> set = new HashSet<>();
        int n = str.length();
        for (int i = 0; i < n; i++) {
            for (int len = 2; i + len <= n; len += 2) {
                int mid = i + len / 2;
                String subStr1 = str.substring(i, mid);
                String subStr2 = str.substring(mid, i + len);
                if (subStr1.equals(subStr2)) set.add(subStr1);
            }
        }
        return set.size();
    }
}