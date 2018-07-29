package com.deceiver.jzoffer;

import java.util.Arrays;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-20
 * Time: 下午2:30
 */
public class ReorderOddEven {

    /**
     * 奇数位于偶数前面
     * @param nums
     * @param length
     */
    public static void reorderOddEven(int[] nums, int length){
        if (nums == null || length == 0)
            return;

        int start = 0;
        int end = length - 1;
        while (start < end){
            while (start < end && (nums[start] & 1) != 0){
                start++;
            }
            while (start < end && (nums[end] & 1) == 0){
                end--;
            }
            if (start < end){
                nums[start] ^= nums[end];
                nums[end] ^= nums[start];
                nums[start] ^= nums[end];
            }
        }
    }

    public static void main(String[] args) {
        int[] array = new int[]{1,2,3,4,5,6,7};
        reorderOddEven(array, array.length);
        System.out.println(Arrays.toString(array));
    }

    private interface ReorderStrage {
        boolean getRole(int num);
    }

    class IsEven implements ReorderStrage {

        @Override
        public boolean getRole(int num) {
            return (num & 1) == 0;
        }
    }
    /**
     * 可扩展性方法
     * @param nums
     * @param length
     * @param strage 为接口，具体实现类具有相同方法，不同的定义
     */
    public void reorderOddEven(int[] nums, int length, ReorderStrage strage){
        if (nums == null || length == 0)
            return;

        int start = 0;
        int end = length - 1;
        while (start < end){
            while (start < end && strage.getRole(nums[start])){
                start++;
            }
            while (start < end && strage.getRole(nums[end])){
                end--;
            }
            if (start < end){
                nums[start] ^= nums[end];
                nums[end] ^= nums[start];
                nums[start] ^= nums[end];
            }
        }
    }

    /**
     * 1.要想保证原有次序，则只能顺次移动或相邻交换。
     * 2.i从左向右遍历，找到第一个偶数。
     * 3.j从i+1开始向后找，直到找到第一个奇数。
     * 4.将[i,...,j-1]的元素整体后移一位，最后将找到的奇数放入i位置，然后i++。
     * 5.終止條件：j向後遍歷查找失敗。
     */
    public void reOrderArray2(int [] a) {
        if(a==null||a.length==0)
            return;
        int i = 0,j;
        while(i<a.length){
            while(i<a.length&&!isEven(a[i]))
                i++;
            j = i+1;
            while(j<a.length&&isEven(a[j]))
                j++;
            if(j<a.length){
                int tmp = a[j];
                for (int j2 = j-1; j2 >=i; j2--) {
                    a[j2+1] = a[j2];
                }
                a[i++] = tmp;
            }else{// 查找失敗
                break;
            }
        }
    }

    boolean isEven(int n){
        if(n%2==0)
            return true;
        return false;
    }

}
