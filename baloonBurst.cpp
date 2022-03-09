#include<bits/stdc++.h>
using namespace std;

//recursive soln very very slow
int getAns(vector<int>nums){
    if(nums.size()==1)
        return nums[0];
    int curr=0;
    for(int i=0;i<nums.size();i++){
        vector<int>temp=nums;
        temp.erase(temp.begin()+i);
        int prod=nums[i];
        if(i-1>=0)
            prod=prod*nums[i-1];
        if(i+1<nums.size())
            prod=prod*nums[i+1];
        curr=max(curr,prod+getAns(temp));
        temp=nums;
    }
    return curr;
}

//dp bottom up
int getAnsdp(vector<int>nums){
    vector<int>arr{1};
    for(int i=0;i<nums.size();i++){
        arr.push_back(nums[i]);
    }
    arr.push_back(1);

    vector<vector<int>>dp(nums.size()+2, vector<int>(nums.size()+2,0));
    int n=nums.size();
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            for(int k=i;k<=j;k++){
                dp[i][j]=max(dp[i][j], arr[i-1]*arr[k]*arr[j+1]+dp[i][k-1]+dp[k+1][j]);
            }
        }
    }
    for(int i=0;i<n+2;i++){
        for(int j=0;j<n+2;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[1][n];
}

//top down
int getAnsTopDown(vector<int>&nums, int s, int e, vector<vector<int>>&dp){
    if(s>e){
        return dp[s][e];
    }
    if(dp[s][e]!=0)
        return dp[s][e];
    for(int i=s;i<=e;i++){
        dp[s][e]=max(dp[s][e], nums[s-1]*nums[i]*nums[e+1]+getAnsTopDown(nums,s,i-1,dp)+getAnsTopDown(nums,i+1,e,dp));
    }
    return dp[s][e];
}

int maxCoins(vector<int> nums) {
    vector<vector<int>>dp(nums.size()+2, vector<int>(nums.size()+2,0));
    vector<int>arr{1};
    for(int i=0;i<nums.size();i++){
        arr.push_back(nums[i]);
    }
    arr.push_back(1);
    int ans=getAnsTopDown(arr,1,nums.size(),dp);
    int ans1=getAnsdp(nums);
    cout<<ans1<<endl;   
    return ans;
}

int main(){
    cout<<maxCoins({3,1,5,8,8,3,5,99,68,99,79});
}