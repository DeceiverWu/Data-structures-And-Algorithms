package com.deceiver.jzoffer;

import java.util.ArrayList;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-23
 * Time: 上午1:07
 */
public class FindPathByTargetSum {


    class TreeNode {
        int val = 0;
        TreeNode left = null;
        TreeNode right = null;
    }

    public ArrayList<ArrayList<Integer>> findPath(TreeNode root, int target) {
        ArrayList<ArrayList<Integer>> paths = new ArrayList<>();
        if (root == null || target <= 0){
            return paths;
        }
        int currentSum = 0;
        ArrayList<Integer> path = new ArrayList<>();
        findPath(root, paths, target, currentSum, path);
        return paths;
    }

    public void findPath(TreeNode root, ArrayList<ArrayList<Integer>> paths, int target,
                                                  int currentSum, ArrayList<Integer> currentPath){
        currentSum += root.val;
        currentPath.add(root.val);

        boolean isLeaf = (root.left == null && root.right == null);
        if (isLeaf && currentSum == target){
            paths.add(new ArrayList<>(currentPath));
        }

        if (root.left != null){
            findPath(root.left, paths, target, currentSum, currentPath);
        }
        if (root.right != null){
            findPath(root.right, paths, target, currentSum, currentPath);
        }
        currentPath.remove(currentPath.size() - 1);
    }
}
