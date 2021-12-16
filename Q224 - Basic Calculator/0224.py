class Solution:
    def calculate(self, s: str) -> int:
        
        result=0
        sumOrDiff=1
        stack=[]
        temp=0
        
        for char in s:
            if char.isdigit():
                temp=temp*10+int(char)
            elif char in ["-","+"]:
                result=result+temp*sumOrDiff
                temp=0
                if char=="-":
                    sumOrDiff=-1
                else:
                    sumOrDiff=1
            elif char=="(":
                stack.append(result)
                stack.append(sumOrDiff)
                sumOrDiff=1
                result=0
            elif char==")":
                result+=sumOrDiff*temp
                result*=stack.pop()
                result+=stack.pop()
                temp=0
        
        return result + temp * sumOrDiff
    