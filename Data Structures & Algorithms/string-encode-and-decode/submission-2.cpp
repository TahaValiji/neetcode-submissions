class Solution {
public:

    string encode(vector<string>& strs) {
        int n = strs.size();
        string t;

        for (int i = 0; i < n; i++) {
            int len = strs[i].size();

            t += strs[i];
            t += "`";
        }

        return t;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        string t;
        for (auto &c : s) {

            if (c != '`') t.push_back(c);
            else {
                ans.push_back(t);
                t.clear();
            }
        }
        return ans;
    }
};
