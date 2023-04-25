class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.size();
        int left = 0, right = 0, ans = 0;
        unordered_map<char, int> mp;
        ans = 0;
        while (right < n) {
            mp[s[right]]++;
            while (mp.size() > 2) {
                mp[s[left]]--;
                if (mp[s[left]] == 0) {
                    mp.erase(s[left]);
                }
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};