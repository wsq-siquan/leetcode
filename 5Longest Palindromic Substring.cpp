#include<string>
#include<cstring>
#include<iostream>
using namespace std;

    //string res[1000][1000];
    string longestPalindrome(string s) {
        string res = "";
        int len = s.length();
        if (len == 1) return s;
        if (len == 0) return res;
        //res = s[0];
        for(int i = 0; i < len; ++i) {
            int j = 0;
            while(i - j >= 0 && i + j <len) {
                if(s[i - j] == s[i + j]) {
                    string t = s.substr(i - j, 2 * j + 1);
                    cout << t <<"\t"<< i << j<< endl;
                    if(res.length() < t.length()) res = t;
                    cout << res <<"\tone"<< i << j<< endl;
                    j++;
                } else {
                    j = 0;
                    break;
                }
            }
            j = 0;
            while(i - j >= 0 && i + j + 1 < len) {
                //j = 0;
                if(s[i - j] == s[i + j + 1]) {
                    string t = s.substr(i - j, 2 * (j + 1));
                    if(res.length() < t.length()) res = t;
                    j++;
                } else {
                    j = 0;
                    break;
                }
            }
        }
        return res;
    }




    int main() {
        //string x = "babaddtattarrattatddetartrateedredividerb";
        string x;
        x= "aabaaa";
        string a = "dd", b= "aaddaa";
        string res =  longestPalindrome(x);
        cout << endl;
        cout << res;

    }
