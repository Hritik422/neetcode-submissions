class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.size();

        for (char c = 'A'; c <= 'Z'; c++) {
            int l = 0;
            int changes = 0;

            for (int r = 0; r < n; r++) {
                if (s[r] != c)
                    changes++;

                while (changes > k) {
                    if (s[l] != c)
                        changes--;
                    l++;
                }

                ans = max(ans, r - l + 1);
            }
        }

        return ans;
    }
};