class Solution {
public:

    int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    int gcdOfOddEvenSums(int n) {
        return gcd(n * n , n * (n + 1));
    }
};