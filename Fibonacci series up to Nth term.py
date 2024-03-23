#User function Template for python3

class Solution:
    def series(self, n):
        # Code here
        dp=[0]*(n+1)
        dp[1]=1
        for i in range(2,n+1):
            dp[i]=(dp[i-1]+dp[i-2])%(10**9+7)
        return dp


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        result = ob.series(N)
        print(*result)
# } Driver Code Ends
