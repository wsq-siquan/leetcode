class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        help(nums);
        return res;
    }
    void help(vector<int> & n) {
        if(n.empty()) {
            res.push_back(t);
            return;
        }
        for(int i= 0; i < n.size(); ++i) {
            int x = n[i];
            t.push_back(x);
            n.erase(n.begin() + i);
            help(n);
            n.insert(n.begin() + i,x);
            t.pop_back();
        }
    }
private:
    vector<vector<int>> res;
    vector<int> t;
};
