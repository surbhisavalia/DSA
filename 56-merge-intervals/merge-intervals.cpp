class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end());
        answer.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            int lastEnd = answer.back()[1];
            if (intervals[i][0] <= lastEnd) {
                answer.back()[1] =
                    max(answer.back()[1], intervals[i][1]);
            }
            else {
                answer.push_back(intervals[i]);
            }
        }
        return answer;
    }
};