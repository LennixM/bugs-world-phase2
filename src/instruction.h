/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   instruction.h
 * 
 *
 * Created on March 22, 2018, 4:54 PM
 */

#ifndef INSTRUCTION_H
#define INSTRUCTION_H
#include "world.h"

using namespace std; 

class Instruction: public World //should inherit from Program
{
    World w;
    virtual void execute(Bug b);
    virtual void parse(string args);
};


#endif /* INSTRUCTION_H */

