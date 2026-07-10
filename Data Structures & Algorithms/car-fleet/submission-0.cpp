class Solution {
public:
    int carFleet(int target, vector<int>& p, vector<int>& s) {
        int n = p.size();
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({p[i], s[i]});
        }

        sort(a.begin(), a.end(), greater<pair<int, int>>());

        stack<double> st;

        for (auto &x : a) {
            int pos = x.first;
            int spd = x.second;

            double time = (double)(target - pos) / spd;
            if (st.empty() || time > st.top()) st.push(time);
        }

        return st.size();
    }
};