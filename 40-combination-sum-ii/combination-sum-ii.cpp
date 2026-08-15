class Solution {
public:
    vector<vector<int>> answer;
    vector<int> combination;

    void solve(vector<int>& candidates, int target, int start) {

        if (target == 0) {
            answer.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            combination.push_back(candidates[i]);

            solve(candidates, target - candidates[i], i + 1);

            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);
        return answer;
    }
};