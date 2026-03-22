#include "context.h"

struct Context buildContext() {
  return (struct Context) {
    .boidAmount = 50,

    .visionDistance = 200,
    .separationDistance = 100,

    .turnFactor = 0.2,
    .avoidFactor = 0.05,
    .matchingFactor = 0.05,

    .maxspeed = 20,
    .minspeed = 3,
    
    .fps = 60,
    .screenWidth = 800,
    .screenHeight = 600
  };
}
