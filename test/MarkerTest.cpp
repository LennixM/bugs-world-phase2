#include "../marker.h"

using namespace std;


//=========Testing set_marker()=================//
bool test_set_Marker(){
    Marker m;
    m.set_marker(4,1);
    return m.get_marker() == 1<<10;
}

bool test_set_Marker_except(){
    Marker m;
    try{
        m.set_marker(10,10);
        return false;
    }
    catch (const invalid_argument &ia){
        return true;
    }
}

bool test_set_Marker_except_color(){
    Marker m;
    try{
        m.set_marker(2,10);
        return false;
    }
    catch (const invalid_argument &ia){
        return true;
    }
}

bool test_set_Marker_except_marker(){
    Marker m;
    try{
        m.set_marker(10,1);
        return false;
    }
    catch (const invalid_argument &ia){
        return true;
    }
}
//=========Testing clear_marker()=================//
bool test_clear_Marker(){
    Marker m;
    m.set_marker(4,1);
    m.clear_marker(4,1);
    return m.get_marker() == 0;
}

bool test_clear_Marker_except(){
    Marker m;
    try{
        m.clear_marker(10,10);
        return false;
    }
    catch (const invalid_argument &ia){
        return true;
    }
}

bool test_clear_Marker_except_color(){
    Marker m;
    try{
        m.clear_marker(4,10);
        return false;
    }
    catch (const invalid_argument &ia){
        return true;
    }
}

bool test_clear_Marker_except_marker(){
    Marker m;
    try{
        m.clear_marker(10,1);
        return false;
    }
    catch (const invalid_argument &ia){
        return true;
    }
}

//=========Testing check_marker()=================//
bool test_check_Marker(){
    Marker m;
    m.set_marker(4,1);
    return m.check_marker(4,1);
}

bool test_check_Marker_except_marker(){
    Marker m;
    m.set_marker(4,1);
    try{
        m.check_marker(10,1);
        return false;
    }
    catch (const invalid_argument &ia){
        return true;
    }
}

bool test_check_Marker_except_color(){
    Marker m;
    m.set_marker(4,1);
    try{
        m.check_marker(4,10);
        return false;
    }
    catch (const invalid_argument &ia){
        return true;
    }
}

bool test_check_Marker_except(){
    Marker m;
    m.set_marker(4,1);
    try{
        m.check_marker(19,10);
        return false;
    }
    catch (const invalid_argument &ia){
        return true;
    }
}


//=========Testing clear_other_marker()=================//
bool test_check_other_Marker(){
    Marker m;
    m.set_marker(4,1);
    return m.check_other_marker(1);
}

bool test_check_other_Marker_except(){
    Marker m;
    try{
        m.check_other_marker(7);
        return false;
    }
    catch (const invalid_argument &ia){
        return true;
    }
}

int main() {
    int fail = 0;
    //=========Result of test set_marker()=================//
    if (!test_set_Marker()) {
        cout << "set_marker() failed!" << endl;
        fail++;
    }

    if (!test_set_Marker_except_color()){
        cout << "set_marker() with wrong input color failed!" << endl;
        fail++;
    }
    
    if (!test_set_Marker_except_marker()){
        cout << "set_marker() with wrong input marker failed!" << endl;
        fail++;
    }
    
    if (!test_set_Marker_except()) {
        cout << "set_marker() with wrong input marker and color failed!" << endl;
        fail++;
    }
    
    //=========Result of test clear_marker()=================//
    if (!test_clear_Marker()) {
        cout << "clear_marker() failed!" << endl;
        fail++;
    }
    
    if (!test_clear_Marker_except_color()) {
        cout << "clear_marker() with wrong input color failed!" << endl;
        fail++;
    }

    if (!test_clear_Marker_except_marker()) {
        cout << "clear_marker() with wrong input marker passed!" << endl;
        fail++;
    }

    if (!test_clear_Marker_except()) {
        cout << "clear_marker() with wrong input marker and color failed!" << endl;
        fail++;
    }
    
    
    //=========Result of test check_marker()=================//
    if (!test_check_Marker()) {
        cout << "check_marker() failed!" << endl;
        fail++;
    }

    if (!test_check_Marker_except_color()){
        cout << "check_other_marker() with wrong marker input failed!" << endl;
        fail++;
    }
    
    if (!test_check_Marker_except_marker()){
        cout << "check_other_marker() with wrong color input failed!" << endl;
        fail++;
    }
    
    if (!test_check_Marker_except()){
        cout << "check_other_marker() with wrong color, marker input failed!" << endl;
        fail++;
    }
    
    
    //=========Result of test check_other_marker()=================//
    if (!test_check_other_Marker()) {
        cout << "check_other_marker() failed!" << endl;
        fail++;
    }
    
    if (!test_check_other_Marker_except()) {
        cout << "check_other_marker() with wrong input failed!" << endl;
        fail++;
    }

    cout << fail << " amount of tests failed." << endl;
    
    return (EXIT_SUCCESS);
}
