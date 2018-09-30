class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int max = 0;
        int min = 10000;
        for(int i = 0; i < A.size(); ++i) {
            if(A[i] > max) max = A[i];
            if(A[i] < min) min = A[i];
        }
        int res = max - min - 2 * K;
        return res >= 0 ? res: 0;
    }
};