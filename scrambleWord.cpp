#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool getAnsRec(string s1, string s2){
        if(s1.size()==1)
            return s1==s2;
        if(s1==s2)
            return true;
        int n=s1.size();
        for(int i=0;i<n-1;i++){
            if(
                (getAnsRec(s1.substr(0,i+1),s2.substr(0,i+1)) && getAnsRec(s1.substr(i+1),s2.substr(i+1))) ||
                (getAnsRec(s1.substr(0,i+1),s2.substr(n-i-1)) && getAnsRec(s1.substr(i+1),s2.substr(0,n-i-1)))
            )
                return true;
        }
        return false;
    }
    
    bool getAnsRecPlusDp(string s1, string s2, unordered_map<string,bool>&um){
        if(s1.size()==1)
            return um[s1+s2]=s1==s2;
        if(s1==s2)
            return true;
        if(um.find(s1+s2)!=um.end())
            return um[s1+s2];
        int n=s1.size();
        for(int i=0;i<n-1;i++){
            if(
                (getAnsRecPlusDp(s1.substr(0,i+1),s2.substr(0,i+1),um) && getAnsRecPlusDp(s1.substr(i+1),s2.substr(i+1),um)) ||
                (getAnsRecPlusDp(s1.substr(0,i+1),s2.substr(n-i-1),um) && getAnsRecPlusDp(s1.substr(i+1),s2.substr(0,n-i-1),um))
            )
                return um[s1+s2]=true;
        }
        return um[s1+s2]=false;
    }
    
    bool getAnsRecPlusDpOptimized(string s1, string s2, unordered_map<string,bool>&um){
        if(s1.size()==1)
            return um[s1+s2]=s1==s2;
        if(s1==s2)
            return true;
        if(um.find(s1+s2)!=um.end())
            return um[s1+s2];
        int n=s1.size();
        vector<int>s1count(26,0);
        vector<int>s2count(26,0);
        for(int i=0;i<n;i++){
            s1count[s1[i]-'a']++;
            s2count[s2[i]-'a']++;
        }
        if(s1count!=s2count)
            return um[s1+s2]=false;
        for(int i=0;i<n-1;i++){
            if(
                (
                    getAnsRecPlusDpOptimized(s1.substr(0,i+1),s2.substr(0,i+1),um) && 
                    getAnsRecPlusDpOptimized(s1.substr(i+1),s2.substr(i+1),um)
                ) ||
                (
                    getAnsRecPlusDpOptimized(s1.substr(0,i+1),s2.substr(n-i-1),um) && 
                    getAnsRecPlusDpOptimized(s1.substr(i+1),s2.substr(0,n-i-1),um)
                )
            )
                return um[s1+s2]=true;
        }
        return um[s1+s2]=false;
    }
    
    bool isScramble(string s1, string s2) {
        unordered_map<string,bool>um;
        return getAnsRecPlusDpOptimized(s1,s2,um);
    }
};

int main(){
    Solution s;
    cout<<s.isScramble("great","rgeat");
}