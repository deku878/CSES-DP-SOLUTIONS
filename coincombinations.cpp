#include <iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;
 
int main() {
   // your code goes here
    long long int n,x;
    cin>>n>>x;
    vector<long long int>c(n);
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    long long int mod=1e9+7;
    vector<long long int>dp(x+1,0);
    dp[0]=1;
    for(int i=0;i<=x;i++){
       for(int j=0;j<n;j++){
           if(i+c[j]<=x){dp[i+c[j]]=(dp[i]+dp[i+c[j]])%mod;}}}
    cout<<dp[x]%mod<<endl;
   return 0;
}