class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int sum = 0, dum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            dum -= nums[i];
            ans.push_back(nums[i]);
            if (sum > dum) break;
        }
        return ans;
    }
};