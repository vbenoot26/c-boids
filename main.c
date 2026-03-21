#include "boid.h"
#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw(struct Boid boid) {
  DrawCircle(boid.location.x, boid.location.y, 5, WHITE);
}

void init() { srandom(time(NULL)); }

int main() {
  init();

  const int screenWidth = 800;
  const int screenHeight = 600;

  const int boidsAmount = 50;

  InitWindow(screenWidth, screenHeight, "CIRCLE");
  SetTargetFPS(60);

  struct Boid boids[boidsAmount];

  for (int i = 0; i < boidsAmount; i++) {
    boids[i] = newBoid(screenWidth, screenHeight);
  }

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(BLACK);
    for (int i = 0; i < boidsAmount; i++) {
      boids[i].location.x += boids[i].speed.x;
      boids[i].location.x = (int)boids[i].location.x % screenWidth;
      boids[i].location.y += boids[i].speed.y;
      boids[i].location.y = (int)boids[i].location.y % screenHeight;

      draw(boids[i]);
    }
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
