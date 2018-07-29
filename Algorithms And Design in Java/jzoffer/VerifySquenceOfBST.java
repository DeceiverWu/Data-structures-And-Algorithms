package com.deceiver.jzoffer;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-21
 * Time: 下午11:12
 */
public class VerifySquenceOfBST {

    public boolean verifySquenceOfBST(int[] sequence){
        if(sequence == null || sequence.length == 0){
            return false;
        }
        return isTreeBST(sequence, 0, sequence.length - 1);
    }

    private boolean isTreeBST(int[] sequence, int start, int end){
        int root = sequence[end];

        // left sub tree is all smaller than root
        int i = start;
        for (; i < end; i++){
            if (sequence[i] > root){
                break;
            }
        }

        // find the element from right sub tree, if it has any element is smaller than root, return false;
        for (int j = i; j < end; j++){
            if (sequence[j] < root){
                return false;
            }
        }

        boolean left = true;
        if (i > 0){
            left = isTreeBST(sequence, 0, i - 1);
        }

        boolean right = true;
        if (i < end - 1){
            right = isTreeBST(sequence, i, end - 1);
        }
        return  left && right;
    }
}
