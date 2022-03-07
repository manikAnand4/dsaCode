#include<bits/stdc++.h>
using namespace std;

int getAnsWhereFirstElementIsGreaterOrEquall(vector<int>&v){
	int n=v.size();
	int marr[n];
	int m=INT_MAX;
	for(int i=n-1;i>=0;i--){
		m=min(m,v[i]);
		marr[i]=m;
	}
	for(int i=0;i<n;i++){
		cout<<marr[i]<<" ";
	}
	cout<<endl;
	int i=0,j=0,ans=0;
	while(i<n && j<n){
		if(v[i]>=marr[j]){
			ans=max(ans,j-i+1);
			j++;
		}
		else{
			i++;
		}
	}
	return ans;
}

int getAnsWhereFirstElementIsLessOrEquall(vector<int>v){
	int n=v.size();
	int marr[n];
	int m=INT_MIN;
	for(int i=n-1;i>=0;i--){
		m=max(m, v[i]);
		marr[i]=m;
	}
	int i=0,j=0,ans=0;
	while(i<n && j<n){
		if(marr[j]>=v[i]){
			ans=max(ans,j-i+1);
			j++;
		}
		else{
			i++;
		}
	}
	return ans;
}

int main(){
	vector<int>v{34, 8, 10, 3, 2, 80, 30, 33, 1};
	cout<<getAnsWhereFirstElementIsGreaterOrEquall(v)<<endl;
	cout<<getAnsWhereFirstElementIsLessOrEquall(v)<<endl;	
}