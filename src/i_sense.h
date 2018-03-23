#ifndef __i_sense__
#define __i_sense__

#include "instruction.h"

class I_sense: public Instruction {
private:
    tsensedir dir;
    tstate x;
    tstate y;
    tcondition condition;
};

#endif