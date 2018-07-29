package com.deceiver.design.builder;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-29
 * Time: 下午4:47
 */
public class ComputerDirection {

    public Computer buildComputer(ComputerBuilder builder){
        builder.buildCpu();
        builder.buildHd();
        builder.buildBios();
        builder.buildRam();
        return builder.buildComputer();
    }
}
