class Solution {
public:
    int smallestRangeII(vector<int>& A, int k) {
        int n = A.size() -1;
        sort(A.begin(), A.end());
        int res = A[n] - A[0];
        int kk = 2 * k;
        int tmax = A[n];
        int tmin = A[0] + kk;
        int a,b;
        for(int i = 0; i < n ; ++i) {
            a = max(A[i] + kk, tmax);
            b = min(tmin, A[i + 1]);
            res = min(res, a - b);
        }
        return res;
    }
};