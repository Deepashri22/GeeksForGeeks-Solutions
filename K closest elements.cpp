//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
        int ind = -1;
        int l = 0;
        int r = n-1;
        while(r >= l)
        {
            int mid = (l+r)>>1;
            if(arr[mid] < x)
            {
                l = mid+1;
            }
            else{
                ind = mid;
                r = mid-1;
            }
        }
        vector<int> ans;
        l = ind-1; r = ind+1;
        if(ind == -1)
        {
            if(x > arr[n-1])
            {
                while(k)
                {
                    ans.push_back(arr[n-1]);
                    n--;
                    k--;
                }
            }
            else{
                ind = 0;
                while(k)
                {
                    ans.push_back(arr[ind]);
                    ind++;
                    k--;
                }
            }
            return ans;
        }
        if(ind < n && x != arr[ind])
        {
            r--;
        }
        while(k)
        {
            if(l <0 || r >= n) break;
            if(abs(arr[l]-x) < arr[r]-x)
            {
                ans.push_back(arr[l]);
                l--;
            }
            else
            {
                ans.push_back(arr[r]);
                r++;
            }
            k--;
        }
        if(k)
        {
            while(l>=0 && k)
            {
                ans.push_back(arr[l]);
                l--;
                k--;
            }
            while(r < n && k)
            {
                ans.push_back(arr[r]);
                r++;
                k--;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
