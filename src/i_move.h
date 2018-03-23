#ifndef __i_move__
#define __i_move__

#include <string>

class I_move: public Instruction {
    public:
        void execute(Bug);
        void parse(std::string);
    private:
        tstate x;
        tstate y;
};

#endif