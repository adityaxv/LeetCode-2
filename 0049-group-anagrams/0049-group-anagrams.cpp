class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> freq(26);
            for (int k = 0; k < strs[i].size(); k++) {
                freq[strs[i][k] - 'a']++;             
            }
            mp[freq].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto const [key, value] : mp) {
            vector<string> temp;
            for (string s : value) {
                temp.push_back(s);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};