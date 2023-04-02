class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int od = 0, ev = 0;
        for (int i = 0; i < position.size(); i++) {
            if (position[i] % 2 == 0) ev++;
            else od++;
        }
        if (od > 0 and ev > 0) {
            return min(od, ev);
        }
        return 0;
    }
};