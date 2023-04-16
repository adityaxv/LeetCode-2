class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> pr;
        for (int i = 0; i < ages.size(); i++) {
            pr.push_back({ages[i], scores[i]});
        }
        sort(pr.begin(), pr.end());
        int n = ages.size(), ans = 0;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = pr[i].second;
        }
        for (int i = 0; i < n; i++) {
            for (int k = i - 1; k >= 0; k--) {
                if (pr[i].second >= pr[k].second) {
                    dp[i] = max(dp[i], dp[k] + pr[i].second);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};