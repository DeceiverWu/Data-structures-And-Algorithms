package com.deceiver.jzoffer;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-23
 * Time: 上午11:18
 */
public class CloneListNode {

    class RandomListNode {
        int label;
        RandomListNode next = null;
        RandomListNode random = null;

        RandomListNode(int label) {
            this.label = label;
        }
    }

    public RandomListNode clone(RandomListNode pHead) {
        cloneNode(pHead);
        connectSiblingNode(pHead);
        return removeOriginNode(pHead);
    }

    /**
     * 将克隆的结点先链接在被克隆结点后面 N - > N'
     * @param pHead
     */
    public void cloneNode(RandomListNode pHead) {
        RandomListNode pNode = pHead;
        while (pNode != null){
            RandomListNode node = new RandomListNode(pNode.label);
            node.next = pNode.next;
            node.random = null;
            pNode.next = node;
            pNode = node.next;
        }
    }

    /**
     * 链接随机指针
     * @param pHead
     */
    public void connectSiblingNode(RandomListNode pHead){
        RandomListNode pNode = pHead;
        while (pNode != null){
            RandomListNode node = pNode.next;
            if (pNode.random != null) {
                node.random = pNode.random.next;
            }
            pNode = node.next;
        }
    }

    /**
     * 将原链表从复制链表分离
     * @param pHead
     * @return
     */
    public RandomListNode removeOriginNode(RandomListNode pHead){
        RandomListNode pNode = pHead;
        RandomListNode cloneHead = null;
        RandomListNode cloneNode = null;
        //确定复制链表头
        if (pNode != null){
            cloneHead = cloneNode = pNode.next;
            pNode.next = cloneHead.next;
            pNode = pNode.next;
        }
        //拆卸原链表和复制链表
        while (pNode != null){
            cloneNode.next = pNode.next;
            cloneNode = cloneNode.next;
            pNode.next = cloneNode.next;
            pNode = pNode.next;
        }

        return cloneHead;
    }
}
