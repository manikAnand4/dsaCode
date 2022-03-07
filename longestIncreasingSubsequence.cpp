#include<bits/stdc++.h>
using namespace std;

int lis(vector<int>&v, int n){
	vector<int>lis(n);
	lis[0]=1;
	for(int i=1;i<v.size();i++){
		lis[i]=1;
		for(int j=0;j<i;j++){
			if(v[j]<v[i]){
				lis[i]=max(lis[j]+1, lis[i]);
			}
		}
	}
	int ans=1;
	for(int i=0;i<n;i++)
		ans=max(ans,lis[i]);
	return ans;
}

int main(){
	vector<int>v{10,9,2,5,3,7,101,18};
	cout<<lis(v,v.size())<<endl;
}