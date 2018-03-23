/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   I_mark.h
 * 
 *
 * Created on March 22, 2018, 4:54 PM
 */

#ifndef I_MARK_H
#define I_MARK_H
#include "instruction.h"

class I_mark{
    private:
        int m;
        int tstate;
       
    public:
        void execute(Bug b);
        void parse(string args);
            
};


#endif /* I_MARK_H */

