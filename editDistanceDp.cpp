#include<bits/stdc++.h>
using namespace std;

int getans(string w1, string w2, int i, int j, vector<vector<int>>&dp){
    if(i<=0)return j;
    if(j<=0)return i;

    if(dp[i][j]!=-1)
        return dp[i][j];
    
    int ans;
    if(w1[i-1]==w2[j-1])
        ans=getans(w1,w2,i-1,j-1,dp);
    else
        ans=1+min( 
            min(getans(w1,w2,i-1,j-1,dp), getans(w1,w2,i-1,j,dp)),
            getans(w1,w2,i,j-1,dp)
        );
    return dp[i][j]=ans;
    
}
int main() {
    string w1="dinitrophenylhydrazinemanikanandmanikanand";
    string w2="acetylphenylhydrazinegarimaanandgarimaanand";
    vector<vector<int>>dp(w1.size()+1,vector<int>(w2.size()+1,-1));
    cout<<getans(w1,w2,w1.size(),w2.size(),dp);
}
