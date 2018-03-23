#ifndef CELL_H
#define CELL_H

   

#include "bug.h"
#include "marker.h"

class Cell{

private:
    Bug* occupant = nullptr;
    // Default cell
    bool obstructed = false;
    int food = 0;
    bool home_black_bug = false;
    bool home_red_bug = false;

public:
    Marker mark;
    ~Cell() {}
    Cell() {}
    Cell(char symb){
        /*
         * The following code sets the properties according to 
         * passed "symb".
         * Note: Symbols taken from bug.pdf
         */
        if (symb == '#'){ 
            this->obstructed = true;
        }
        else if (symb >= '1' && symb <= '9'){
            this->food = symb - '0';
        }
        else if (symb == '+') {
            this->home_red_bug = true;
        }
        else if (symb == '-') {
            this->home_black_bug = true;
        }
        else if (symb == '.'){}
        else{
            throw std::invalid_argument("In \"" + std::string(__FILE__) + \
                   "\" line:" + std::to_string(__LINE__)\
                   + "; Wrong symb(\""+symb+"\") entered!");
        }
    };
    // get and set methods
    Bug* get_occupant () {
        return this->occupant;
    }
    void set_occupant (Bug* new_occupant) {
        if (this->obstructed){
            throw std::invalid_argument("In \"" + std::string(__FILE__) + \
                                 "\" line:" + std::to_string(__LINE__) \
                                + "; Obstructed cell cannot have occupant!");
        }
	this->occupant = new_occupant;
    }
    int get_food() {return this->food;}
    void set_food(int new_food) {
        if (new_food < 0){
            throw std::invalid_argument("In \"" + std::string(__FILE__) + \
                                         "\" line:" + std::to_string(__LINE__)\
                                        + "; Food cannot be negative value!");
        }
        this->food = new_food;
    }
    bool get_obstructed() {return this->obstructed;}
    
    // check homes
    bool is_black_home_area () {return this->home_black_bug;}
    bool is_red_home_area () {return this->home_red_bug;}
    

};


#endif /* CELL_H */

