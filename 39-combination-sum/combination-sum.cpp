class Solution {
public:
    vector<vector<int>> answer;
    vector<int> combination;
    void solve(vector<int>& candidates, int target, int index) {
        if (target == 0) {
            answer.push_back(combination);
            return;
        }
        if (index == candidates.size()) {
            return;
        }
        solve(candidates, target, index + 1);
        if (candidates[index] <= target) {
            combination.push_back(candidates[index]);
            solve(candidates,
                  target - candidates[index],
                  index);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0);
        return answer;
    }
};