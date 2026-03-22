#ifndef CALC_H
#define CALC_H

#include "context.h"
#include "boid.h"

void getNeighbours(const struct Context *ctx, const struct Boid boid,
                   struct Boid *allboids, int boidsAmount,
                   struct Boid *neighbourlist, int *neighbourAmount,
                   struct Boid *separatorlist, int *separatorAmount
                 );

void update(const struct Context *ctx, struct Boid *boid,
            struct Boid *neighbours, int neighbourAmount,
            struct Boid *separators, int separatorAmount
          );

#endif
