class Solution {
public:

    bool isPalindrome(string s) {
        string t;

        for (auto &c : s) {
            if (isalnum(c)) {
                t += tolower(c);
            }
        }
        string u = t;
        reverse(u.begin(), u.end());
        return u == t;
    }
};
