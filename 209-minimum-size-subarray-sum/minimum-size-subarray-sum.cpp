class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int left = 0;
        int sum = 0;
        int answer = nums.size() + 1;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                int length = right - left + 1;
                answer = min(answer, length);
                sum -= nums[left];
                left++;
            }
        }
        if (answer == nums.size() + 1) {
            return 0;
        }
        return answer;
    }
};