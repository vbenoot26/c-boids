#include "context.h"

struct Context buildContext() {
  return (struct Context) {
    .boidAmount = 50,
    .visionDistance = 50,
    .separationDistance = 25,

    .fps = 60,
    .screenWidth = 800,
    .screenHeight = 600
  };
}
