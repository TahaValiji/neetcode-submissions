class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        map<char, int> mp;
        int res = 0;

        int l = 0;
        for (int r = 0; r < n; r++) {
            mp[s[r]]++;
            while (mp[s[r]] > 1)  mp[s[l++]]--;
            res = max(res, r - l + 1);
        }

        return res;
    }
};
