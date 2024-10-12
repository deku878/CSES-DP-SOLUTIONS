#include <iostream>
#include<vector>
#include<climits>
#include<map>
#include<queue>
#include<cmath>
#include<climits>
using namespace std;
 
int main() {
    long long int mod=1e9+7;
	// your code goes here
    long long int n;
    cin>>n;
    vector<vector<char>>a(n,vector<char>(n,'.'));
    vector<vector<long long int>>dp(n,vector<long long int>(n,0));
    dp[0][0]=1;
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
cin>>a[i][j];
}
}
if(a[0][0]=='*'){
cout<<0<<endl;
}
else if(a[a.size()-1][a.size()-1]=='*'){
cout<<0<<endl;
}
else{
for(int i=0;i<n;i++)
{
if(a[0][i]=='*'){
dp[0][i]=0;
break;
}
dp[0][i]=1;
}
 
for(int i=0;i<n;i++)
{
if(a[i][0]=='*'){
dp[i][0]=0;
break;
}
dp[i][0]=1;
}
 
for(int i=1;i<n;i++){
for(int j=1;j<n;j++){
if(a[i][j]!='*'){
dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
}
}
}
cout<<dp[n-1][n-1]%mod<<endl;
}
	return 0;
}
