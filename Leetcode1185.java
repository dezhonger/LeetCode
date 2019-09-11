
/**
 * Created by dezhonger on 2019/9/11
 */
public class Leetcode1185 {
    //https://en.wikipedia.org/wiki/Zeller%27s_congruence
    public String dayOfTheWeek(int day, int month, int year) {
        String[] s = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        if (month < 3) {
            year--;
            month += 12;
        }
        int w = (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + day) % 7;
        return s[w];
    }
}
