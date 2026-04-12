#include "grid.h"
#include "boid.h"
#include "context.h"
#include <math.h>
#include <stdlib.h>

bool squareContains(struct Square *square, struct Boid boid) {
  int x = boid.location.x;
  int y = boid.location.y;
  bool xOk = square->xMin <= x && x < square->xMin + square->width;
  bool yOk = square->yMin <= y && y < square->yMin + square->width;

  return xOk && yOk;
}

int getIndex(struct Grid *grid, int row, int column) {
  return row * grid->columns + column;
}

struct Grid *newGrid(struct Context ctx) {
  struct Grid *baby = malloc(sizeof(struct Grid));

  int width = ctx.visionDistance;

  baby->columns = ceil(((double)ctx.screenWidth) / width);
  baby->rows = ceil(((double)ctx.screenHeight) / width);

  baby->squares = malloc(sizeof(struct Square) * baby->rows * baby->columns);

  int currX = 0;
  int currY = 0;

  for (int row = 0; row < baby->rows; row++) {
    for (int col = 0; col < baby->columns; col++) {
      baby->squares[getIndex(baby, row, col)] =
          (struct Square){.xMin = currX,
                          .yMin = currY,
                          .width = ctx.visionDistance,
                          .boids = malloc(sizeof(struct Boid) * ctx.boidAmount),
                          .boidAmount = 0};

      currX += width;
    }

    currX = 0;
    currY += width;
  }

  return baby;
}
