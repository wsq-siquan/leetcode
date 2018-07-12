#include<iostream>
#include<cstdio>
#include<cstdlib>
 using namespace std;



int res[100000];

int real(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    else {
        if(res[n] == 0) {
            for(int i = 0; i < n - 1; ++i) {
                res[n] += real(i) * real(n - 1 - i);
            }
            return res[n];
        } else {
            return res[n];
        }
    }
}
int numTrees(int n) {
    for (int i = 0; i <= n; ++i) {
        res[i] = 0;
    }
    res[0] = res[1] =1;
    return real(n);
}
