#ifndef __i_pickup__
#define __i_pickup__

#include "instruction.h"

class I_sense: public Instruction {
private:
    tstate x;
    tstate y;
};

#endif