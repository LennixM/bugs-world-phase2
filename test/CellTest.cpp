#include "../cell.h"

using namespace std;

//=============Testing set and get food========//
bool test_get_set_food_Cell() {
    Cell c('.');
    c.set_food(5);
    return c.get_food() == 5;
}

bool test_set_food_Cell() {
    Cell c('.');
    try{
        c.set_food(-5);
        return false;
    }
    catch(const invalid_argument &ia){
        return true;
    }
}

bool test_get_food_Cell_default() {
    Cell c('.');
    return c.get_food() == 0;
}




//==========Testing get and set occupant=========//
bool test_get_occupant_Cell_default(){
    Cell c1('.');
    Cell c2('#');
    Cell c3('-');
    Cell c4('+');
    Cell c5('2');
    Bug *b1 = c1.get_occupant();
    Bug *b2 = c2.get_occupant();
    Bug *b3 = c3.get_occupant();
    Bug *b4 = c4.get_occupant();
    Bug *b5 = c5.get_occupant();
    return b1 == nullptr && b2 == nullptr && b3 == nullptr \
            && b4 == nullptr && b5 == nullptr;
}

bool test_set_get_occupant_Cell(){
    Cell c1('.');
    Cell c2('-');
    Cell c3('+');
    Cell c4('2');
    Bug b(1,2,3);
    c1.set_occupant(&b);
    c2.set_occupant(&b);
    c3.set_occupant(&b);
    c4.set_occupant(&b);
    return  c1.get_occupant() == &b && c2.get_occupant() == &b \
	      && c3.get_occupant() == &b && c4.get_occupant() == &b;
}

//=========Testing cell types========//
bool test_black_home_Cell(){
    Cell c('-');
    return c.is_black_home_area() == true;
}
bool test_red_home_Cell(){
    Cell c('+');
    return c.is_red_home_area() == true;
}

bool test_obstacle_Cell(){
    Cell c('#');
    return c.get_obstructed() == true;
}




int main() {
    int fail = 0;
    //=====Results of set and get tests for occupant==========//
    if (!test_get_occupant_Cell_default()){
        cout << "Default occupant failed!" << endl;
        fail++;
    }
    if (!test_set_get_occupant_Cell()){
        cout << "set and get method failed!" << endl;
        fail++;
    }
    //========Results of cell types=============//
    if (!test_black_home_Cell()){
        cout << "Black home initialization failed!" << endl;
        fail++;
    }
    if (!test_red_home_Cell()){
        cout << "Red home initialization failed!" << endl;
        fail++;
    }
    if(!test_obstacle_Cell()){
        cout << "Obstructed initialization failed!" << endl;
        fail++;
    }
    
    //===========Results of food test===========//
    if(!test_get_set_food_Cell()) {
        cout << "set and get food failed!" << endl;
        fail++;
    }
    if(!test_set_food_Cell()){
        cout << "set_food() with wrong input failed!" << endl;
        fail++;
    }
    if(!test_get_food_Cell_default()) {
        cout << "get_food() default failed!" << endl;
    }
    
    cout << fail << " amount of test failed!" << endl;
    return (EXIT_SUCCESS);
}

