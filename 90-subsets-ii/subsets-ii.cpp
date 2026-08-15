class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> current;

        solve(nums, 0, current, ans);
        return ans;
    }

    void solve(vector<int>& nums, int index,
               vector<int>& current,
               vector<vector<int>>& ans) {
        ans.push_back(current);
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1])
            continue;
            current.push_back(nums[i]);
            solve(nums, i + 1, current, ans);
            current.pop_back();
        }
    }
};