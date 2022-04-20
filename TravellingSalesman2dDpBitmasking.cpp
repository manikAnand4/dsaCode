#include<bits/stdc++.h>
using namespace std;

int getcost(vector<vector<int>>&cost, int city, int mask, vector<vector<int>>&dp, int &VISITED_ALL){
	if(VISITED_ALL==mask){
		return cost[city][0];
	}
	if(dp[mask][city]!=-1)
		return dp[mask][city];
	int ans=INT_MAX;
	for(int i=0;i<cost.size();i++){
		if((mask&(1<<i))==0){
			int temp=cost[city][i]+getcost(cost,i,mask|(1<<i),dp,VISITED_ALL);
			ans=min(ans, temp);
		}
	}
	return dp[mask][city]=ans;
}

int main(){
	vector<vector<int>> cost{
		{0,20,42,25},
		{20,0,30,34},
		{42,30,0,10},
		{25,34,10,0}
	};
	int n=cost.size();
	int VISITED_ALL=(1<<n)-1;
	vector<vector<int>>dp(pow(2,n),vector<int>(n,-1));
	// for(int i=0;i<dp.size();i++){
	// 	for(int j=0;j<dp[0].size();j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	cout<<getcost(cost, 0, 1, dp, VISITED_ALL)<<endl;
	// for(int i=0;i<dp.size();i++){
	// 	for(int j=0;j<dp[0].size();j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
}