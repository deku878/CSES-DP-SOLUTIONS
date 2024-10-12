#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
const ll mod = 1e9 + 7;
const ll N = 1e6 + 10;
 
 
int main() {
    ll OneBlock[N], TwoBlocks[N];
    OneBlock[1] = TwoBlocks[1] = 1;
 
    for (int i = 2; i < N; i++) {
    	//isme dekho agar neeche bas ek hi block hh toh upar pe bas 2 one block aur ek two block
        OneBlock[i] = (2 * OneBlock[i - 1] + TwoBlocks[i - 1]) % mod;
        //isme dekho 4 two blocks wale cases me multiply honge aur ek ek oneblock
        TwoBlocks[i] = (4 * TwoBlocks[i - 1] + OneBlock[i - 1]) % mod;
    }
 
    int t;
    cin >> t;
    while (t--){
        int n; cin >> n;
        cout << (OneBlock[n] + TwoBlocks[n]) % mod << "\n";
    }       
    return 0;
}
