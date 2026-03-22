#include "boid.h"
#include "calculator.h"
#include "raylib.h"
#include <stdlib.h>
#include <time.h>

const int screenWidth = 800;
const int screenHeight = 600;

const struct Boid testBoid = {
    {((float)screenWidth) / 2.0, ((float)screenHeight) / 2.0}, {0, 0}};

void draw(struct Boid boid, Color color) {
  DrawCircle(boid.location.x, boid.location.y, 5, color);
}

void init() { srandom(time(NULL)); }

int main() {
  init();

  const int boidsAmount = 50;

  InitWindow(screenWidth, screenHeight, "CIRCLE");
  SetTargetFPS(60);

  struct Boid boids[boidsAmount];
  struct Boid neighbours[boidsAmount];

  for (int i = 0; i < boidsAmount; i++) {
    boids[i] = newBoid(screenWidth, screenHeight);
  }

  while (!WindowShouldClose()) {
    BeginDrawing();

    draw(testBoid, RED);

    ClearBackground(BLACK);
    for (int i = 0; i < boidsAmount; i++) {
      boids[i].location.x += boids[i].speed.x;
      boids[i].location.x = (int)boids[i].location.x % screenWidth;
      boids[i].location.y += boids[i].speed.y;
      boids[i].location.y = (int)boids[i].location.y % screenHeight;

      draw(boids[i], WHITE);
    }

    int amNeighbours =
        getNeighbours(testBoid, boids, boidsAmount, neighbours, boidsAmount);

    for (int i = 0; i < amNeighbours; i++) {
      draw(neighbours[i], MAGENTA);
    }

    EndDrawing();
  }
  CloseWindow();
  return 0;
}
