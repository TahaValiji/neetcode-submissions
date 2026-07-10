class Solution {
public:
    bool chk(char a, char b) {
        if ((a == '}'  && b == '{') || (a == ')' && b == '(') || (a == ']' && b == '[')) return true;
        return false;
    }
    bool chk(char c) {
        if (c == '(' || c == '[' || c == '{') return true;
        return false;
    }
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (chk(c)) st.push(c);
            else {
                if (st.empty()) return false;
                if (!chk(c, st.top())) return false;
                st.pop();
                
            }
        }

        if (st.empty()) return true;
        return false;
    }
};
