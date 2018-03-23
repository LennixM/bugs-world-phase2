#include "i_sense.h"

using namespace std;

void I_sense::execute(Bug b) {
    
}

void I_sense::parse(string args) {
    string *argarr = strtok(args," ");
    this->dir = (tsensedir)*(argarr);
    this->x = (tstate)*(argarr+1);
    this->y = (tstate)*(argarr+1);
    this->condition = (tcondition)*(argarr+1);
}

