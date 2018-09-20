class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> t;
        helper(res, t, candidates, 0, target);
        return res;

    }

    void helper(vector<vector<int>> & res, vector<int> t, const vector<int> c, int pos, int remaintarget) { // c means candidates
        if(pos >= c.size()) return;
        if(remaintarget < 0) return;
        //int flag = 1;
        for(int i= pos; i < c.size(); ++i) {
            if(c[i] == remaintarget) {
                t.push_back(c[i]);
                res.push_back(t);
                t.pop_back();
                //flag = 0;
            } else {
                t.push_back(c[i]);
                helper(res, t, c, i, remaintarget - c[i]);
                //helper(res, t, c, i + 1, remaintarget - c[i]);
                t.pop_back();
            }
        }
    }
};
