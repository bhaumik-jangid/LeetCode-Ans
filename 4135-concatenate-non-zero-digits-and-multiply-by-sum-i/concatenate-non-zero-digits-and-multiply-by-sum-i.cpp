class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n < 10) return n*n;
        long long sum = 0;
        long long x = 0;
        int c = 0;
        while(n != 0) {
            long long rem = n % 10;
            if(rem != 0) {
                sum += rem;
                x = rem * pow(10,c) + x;
                c++;
            }
            n /= 10;
        }
        cout<<sum<<" "<<x;
        return x*sum;
    }
};