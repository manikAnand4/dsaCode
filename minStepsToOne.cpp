#include <bits/stdc++.h>
using namespace std;

//dp bottom up
int getAns(int n){
	unordered_map<int,int>um;
	um[2]=1;
	um[3]=1;
	for(int i=4;i<=n;i++){
		int steps=INT_MAX;
		if(i%2==0)
			steps=min(steps, um[i/2]);
		if(i%3==0)
			steps=min(steps, um[i/3]);
		steps=min(steps, um[i-1]);
		steps++;
		um[i]=steps;
	}
	return um[n];
}

//dp top dpwn
int getAnsTopDown(int n, unordered_map<int, int>&um){
	if(n==1)
		return 0;
	if(n==2||n==3)
		return 1;
	if(um[n]!=0)
		return um[n];
	if(n%2==0 && n%3==0)
		um[n]= 1+ min(min(getAnsTopDown(n/2,um),getAnsTopDown(n/3,um)), getAnsTopDown(n-1,um));
	else if(n%2==0)
		um[n]= 1+ min(getAnsTopDown(n/2,um),getAnsTopDown(n-1,um));
	else if(n%3==0)
		um[n]= 1+ min(getAnsTopDown(n-1,um),getAnsTopDown(n/3,um));
	else
		um[n]= 1+ getAnsTopDown(n-1,um);
	return um[n];
}

int main(){
	// int n;
	// cin>>n;
	int n=100;
	cout<<getAns(n)<<'\n';

	unordered_map<int,int> um;
	cout<<getAnsTopDown(n, um)<<'\n';
}