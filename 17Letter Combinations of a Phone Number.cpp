class Solution {
public:
    vector<string> letterCombinations(string digits) {

        vector<string> res;
        if(digits == "") return res;
        string t;
        helper(res, t, digits);

        return res;

    }

    void helper(vector<string> & res, string ans, string left) {
        if(left.size() == 0) {
            res.push_back(ans);
        } else {
            if(left[0] == '2') {
                helper(res, ans + "a", left.substr(1));
                helper(res, ans + "b", left.substr(1));
                helper(res, ans + "c", left.substr(1));
            } else if(left[0] == '3') {
                helper(res, ans + "d", left.substr(1));
                helper(res, ans + "e", left.substr(1));
                helper(res, ans + "f", left.substr(1));
            } else if(left[0] == '4') {
                helper(res, ans + "g", left.substr(1));
                helper(res, ans + "h", left.substr(1));
                helper(res, ans + "i", left.substr(1));
            } else if(left[0] == '5') {
                helper(res, ans + "j", left.substr(1));
                helper(res, ans + "k", left.substr(1));
                helper(res, ans + "l", left.substr(1));
            } else if(left[0] == '6') {
                helper(res, ans + "m", left.substr(1));
                helper(res, ans + "n", left.substr(1));
                helper(res, ans + "o", left.substr(1));
            } else if(left[0] == '7') {
                helper(res, ans + "p", left.substr(1));
                helper(res, ans + "q", left.substr(1));
                helper(res, ans + "r", left.substr(1));
                helper(res, ans + "s", left.substr(1));
            } else if(left[0] == '8') {
                helper(res, ans + "t", left.substr(1));
                helper(res, ans + "u", left.substr(1));
                helper(res, ans + "v", left.substr(1));
            } else if(left[0] == '9') {
                helper(res, ans + "w", left.substr(1));
                helper(res, ans + "x", left.substr(1));
                helper(res, ans + "y", left.substr(1));
                helper(res, ans + "z", left.substr(1));
            }
        }
    }
};
