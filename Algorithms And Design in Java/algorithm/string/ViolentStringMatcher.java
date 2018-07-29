package com.deceiver.algorithm.string;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-07
 * Time: 下午11:55
 */
public class ViolentStringMatcher {

    public static int indexOf(String source, String pattern){
        int i = 0, j = 0;
        int sLen = source.length(), pLen = pattern.length();
        char[] src = source.toCharArray();
        char[] ptn = pattern.toCharArray();

        while (i < sLen && j < pLen){
            if (src[i] == ptn[j]){
                i++;
                j++;
            }else{
                // 如果当前字符匹配不成功,则i回溯到此次匹配最开始的位置+1处,也就是i = i - j + 1
                i = i - j + 1;
                j = 0;
            }
        }

        if (j == pLen){
            return i - j;
        }else {
            return -1;
        }
    }

    public static void main(String[] args) {
        String str = "abceiosjdfoabcd";
        System.out.println(indexOf(str, "bcd"));

    }

}
