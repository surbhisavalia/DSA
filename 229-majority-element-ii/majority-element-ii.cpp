class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> count;
        int n = nums.size();
        for(int i = 0;i<nums.size();i++){
            count[nums[i]]++;
        }
        vector<int> ans;
        int use = n/3;

        for(auto it = count.begin(); it!=count.end();it++){
            if(it->second > use){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};