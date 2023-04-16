class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(*max_element(days.begin(), days.end()) + 1, -1);
        for (int i = 0; i < days.size(); i++) {
            dp[days[i]] = 0;
        }
        dp[0] = 0;
        for (int i = 1; i < dp.size(); i++) {
            if (dp[i] == -1) {
                dp[i] = dp[i - 1];
            }
            else {
                dp[i] = min({costs[0] + (i >= 1 ? dp[i - 1] : 0), 
                             costs[1] + (i >= 7 ? dp[i - 7] : 0), 
                             costs[2] + (i >= 30 ? dp[i - 30] : 0)});
            }
        }
        return dp.back();
    }
};