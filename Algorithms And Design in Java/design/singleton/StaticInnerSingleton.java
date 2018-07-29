package com.deceiver.design.singleton;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-29
 * Time: 上午10:37
 */
public class StaticInnerSingleton {

    private static class LazyHolder {
        private static final StaticInnerSingleton INSTANCE = new StaticInnerSingleton();
    }

    private StaticInnerSingleton() {

    }

    public static final StaticInnerSingleton getInstance(){
        return LazyHolder.INSTANCE;
    }

}
