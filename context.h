#ifndef CONTEXT_H
#define CONTEXT_H

struct Context {
  int boidAmount;

  int visionDistance;
  int separationDistance;

  // Raylib specific
  int fps;

  int screenWidth;
  int screenHeight;
};

struct Context buildContext();

#endif // CONTEXT_H
