#include "i_pickup.h"

using namespace std;

void I_pickup::execute(Bug b) {
    
}

void I_pickup::parse(string args) {
    string *argarr = strtok(args," ");
    this->x = (tstate)*(argarr);
    this->y = (tstate)*(argarr+1);
}


