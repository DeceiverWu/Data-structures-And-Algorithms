package com.deceiver.design.builder;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-29
 * Time: 下午4:34
 */
public class ManBuilder implements PersonBuilder {

    private Person person;

    public ManBuilder() {
        this.person = new Person();
    }

    @Override
    public void buildHead() {
        person.setHead("建造头部...");
    }

    @Override
    public void buildBody() {
        person.setBody("建造身体...");
    }

    @Override
    public void buildFoot() {
        person.setFoot("建造四肢...");
    }

    @Override
    public Person buildPerson() {
        return person;
    }
}
