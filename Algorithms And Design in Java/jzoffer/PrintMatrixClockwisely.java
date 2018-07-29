package com.deceiver.jzoffer;

import java.util.ArrayList;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-21
 * Time: 下午4:48
 */
public class PrintMatrixClockwisely {

    public ArrayList<Integer> printMatrix(int[][] matrix){
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0){
            return null;
        }

        ArrayList<Integer> list = new ArrayList<>();
        int rows = matrix.length - 1;
        int columns = matrix[0].length - 1;
        int row = 0;
        int column = 0;

        while (row <= rows && column <= columns){
            // left -> right
            for (int i = column; i <= columns; i++){
                list.add(matrix[row][i]);
            }

            // top -> bottom
            if (row < rows){
                for (int i = row + 1; i <= rows; i++){
                    list.add(matrix[i][columns]);
                }
            }

            // right -> left
            if (column < columns && row < rows){
                for (int i = columns - 1; i >= column; i--){
                    list.add(matrix[rows][i]);
                }
            }

            // bottom -> top
            if (row < rows && column < columns){
                for (int i = rows - 1; i >= row + 1; i--){
                    list.add(matrix[i][column]);
                }
            }

            // Reduce the clockwise range
            row++; column++; columns--; rows--;
        }
        return list;
    }
}
