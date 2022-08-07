// Print longest common subsequence for 2 given strings
// Bottom-Up Approach
// m-> length of first string
// n-> length of second string
// Time: O(m*n)
// Space: O(m*n)

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> longest_common_susbsequence(string s1,string s2)
{
    vector<vector<int>> dp;
    vector<int> temp;
    int i,j;
    for(i=0;i<=s1.length();i++)
    {
        for(j=0;j<=s2.length();j++)
        temp.push_back(0);
        dp.push_back(temp);
    }
    for(i=1;i<=s1.length();i++)
    {
        for(j=1;j<=s2.length();j++)
        {
            if(s1[i-1]==s2[j-1])
            dp[i][j]=1+dp[i-1][j-1];

            else
            dp[i][j]=0+max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp;
}

void print(vector<vector<int>> dp,string s1,string s2)
{
    int i=s1.length(),j=s2.length();
    vector<char> ans;
    while(i!=0 && j!=0)
    {
        if(s1[i-1]==s2[j-1])
        {
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        i--;
        else
        j--;
    }
    reverse(ans.begin(),ans.end());
    for(char ch:ans)
    cout<<ch;
}

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    vector<vector<int>> dp=longest_common_susbsequence(s1,s2);
    print(dp,s1,s2);
    return 0;
}