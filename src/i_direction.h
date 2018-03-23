#ifndef __i_direction__
#define __i_direction__

#include <string>
#include "instruction.h"

class I_direction: public Instruction {
    public:
        void execute(Bug);
        void parse(std::string);
    private:
        tdirection d;
        tstate x;
        tstate y;
};

#endif