class Solution {
public:
    vector<vector<int>> answer;
    vector<int> current;

    void solve(vector<int>& nums, vector<bool>& used) {

        if (current.size() == nums.size()) {
            answer.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i])
                continue;
            current.push_back(nums[i]);
            used[i] = true;
            solve(nums, used);
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        solve(nums, used);
        return answer;
    }
};