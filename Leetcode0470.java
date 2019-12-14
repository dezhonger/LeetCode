package com.dezhonger.le;

import java.util.Random;

/**
 * Created by dezhonger on 2019/12/14
 *
 * @author dezhonger
 * @since 2019/12/14
 */
public class Leetcode0470 {

    Random random = new Random();

    public int rand7() {
        return random.nextInt(7) + 1;
    }

    public int rand10() {
        while (true) {
            //考虑七进制的一个数AB
            int res = 7 * (rand7() - 1) + rand7() - 1;
            if (res < 40) return res % 10 + 1;
        }
    }
}
