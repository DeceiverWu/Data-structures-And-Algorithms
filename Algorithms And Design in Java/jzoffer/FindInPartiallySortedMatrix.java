package com.deceiver.jzoffer;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-07
 * Time: 下午11:47
 */
public class FindInPartiallySortedMatrix {

    /**
     * 二维数组中的查找
     * 1  2  8  9
     * 2  4  9  12
     * 4  7  10 13
     * 6  8  11 15
     *
     */
    public boolean find(int[][] matrix, int rows, int columns, int target){
        if (matrix == null || rows < 0 || columns < 0)
            return false;

        boolean found = false;
        while (matrix != null && rows > 0 && columns > 0){
            if (matrix[rows][columns] == target){
                found = true;
                break;
            }else if (matrix[rows][columns] > target){
                columns--;
            }else {
                rows++;
            }
        }
        return found;
    }
}
