#include <math.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_HEIGHT 400
#define SCREEN_WIDTH 400

//-------------------------------------------------------------------------

typedef struct Dot {
    int x;
    int y;
    int radius;
    Color color;
} Dot;

void DrawDot(Dot *dot) {
    DrawCircle(dot->x, dot->y, dot->radius, dot->color);
}

int calculateDistance(Dot* dot1, Dot* dot2) {
    return sqrt(pow(abs((dot1->x - dot2->x)), 2) + pow(abs((dot1->y - dot2->y)), 2));
}

void connectDots(Dot *dot) {
    Dot *dot1 = dot;
    Dot *dot2 = dot + 1;
    if (calculateDistance(dot1, dot2) <= 250) {
       DrawLine(dot1->x, dot1->y, dot2->x, dot2->y, WHITE);
     }
}

void MoveDot(Dot *dot) {
    dot->x += (rand() % 11) - 5;
    dot->y += (rand() % 11) - 5;
}

// void connectDots(Dot* dot1, Dot* dot2) {
//     if (calculateDistance(dot1, dot2) <= 300) {
//         DrawLine(dot1->x, dot1->y, dot2->x, dot2->y, WHITE);
//     }
// }


//-------------------------------------------------------------------------


int main(int argc, char const *argv[])
{
    srand(time(NULL));
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Dots");
    SetTargetFPS(60);

    Dot d[20] = {};

    for (int i = 0; i < 20; i++) {
        d[i].x = rand() % 400 + 1;
        d[i].y = rand() % 400 + 1;
        d[i].radius = 3;
        d[i].color = WHITE;
    }


    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
            for (int i = 0; i < 20; ++i)
            {
                DrawDot(&d[i]);
                MoveDot(&d[i-1]);
                connectDots(&d[i]);
            }
        EndDrawing();
    }
    return 0;
}