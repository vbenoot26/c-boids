#ifndef CALC_H
#define CALC_H

int getNeighbours(struct Boid boid,
                  struct Boid *allboids, int boidsAmount,
                  struct Boid *neighbourlist, int maxNeighbours);

#endif
