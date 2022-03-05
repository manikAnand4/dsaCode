#include<bits/stdc++.h>
using namespace std;

void getMaxOfMin(vector<int>&v, int k){
	cout<<"in func"<<endl;
	if(k>v.size())
		return ;
	deque<int>dq;
	int i=0;
	vector<int> ans;
	while(i<v.size()){
		while(!dq.empty() && v[dq.back()]>v[i])
			dq.pop_back();
		dq.push_back(i);
		while(!dq.empty() && dq.front()<=(i-k))
			dq.pop_front();
		if(i>=(k-1))
			ans.push_back(v[dq.front()]);
		i++;
	}
	cout<<ans.size()<<endl;
	int fans=INT_MIN;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
		fans=max(fans,ans[i]);
	}

	cout<<endl<<fans<<endl;
}

int main(){
	vector<int>v{8,2,4,2,5,6,3,7,2,3,4,1,8,9};
	// int s;
	// cout<<"enter size"<<endl;
	// cin>>s;
	// for(int i=0;i<s;i++){
	// 	cout<<"enter"<<endl;
	// 	int x;
	// 	cin>>x;
	// 	v.push_back(x);
	// }

	getMaxOfMin(v,3);
}