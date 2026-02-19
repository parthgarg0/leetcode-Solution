class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            int f = nums[i];
            int s = target - f;

            if (m.find(s) != m.end()) {
                return {m[s], i};
            }

            m[f] = i;
        }

        return {};
    }
};
