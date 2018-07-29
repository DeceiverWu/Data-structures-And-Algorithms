package com.deceiver.jzoffer;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-17
 * Time: 下午11:14
 */
public class SortAge {

    public void sortAge(int[] ages, int length){
        if (ages == null || length == 0)
            return;

        int rangeOfAge = 99;
        //记录每个年龄的人数
        int[] numOfAge = new int[rangeOfAge + 1];
        //初始化辅助数组
        for (int i = 0; i < rangeOfAge; i++){
            numOfAge[i] = 0;
        }

        //计算每个年龄人数
        for (int i = 0; i < length; i++){
            numOfAge[ages[i]]++;
        }

        int index = 0;
        // i 为年龄
        for (int i = 0; i <= rangeOfAge; i++){
            //按从小到大排序，index为序号
            for (int j = 0; j < numOfAge[i]; j++){
                ages[index] = i;
                index++;
            }
        }
    }
}
