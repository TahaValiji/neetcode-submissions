class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        map<char, int> mp;
        int res = 0;

        int l = 0;
        for (int r = 0; r < n; r++) {
            char c = s[r];
            mp[c]++;

            while (mp[c] > 1) {
                mp[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};
