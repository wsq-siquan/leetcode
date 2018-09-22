class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";

        vector<int> seq(n, 1);
        help(k, seq);
        s= cov(seq);
        return s;
    }

    void help(int k, vector<int> & seq) {
        int i;
        for(i= 9; i > 0; --i) {
            if(k > x[i]) break;
        }
        if(k % x[i] == 0) {
            seq[i] = k / x[i];
            for(int j = i - 1; j >=0; j--) {
                seq[j] = j+ 1;
            }
        } else{
            int off = k / x[i] + 1;
            seq[i] = off;
            k %= x[i];
            help(k,seq);
        }
    }

    string cov(vector<int> & seq) {
        string  s= "";
        vector<int> reg;
        int n = seq.size();
        for(int i =0;i <= n;++i) {
            reg.push_back(i); // 0 1 2 3 4 5 6 7 8 9 n
        }

        for(int i = n - 1; i >= 0;--i) {
            s += to_string(reg[seq[i]]);
            reg.erase(reg.begin() + seq[i]);
        }
        return s;
    }
private:
    int x[10] = {1 ,1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
};
