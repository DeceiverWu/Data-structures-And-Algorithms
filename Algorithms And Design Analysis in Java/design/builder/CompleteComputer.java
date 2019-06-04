package com.deceiver.design.builder;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-29
 * Time: 下午4:47
 */
public class CompleteComputer implements ComputerBuilder {

    private Computer computer;

    public CompleteComputer() {
        this.computer = new Computer();
    }

    @Override
    public void buildCpu() {
        computer.setCpu("set cpu...");
    }

    @Override
    public void buildHd() {
        computer.setHd("set hd...");
    }

    @Override
    public void buildRam() {
        computer.setRam("set ram...");
    }

    @Override
    public void buildBios() {
        computer.setBios("set bios...");
    }

    @Override
    public Computer buildComputer() {
        return computer;
    }


}
