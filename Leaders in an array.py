class Solution:
    #Back-end complete function Template for Python 3
    
    #Function to find the leaders in the array.
    def leaders(self, A, N):
        
        
        l=[]
        l.append(A[len(A)-1])
        m = A[len(A)-1]
        for i in range(len(A)-2,-1,-1):
            if A[i]>=m:
                m = A[i]
                l.append(A[i])
            
        l.reverse()
        
        return l
                



#{ 
 # Driver Code Starts
#Initial Template for Python 3

import math


    
def main():
    
    T=int(input())
    
    while(T>0):
        
        
        N=int(input())
        
        A=[int(x) for x in input().strip().split()]
        obj = Solution()
        
        A=obj.leaders(A,N)
        
        for i in A:
            print(i,end=" ")
        print()
        
        T-=1

if __name__=="__main__":
    main()
# } Driver Code Ends
