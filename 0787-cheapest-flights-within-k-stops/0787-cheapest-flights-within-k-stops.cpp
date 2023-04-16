class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> price(n, INT_MAX);
        price[src] = 0;
        for (int i = 0; i < k + 1; i++) {
            vector<int> temp = price;
            for (auto k : flights) {
                if (price[k[0]] != INT_MAX) {
                    temp[k[1]] = min(temp[k[1]], price[k[0]] + k[2]);
                }
            }
            price = temp;
        }
        if (price[dst] == INT_MAX) {
            return -1;
        }
        return price[dst];
    }
};
