#include<bits/stdc++.h>
using namespace std;

int getAns(vector<int>&l, vector<int>&p, int n, vector<int>&dp){
	if(dp[n]!=-1)
		return dp[n];
	int mans=0;
	for(int i=0;i<n;i++){
		int ans=0;
		if(n>=l[i]){
			ans=ans+p[i]+getAns(l,p,n-l[i], dp);
			mans= max(mans, ans);
		}
	}
	return dp[n]=mans;
}

int getAnsBU(vector<int>&l, vector<int>&p, int n){
	int dp[n+1];
	dp[0]=0;
	for(int i=1;i<=n;i++){
		int ans=INT_MIN;
		for(int j=0;j<i;j++){
			int cut=j+1;
			int cans=p[j]+dp[i-cut];
			ans=max(cans,ans);
		}
		dp[i]=ans;
	}
	return dp[n];
}

int main(){
	int n=8;
	vector<int>length{1,2,3,4,5,6,7,8};
	vector<int>price{1,5,8,9,10,17,17,20};
	vector<int>dp(n+1,-1);
	// int ans=getAns(length, price, n, dp);
	int ans=getAnsBU(length, price, n);
	cout<<ans<<'\n';
}
