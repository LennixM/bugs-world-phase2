#include "i_move.h"

using namespace std;

void I_move::execute(Bug b) {
    
}

void I_move::parse(string args) {
    string *argarr = strtok(args," ");
    this->x = (tstate)*(argarr);
    this->y = (tstate)*(argarr+1);
}

