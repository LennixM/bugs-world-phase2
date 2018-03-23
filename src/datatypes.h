/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   datatypes.h
 * Author: lennartmeyer
 *
 * Created on March 23, 2018, 10:47 PM
 */

#ifndef DATATYPES_H
#define DATATYPES_H

/* declare new datatype for the Bug state */
  typedef int tstate;

  /* declare new datatype for the Bug direction */
  typedef int tdirection;

  /* declare new datatype for the Bug position */
  typedef struct t_tposition {
    int x;
    int y;
  } tposition;
  typedef int tcolor;
  /* Data type for marker */
  typedef int tmark;
  typedef int tsensedir;
  typedef int tleftright;
  typedef int tcondition;
  


#endif /* DATATYPES_H */

