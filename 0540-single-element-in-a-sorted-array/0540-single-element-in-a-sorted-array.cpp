class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int mid;
        if (high == 0)
            return nums[high];
        while (low < high) {
            mid = low + (high - low) / 2;

            if (nums[0]!=nums[1]) return nums[0];
            if (nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];

            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid - 1]) {
                    high = mid;
                } else {
                    low = mid;
                }
            } else {
                if (nums[mid] == nums[mid - 1]) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
        }
        return -1;
    }
};