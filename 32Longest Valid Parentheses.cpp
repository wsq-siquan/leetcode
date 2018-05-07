#include<iostream>
#include<stack>
#include<cstdio>
#include<string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        std::stack<int> st;
        st.push(-1);
        int ss = s.size(); // string size
        for(int i = 0; i < ss; ++i) {
            if(st.top() == -1 || s[i] == '(') {
                st.push(i);
            } else {
                if(s[st.top()] == '(') st.pop();
                else st.push(i);
            }
        }
        int r = ss;
        int res = 0;
        while(!st.empty()) {
            int t = st.top();
            int diff = r - t - 1;
            res = res > diff ? res : diff;
            r = t;
            st.pop();
        }
        return res;

    }
};
