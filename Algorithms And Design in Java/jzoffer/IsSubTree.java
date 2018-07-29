package com.deceiver.jzoffer;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-21
 * Time: 下午1:16
 */
public class IsSubTree {

    class TreeNode{
        int val;
        TreeNode left = null;
        TreeNode right = null;
    }

    /**
     * 思路：参考剑指offer
     * 1、首先设置标志位result = false，因为一旦匹配成功result就设为true，
     *      剩下的代码不会执行，如果匹配不成功，默认返回false
     *
     * 2、递归思想，如果根节点相同则递归调用 matchSubTree（），
     *      如果根节点不相同，则判断tree1的左子树和tree2是否相同，
     *          再判断右子树和tree2是否相同
     *
     * 3、注意null的条件，HasSubTree中，如果两棵树都不为空才进行判断，
     *      matchSubTree中，如果Tree2为空，则说明第二棵树遍历完了，即匹配成功，
     *
     * tree1为空有两种情况:
     * （1）如果tree1为空&&tree2不为空说明不匹配，
     * （2）如果tree1为空，tree2为空，说明匹配。
     * @param srcRoot
     * @param subRoot
     * @return
     */
    public boolean isSubTree(TreeNode srcRoot, TreeNode subRoot){
        boolean result = false;
        if (srcRoot != null && subRoot != null){
            if (srcRoot.val == subRoot.val){
                //根节点匹配，进入左右子树匹配
                result = matchSubTree(srcRoot, subRoot);
            }
            //开始左子树匹配
            if (!result){
                result = isSubTree(srcRoot.left, subRoot);
            }
            //开始右子树匹配
            if (!result){
                result = isSubTree(srcRoot.right, subRoot);
            }
        }
        return result;
    }

    public boolean matchSubTree(TreeNode srcRoot, TreeNode subRoot){
        if (subRoot == null){
            return true;
        }
        if (srcRoot == null){
            return false;
        }

        if (srcRoot.val != subRoot.val){
            return false;
        }

        return matchSubTree(srcRoot.left, subRoot.left) && matchSubTree(srcRoot.right, subRoot.right);

    }
}
