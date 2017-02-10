package p1107.p20170210;

/**
 * Created by dezhonger on 2017/2/10.
 * 判断s是不是t的子序列，不必连续。
 */
public class Leetcode392 {
	public boolean isSubsequence(String s, String t) {
		if(s.length() == 0) return true;
		if(t.length() == 0) return false;
		int index = 0;
		for(int i = 0; i < t.length(); i++) {
			char c = t.charAt(i);
			if(c == s.charAt(index)) {
				index++;
				if(index == s.length()) {
					return true;
				}
			}
		}
		return false;
	}
}
