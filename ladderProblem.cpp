#include<bits/stdc++.h>
using namespace std;

//rec
int getAns(int n, int k){
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	int ans=0;
	for( int i=1;i<=k;i++){
		ans=ans+getAns(n-i,k);
	}
	return ans;
}

//dp
int getAnsDP(int n, int k, vector<vector<int>>&dp){
	if(n==0)
		return 1;
	if(n<0)
		return 0;
	if(dp[n][k]!=-1)
		return dp[n][k];
	int ans=0;
	for( int i=1;i<=k;i++){
		ans=ans+getAnsDP(n-i,k,dp);
	}
	return dp[n][k]=ans;
}

int main(){
	int n=25,k=5;
	cout<<getAns(n,k)<<endl;
	vector<vector<int>> dp(26,vector<int>(6,-1));
	cout<<getAnsDP(n,k,dp)<<endl;
}