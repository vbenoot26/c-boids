#include "boid.h"
#include "context.h"
#include "calculator.h"
#include "raylib.h"
#include <stdlib.h>
#include <time.h>

void draw(struct Boid boid, Color color) {
  DrawCircle(boid.location.x, boid.location.y, 5, color);
}

void init() { srandom(time(NULL)); }

int main() {
  init();

  const struct Context ctx = buildContext();

  int boidsAmount = ctx.boidAmount;

  InitWindow(ctx.screenWidth, ctx.screenHeight, "CIRCLE");
  SetTargetFPS(60);

  struct Boid boids[boidsAmount];
  struct Boid neighbours[boidsAmount];

  for (int i = 0; i < boidsAmount; i++) {
    boids[i] = newBoid(ctx.screenWidth, ctx.screenHeight);
  }

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);
    for (int i = 0; i < boidsAmount; i++) {
      update(ctx, boids + i, (void *)0, 0);
      draw(boids[i], WHITE);
    }

    EndDrawing();
  }
  CloseWindow();
  return 0;
}
