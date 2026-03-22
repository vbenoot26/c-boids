#ifndef CALC_H
#define CALC_H

void getNeighbours(const struct Context ctx, const struct Boid boid,
                   struct Boid *allboids, int boidsAmount,
                   struct Boid *neighbourlist, int *neighbourAmount,
                   int maxNeighbours, struct Boid *separatorlist,
                   int *separatorAmount);

void update(struct Context ctx, struct Boid *boid,
            struct Boid *neighbours, int neighbourAmount,
            struct Boid *separators, int separatorAmount
          );

#endif
