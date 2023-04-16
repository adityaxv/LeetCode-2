class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        dfs(ans, temp, s, 0);
        return ans;
    }
    
    void dfs(vector<vector<string>>& ans, vector<string>& temp, string s, int start) {
        if (start == s.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (is_pal(i, start, s) == 1) {
                temp.push_back(s.substr(start, i - start + 1));
                dfs(ans, temp, s, i + 1);
                temp.pop_back();
            }
        }
    }
    
    bool is_pal(int i, int start, string s) {
        while (start < i) {
            if (s[start++] != s[i--]) {
                return false;
            }
        }
        return true;
    }
};