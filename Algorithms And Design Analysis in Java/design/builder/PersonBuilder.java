package com.deceiver.design.builder;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-29
 * Time: 下午4:31
 */
public interface PersonBuilder {

    void buildHead();
    void buildBody();
    void buildFoot();
    Person buildPerson();
}
