//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int r) {
        
        int ans=0;
        for(int i=1;i<2*r;i++){
            int target=(4*r*r)-(i*i);
            int l=1;
            int h=2*r;
            int temp=0;
            //searching through binary search instead of using for loop
            while(l<=h){
                int m=l+(h-l)/2;
                if(m*m<=target){
                    temp=m;
                    l=m+1;
                }else{
                    h=m-1;
                }
            }
            ans+=temp;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends
