class Solution {
public:
    int firstUniqChar(string s) {
        /*vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        int i = 0;
        for (char ch : s) {
            if (freq[ch - 'a'] == 1)
                return i;
            i++;
        }
        return -1;*/

        unordered_map<char, int> m;
        queue<int> q;

        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end()) {
                q.push(i);
            }
            
            m[s[i]]++;
            
            while (!q.empty() && m[s[q.front()]] > 1)
                q.pop();
        }

        if (q.empty())
            return -1;
        else
            return q.front();
    }
};