class Solution {
public:
    bool isPalindrome(string s) {
        string k;
        for (int i = 0; i < s.size(); i++) {
            if ((s[i] >= 97 and s[i] <= 122) or (s[i] >= 65 and s[i] <= 90) or (48 <= s[i] and s[i] <= 57)) {
                k.push_back(tolower(s[i]));
            }
        }
        cout << k << " "; int cnt = 0;
        for (int i = 0; i < k.size() / 2; i++) {
            if (k[i] != k[k.size() - i - 1]) {
                return false;
            }
        }
        return true;
    }
};