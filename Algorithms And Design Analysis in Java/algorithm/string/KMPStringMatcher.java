package com.deceiver.algorithm.string;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-08
 * Time: 上午12:07
 */
public class KMPStringMatcher {

    /**
     * 取KMP算法中pattern字符串对应的next数组
     * @return
     */
    private static int[] getNext(char[] p){
        /**
         * 已知next[j] = k,利用递归的思想求出next[j+1]的值
         * 如果已知next[j] = k,如何求出next[j+1]呢?具体算法如下:
         * 1. 如果p[j] = p[k], 则next[j+1] = next[k] + 1;
         * 2. 如果p[j] != p[k], 则令k=next[k],如果此时p[j]==p[k],则next[j+1]=k+1,
         * 如果不相等,则继续递归前缀索引,令 k=next[k],继续判断,直至k=-1(即k=next[0])或者
         */
        if (p == null)
            return null;

        int pLen = p.length;
        int[] next = new int[pLen];
        int k = -1;
        int j = 0;
        next[0] = -1;
        while (j < pLen - 1){
            if (k == -1 || p[k] == p[j]){
                k++;
                j++;
                next[j] = k;
            }else {
                k = next[j];
            }
        }
        return next;
    }

    public static int indexOf(String source, String pattern){
        int i = 0, j = 0;
        int slen = source.length();
        int plen = pattern.length();
        char[] src = source.toCharArray();
        char[] ptn = pattern.toCharArray();
        int[] next = getNext(ptn);
        while (i < slen && j < plen){
            if (j == -1 || src[i] == ptn[j]){
                i++;
                j++;
            }else {
                // 如果j!=-1且当前字符匹配失败,则令i不变,j=next[j],即让pattern模式串右移j-next[j]个单位
                j = next[j];
            }
        }
        if (j == plen) {
            return i - j;
        }
        return -1;
    }

    public static void main(String[] args) {
        
    }
}
