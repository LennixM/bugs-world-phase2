#include "i_direction.h"
#include "bug.h"
#include <string>

using namespace std;

void I_direction::execute(Bug b) {
    if (this->d == b.get_direction()) {
        b.set_state(this->x);
    }
    else {
        b.set_state(this->y);
    }
}

void I_direction::parse(string args) {
    string *argarr = strtok(args," ");
    this->d = (tstate)*argarr;
    this->x = (tstate)*(argarr+1);
    this->y = (tstate)*(argarr+2);
}