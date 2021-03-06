/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bug.h
 * 
 *
 * Created on March 22, 2018, 5:03 PM
 */

#ifndef BUG_H
#define BUG_H
  
#include <stdexcept> 
#include <utility>

class Bug {
   
private:
    int color = -1; // 0: black, 1: red
    int state = -1; // 0 ... 9999
    int prog_id = -1;
    std::pair <int, int> pos; // Using pair object as pos.
    int direction = -1; // 0 ... 5
    int resting = -1;
    int remaining_rest = 0;
    bool food = false;
    bool dead = false;
public:
    Bug () {}; // Empty Constructor
    ~Bug () {};
    Bug(int i_col, int i_progid, int i_resting){
        /*
         * Error handling for invalid arguments.
         * Checking i_col and i_resting
         */
        if (!(i_col == 0 || i_col == 1)){
            throw std::invalid_argument("In \"" + std::string(__FILE__) + \
                                         "\" line:" + std::to_string(__LINE__)\
                                        + "; Wrong color number! Black:0, Red:1");
        }
        if (i_resting < 0){
            throw std::invalid_argument("In \"" + std::string(__FILE__) + \
                                         "\" line:" + std::to_string(__LINE__)\
                                        + "; Resting cannot be negative value!");
        }
        if (i_progid < 0){
            throw std::invalid_argument("In \"" + std::string(__FILE__) + \
                                         "\" line:" + std::to_string(__LINE__)\
                                        + "; Bug ID cannot be negative value!");
        }
        this->color = i_col;
        this->prog_id = i_progid;
        this->resting = i_resting;
        this->dead = false;   
    }
    void start_resting() {this->remaining_rest=this->resting;}
    bool rested() {
        
        if (this->remaining_rest == 0){
            return true;
        }
        
        this->remaining_rest--;
        return false;
         
    }
    
    int get_progid() {return this->prog_id;}
    int get_color() {return this->color;}
    
    int get_state() {return this->state;}
    void set_state(int new_state) {
        /*
         * Error handling for invalid arguments.
         * Checking new_state
         */
        if (new_state > 9999 || new_state < 0){
            throw std::invalid_argument("In \"" + std::string(__FILE__) + \
                                         "\" line:" + std::to_string(__LINE__)\
                                        + "; State value must be between 0 and 9999!");
        }
        this->state = new_state;
    }
    
    int get_direction() {return this->direction;}
    void set_direction(int new_direction) {
        if (new_direction > 5 || new_direction < 0){
            throw std::invalid_argument("In \"" + std::string(__FILE__) + \
                                         "\" line:" + std::to_string(__LINE__)\
                                        + "; Direction value must be between 0 and 5!");
        }
        this->direction = new_direction;
    }
    std::pair <int,int> get_position() {return this->pos;}
    void set_position(std::pair <int, int> &new_pos) {
        if (new_pos.first < 0 || new_pos.second < 0){
            throw std::invalid_argument("In \"" + std::string(__FILE__) + \
                                         "\" line:" + std::to_string(__LINE__)\
                                        + "; Position values must be greater than 0!");
        }
        this->pos = new_pos;
    }
    
    void set_food(bool new_food) {this->food = new_food;}
    bool get_food() {return this->food;}
    
    bool is_dead () {return this->dead;}
    void kill() {
        if (this->dead){
            throw "In \"" + std::string(__FILE__) + \
                  "\" line:" + std::to_string(__LINE__)\
                  + "; You can not kill a dead bug!";
        }
        this->dead = true;
    } // It might be wrong.
    
    
    
    


};

#endif /* BUG_H */

