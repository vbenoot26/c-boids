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

  const struct Boid testBoid = {
      {(float)ctx.screenWidth / 2.0, (float)ctx.screenHeight / 2}, {0.0, 0.0}};

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);

    DrawCircle(testBoid.location.x, testBoid.location.y, ctx.visionDistance, GRAY);

    for (int i = 0; i < boidsAmount; i++) {
      update(&ctx, boids + i, neighbours, neighbourAmount, separators,
             separatorAmount);
    }

    getNeighbours(&ctx, testBoid, boids, ctx.boidAmount, neighbours,
                  &neighbourAmount, separators, &separatorAmount);

    for (int i = 0; i < neighbourAmount; i++) {
      draw(neighbours[i], RED);
    }

    for (int i = 0; i < separatorAmount; i++) {
      draw(separators[i], MAGENTA);
    }

    EndDrawing();
  }
  CloseWindow();
  return 0;
}
