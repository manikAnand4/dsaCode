#include<bits/stdc++.h>
using namespace std;

int myfunc(vector<int>&v, int s,int e,int i, vector<vector<int>>&dp){
	if(i>v.size())
		return 0;
	if(dp[s][e]!=-1)
		return dp[s][e];
	int f=v[s];
	int l=v[e];
	int ans1=(l*i)+myfunc(v,s,e-1,i+1, dp);
	int ans2=(f*i)+myfunc(v,s+1,e, i+1, dp);
	return dp[s][e]=max(ans1,ans2);
}

int main(){
	vector<int>v{2,3,5,1,4};
	vector<vector<int>>dp(
		5, 
		vector<int>(5,-1)
	);
	cout<<myfunc(v,0,v.size()-1,1,dp)<<endl;
}
