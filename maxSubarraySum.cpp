#include<bits/stdc++.h>
using namespace std;

//dp with o(n) space
int getSum(vector<int>v){
	vector<int>dp(v.size());
	dp[0]=v[0]>=0?v[0]:0;
	int ans=0;
	for(int i=1;i<v.size();i++){
		dp[i]=dp[i-1]+v[i];
		if(dp[i]<0)
			dp[i]=0;
		ans=max(ans,dp[i]);
	}
	return ans;
}

//dp with o(1) space
int getSumOptimimzed(vector<int>&v){
	int cmax, gmax=0;
	cmax=v[0]>=0?v[0]:0;
	for(int i=0;i<v.size();i++){
		cmax=cmax+v[i];
		if(cmax<0)
			cmax=0;
		gmax=max(gmax,cmax);
	}
	//if all elements negative
	int negCount=0;
	int minNegElement=INT_MIN;
	for(int i=0;i<v.size();i++){
		if(v[i]<0){
			negCount++;
			minNegElement=max(v[i],minNegElement);
		}
	}
	if(negCount==v.size()){
		return minNegElement;
	}
	
	return gmax;
}

int main(){
	vector<int>v{-2, -3,  -1, -2,  -3};
	int ans=getSum(v);
	int ans1=getSumOptimimzed(v);
	cout<<ans<<'\n';
	cout<<ans1<<'\n';
}