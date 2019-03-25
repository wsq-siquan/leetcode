#include<iostream>
#include<cstdio>
using namespace std;

class R{
public:
    int x;
    R(int a= 0) {
        x = a;
    }
};

const R&  ttt(const R& t) {
    static R x;
    x= t;
    return x;
}

bool operator==(const R& a, const R& b) {
    if(a.x == b.x) return true;
    else return false;
}

int div(int nu, int de) {

    int temp = 1;
    int quotient = 0;

    while (de <= nu) {
        de <<= 1;
        temp <<= 1;
    }

    printf("%d %d\n",de,temp);
    while (temp > 1) {
        de >>= 1;
        temp >>= 1;

        if (nu >= de) {
            nu -= de;
            printf("%d %d\n",quotient,temp);
            quotient += temp;
        }
    }

    return quotient;
}

int main() {
    /*int a = 10;
    int b =20;
    R aa = R(a);
    R bb = R(b);

    if(ttt(aa) == ttt(bb))
        cout << "xx" << endl;
    else cout << "aa" << endl;*/
    int a,b;
    cin >> a >>b;
    cout << div(a,b) <<endl;
    //int b = a >>=2;
    //cout << a << endl;

}
