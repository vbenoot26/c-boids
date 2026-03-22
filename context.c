#include "context.h"

struct Context buildContext() {
  return (struct Context) {
    .boidAmount = 50,

    .visionDistance = 50,
    .separationDistance = 25,

    .turnFactor = 0.2,
    .avoidFactor = 0.05,
    .matchingFactor = 0.05,
    
    .fps = 60,
    .screenWidth = 800,
    .screenHeight = 600
  };
}
