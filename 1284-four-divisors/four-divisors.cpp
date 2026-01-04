class Solution {
public:
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int x : nums) {
            int r = round(cbrt(x));
            if (1LL * r * r * r == x && isPrime(r)) {
                ans += 1 + r + r * r + x;
                continue;
            }

            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    int a = i, b = x / i;
                    if (a != b && isPrime(a) && isPrime(b)) {
                        ans += 1 + a + b + x;
                    }
                    break;
                }
            }
        }

        return ans;
    }
};
