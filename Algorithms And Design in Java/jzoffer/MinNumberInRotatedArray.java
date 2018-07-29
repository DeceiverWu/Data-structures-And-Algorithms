package com.deceiver.jzoffer;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-17
 * Time: 下午11:24
 */
public class MinNumberInRotatedArray {

    public int min(int[] numbers, int length){
        if (numbers == null || length == 0) {
            return 0;
        }

        int left = 0;
        int right = length - 1;
        int mid = left;
        while (numbers[left] >= numbers[right]){
            if ((right - left) == 1){
                mid = right;
                break;
            }

            mid = (left + right) / 2;

            //如果下标left、right、mid指向的三个数都相等，就只能按顺序查找
            if (numbers[left] == numbers[mid] && numbers[left] == numbers[right] && numbers[mid] == numbers[right]){
                return minInOrder(numbers, left, right);
            }

            if (numbers[mid] >= numbers[left]){
                left = mid;
            }else if (numbers[mid] <= numbers[right]){
                right = mid;
            }

        }
        return numbers[mid];
    }

    /**
     * 找到最小值
     * @param numbers
     * @param left
     * @param right
     * @return
     */
    public int minInOrder(int[] numbers, int left, int right){
        int result = numbers[left];
        for (int i = left + 1; i < right; i++){
            if (result > numbers[i]){
                result = numbers[i];
            }
        }
        return result;
    }
}
