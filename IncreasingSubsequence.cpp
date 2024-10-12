#include <iostream>
#include<vector>
#include<climits>
#include<map>
#include<queue>
#include<cmath>
#include<climits>
using namespace std;
 
int main() {
	// your code goes here
    long long int n;
    cin>>n;
    vector<long long int>a(n);
   for(int i=0;i<n;i++){
cin>>a[i];
}
    vector<long long int>res;
    for(int i=0;i<n;i++){
long long int it=lower_bound(res.begin(),res.end(),a[i])-res.begin();
if(it>=res.size()){
res.push_back(a[i]);
}
else{
res[it]=a[i];
}
}
cout<<res.size()<<endl;
	return 0;
}
