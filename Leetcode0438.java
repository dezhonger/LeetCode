

import java.util.ArrayList;
import java.util.List;

/**
 * Created by dezhonger on 2017/2/14.
 */
public class Leetcode0438 {

	public void f(int[] a, String s) {
		for(int i = 0; i < s.length(); i++) {
			a[s.charAt(i) - 'a']++;
		}
	}

	public boolean eq(int[] a, int[] b) {
		for(int i = 0; i < a.length; i++) {
			if(a[i] != b[i]) return false;
		}
		return true;
	}

	public List<Integer> findAnagrams(String s, String p) {
		List<Integer> list = new ArrayList<>();
		if(s == null || s.length() < p.length()) return list;
		int[] cnt1 = new int[26];
		int[] cnt2 = new int[26];
		f(cnt1, p);
		for(int i = 0; i < p.length(); i++) {
			cnt2[s.charAt(i) - 'a']++;
		}
		if(eq(cnt1, cnt2)) {
			list.add(0);
		}
		for(int i = p.length(), j = 0; i < s.length(); i++, j++) {
			System.out.println(s.charAt(i) + " " + s.charAt(j));
			cnt2[s.charAt(j) - 'a']--;
			cnt2[s.charAt(i) - 'a']++;
			if(eq(cnt1, cnt2)) {
				list.add(j + 1);
			}
		}
//		System.out.println(list);
		return list;
	}

	public static void main(String[] args) {
//		new Leetcode438().findAnagrams("cbaebabacd", "abc");
//		new Leetcode438().findAnagrams("abab", "ab");
	}
}
