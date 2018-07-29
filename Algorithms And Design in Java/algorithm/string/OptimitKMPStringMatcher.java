package com.deceiver.algorithm.string;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-10
 * Time: 上午12:54
 */
public class OptimitKMPStringMatcher {

    private static int[] getNext(char[] p){
        int i = 0, k = -1;
        int len = p.length;
        int[] next = new int[len];
        next[0] = -1;

        while (i < len - 1){
            if(k == -1 || p[i] == p[k]){
                ++k;
                ++i;

                if (p[i] != p[k]){
                    next[i] = k;
                }else {
                    next[i] = next[k];
                }
            }else {
                k = next[k];
            }
        }
        return next;
    }
}
