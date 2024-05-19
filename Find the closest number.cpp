//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        int b;
        int arr1[n];
        for(int i=0;i<n;i++){
            int a=abs(arr[i]-k);
            arr1[i]=a;
        }
        int min=arr1[0];
        for(int i=0;i<n;i++){
            if(arr1[i]<=min){
                min=arr1[i];
            }
        }
        for(int i=0;i<n;i++){
            if(arr1[i]==min){
                b=i;
            }
        }
        return arr[b];
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends
