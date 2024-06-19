class Solution {
public:
    constexpr long long squareRoot(long long n){
        long long x = sqrt(n) + 1;
        return x;
    }
    bool judgeSquareSum(int n) {
        long long a = 0;
        long long b = squareRoot(n);
        while(a <= b){
            long long sum = a*a + b*b;
            if(sum == n) return true;
            else if(sum < n) a++;
            else b--;
        }
        return false;
    }
};
