class Solution {
public:
    static bool cmp(string &a, string &b) {
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        int ans = 0;
        sort(words.begin(), words.end(), cmp);
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); i++) {
            for (int k = 0; k < words[i].size(); k++) {
                string temp1 = words[i].substr(0, k);
                string temp2 = words[i].substr(k + 1);
                string total = temp1 + temp2;
                mp[words[i]] = max(mp[words[i]], mp[total] + 1);
            }
            ans = max(ans, mp[words[i]]);
        }
        return ans;
    }
};