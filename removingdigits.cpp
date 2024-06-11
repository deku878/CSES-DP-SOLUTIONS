#include <iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<queue>
using namespace std;
 
int main() {
   // your code goes here
    long long int n;
    cin>>n;
    queue<pair<int,int>>q;
    q.push({n,0});
    vector<bool>vis(n+1,false);
    long long int ans=INT_MAX;
    while(!q.empty()){
        auto y=q.front();
        int num=y.first;
        string x=to_string(y.first);
        q.pop();
        if(num==0){
            ans=y.second;
            break;
        }
        for(int i=0;i<x.size();i++){
            num-=x[i]-'0';
            if(!vis[num]){
            q.push({num,y.second+1});
            vis[num]=true;
            }
            num+=x[i]-'0';
        }
    }
    cout<<ans<<endl;
   return 0;
}