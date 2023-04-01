class Solution {
public:
    int minimumKeypresses(string s) {
        vector<int> freq(26);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        sort(freq.rbegin(), freq.rend());
        int ans = 0, mul = 0;
        for (int i = 0; i < 26; i++) {
            if (i % 9 == 0) {
                mul++;
            }
            ans +=  mul * freq[i];
        }
        return ans;
    }
};

// my solution...
// class Solution {
// public:
//     int minimumKeypresses(string s) {
//         unordered_map<char, int> mp;
//         priority_queue<pair<int, int>> pq;
//         for(int i=0; i<s.size(); i++){
//             mp[s[i]]++;
//         }
//         for(auto i:mp){
//             pq.push({i.second, i.first});
//         }
//         int ans = 0, cnt = 1;
//         while(pq.size()){
//             if(cnt <= 9) { 
//                 ans += pq.top().first;
//             } 
//             else if (cnt <= 18) {
//                 ans += pq.top().first * 2;
//             }
//             else {
//                 ans += pq.top().first * 3;
//             }
//             cnt++;
//             pq.pop();
//         }        
//         return ans;
//     }
// };