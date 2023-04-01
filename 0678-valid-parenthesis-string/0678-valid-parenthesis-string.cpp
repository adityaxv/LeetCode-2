class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int lmn = 0, lmx = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                lmn++, lmx++;
            }
            else if(s[i] == ')'){
                lmn--; lmx--;
            }
            else{
                lmn--; lmx++;
            }
            lmn = max(lmn, 0);
            if(lmx < 0){
                return false;
            }
        }
        if(lmn == 0){
            return true;
        }
        return false;
    }
};