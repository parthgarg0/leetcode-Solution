class Solution {
public:
    void cs(vector<int>& arr, int idx, int tar,
            vector<int>& combi, vector<vector<int>>& ans) {

        if (tar == 0) {
            ans.push_back(combi);
            return;
        }

        for (int i = idx; i < arr.size(); i++) {

            // skip duplicates
            if (i > idx && arr[i] == arr[i-1]) continue;

            // pruning
            if (arr[i] > tar) break;

            combi.push_back(arr[i]);

            // move forward (each used once)
            cs(arr, i + 1, tar - arr[i], combi, ans);

            combi.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int tar) {
        vector<vector<int>> ans;
        vector<int> combi;

        sort(arr.begin(), arr.end());
        cs(arr, 0, tar, combi, ans);

        return ans;
    }
};
