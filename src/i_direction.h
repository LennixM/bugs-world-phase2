#ifndef __i_direction__
#define __i_direction__

#include "instruction.h"

class I_direction: public Instruction {
    public:
        void execute(Bug b);
        void parse(string args);
    private:
        tdirection d;
        tstate x;
        tstate y;
};

#endif