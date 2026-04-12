#ifndef GRID_H
#define GRID_H

#include "boid.h"

struct Square {
  int xMin;
  int yMin;

  int width;
  
  struct Boid *boids;
  int boidAmount;
};

struct Grid {
  int rows;
  int columns;

  struct Square *squares;
};

struct Grid *newGrid(struct Context ctx);

#endif 
