#include <raylib.h>

#define SCREEN_HEIGHT 640
#define SCREEN_WIDTH 480 

void setup() {
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Dots");
	SetTargetFPS(120);
}

void update() {
	DrawFPS(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
	ClearBackground(RAYWHITE);
}