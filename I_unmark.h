/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   I_unmark.h
 * 
 *
 * Created on March 22, 2018, 4:54 PM
 */

#ifndef I_UNMARK_H
#define I_UNMARK_H

using namespace std;

class I_umark{
    private:
        int m;
        int tstate;
       
    public:
        void execute(Bug b);
        void parse(string args);
            
};

#endif /* I_UNMARK_H */

