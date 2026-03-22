#include "boid.h"
#include "calculator.h"
#include "context.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw(struct Boid boid, Color color) {
  DrawCircle(boid.location.x, boid.location.y, 5, color);
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

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);

    for (int i = 0; i < boidsAmount; i++) {
      getNeighbours(&ctx, boids[i], boids, ctx.boidAmount, neighbours,
                    &neighbourAmount, separators, &separatorAmount);

      update(&ctx, boids + i, neighbours, neighbourAmount, separators,
             separatorAmount);

      draw(boids[i], WHITE);
    }

    EndDrawing();
  }
  CloseWindow();
  return 0;
}
