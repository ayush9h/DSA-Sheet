class Solution {
public:
    int maximumGain(string s, int x, int y) {
        vector<char> st1, st2;
        int ans = 0;
        int checker = (y > x) ? 1 : 0;

        for (auto ch : s) {
            if (!st1.empty()) {
                if (checker) {
                    if (st1.back() == 'b' && ch == 'a') {
                        ans += y;
                        st1.pop_back();
                        continue;
                    }
                } else {
                    if (st1.back() == 'a' && ch == 'b') {
                        ans += x;
                        st1.pop_back();
                        continue;
                    }
                }
            }
            st1.push_back(ch);
        }

        for (auto ch : st1) {
            if (!st2.empty()) {
                if (!checker) {
                    if (st2.back() == 'b' && ch == 'a') {
                        ans += y;
                        st2.pop_back();
                        continue;
                    }
                } else {
                    if (st2.back() == 'a' && ch == 'b') {
                        ans += x;
                        st2.pop_back();
                        continue;
                    }
                }
            }
            st2.push_back(ch);
        }

        return ans;
    }
};
