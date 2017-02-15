public class Solution {
    public String getHint(String secret, String guess) {
        int a, b, len = secret.length();
        a = b = 0;
        String ans;
        int[] m = new int[10];
        int[] n = new int[10];
        for(int i = 0; i < 10; i++) m[i] = n[i] = 0;
        for(int i = 0; i <len; i++) {
            if(secret.charAt(i) == guess.charAt(i)) a++;
            m[secret.charAt(i) - '0']++;
            n[guess.charAt(i) - '0']++;
        }
        
        for(int i = 0; i < 10; i++) {
            b += Math.min(m[i], n[i]);
        }
        b -= a;
        ans = "" + a + 'A' + b + 'B';
        return ans;
    }
}
