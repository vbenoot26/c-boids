#include "context.h"

struct Context buildContext() {
  return (struct Context) {
    .boidAmount = 50,

    .visionDistance = 50,
    .separationDistance = 25,

    .avoidFactor = 0.05,
    .matchingFactor = 0.05,
    .centeringFactor = 0.0005,

    .maxspeed = 3,
    
    .fps = 60,
    .screenWidth = 800,
    .screenHeight = 600
  };
}
