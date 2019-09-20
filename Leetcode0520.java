package p1107.p20170221;

/**
 * Created by dezhonger on 2017/2/21.
 */
public class Leetcode520 {
	public boolean detectCapitalUse(String word) {
		int len = word.length();
		if(len == 1) return true;
		int cnt = 0;
		for(int i = 0; i < len; i++) {
			if(Character.isUpperCase(word.charAt(i))) cnt++;
		}
		if(cnt == len || cnt == 0) return true;
		if(cnt == 1) {
			return Character.isUpperCase(word.charAt(0));
		}
		return false;
	}
}
