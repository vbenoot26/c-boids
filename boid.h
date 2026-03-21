#ifndef BOID_H
#define BOID_H

#include "raylib.h"

struct Boid {
  Vector2 location;
  Vector2 speed;
};

struct Boid newBoid(int width, int height);

#endif // BOID_H
