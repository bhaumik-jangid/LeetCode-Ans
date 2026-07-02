class Solution {
public:

    bool isVowel(char c) {
        if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int ans = INT_MIN;
        int l = 0;
        int count = 0;

        for(int r = 0; r <= s.length(); r++) {
            if(r < k) {
                if( isVowel(s[r])) count++;
                continue;
            }

            ans = ans > count ? ans : count;

            if( isVowel(s[r])) count++;

            if( isVowel(s[l])) count--;
            l++;
        }

        return ans;
    }
};