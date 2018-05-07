#include<string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        int gapm = numRows * 2 - 2;
        string res = "";
        for(int i = 0;i < numRows; ++i) {
            int gap = (numRows - i) * 2 - 2;
            int j=i;
            while(j < s.length()) {
                res += s[j];
                if(gap == 0) gap = gapm -gap;
                j+=gap;
                gap = gapm -gap;
            }
        }
        return res;
    }
};
