class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int prev2 = 0;
        int prev1 = 0;
        for (int i = 0; i < n; i++) {  
            int robCurrent = nums[i] + prev2;
            int notRobCurrent = prev1;
            int current = max(robCurrent, notRobCurrent);
            prev2 = prev1;
            prev1 = current;
        }
        return prev1;
    }
};