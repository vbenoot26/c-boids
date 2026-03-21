#include "raylib.h"

struct Bal {
  Vector2 location;
  Vector2 speed;
};

void draw(struct Bal model) {
  BeginDrawing();

  ClearBackground(BLACK);
  DrawCircle(model.location.x, model.location.y, 20, WHITE);

  EndDrawing();
}

int main() {
  const int screenWidth = 800;
  const int screenHeight = 600;

  InitWindow(screenWidth, screenHeight, "CIRCLE");
  SetTargetFPS(60);

  struct Bal bal = {{200.0, 200.0}, {10.0, 10.0}};

  while (!WindowShouldClose()) {

    bal.location.x += bal.speed.x;
    bal.location.x = (int) bal.location.x % screenWidth;
    bal.location.y += bal.speed.y;
    bal.location.y = (int) bal.location.y % screenHeight;
    
    draw(bal);
  }
  CloseWindow();
  return 0;
}


