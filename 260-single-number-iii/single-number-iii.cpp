class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int allXor = 0;
        for (int x : nums) {
            allXor = allXor ^ x;
        }
        unsigned int bit = (unsigned int)allXor & 
                           (-(unsigned int)allXor);
        int num1 = 0;
        int num2 = 0;
        for (int x : nums) {
            if ((unsigned int)x & bit) {
                num1 = num1 ^ x;
            }
            else {
                num2 = num2 ^ x;
            }
        }
        return {num1, num2};
    }
};