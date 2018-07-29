package com.deceiver.jzoffer;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-25
 * Time: 上午10:17
 */
public class FindGreatestSumOfSubArray {

    public int findGreatestSumOfSubArray(int[] array) {
        if (array == null || array.length <= 0){
            return 0;
        }

        int maxSum = 0x80000000;
        int curSum = 0;
        for (int i = 0; i < array.length; i++){
            if (curSum <= 0){
                curSum = array[i];
            } else {
                curSum += array[i];
            }

            if (curSum > maxSum){
                maxSum = curSum;
            }
        }
        return maxSum;
    }

    public static void main(String[] args) {
        FindGreatestSumOfSubArray ofSubArray = new FindGreatestSumOfSubArray();
        int sum = ofSubArray.findGreatestSumOfSubArray(new int[]{-2,-8,-1,-5,-9});
        System.out.println(sum);
    }


    public  int findGreatestSumOfSubArray2(int[] array) {
        //记录当前所有子数组的和的最大值
        int res = array[0];
        //包含array[i]的连续数组最大值
        int max=array[0];
        for (int i = 1; i < array.length; i++) {
            max=Math.max(max+array[i], array[i]);
            res=Math.max(max, res);
        }
        return res;
    }

}
