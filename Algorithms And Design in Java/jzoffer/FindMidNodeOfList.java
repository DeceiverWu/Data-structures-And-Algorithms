package com.deceiver.jzoffer;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-20
 * Time: 下午10:33
 */
public class FindMidNodeOfList {

    class ListNode{
        int val;
        ListNode next = null;

        ListNode(int val){
            this.val = val;
        }
    }

    /**
     * 求链表的中间结点
     *
     * 两个指针，一个一步，一个两步，两步的到尾，那么一步的就到中间了
     *
     * @param pHead
     * @return
     */
    public ListNode finMidNodeOfList(ListNode pHead){
        if (pHead == null){
            return null;
        }

        ListNode p1 = pHead;
        ListNode p2 = pHead;

        while (p2.next != null){
            p1 = p1.next;
            p2 = p2.next.next;
        }
        return p1;
    }


    public boolean isCycle(ListNode pHead){
        if (pHead == null){
            return false;
        }

        ListNode pre = pHead;
        ListNode tail = pHead;

        while (pre.next != null){
            pre = pre.next.next;
            tail = tail.next;

            if (pre == tail){
                return true;
            }
        }
        return false;
    }
}
