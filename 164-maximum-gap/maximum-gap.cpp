class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        if (n < 2)
            return 0;
        int minValue = *min_element(nums.begin(), nums.end());
        int maxValue = *max_element(nums.begin(), nums.end());
        if (minValue == maxValue)
            return 0;
        int gap = (maxValue - minValue) / (n - 1);
        if (gap == 0)
            gap = 1;
        int bucketCount = (maxValue - minValue) / gap + 1;

        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);
        vector<bool> used(bucketCount, false);

        for (int num : nums) {
            int index = (num - minValue) / gap;
            bucketMin[index] = min(bucketMin[index], num);
            bucketMax[index] = max(bucketMax[index], num);
            used[index] = true;
        }
        int answer = 0;
        int previousMax = minValue;

        for (int i = 0; i < bucketCount; i++) {
            if (!used[i])
                continue;
            answer = max(answer, bucketMin[i] - previousMax);
            previousMax = bucketMax[i];
        }
        return answer;
    }
};