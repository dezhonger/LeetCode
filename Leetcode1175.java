
/**
 * Created by dezhonger on 2019/9/1
 */
public class Leetcode1175 {

    long[] f = new long[101];

    void g() {
        f[0] = f[1] = 1;
        for (int i = 2; i <= 100; i++) {
            f[i] = f[i - 1] * i;
            f[i] %= 10_0000_0007;
        }
    }

    boolean isPrime(int k) {
        if (k == 1) return false;
        for (int i = 2; i * i <= k; i++) {
            if (k % i == 0) return false;
        }
        return true;
    }

    public int numPrimeArrangements(int n) {
        g();
        int a = 0, b = 0;
        for (int i = 1; i <= n; i++) {
            if (isPrime(i)) a++;
            else b++;
        }
        return (int) (((f[a] % 10_0000_0007) * (f[b] % 10_0000_0007)) % 10_0000_0007);
    }
}
