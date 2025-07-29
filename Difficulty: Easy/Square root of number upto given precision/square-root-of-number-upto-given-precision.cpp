class Solution {
  public:
    double squareRoot(int n, int p) {
        int start = 0, end = n;
        double ans = 0.0;

        // Step 1: Binary search for integer part
        while (start <= end) {
            int mid = (start + end) / 2;
            if (mid * mid == n) {
                ans = mid;
                break;
            } else if (mid * mid < n) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        // Step 2: Add decimal precision
        double increment = 0.1;
        for (int i = 0; i < p; i++) {
            while (ans * ans <= n) {
                ans += increment;
            }
            ans -= increment;
            increment /= 10.0;
        }

        // Round the result to p digits
        int factor = pow(10, p);
        return (double)((int)(ans * factor + 0.5)) / factor;
    }
};
