#include "boid.h"
#include "calculator.h"
#include "context.h"
#include "grid.h"
#include "raylib.h"
#include <stdlib.h>
#include <time.h>

void draw(struct Boid boid, Color color) {
  DrawPixel(boid.location.x, boid.location.y, color);
}

void init(const struct Context *ctx) {
  srandom(time(NULL));

  InitWindow(ctx->screenWidth, ctx->screenHeight, "CIRCLE");
  SetTargetFPS(ctx->fps);
}

int main() {
  const struct Context ctx = buildContext();
  init(&ctx);

  int boidsAmount = ctx.boidAmount;

  struct Boid boids[boidsAmount];
  struct Boid neighbours[boidsAmount];
  struct Boid separators[boidsAmount];

  int neighbourAmount, separatorAmount;

  for (int i = 0; i < boidsAmount; i++) {
    boids[i] = newBoid(ctx.screenWidth, ctx.screenHeight);
  }

  struct Grid *grid = newGrid(ctx);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);

    for (int i = 0; i < boidsAmount; i++) {
      getNeighbours(&ctx, boids[i], boids, ctx.boidAmount, neighbours,
                    &neighbourAmount, separators, &separatorAmount);

      update(&ctx, boids + i, neighbours, neighbourAmount, separators,
             separatorAmount);

    }

    for (int i = 0; i < boidsAmount; i++) {
      draw(boids[i], WHITE);
    }
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
