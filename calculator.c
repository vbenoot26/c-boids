#include "boid.h"
#include "context.h"
#include "math.h"
#include <raylib.h>
#include <stdio.h>

float getDistance(const struct Boid boid1, const struct Boid boid2) {
  Vector2 loc1 = boid1.location;
  Vector2 loc2 = boid2.location;

  return sqrt((loc1.x - loc2.x) * (loc1.x - loc2.x) +
              (loc1.y - loc2.y) * (loc1.y - loc2.y));
}

void getNeighbours(const struct Context *ctx, const struct Boid boid,
                   struct Boid *allboids, int boidsAmount,
                   struct Boid *neighbourlist, int *neighbourAmount,
                   struct Boid *separatorlist, int *separatorAmount) {
  int foundNeighbours = 0;
  int foundSeparators = 0;

  for (int i = 0; i < boidsAmount; i++) {
    float dist = getDistance(boid, allboids[i]);
    if (dist < ctx->visionDistance) {
      neighbourlist[foundNeighbours] = allboids[i];
      foundNeighbours++;

      if (foundNeighbours > ctx->boidAmount) {
        *neighbourAmount = -1;
        return;
      }
    }

    if (dist < ctx->separationDistance) {
      separatorlist[foundSeparators] = allboids[i];
      foundSeparators++;
      if (foundSeparators > ctx->boidAmount) {
        *separatorAmount = -1;
        return;
      }
    }
  }

  *neighbourAmount = foundNeighbours;
  *separatorAmount = foundSeparators;
}

void update(const struct Context *ctx, struct Boid *boid,
            struct Boid *neighbours, int neighbourAmount,
            struct Boid *separators, int separatorAmount) {
  boid->location.x += boid->speed.x;
  boid->location.x = (int)boid->location.x % ctx->screenWidth;
  boid->location.y += boid->speed.y;
  boid->location.y = (int)boid->location.y % ctx->screenHeight;
}
