
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*if (s.empty())
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
        return ans;*/

        if (s.empty())
            return 0;
        int left = 0;
        int ans = 0;
        unordered_set<char> st;
        for (int right = 0; right < s.size(); right++) {
            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            int temp = right - left + 1;
            ans = max(ans, temp);
        }
        return ans;
    }
};
