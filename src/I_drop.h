/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   I_drop.h
 *
 *
 * Created on March 22, 2018, 4:55 PM
 */

#ifndef I_DROP_H
#define I_DROP_H
#include "instruction.h"

class I_drop{
    private:
        int state;

    public:
        void execute(Bug b);
        void parse(string args);
};



#endif /* I_DROP_H */

