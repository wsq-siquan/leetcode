#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std:

int firstMissingPositive(int* n, int ns) {
    int t;
    for(int i = 0; i < ns; ++i) {
        t = n[i];
        n[i] = 0;
        while(t > 0 && t <= ns && n[t - 1] != t) {
            int x = n[t - 1];
            n[t - 1] = t;
            t = x;
        }
    }
    for(int i = 0; i < ns; ++i) {
        if(n[i] != i + 1) return i + 1;
    }
    return ns + 1;
}
