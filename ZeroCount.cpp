#include<iostream>
using namespace std;
int zerocount(int L, int K) {
    if (K == 0) {
        return L;
    }
    if (K == L) {
        return 0;
    }
    int max_zeros = 0;
    if (K > 0) {
        max_zeros = 1;
    }
    return max_zeros;
}int main() 
{
    int L, K;
    cin >> L >> K;
    int res = zerocount(L, K);
    cout << res;
    return 0;
}
