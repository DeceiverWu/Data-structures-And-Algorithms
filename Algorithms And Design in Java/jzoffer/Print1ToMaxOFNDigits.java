package com.deceiver.jzoffer;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-20
 * Time: 上午12:14
 */
public class Print1ToMaxOFNDigits {

    public void print1ToMaxOfNDigits(int n){
        if (n <= 0) {
            return;
        }

        char[] num = new char[n + 1];
        num[n] = '\0';
        for (int i = 0; i < 10; i++){
            num[n] = (char)('0' + i);
            print1ToMaxOfNDigitsRecursively(num, n, 0);
            System.out.println();
        }

    }

    public void print1ToMaxOfNDigitsRecursively(char[] number, int length, int index){
        if (index == length - 1){
            printNum(number);
            return;
        }
        for (int i = 0; i < 10; i++){
            number[index + 1] = (char)('0' + i);
            print1ToMaxOfNDigitsRecursively(number, length, index + 1);
        }
    }

    public void printNum(char[] nums){
        if (nums == null || nums.length == 0)
            return;

        for (int i = 0; i < nums.length; i++){
            if (nums[i] != '0'){
                System.out.print(nums[i] + ' ');
            }
        }

    }
}
