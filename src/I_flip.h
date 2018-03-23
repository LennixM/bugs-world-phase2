/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   I_flip.h
 * 
 *
 * Created on March 22, 2018, 4:54 PM
 */

#ifndef I_FLIP_H
#define I_FLIP_H
#include "instruction.h"

using namespace std;

class I_flip: public Instruction{
    private:
        tposition p;
        tstate xtate;
        tstate ystate;
        int seed;
    public:
        void execute(Bug b);
        void parse(string args);
        int randomint();
            
};



#endif /* I_FLIP_H */

