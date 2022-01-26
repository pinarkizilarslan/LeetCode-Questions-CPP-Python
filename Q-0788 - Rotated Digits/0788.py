class Solution:
    def rotatedDigits(self, n: int) -> int:
        count = 0
        for i in range(0,n+1):
            j = i
            check = False
            while (j > 0):
                if (j % 10 == 3 or j % 10 == 4 or j % 10 == 7):
                    check = False 
                    break                
                elif (j % 10 == 2 or j % 10 == 5 or j % 10 == 6 or j % 10 == 9) :
                    check = True
                    
                j = int(j / 10) 
            
            if (check):
                count+=1
        
        return count