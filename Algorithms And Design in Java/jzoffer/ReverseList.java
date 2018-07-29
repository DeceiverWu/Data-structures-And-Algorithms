package com.deceiver.jzoffer;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-20
 * Time: 下午11:23
 */
public class ReverseList {

    class ListNode{
        int val;
        ListNode next = null;
    }

    public ListNode reverseList(ListNode pHead){
        if (pHead == null || pHead.next == null){
            return pHead;
        }

        ListNode newHead = null;
        ListNode midNode = pHead;
        ListNode nextNode = null;
        ListNode preNode = null;

        while (midNode != null){
            nextNode = midNode.next;
            if (nextNode == null){
                newHead = midNode;
            }

            midNode.next = preNode;
            preNode = midNode;
            midNode = nextNode;
        }
        return newHead;
    }
}
