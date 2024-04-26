#User function Template for python3

class Solution:
	def FindExitPoint(self, n, m, matrix):
		# Code here


        def is_valid(x,y):


            if 0<=x < m and 0 <= y < n:

                return True


            else:

                return False


        def next_move(d, x, y):


            if d == 0:

                return (x+1, y)

            elif d ==1:

                return (x, y+1)

            elif d==2:

                return (x-1, y)

            elif d ==3:

                return (x, y-1)


            
        d = 0

        x = 0

        y = 0





        while True:

             d = (d + matrix[y][x])% 4

             nx, ny = next_move(d, x, y)

             if is_valid(nx,ny):

                  matrix[y][x] = 0

                  x, y = nx, ny

             else:

                 return (y,x)


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n, m = input().split()
        n = int(n)
        m = int(m)
        matrix = []
        for _ in range(n):
            matrix.append(list(map(int, input().split())))
        ob = Solution()
        ans = ob.FindExitPoint(n, m, matrix)
        for _ in ans:
            print(_, end=" ")
        print()

# } Driver Code Ends
