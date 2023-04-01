class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(int i=0; i<n; i++){
            mp[s[i]] = i;
        }
        int prev = -1, end = 0;
        vector<int> ans;
        for(int i=0; i<n; i++){
            end = max(end, mp[s[i]]);
            if(end == i){
                ans.push_back(end - prev);
                prev = i;
            }
        }
        return ans;
    }
};