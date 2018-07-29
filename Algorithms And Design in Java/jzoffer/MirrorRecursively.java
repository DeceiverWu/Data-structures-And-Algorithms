package com.deceiver.jzoffer;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-21
 * Time: 下午5:13
 */
public class MirrorRecursively {


    class TreeNode{
        int val;
        TreeNode left = null;
        TreeNode right = null;
    }

    public void mirror(TreeNode root){
        if (root == null || (root.left == null && root.right == null)){
            return;
        }

        TreeNode tmp = root.left;
        root.left = root.right;
        root.right = tmp;

        if (root.left != null){
            mirror(root.left);
        }
        if (root.right != null){
            mirror(root.right);
        }
    }
}
