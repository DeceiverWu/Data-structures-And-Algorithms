package com.deceiver.jzoffer;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-23
 * Time: 下午4:56
 */
public class BinaryTreeTransToDoubleList {

    class TreeNode {
        int val;
        TreeNode left = null;
        TreeNode right = null;
    }

    private TreeNode lastNode = null;

    public TreeNode convert(TreeNode root) {
        if (root == null){
            return null;
        } else if (root.left == null && root.right == null){
            return root;
        }

        TreeNode left = convert(root.left);
        TreeNode pNode = left;
        while (pNode != null && pNode.right != null){
            pNode = pNode.right;
        }

        if (left != null){
            pNode.right = root;
            root.left = pNode;
        }

        TreeNode right = convert(root.right);

        if (right != null){
            right.left = root;
            root.right = right;
        }
        return left != null ? left : root;
    }

    // 记录子树链表的最后一个节点，终结点只可能为只含左子树的非叶节点与叶节点
    public TreeNode convert2(TreeNode root){
        if (root == null){
            return null;
        } else if (root.left == null && root.right == null){
            // 最后的一个节点可能为最右侧的叶节点
            lastNode = root;
            return root;
        }
        // 1.将左子树构造成双链表，并返回链表头节点
        TreeNode left = convert2(root.left);
        // 3.如果左子树链表不为空的话，将当前root追加到左子树链表
        if (left != null){
            lastNode.right = root;
            root.left = lastNode;
        }
        // 当根节点只含左子树时，则该根节点为最后一个节点
        lastNode = root;
        // 4.将右子树构造成双链表，并返回链表头节点
        TreeNode right = convert2(root.right);
        // 5.如果右子树链表不为空的话，将该链表追加到root节点之后
        if (right != null){
            right.left = root;
            root.right = right;
        }
        return left != null ? left : root;
    }

}
