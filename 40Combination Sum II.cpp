class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> t;
        sort(candidates.begin(), candidates.end());
        helper(res, t, candidates, 0, target);
        return res;

    }

    void helper(vector<vector<int>> & res, vector<int> t, const vector<int> c, int pos, int remaintarget) { // c means candidates
        if(pos >= c.size()) return;
        if(remaintarget < 0) return;
        for(int i= pos; i < c.size(); ++i) {
            if(c[i] == remaintarget) {
                t.push_back(c[i]);
                if(check(res,t)) {
                    res.push_back(t);
                    return;
                }
                t.pop_back();
            } else {
                t.push_back(c[i]);
                helper(res, t, c, i+1, remaintarget - c[i]);
                //helper(res, t, c, i + 1, remaintarget - c[i]);
                t.pop_back();
            }
        }
    }
    bool check(vector<vector<int>> & res, vector<int> t) {
        for(int i = 0; i < res.size(); ++i) {
            if(t == res[i]) return false;
        }
        return true;
    }
};
