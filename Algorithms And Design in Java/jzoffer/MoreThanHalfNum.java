package com.deceiver.jzoffer;

import java.util.HashMap;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-23
 * Time: 下午10:31
 */
public class MoreThanHalfNum {

    /**
     * 1.出现次数多于 length 的一半，说明这个数字出现次数 times 减去其他所有数字出现的次数依旧会大于0
     * 2.
     * @param array
     * @return
     */
    public int moreThanHalfNum(int[] array) {
        if (array == null || array.length <= 0){
            return 0;
        }

        int result = array[0];
        int times = 1;

        for (int i = 1; i < array.length; i++){
            if (times == 0){
                result = array[i];
                times = 1;
            } else if (array[i] == result){
                times++;
            } else {
                times--;
            }
        }

        times = 0;
        for (int i = 0; i < array.length; i++){
            if (array[i] == result){
                times++;
            }
        }

        if (times * 2 < array.length){
            result = 0;
        }

        return result;
    }

    public static void main(String[] args) {
        MoreThanHalfNum halfNum = new MoreThanHalfNum();
        int num = halfNum.moreThanHalfNum(new int[]{1,2,3,2,2,2,5,4,2});
        System.out.println(num);
    }
}
