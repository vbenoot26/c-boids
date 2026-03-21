#include "boid.h"
#include <stdlib.h>

struct Boid newBoid(int width, int height) {
  int x = random() % width;
  int y = random() % height;

  int speedx = random() % 10 - 5;
  int speedy = random() % 10 - 5;

  struct Boid boid = {
    {x, y}, {speedx, speedy}
  };

  return boid;
} 
