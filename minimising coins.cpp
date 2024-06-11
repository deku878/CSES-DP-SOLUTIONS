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
    vector<long long int>dp(x+1,INT_MAX);
    dp[0]=0;
    for(int i=0;i<=x;i++){
       for(int j=0;j<n;j++){
           if(i+c[j]<=x){dp[i+c[j]]=min(1+dp[i],dp[i+c[j]]);}
}
}
if(dp[x]==INT_MAX){
    cout<<-1<<endl;
}
else{
    cout<<dp[x]<<endl;
}
   return 0;
}