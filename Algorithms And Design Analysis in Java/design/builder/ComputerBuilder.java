package com.deceiver.design.builder;

/**
 * Created with IntelliJ IDEA.
 * Description:
 * Author: deceiver
 * Date: 2018-07-29
 * Time: 下午4:45
 */
public interface ComputerBuilder {

   void buildCpu();
   void buildHd();
   void buildRam();
   void buildBios();
   Computer buildComputer();
}
