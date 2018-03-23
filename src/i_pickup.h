#ifndef __i_pickup__
#define __i_pickup__

class I_pickup: public Instruction {
    public:
        void execute(Bug);
        void parse(std::string);
    private:
        tstate x;
        tstate y;
};

#endif