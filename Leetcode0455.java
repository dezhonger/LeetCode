package p1107.p20170214;

import java.util.Arrays;

/**
 * Created by dezhonger on 2017/2/14.
 * 把饼干分给孩子，第i个孩子要的饼干至少为g[i]
 * 排序贪心即可。
 */
public class Leetcode455 {
	public int findContentChildren(int[] g, int[] s) {
		Arrays.sort(g);
		Arrays.sort(s);
		int ans = 0;
		int index = 0;
		for(int i = 0; i < s.length; i++) {
			if(s[i] >= g[index]) {
				ans++;
				index++;
				if(index >= g.length) break;
			}
		}
		return ans;
	}
}
