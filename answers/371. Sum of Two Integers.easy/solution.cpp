class Solution {
public:
    int getSum(int a, int b) {
        int jin;
        while(b != 0){
            jin = (a & b) << 1;
            a = a ^ b;
            b = jin;
        }
        return a;
    }
};