#include<iostream>
#include<string>
using namespace std;
int main() {
    int xx[10000];
    string x = "b";
    xx[x[0]]=1;
    cout <<  xx[x[0]]<< endl;
}

class Solution {
public:
    int lengthOfLongestSubstring(string x) {
        int ap[256];
        int res=0;
        int len = x.length();
        if(len==0) return res;
        for(int i = 0; i < 256; ++i) {
            ap[i]=-1;
        }
        int tr = 0;
        int left=0;
        for(int i = 0; i < len; ++i) {
            if(ap[x[i]]== -1) {
                ap[x[i]] = i;
                tr++;
            } else {
                left = left > ap[x[i]] ? left : ap[x[i]];
                tr = i - left;
                ap[x[i]] = i;
            }
            res = res > tr ? res : tr;
        }
        return res;
    }
};
