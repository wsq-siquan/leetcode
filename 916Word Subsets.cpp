class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int sizea = A.size();
        int sizeb = B.size();
        vector<string> res;
        int a[26];
        int b[10005][26];
        int bb[26];
        for(int i=0;i < 26; ++i) {
            bb[i] = 0;
        }
        for(int i= 0; i< 10005; ++i) {
        	for(int j = 0; j < 26; ++j) {
        		b[i][j] = 0;
        	}
        }
        int bmax = 0;
        int bmin = 1000;
        for(int j = 0; j < sizeb; ++j) {
        		int sizex = B[j].size();
        		for(int k = 0; k < sizex; ++k) {
        			b[j][B[j][k] - 'a']++;
        		}
            for(int q = 0; q < 26; ++q) {
                bb[q] = max(bb[q], b[j][q]);
            }
            bmax = max(bmax, sizex);
            bmin = min(bmin, sizex);
        }


        for(int i= 0; i < sizea; ++i) {
            if(A[i].size() < bmax ) continue;
        	for(int j = 0; j < 26; ++j) {
        		a[j] = 0;
        		//b[j] = 0;
        	}
        	int sizes = A[i].size();
        	for(int k=0; k < sizes; ++k) {
        		a[A[i][k]-'a']++;
        	}
        	bool flag = true;
        	for(int j= 0; j < 26; ++j) {
        		if(bb[j] > a[j]) flag = false;
        		if(flag == false) break;
        	}
        	if(flag == true) res.push_back(A[i]);
        }
        return res;
    }
};