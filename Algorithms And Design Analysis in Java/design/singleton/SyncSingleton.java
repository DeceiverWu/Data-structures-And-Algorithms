package com.deceiver.design.singleton;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-29
 * Time: 上午10:30
 */
public class SyncSingleton {

    private static SyncSingleton instance = null;

    private SyncSingleton() {

    }

    public static synchronized SyncSingleton getInstance() {
        if (instance == null){
            instance = new SyncSingleton();
        }
        return instance;
    }
}
