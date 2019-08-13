public class Leetcode1156 {

    public int maxRepOpt1(String text) {
        int len = text.length();
        int[] l = new int[len];
        int[] r = new int[len];
        int[] c = new int[26];
        for (char ch : text.toCharArray()) c[ch - 'a']++;
        l[0] = 1;
        r[len - 1] = 1;
        for (int i = 1; i < len; i++) l[i] = text.charAt(i) == text.charAt(i - 1) ? l[i - 1] + 1 : 1;
        for (int i = len - 2; i >= 0; i--) r[i] = text.charAt(i) == text.charAt(i + 1) ? r[i + 1] + 1 : 1;
        int res = 0;
        //枚举第i个位置被替换后的最大值
        for (int i = 1; i < len - 1; i++) {
            char c1 = text.charAt(i - 1);
            char c2 = text.charAt(i + 1);
            //左右两侧字符相等，把中间的替换为c1/c2
            if (c1 == c2) {
                if (l[i - 1] + r[i + 1] == c[c1 - 'a']) res = Math.max(res, c[c1 - 'a']);
                else res = Math.max(res, l[i - 1] + r[i + 1] + 1);
            } else {
                //替换为c1
                if (l[i - 1] == c[c1 - 'a']) res = Math.max(res, c[c1 - 'a']);
                else res = Math.max(res, l[i - 1] + 1);
                //替换为c2
                if (r[i + 1] == c[c2 - 'a']) res = Math.max(res, c[c2 - 'a']);
                else res = Math.max(res, r[i + 1] + 1);
            }
        }
        //index:0, len - 2
        //特殊判断下替换首位和末位
        if (len > 1) {
            if (r[1] == c[text.charAt(1) - 'a']) res = Math.max(res, r[1]);
            else res = Math.max(res, r[1] + 1);

            if (l[len - 2] == c[text.charAt(len - 2) -'a']) res = Math.max(res, l[len - 2]);
            else res = Math.max(res, l[len - 2] + 1);
        }
        return res;
    }
}
