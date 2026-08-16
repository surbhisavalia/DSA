class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.length();
        vector<bool> possible(n + 1, false);
        possible[0] = true;

        for (int i = 1; i <= n; i++) {
            for (string word : wordDict) {
                int len = word.length();
                if (i >= len && possible[i - len]) {
                    if (s.substr(i - len, len) == word) {
                        possible[i] = true;
                        break;
                    }
                }
            }
        }
        return possible[n];
    }
};