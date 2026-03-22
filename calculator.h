#ifndef CALC_H
#define CALC_H

int getNeighbours(struct Boid boid,
                  struct Boid *allboids, int boidsAmount,
                  struct Boid *neighbourlist, int maxNeighbours);

void update(struct Context ctx, struct Boid *boid, struct Boid *neighbours, int neighbourAmount);

#endif
