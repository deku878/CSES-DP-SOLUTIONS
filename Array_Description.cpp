#include <bits/stdc++.h>
using namespace std;
// ================================== take ip/op like vector,pairs directly!==================================
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
 
long long int mod=1e9+7;
//some maths
//mod add a ,  b ((a%MOD)+(b%MOD))%MOD
//modd sub  a ,  b =((a%MOD)-(b%MOD)+MOD)%MOD
//mod mull a , b =((a%MOD)*(b%MOD))%MOD
 
//segment tree lol
#ifndef SEGMENTTREE_H
 
#define SEGMENTTREE_H
 
#define left(i) (2*i + 1)
 
#define right(i) (2*i + 2)
 
#define parent(i) ((i-1)/2)
 
#include <vector>
 
 
template<class T>
 
class SegmentTree
{
    public:
        //tree constructors.
        SegmentTree(std::vector<T> data, T value, T (*combine)(T obj1, T obj2));
        
        SegmentTree(T ar[], int n, T value, T (*combine)(T obj1, T obj2));
        
        //query the range l to r, 0 based array indexing.
        T query(int l, int r);
        
        //update the element at index idx to val.
        
        void update(int idx, T val);
        
        ///TODO lazy propagation
    
    private:
        //represents the segment tree.
        
        T *tree;
    
        //builds the segment tree.
        
        void buildTree(std::vector<T> data);
        
        //size of the segment tree array.
        
        int segTreeSize;
    
        //extra nodes must be added to array to make its size a power of 2
        //this is the value to be filled for the those nodes.
        
        T valueForExtraNodes;
    
        //specifies how to combine child node results to form parent node result.
        
        T (*combine)(T obj1, T obj2);
    
        //used to calculate the size of array needed to store the tree.
        
        int calculateSize(int n);
    
        //helps to solve a range query.
        
        T queryHelper(int l,int r, int st, int ed, int node);
};
 
template<class T> SegmentTree<T>::SegmentTree(std::vector<T> data,
                                                T value, T (*combine)(T obj1, T obj2))
{
   this->combine = combine;
   
   valueForExtraNodes = value;
   
   segTreeSize = calculateSize(data.size());
   
   buildTree(data);
}
 
template<class T> SegmentTree<T>::SegmentTree(T ar[], int n,
                                            T value, T (*combine)(T obj1, T obj2))
{
   this->combine = combine;
   
   valueForExtraNodes = value;
   
   segTreeSize = calculateSize(n);
 
   std::vector<T> data;
   
   for(int i = 0; i < n; i++)
         data.push_back(ar[i]);
 
   buildTree(data);
}
 
 
template<class T> int SegmentTree<T>::calculateSize(int n)
{
    int pow2 = 1;
    
    while( pow2 < n)
    {
        pow2 = pow2 << 1;
    }
    
    return 2*pow2 - 1;
}
 
template<class T> T SegmentTree<T>::query(int l, int r)
{
    int st = 0, ed = segTreeSize/2;
    
    return queryHelper(l, r, st, ed, 0);
}
 
template<class T> T SegmentTree<T>::queryHelper(int l,int r, int st, int ed, int node)
{
    if( (r < st) || (l > ed) || (l > r) )
        return valueForExtraNodes;
    
    if(st >= l && ed <= r)
        return tree[node];
    
    T leftVal = queryHelper(l, r, st, (st + ed)/2, left(node));
    
    T rightVal = queryHelper(l, r, (st+ed)/2 + 1, ed, right(node));
    
    return combine(leftVal, rightVal);
}
 
template<class T> void SegmentTree<T>::buildTree(std::vector<T> data)
{
   int n = data.size();
   
   tree = new T[segTreeSize];
   
   int extraNodes = (segTreeSize/2 + 1) - n;
   
   
   for(int i = segTreeSize - 1; i >= 0; i--)
   {
       
       if(extraNodes>0)
           
           {
               
               tree[i] = valueForExtraNodes;
               
               extraNodes--;
           
           }
       
       else if(n>0)
           {
               tree[i] = data[n-1];
               
               n--;
           
           }
       
       else
           
           tree[i] = combine(tree[left(i)], tree[right(i)]);
   }
}
 
template<class T> void SegmentTree<T>::update(int idx, T val)
{
    int segTreeIdx = (segTreeSize/2) + idx;
    
    tree[segTreeIdx] = val;
    
    while(parent(segTreeIdx) >= 0)
    {
        segTreeIdx = parent(segTreeIdx);
        
        if(right(segTreeIdx) < segTreeSize)
          tree[segTreeIdx] = combine(tree[left(segTreeIdx)], tree[right(segTreeIdx)]);
        
        if(segTreeIdx == 0)
            
            break;
    }
}
 
#endif // SEGMENTTREE_H
 
long long int miny(long long int x,long long int y){
	return min(x,y);
}
 
int main() {
	long long int mod=1e9+7;
	long long int n,m;
	cin>>n>>m;
	vector<vector<long long int>>dp(n,vector<long long int>(m+1,0));
	long long int x;
	cin>>x;
	if(x==0){
		for(int i=0;i<=m;i++){
			dp[0][i]=1;
		}
	}
	else{
		dp[0][x]=1;
	}
	for(int i=1;i<n;i++){
		long long int x;
		cin>>x;
		if(x==0){
			for(long long int j=1;j<=m;j++){
				for(int k:{j-1,j,j+1}){
					if(k>=1 and k<=m){
						(dp[i][j]+=dp[i-1][k])%=mod;
					}
				}
			}			
		}
		else{
			for(int k:{x-1,x,x+1}){
				if(k>=1 and k<=m){
					(dp[i][x]+=dp[i-1][k])%=mod;
				}
			}
		}
	}
	long long int ans=0;
	for(int j=1;j<=m;j++){
		(ans+=dp[n-1][j])%=mod;
	}
	cout<<ans<<endl;
}
