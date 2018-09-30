class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
    	int size = A.size();
        vector<int> big(size);
        vector<int> small(size);
        big[0] = A[0];
        small[size-1] = A[size-1];
        for(int i= 1; i < size; ++i) {
        	big[i] = max(A[i], big[i - 1]);
        }
        for(int i = size - 2; i >= 0; i--) {
        	small[i] = min(A[i + 1], small[i + 1]);
        }
        for(int i= 0; i < size; ++i) {
        	if(big[i] <= small[i])
        		return i + 1;
        }
        return 0;
    }
};