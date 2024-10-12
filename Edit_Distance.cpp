#include <bits/stdc++.h>
using namespace std;
 
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
 
bool sortbysec(pair<long long int,long long int>&a,pair<long long int,long long int>&b){
	return a.second>b.second;
}
bool sortus(pair<pair<long long int,long long int>,long long int>&a,pair<pair<long long int,long long int>,long long int>&b){
	
	if(a.second==b.second){
		if(a.first.first>b.first.first){
			return b.second>a.second;
		}
		else{
			return a.second>b.second;
		}
	}
	
	return b.second>a.second;
}
int main() {
 //code by deku878
 //clean code
 //readability gayi cha mudane
 ios_base::sync_with_stdio(false);
 cin.tie(0);
 string s;
 cin>>s;
 string t;
 cin>>t;
 long long int m=s.size();
 long long int n=t.size();
 vector<vector<long long int>>dp(m+1,vector<long long int>(n+1,1e9));
 dp[0][0]=0;
 for(int i=0;i<=m;i++){
 	for(int j=0;j<=n;j++){
 		if(i){
 			dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
 		}
 		if(j){
 			dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
 		}
 		if(i and j){
 			dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(s[i-1]!=t[j-1]));
 		}
 	}
 }
 cout<<dp[m][n]<<endl; 
 return 0;}
