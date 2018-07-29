package com.deceiver.jzoffer;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-19
 * Time: 上午12:10
 */
public class NumberOf1 {

    public int numOfOne(int n){
        int count = 0;
        int flag = 1;
        while (flag > 0){
            if ((n & flag) == 1){
                count++;
            }
            flag <<= 1;
        }
        return count;
    }

    /**
     * 牛逼版本
     * 二进制：1100、1011
     * 算法解析：
     *  （1）1100 - 1 = 1011
     *  （2）1100 & 1011 = 1000
     *  （3）1000 - 1 = 0111
     *  （4）1000 & 0111 = 0
     *  利用位与运算计算二进制中 1 的个数
     *  很明显的看出二进制数进行减1运算时，最右边的数"1"变为0，若其后面有"0"，则所有"0"都变为"1"
     *  而其前面的数都保持不变
     * @param n
     * @return
     */
    public int numOf1InBinary(int n){
        int count = 0;
        while (n != 0){
            ++count;
            n = (n - 1) & n;
        }
        return count;
    }
}
