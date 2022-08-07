// To sort given strings (lexicographically/numerically) on the basis of a particular index of each string 

#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
#include<utility>
using namespace std;

// To extract a particular token from a string 
string extractToken(string s,int key)
{
    char* a=strtok((char*)s.c_str()," ");
    while(key>1)
    {
        a=strtok(NULL," ");
        key--;
    }
    int i,n=strlen(a);
    for(i=0;i<n;i++)
    s[i]=a[i];
    s[i]='\0';
    return s; 
}

//To convert a string into integer
int int_convert(string b)
{
    int ans=0,p=1,n=b.length(),i;
    for(i=n-1;i>=0;i--)
    {
        ans+=((b[i]-'0')*p);
        p=p*10;
    }
    return ans;
}

//Comparator function for lexicographical sorting
bool lexicoSort(pair<string,string> p1,pair<string,string> p2)
{
    return p1.second<p2.second;
}

//Comparator function for numerical sorting
bool numSort(pair<string,string> p1,pair<string,string> p2)
{
    return int_convert(p1.second)<int_convert(p2.second);
}

int main() 
{
	int n,i,key,j;
    vector<string> s;
    string y,reverse,sort_type;
    pair<string,string> p[100];

    //Input
    cin>>n;
    fflush(stdin);
	for(i=0;i<n;i++)
    {
        getline(cin,y);
        s.push_back(y);
    }
    cin>>key>>reverse>>sort_type;

    //Extracting tokens and storing them in pair along with respective strings
    for(i=0;i<n;i++)
    {
        p[i].first=s[i];
        p[i].second=extractToken(s[i],key);
    }
    
    //Sorting
    if(sort_type=="lexicographical")
    sort(p,p+n,lexicoSort);
    else
    sort(p,p+n,numSort);

    
    //Ascending/Descending
    if(reverse=="true")
    {
        j=n-1;
        pair<string,string> temp;
        for(i=0;i<j;i++)
        {
            temp.first=p[i].first;
            temp.second=p[i].second;
            p[i].first=p[j].first;
            p[i].second=p[j].second;
            p[j].first=temp.first;
            p[j].second=temp.second;
            j--;
        }
    }

    //Output
    for(i=0;i<n;i++)
    cout<<p[i].first<<endl;

	return 0;
}