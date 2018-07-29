package com.deceiver.jzoffer;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-21
 * Time: 上午10:48
 */
public class MergeListNode {

    class ListNode{
        int val;
        ListNode next = null;

        ListNode(int val){
            this.val = val;
        }
    }

    public ListNode merge(ListNode l1, ListNode l2){
        if (l1 == null){
            return l2;
        } else if (l2 == null){
            return l1;
        }

        ListNode pHead = null;

        if (l1.val < l2.val){
            pHead = l1;
            pHead.next = merge(l1.next, l2);
        } else {
            pHead = l2;
            pHead.next = merge(l1, l2.next);
        }

        return pHead;
    }
}
