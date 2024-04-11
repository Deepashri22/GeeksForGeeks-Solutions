#User function Template for python3

#Function to find a continuous sub-array which adds up to a given number.
class Solution:
    def subArraySum(self, arr, n, s):
        if s == 0:
            for i in range(n):
                if arr[i] == 0:
                    return [i + 1, i + 1]
            return [-1]
        
        left, right = 0, 0
        curr_sum = 0

        while right < n:
            curr_sum += arr[right]
            
            while curr_sum > s:
                curr_sum -= arr[left]
                left += 1
                
            if curr_sum == s:
                return [left + 1, right + 1]
            
            right += 1

        return [-1]


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math

def main():
        T=int(input())
        while(T>0):
            
            NS=input().strip().split()
            N=int(NS[0])
            S=int(NS[1])
            
            A=list(map(int,input().split()))
            ob=Solution()
            ans=ob.subArraySum(A, N, S)
            
            for i in ans:
                print(i, end=" ")
                
            print()
            
            T-=1


if __name__ == "__main__":
    main()
# } Driver Code Ends
