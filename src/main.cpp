#include <iostream>
#include <fstream>

using namespace std;

#include "cell.h"
#include "bug.h"
#include "marker.h"
#include "world.h"
#include <utility>
#include <bitset>


int main() {
    try{
    Cell cd('2');
    cout << cd.get_food() << endl;
    Marker a;

    a.clear_marker(0,1);
   
    Bug b(0,1,1);
    pair<int, int> c(1,2);
    b.set_position(c);
    b.set_state(1000);
  
    
    bitset<16> y(a.get_marker());
    cout << y << endl;

    }
    catch (const invalid_argument& ia){
        cerr << ia.what() << endl;
    }
    
    //try {
        World a;
        a.load("testworld.txt");
        a.red_count();
    //}
    //catch (const string& ia){
    //    cerr << ia<< endl;
    //}
    
    

    
    return 0;
}

