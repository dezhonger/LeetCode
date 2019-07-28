package com.netease.music.p20190729;

/**
 * Created by dezhonger on 2019/7/29
 */
public class Leetcode1138 {
    public static void main(String[] args) {
        String leet = new Leetcode1138().alphabetBoardPath("leet");
        System.out.println(leet);
    }

    int[] x = new int[]{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5};
    int[] y = new int[]{0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0, 1, 2, 3, 4, 0};

    public String alphabetBoardPath(String target) {
        StringBuilder sb = new StringBuilder();
        int posx = 0;
        int posy = 0;

        for (char c : target.toCharArray()) {
            int dx = x[c - 'a'];
            int dy = y[c - 'a'];
            if (dx == posx && posy == dy) {
                sb.append("!");
            } else {
                int ddx = dx - posx;
                int ddy = dy - posy;
                while (true) {
                    while (ddx != 0) {
                        if (dx > posx) {
                            if (check(posx + 1, posy)) {
                                posx++;
                                ddx--;
                                sb.append("D");
                            } else {
                                break;
                            }
                        } else {
                            if (check(posx - 1, posy)) {
                                posx--;
                                ddx++;
                                sb.append("U");
                            } else {
                                break;
                            }
                        }
                    }
                    while (ddy != 0) {
                        if (dy > posy) {
                            if (check(posx, posy + 1)) {
                                posy++;
                                ddy--;
                                sb.append("R");
                            } else {
                                break;
                            }
                        } else {
                            if (check(posx, posy - 1)) {
                                posy--;
                                ddy++;
                                sb.append("L");
                            } else {
                                break;
                            }
                        }
                    }
                    if (posx == dx && posy == dy) {
                        sb.append("!");
                        break;
                    }
                }
            }
        }
        return sb.toString();
    }

    private boolean check(int x, int y) {
        if (x >= 0 && x <= 4 && y >= 0 && y <= 4) return true;
        if (x == 5 && y == 0) return true;
        return false;
    }

}
