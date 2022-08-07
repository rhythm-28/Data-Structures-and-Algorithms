// Find length of longest common subsequence for 2 given strings
// Top-Down Approach
// m-> length of first string
// n-> length of second string
// Time: O(m*n)
// Space: O(m*n)

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int longest_common_susbsequence(string s1,string s2,int i,int j,vector<vector<int>> &dp)
{
    if(i==s1.length() || j==s2.length())
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    if(s1[i]==s2[j])
    {
        dp[i][j]= 1+ longest_common_susbsequence(s1,s2,i+1,j+1,dp);
        return dp[i][j];
    }

    else
    {
        int op1=longest_common_susbsequence(s1,s2,i+1,j,dp);
        int op2=longest_common_susbsequence(s1,s2,i,j+1,dp);
        dp[i][j]=max(op1,op2);
        return dp[i][j];
    }
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    vector<vector<int>> dp;
    vector<int> temp;
    int i,j;
    for(i=0;i<s1.length();i++)
    {
        for(j=0;j<s2.length();j++)
        temp.push_back(-1);
        dp.push_back(temp);
    }
    cout<<longest_common_susbsequence(s1,s2,0,0,dp);
    return 0;
}