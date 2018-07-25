class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string p = strs[0];
        for(int i = 1; i < strs.size(); ++i) {
            for(int j=0; j < p.size(); ++j) {
                if(strs[i][j] != p[j]) {
                    p.resize(j);
                    break;
                }
            }
        }
        return p;
    }
};
