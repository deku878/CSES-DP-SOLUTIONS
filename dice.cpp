#include <iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;
 
int main() {
	// your code goes here
    long long int n;
    cin>>n;
    long long int mod=1e9+7;
    vector<long long int>dp(n+1,0);
    dp[0]=1;
    for(int i=0;i<=n;i++){
       for(int j=1;j<=6;j++){
           if(i+j<=n){dp[i+j]=(dp[i+j]+dp[i])%mod;}
}
}
cout<<dp[n]%mod<<endl;
	return 0;
}