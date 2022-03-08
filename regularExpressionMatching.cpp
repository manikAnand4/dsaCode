#include<bits/stdc++.h>
using namespace std;

//dp soln
bool getAns(int i, int j, string s, string p, vector<vector<int>>&dp){
	if(j==p.size())
		return i==s.size();
	if(dp[i][j]!=-1)
		return dp[i][j];
	bool first_match= i<s.size() && (s[i]==p[j] || p[j]=='.');
	bool ans=false;
	if(j+1<p.size() && p[j+1]=='*'){
		ans=(first_match&&getAns(i+1,j,s,p,dp))||getAns(i,j+2,s,p,dp);
	}
	else{
		ans=first_match&&getAns(i+1,j+1,s,p,dp);
	}
	return dp[i][j]=ans;
}

int main(){
	string s="aab";
	string p="a.*";
	vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
	cout<<getAns(0,0,s,p,dp)<<endl;
}