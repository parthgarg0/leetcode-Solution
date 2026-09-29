
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        int ans = 1;
        int var = 1;
        string t;
        t += s[0];
        int it = 1;
        while (it < s.size()) {
            // Character is not already present
            if (t.find(s[it]) == string::npos) {
                t += s[it];
                var++;
                ans = max(ans, var);
                it++;
            }
            // Character is already present
            else {
                // Remove characters from the beginning
                // until the duplicate character is removed
                t.erase(0, 1);
                var--;
            }
        }
        return ans;
    }
};
