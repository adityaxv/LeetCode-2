class Solution {
public:
    string decodeString(string s) {
        stack<char> sk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ']') {
                sk.push(s[i]);
            }
            else {
                string temp = "";
                while (sk.top() != '[') {
                    temp = sk.top() + temp;
                    sk.pop();
                }
                sk.pop();
                string number = "";
                while (sk.size() and isdigit(sk.top())) {
                    number = sk.top() + number;
                    sk.pop();
                }
                int nums = stoi(number);
                while (nums--) {
                    for (int k = 0; k < temp.size(); k++) {
                        sk.push(temp[k]);
                    }
                }
            }
        }
        string ans = "";
        while (sk.size()) {
            ans = sk.top() + ans;
            sk.pop();
        }
        return ans;
    }
};