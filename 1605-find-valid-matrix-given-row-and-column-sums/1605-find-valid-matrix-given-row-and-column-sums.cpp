class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {   
       int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> a(n, vector<int>(m));
        for(int i=0; i<n; i++){
            for(int k=0; k<m; k++){
                int x = min(rowSum[i], colSum[k]);
                a[i][k] = x;
                rowSum[i] -= x;
                colSum[k] -= x;
            }
        }
        return a;
    }
};