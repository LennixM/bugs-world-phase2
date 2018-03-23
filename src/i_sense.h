#ifndef __i_sense__
#define __i_sense__


class I_sense: public Instruction {
    public:
        void execute(Bug);
        void parse(std::string);
    private:
        tsensedir dir;
        tstate x;
        tstate y;
        tcondition condition;
};

#endif