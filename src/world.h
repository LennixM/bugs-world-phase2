/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   world.h
 * 
 *
 * Created on March 22, 2018, 5:05 PM
 */

#ifndef WORLD_H
#define WORLD_H


#include "cell.h"

class World{

private:
    int Length, Width;
    Cell **board;
public:
    ~World() {
        
        // freeing the memory!
        for (int i = 0; i < this->Length; i++)
                delete[] board[i];
        delete[] board;
    }
    World(){};
    void load(std::string filenames);
    void error(std::string message) {
        throw message;
    }
    Cell get_cell(std::pair<int,int> pos){
        int i = pos.first, j = pos.second;
        
        if ((i < 0 || j < 0) || (i >= this->Width || j >= this->Length)){
            this->error("Invalid position!");
        }
        
        return this->board[i][j];
    }
    std::pair<int, int> adjacent(int dir, std::pair<int, int> pos);
    int other_color (int col) {return 1 - col;}
    int red_food();
    int black_food();
    int red_count();
    int black_count();
    int winner() {
        if (this->red_food() > this->black_food()){
            return 1;
        }
        else if (this->black_food() > this->red_food()){
            return 0;
        }
        else {} // We need to decide something!
    }
    void set_marker_at(std::pair<int, int> pos, int col, int mark);
    void clear_marker_at(std::pair<int, int> pos, int col, int mark);
    bool check_marker_at(std::pair<int, int> pos, int col, int mark);
    bool check_other_marker_at(std::pair<int, int> pos, int col);
};


#endif /* WORLD_H */


