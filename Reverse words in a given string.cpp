//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
{ 
	S+='.';
 	int n = S.length();
 	vector<string>temp;
 	string word = "";
 	for (int i = 0; i < n; ++i)
 	{
 		if(S[i]=='.')
 		{
 			temp.push_back(word);
 			word = "";
 		}
 		else
 		{
                  word += S[i];
        }
        }
 	
 	string result = "";
 	for (int i = temp.size()-1; i >=0; --i)
 	{
 		result+=temp[i];
 		if(i!=0)
 		{
 			result+='.';
 		}
 	}

 	return result;
} 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends
