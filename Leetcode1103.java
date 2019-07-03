
/**
 * Created by dezhonger on 2019/7/3
 */
public class Leetcode1103 {
    public int[] distributeCandies(int candies, int num_people) {
        int c = 1;
        int index = 0;
        int[] a = new int[num_people];
        while(true) {
            int x = Math.min(c, candies);
            a[index] += x;
            candies -=x;
            if(candies <= 0) break;
            c++;
            index = (index + 1) % num_people;
        }
        return a;
    }
}
