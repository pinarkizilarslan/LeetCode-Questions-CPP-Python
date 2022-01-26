class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 0; i <= n; i++) {
            int j = i;
            bool check = false;
            while (j > 0) {
                if (j % 10 == 3 || j % 10 == 4 || j % 10 == 7) {
                    check = false;
                    break;
                }
                else if (j % 10 == 2 || j % 10 == 5 || j % 10 == 6 || j % 10 == 9) {
                    check = true;
                }
                j = j / 10;
            }
            if (check)
                count++;
        }
        return count;
    }
};