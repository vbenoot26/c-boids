#include "boid.h"
#include "context.h"
#include "math.h"
#include <raylib.h>

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

Vector2 calculateSeparation(const struct Boid *boid,
                            const struct Boid separators[],
                            int separatorAmount) {
  Vector2 location1 = boid->location;

  float dx = 0;
  float dy = 0;

  for (int i = 0; i < separatorAmount; i++) {
    Vector2 location2 = separators[i].location;
    dx += location1.x - location2.x;
    dy += location1.y - location2.y;
  }

  return (Vector2){dx, dy};
}

float clampSpeedComponent(float speed, float max) {
  if (speed > max) {
    return max;
  } else if (speed < -max) {
    return -max;
  }

  return speed;
}

float updateLocationcomponent(int max, float location, float speed) {
  float result = location + speed;

  if (result > max) {
    return 0;
  } else if (location < 0) {
    return max;
  }

  return result;
}

void update(const struct Context *ctx, struct Boid *boid,
            const struct Boid *neighbours, const int neighbourAmount,
            const struct Boid *separators, const int separatorAmount) {
  Vector2 separation = calculateSeparation(boid, separators, separatorAmount);

  boid->speed.x += ctx->avoidFactor * separation.x;
  boid->speed.y += ctx->avoidFactor * separation.y;

  boid->speed.x = clampSpeedComponent(boid->speed.x, ctx->maxspeed);
  boid->speed.y = clampSpeedComponent(boid->speed.y, ctx->maxspeed);

  boid->location.x = updateLocationcomponent(ctx->screenWidth, boid->location.x, boid->speed.x);
  boid->location.y = updateLocationcomponent(ctx->screenWidth, boid->location.y, boid->speed.y);
}
