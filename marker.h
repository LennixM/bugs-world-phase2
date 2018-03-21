#ifndef MARKER_H
#define MARKER_H
   
#include <stdexcept> 
#include <iostream>

class Marker{

private:
    int bits; // 0-5 bits for black, 6-12 bits for red
    
public:
    ~Marker() {}
    Marker() {this->bits = 0;};
    int get_marker() {return bits;}
    
    void set_marker(int mark, int col){
        /*
         * Error handling for invalid arguments.
         * Checking col and mark
        */
        
        if ((mark > 5 || mark < 0) && !(col == 1 || col == 0)){
            throw std::invalid_argument("In \"" + std::string(__FILE__) + \
                                 "\" line:" + std::to_string(__LINE__)\
                                + "; Mark value must be between 0 and 5\
                                    and col value must be either 0(black) or 1(red)!");
        }
        
        if (mark > 5 || mark < 0){
            throw std::invalid_argument("In \"" + std::string(__FILE__) + \
                                         "\" line:" + std::to_string(__LINE__)\
                                        + "; Mark value must be between 0 and 5!");
        }
        if (!(col == 1 || col == 0)){
            throw std::invalid_argument("In \"" + std::string(__FILE__) + \
                                         "\" line:" + std::to_string(__LINE__)\
                                        + "; col value must be either 0(black) or 1(red)!");
        }
                
        if (this->check_marker(mark, col)) { // Printing small warning!
            std::cout << "Trying to set an existing Mark!" << std::endl;
        }
        
        // For setting the marker for given colored bug.
        this->bits |= 1<<(mark+6*col);

    }
    
    void clear_marker (int mark, int col) {
        /*
         * Error handling for invalid arguments.
         * Checking col and mark
        */
        if ((mark > 5 || mark < 0) && !(col == 1 || col == 0)){
            throw std::invalid_argument("In \"" + std::string(__FILE__) + \
                                 "\" line:" + std::to_string(__LINE__)\
                                + "; Mark value must be between 0 and 5\
                                    and col value must be either 0(black) or 1(red)!");
        }
        
        if (mark > 5 || mark < 0){
            throw std::invalid_argument("In \"" + std::string(__FILE__) + \
                                         "\" line:" + std::to_string(__LINE__)\
                                        + "; Mark value must be between 0 and 5!");
        }
        if (!(col == 1 || col == 0)){
            throw std::invalid_argument("In \"" + std::string(__FILE__) + \
                                         "\" line:" + std::to_string(__LINE__)\
                                        + "; col value must be either 0(black) or 1(red)!");
        }
        
        if (!this->check_marker(mark, col)) { // Printing small warning!
            std::cout << "Trying to clear an empty Mark!" << std::endl;
        }
        // Clearing the given marker of given colored bug.
        this->bits &= ~1<<(mark+6*col);
    }
        
    bool check_marker (int mark, int col) {
        /*
         * Error handling for invalid arguments.
         * Checking col and mark
        */
        if ((mark > 5 || mark < 0) && !(col == 1 || col == 0)){
            throw std::invalid_argument("In \"" + std::string(__FILE__) + \
                                 "\" line:" + std::to_string(__LINE__)\
                                + "; Mark value must be between 0 and 5\
                                    and col value must be either 0(black) or 1(red)!");
        }
        
        if (mark > 5 || mark < 0){
            throw std::invalid_argument("In \"" + std::string(__FILE__) + \
                                         "\" line:" + std::to_string(__LINE__)\
                                        + "; Mark value must be between 0 and 5!");
        }
        if (!(col == 1 || col == 0)){
            throw std::invalid_argument("In \"" + std::string(__FILE__) + \
                                         "\" line:" + std::to_string(__LINE__)\
                                        + "; col value must be either 0(black) or 1(red)!");
        }
         
         // Checking is marker exist for given colored bug.
         return this->bits & 1<<(mark+6*col);
     }
    
    bool check_other_marker(int col) {
       /*
        * Error handling for invalid argument.
        * Checking col
        */
        if (!(col == 1 || col == 0)){
            throw std::invalid_argument("In \"" + std::string(__FILE__) + \
                                         "\" line:" + std::to_string(__LINE__)\
                                        + "; col value must be either 0(black) or 1(red)!");
        }
        
        // Checks is there any marker in given colored bug.
        for (int i = 0; i < 6; i ++){
            if (this->bits & 1<<(i + 6*col)){
                return true;
            }
        }
        return false;
        
    }
    
    


};


#endif /* MARKER_H */

