class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        help(1, k, n);
        return res;
    }

    void help(int begin, int rest, int n) {
        if(rest == 0) {
            res.push_back(t);
        } else {
            for(int i = begin; i < n - rest + 2; ++i) {
                t.push_back(i);
                help(i + 1, rest - 1, n);
                t.pop_back();
            }
        }
    }

private:
    vector<vector<int>> res;
    vector<int> t;
};
