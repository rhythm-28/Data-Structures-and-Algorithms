// Find smallest substring in a given string which contains all the characters (with the same frequency) of another given string

#include<iostream>
#include<cstring>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<climits>
using namespace std;

// s1 should contain elements of s2
string smallest_substring(string s1,string s2)
{
    unordered_map<char,int> b;
    unordered_map<char,int> a;
    int i,m=s1.length(),n=s2.length();

    // map for smaller string
    for(i=0;i<n;i++)
    {
        char c=s2[i];
        if(b.find(c)==b.end())
        b[c]=1;
        else
        b[c]+=1;
    }
    int count=0,start=0;
    int cur_length,min_length=INT_MAX,start_idx=-1;
    // sliding window for bigger string
    for(i=0;i<m;i++)
    {
        // expand window from right
        char ch=s1[i];
        if(b.find(ch)==a.end())
        a[ch]=1;
        else
        a[ch]+=1;

        // check if map(s2) is present in map(s1)
        if(b.find(ch)!=b.end())
        {
            if(a[ch]<=b[ch])
            count++;
        }
        
        if(count==n)
        {
            // present
            // start deleting wunwanted elements from left
            // unwanted elements => 1) elements not present in required pattern
            //                      2) elements with frequency greater than what is required
            // onlt those elements would be deleted which are present before first wanted element
            char temp=s1[start];
            while(b.find(temp)==b.end() || a[temp]>b[temp])
            {
                if(a[temp]>1)
                a[temp]--;
                else
                a.erase(temp);

                start++;
                temp=s1[start];
            }

            // update min if less length window found
            cur_length=i-start+1;
            if(cur_length<min_length)
            {
                min_length=cur_length;
                start_idx=start;
            }
        }
    }
    if(start_idx==-1)
    return "not found";
    string ansd=s1.substr(start_idx,min_length);
    return ansd;
}

int main()
{
    string s1,s2,s3;
    getline(cin,s1);
    getline(cin,s2);
    if(s2.length()>s1.length())
    cout<<"not possible";
    else
    cout<<smallest_substring(s1,s2);
    return 0;
}