#include<iostream>
#include<vector>
#include<stack>
#include<utility>
using namespace std;



int mod = 1000000007;
    int sumSubarrayMins(vector<int>& A) {
        int s = A.size();
        stack<pair<int, int>> l,r;
        vector<int> left(s), right(s);
        l.push(pair<int, int>(A[0],1));
        //int last =A[0];
        left[0] = 1;
        for(int i= 1; i < s; ++i) {
            if(A[i] > l.top().first){
                l.push(pair<int, int>(A[i], 1));
                left[i] = 1;
            } else {
                int c = 1;
                while(!l.empty() && A[i] <= l.top().first) {
                    c +=  l.top().second;
                    l.pop();
                }
                l.push(pair<int, int>(A[i], c));
                left[i] = c;
            }
        }
        r.push(pair<int, int>(A[s-1], 1));
        right[s-1] = 1;
        for(int i = s-2; i >=0; i--) {
            if(A[i] >= r.top().first) {
                r.push(pair<int, int>(A[i],1));
                right[i] = 1;
            } else {
                int c = 1;
                while(!r.empty() && A[i] < r.top().first) {
                    c += r.top().second;
                    r.pop();
                }
                r.push(pair<int, int>(A[i], c));
                right[i] = c;
            }
        }
        int res =0;
        for(int i = 0; i < s; ++i) {
            res += (right[i] * left[i]) % mod * A[i] % mod;
            cout << res << "\t" << left[i] << "\t" << right[i] << "\t" << A[i] << endl;
        }
        return res;

    }


int main() {
    vector<int> a;
    a.push_back(3);
    a.push_back(1);
    a.push_back(2);
    a.push_back(4);

    int res = 0;
    res = sumSubarrayMins(a);
    cout << res << endl;
}
