#include <iostream> 
#include "../bug.h"

using namespace std;

//======Testing start_resting() & rested()=======//
bool test_rested_Bug(){
    Bug b(1,12,14);
    return b.rested();
}

bool test_resting_Bug(){
    Bug b(1,12,14);
    b.start_resting();
    return b.rested() == false;
}

bool test_resting_Bug_count(){
    Bug b(1,12,14);
    b.start_resting();
    for (int i = 0; i < 14; i++){
        if (b.rested() == true){
            return false;
        }
    }
    return true;
}


//======Testing get_color()=======//
bool test_get_color_Bug(){
    Bug b(1,10,14);
    return b.get_color() == 1;
}

bool test_get_color_Bug_default(){
    Bug b;
    return b.get_color() == -1;
}

//======Testing get_progid()=======//
bool test_get_progid_Bug(){
    Bug b(1,10,14);
    return b.get_progid() == 10;
}

bool test_get_progid_Bug_default(){
    Bug b;
    return b.get_progid() == -1;
}


//=======Testing set_food() & get_food()=======//

bool test_set_get_food_Bug_true(){
    Bug b(1,10,14);
    b.set_food(true);
    return b.get_food() == true;
}

bool test_set_get_food_Bug_false(){
    Bug b(1,10,14);
    b.set_food(false);
    return b.get_food() == false;
}

bool test_get_food_Bug_default(){
    Bug b;
    return b.get_food() == false;
}

//=======Testing set_position() & get_position()=======//

bool test_set_get_position_Bug(){
    Bug b(1,10,14);
    pair<int,int> p(1,2), tmp;
    b.set_position(p);
    tmp = b.get_position();
    return tmp.first == 1 && tmp.second == 2;
}

bool test_set_position_Bug_except(){
    Bug b(1,10,14);
    bool t1, t2, t3;
    try{
        pair<int,int> p1(-1,-1);
        b.set_position(p1);
        t1 = false;
    }
    catch(const invalid_argument &ia){
        t1 = true;
        try{
            pair<int,int> p2(1,-1);
            b.set_position(p2);
            t2 = false;
        }
        catch(const invalid_argument &ia){
            t2 = true;
            try{
                pair<int,int> p3(-1,1);
                b.set_position(p3);
                t3 = false;
            }
            catch(const invalid_argument &ia){
                t3 = true;
            }
        }
    }
    return t1 && t2 && t3;
}

bool test_get_position_Bug_default(){
    Bug b;
    pair<int,int> p = b.get_position();
    return p.first == 0 && p.second == 0;
}

//=========Testing is_dead() & kill() ============//
bool test_is_dead_Bug_default(){
    Bug b;
    return b.is_dead() == false;
}

bool test_kill_Bug() {
    Bug b(1,10,14);
    b.kill();
    return b.is_dead() == true;
}

bool test_kill_Bug_except(){
    try{
        Bug b(1,10,14);
        b.kill();
        b.kill();
        return false;
    }
    catch(const string &msg){
        return true;
    }
}


//=======Testing get and set direction=========//
bool test_get_direction_Bug_default(){
    Bug b;
    return b.get_direction() == -1;
}

bool test_set_get_direction_Bug(){
    Bug b(1,12,13);
    b.set_direction(1);
    return b.get_direction() == 1;
}

bool test_set_direction_Bug_except(){
    Bug b(1,12,13);
    try{
        b.set_direction(10);
        return false;
    }
    catch(const invalid_argument &ia){
        return true;
    }
}

//=======Testing get & set state()=========//
bool test_get_state_Bug_default(){
    Bug b;
    return b.get_state() == -1;
}

bool test_set_get_state_Bug(){
    Bug b(1,12,13);
    b.set_state(1);
    return b.get_state() == 1;
}

bool test_set_state_Bug_except(){
    Bug b(1,12,13);
    try{
        b.set_state(-1);
        return false;
    }
    catch(const invalid_argument &ia){
        return true;
    }
}


int main() {
    int fail = 0;
    //=======Results of get and set state=========//
    if(!test_get_state_Bug_default()){
        cout << "Default bug state failed!"<<endl;
        fail++;
    }

    if (!test_set_get_state_Bug()){
        cout << "set and get state failed!" << endl;
        fail++;
    }

    if (!test_set_state_Bug_except()){
        cout << "set_state() with wrong input failed!" << endl;
        fail++;
    }
    //=======Results of get and set direction=========//
    if(!test_get_direction_Bug_default()){
        cout << "Default bug direction failed!"<<endl;
        fail++;
    }

    if (!test_set_get_direction_Bug()){
        cout << "set and get direction failed!" << endl;
        fail++;
    }

    if (!test_set_direction_Bug_except()){
        cout << "set_direction() with wrong input failed!" << endl;
        fail++;
    }
  
    //========Results of test rested() & start_resting()======//
    if(!test_rested_Bug()){
        cout << "rested() failed!" << endl;
        fail ++;
    }

    if(!test_resting_Bug()){
        cout << "start_resting() failed!" << endl;
        fail++;
    }

    if(!test_resting_Bug_count()){
        cout << "rested() with counting failed!" << endl;
        fail++;
    }
    
    
    //=======Results of test get_color()==========//
    if (!test_get_color_Bug()){
        cout<< "get_color() failed!"<<endl;
        fail++;
    }
    if (!test_get_color_Bug_default()){
        cout<< "Default bug color failed!"<<endl;
        fail++;
    }

    //======Results of test get_progid()========//
    if (!test_get_progid_Bug()){
        cout<< "get_progid() failed!"<<endl;
        fail++;
    }
    
    if (!test_get_progid_Bug_default()){
        cout<< "Default bug id failed!"<<endl;
        fail++;
    }
    //=========Results of test is_dead() & kill()=================//
    if (!test_is_dead_Bug_default()){
        cout<< "is_dead() failed!"<<endl;
        fail++;    
    }
    if (!test_kill_Bug()){
        cout<< "kill() failed!"<<endl;
        fail++;    
    }
    if (!test_kill_Bug_except()){
        cout<< "kill() with multiple calling failed!"<<endl;
        fail++;    
    }
    //=======Results of set_food() & get_food()=======//
    if (!test_set_get_food_Bug_true()){
        cout << "set_food(true) is failed!" << endl;
        fail++;
    }
    if(!test_set_get_food_Bug_false()){
        cout << "set_food(false) is failed!" << endl;
        fail++;
    }
    if (!test_get_food_Bug_default()){
        cout << "Default bug food values failed!" << endl;
        fail++;
    }

    //=======Results of set_position() & get_position()=======//
    if (!test_get_position_Bug_default()){
        cout << "Default bug position value failed!" << endl;
        fail++;
    }
    
    if (!test_set_position_Bug_except()){
        cout << "set_position() with wrong input failed!" << endl;
        fail++;    
    }
    
    if (!test_set_get_position_Bug()){
        cout << "set_position() failed!" << endl;
        fail++;      
    }
    
    cout << fail << " amount of tests failed." << endl;
    return (EXIT_SUCCESS);
}

