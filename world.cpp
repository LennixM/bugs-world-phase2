#include "world.h"
#include <iostream>
#include <fstream>
#include <exception>


using namespace std;



void World::load(string filenames){
    ifstream inFile;
    
    inFile.open(filenames);
    if (!inFile) {
        this->error("Could not open the file!");
    }
    //Assuming the first two letters are width and length of the board!
    inFile >> this->Width;
    inFile >> this->Length;
    this->board = new Cell*[this->Length];
    for(int i = 0; i < this->Length; ++i)
        this->board[i] = new Cell[this->Width];
    
    int i = 0, j = 0, count = 0;
    char symb;
    
    while(inFile >> symb){

        i = count/this->Width; 
        j = count - i*this->Width;
       
        // Error handling is wrong symbol entered
        try{
            Cell tmp(symb);
            this->board[i][j] = tmp;
        }
        catch (const invalid_argument& ia){
            this->error(ia.what());
        }

        count ++;
    }
    if(count > this->Width*this->Length || count < this->Width*this->Length){
        this->error("Not enough symbols for the map!");
    }
    inFile.close();
}

pair<int, int> World::adjacent(int dir, pair<int, int> pos){
    // This function taken from bug.pdf page 3!
    
    int i = pos.first, j = pos.second;
    pair<int, int> tmp;

    if ((i < 0 || j < 0) || (i >= this->Width || j >= this->Length)){
        this->error("Invalid position!");
    }

    if (dir > 5 || dir < 0){
        this->error("Invalid direction!");
    }
    if (dir == 0){
        tmp.first = i + 1;
        tmp.second = j;
        return tmp;
    }

    if (dir == 1){
        if (j%2 == 0){
            tmp.first = i;
            tmp.second = j + 1;
            return tmp;
        }
        else {
            tmp.first = i+1;
            tmp.second = j+1;
            return tmp;
        }
    }
    else if (dir == 2){
        if (j%2 == 0){
            tmp.first = i - 1;
            tmp.second = j + 1;
            return tmp;
        }
        else {
            tmp.first = i;
            tmp.second = j + 1;
            return tmp;
        }
    }
    else if (dir == 3){
        tmp.first = i - 1;
        tmp.second = j;
        return tmp;
    }
    else if (dir == 4){
        if (j%2 == 0){
            tmp.first = i - 1;
            tmp.second = j - 1;
            return tmp;
        }
        else {
            tmp.first = i;
            tmp.second = j - 1;
            return tmp;
        }
    }
    else{
        if (j%2 == 0){
            tmp.first = i;
            tmp.second = j - 1;
            return tmp;
        }
        else {
            tmp.first = i +1;
            tmp.first = j -1;
            return tmp;
        }
    }
 }

int World::red_food() {
    int count = 0;
    for (int i = 0; i < this->Width; i++){
        for(int j = 0; j < this->Length; j++){
            if (this->board[i][j].is_red_home_area()){
                count += this->board[i][j].get_food();
            }
        }        
    }
    return count;
}

int World::black_food() {
    int count = 0;
    for (int i = 0; i < this->Width; i++){
        for(int j = 0; j < this->Length; j++){
            if (this->board[i][j].is_black_home_area()){
                count += this->board[i][j].get_food();
            }
        }        
    }
    return count;
}

int World::black_count() {
    int count = 0;
    for (int i = 0; i < this->Width; i++){
        for(int j = 0; j < this->Length; j++){
            Bug* b = this->board[j][i].get_occupant();
            
            if (b == nullptr || b->get_color() == 1){
                continue;
            }
            count++;
             
        }
    }
    return count;
}

int World::red_count() {
    int count = 0;
    for (int i = 0; i < this->Width; i++){
        for(int j = 0; j < this->Length; j++){
            Bug* b = this->board[j][i].get_occupant();
            
            if (b == nullptr || b->get_color() == 0){
                continue;
            }
            count++;
        }        
    }
    return count;
}


void World::set_marker_at(std::pair<int, int> pos, int col, int mark){
    int i = pos.first, j = pos.second;

    if ((i < 0 || j < 0) || (i >= this->Width || j >= this->Length)){
        this->error("Invalid position!");
    }

    try {
        this->board[i][j].mark.set_marker(mark, col);
    }
    catch (const invalid_argument& ia){
        this->error(ia.what());
    }
}
void World::clear_marker_at(std::pair<int, int> pos, int col, int mark){
    int i = pos.first, j = pos.second;

    if ((i < 0 || j < 0) || (i >= this->Width || j >= this->Length)){
        this->error("Invalid position!");
    }

    try {
        this->board[i][j].mark.clear_marker(mark, col);
    }
    catch (const invalid_argument& ia){
        this->error(ia.what());
    }
}
bool World::check_marker_at(std::pair<int, int> pos, int col, int mark){
    int i = pos.first, j = pos.second;

    if ((i < 0 || j < 0) || (i >= this->Width || j >= this->Length)){
        this->error("Invalid position!");
    }

    try {
        return this->board[i][j].mark.check_marker(mark, col);
    }
    catch (const invalid_argument& ia){
        this->error(ia.what());
        return false;
    }
}
bool World::check_other_marker_at(std::pair<int, int> pos, int col){
    int i = pos.first, j = pos.second;

    if ((i < 0 || j < 0) || (i >= this->Width || j >= this->Length)){
        this->error("Invalid position!");
    }

    try {
        return this->board[i][j].mark.check_other_marker(col);
    }
    catch (const invalid_argument& ia){
        this->error(ia.what());
        return false;
    }
}
