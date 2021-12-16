class Solution {
public:
    int calculate(string s) {

        int result=0, sumOrDiff=1;
        stack<int> stack;

        for(int i = 0; i < s.size(); i++) {
            char temp = s[i];
            if(temp >= '0' && temp <= '9') {
                int num = 0;
                while(i < s.size() && s[i]>='0' && s[i]<= '9')
                    num = num * 10 + (s[i++] - '0');
                result += sumOrDiff * num;
                i--;
            }
            else if(temp =='+') 
                sumOrDiff = 1;
            else if(temp =='-') 
                sumOrDiff = -1;
            else if(temp =='(') { 
                stack.push(result);
                stack.push(sumOrDiff);
                result = 0;
                sumOrDiff = 1;
            }
            else if(temp ==')') {
                result *= stack.top(); 
                stack.pop();
                result += stack.top(); 
                stack.pop();
            }
        }
        return result;
    }
};