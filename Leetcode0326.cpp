bool isPowerOfThree(int n) {
    if (n <= 0) return 0;

    int max_pow3 = log10(INT_MAX)/log10(3); // simple math formula to compute log_3(N)
    int max_pow3_val = pow(3, max_pow3);

    return max_pow3_val % n == 0;
}



return n > 0 && 1162261467 % n == 0;


return Integer.toString(n, 3).matches("10*");


