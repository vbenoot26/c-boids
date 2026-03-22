#include "context.h"
#include <stdio.h>

struct Context buildContext() {
  int boidAmount = (1080 * 920) / 100;
  printf("boids: %d\n", boidAmount);
  return (struct Context) {
    .boidAmount = boidAmount,

    .visionDistance = 100,
    .separationDistance = 5,

    .avoidFactor = 0.05,
    .matchingFactor = 0.05,
    .centeringFactor = 0.0005,

    .maxspeed = 3,
    
    .fps = 60,
    .screenWidth = 1080,
    .screenHeight = 920
  };
}
