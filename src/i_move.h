#ifndef __i_move__
#define __i_move__

#include "instruction.h"

class I_move: public Instruction {
    public:
        void execute(Bug b);
        void parse(string args);
    private:
        tstate x;
        tstate y;
};

#endif