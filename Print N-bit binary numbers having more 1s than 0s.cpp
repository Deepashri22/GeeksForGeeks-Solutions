//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    void fun(int n, int oneCount, int zeroCount, string s, vector<string>&ans)
    {
        if(s.size() == n)
        {
            ans.push_back(s);
            return;
        }
        if(oneCount == zeroCount)
        {
            s += to_string(1);
            fun(n, oneCount+1, zeroCount, s, ans);
        }
        else if(oneCount > zeroCount)
        {
            s += to_string(1);
            fun(n, oneCount+1, zeroCount, s, ans);
            s.pop_back();
            s += to_string(0);
            fun(n, oneCount, zeroCount+1, s, ans);
        }
        return;
    }
vector<string> NBitBinary(int n)
{
    // Your code goes here
    vector<string>ans;
    fun(n, 0, 0, "", ans);
    return ans;
}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends
