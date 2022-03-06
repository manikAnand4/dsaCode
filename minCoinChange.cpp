#include<bits/stdc++.h>
using namespace std;
vector<int> curency{1,2,5,10,20,50,100,500,1000,2000};

//top down approach
int getAnsTD(int n, unordered_map<int,int>&um){
	if(n==0)
		return 0;
	if(n<0)
		return INT_MAX;
	if(um[n]!=0)
		return um[n];
	int ans=INT_MAX;
	for(int i=curency.size()-1;i>=0;i--){
		ans=min(ans,getAnsTD(n-curency[i],um));
	}
	return um[n]=ans+1;
}


//bottom up approach
int getAnsBU(int n){
	unordered_map<int,int>um;
	um[0]=0;
	for(int i=1;i<=n;i++){
		int ans=INT_MAX;
		for(int j=0;j<curency.size();j++){
			if(um.find(i-curency[j])!=um.end()){
				ans=min(ans, um[i-curency[j]]);
			}
		}
		ans= ans==INT_MAX?ans:ans+1;
		// cout<<ans<<"  ";
		um[i]=ans;
	}
	return um[n];
}

int main(){
	int n=10234;
	unordered_map<int,int>um;
	cout<<getAnsTD(n,um)<<'\n';
	cout<<getAnsBU(n)<<'\n';
}