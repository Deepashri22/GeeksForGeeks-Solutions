#User function Template for python3

class Solution:
    
    #Function to find the maximum number of meetings that can
    #be performed in a meeting room.
    def maximumMeetings(self,n,start,end):
        # code here
        
        arr=[]
        for i in range(len(start)):
            arr.append([end[i],start[i],i])
            
        arr.sort()
        limit=arr[0][0] 
        count=1
        for i in range(1,len(arr)):
            if arr[i][1]>limit:
                count+=1
                limit=arr[i][0]
            else:
                continue
        return count 


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

#Contributed by : Nagendra Jha

if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n = int(input())
        start = list(map(int,input().strip().split()))
        end = list(map(int,input().strip().split()))
        ob=Solution()
        print(ob.maximumMeetings(n,start,end))
# } Driver Code Ends
