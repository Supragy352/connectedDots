#include <math.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_HEIGHT 1000
#define SCREEN_WIDTH 800
#define numDots 50
#define lineThreshold 0.2

//-------------------------------------------------------------------------

typedef struct Dot {
    int x;
    int y;
    int vx;
    int vy;
    int radius;
    Color color;
} Dot;

void DrawDot(Dot *dot) {
    DrawCircle(dot->x, dot->y, dot->radius, dot->color);
}

int calculateDistance(Dot* dot1, Dot* dot2) {
    return sqrt(pow(abs((dot1->x - dot2->x)), 2) + pow(abs((dot1->y - dot2->y)), 2));
}

void ConnectDots(Dot* dot) {
    for (int i = 0; i < numDots; i++)
    {
        Dot *dot1 = dot;
        Dot *dot2 = dot + i;

        if (calculateDistance(dot1, dot2) <= (lineThreshold * SCREEN_WIDTH)) {
            // DrawLineEx((Vector2)(10,10), (Vector2)(10,10), 1.0f, WHITE);
           // DrawLine(dot1->x, dot1->y, dot2->x, dot2->y,WHITE);
           DrawLine(dot1->x, dot1->y, dot2->x, dot2->y, (Color) {17, 63, 86, 120});
        }
    }
}

void MoveDot(Dot *dot) {
    dot->x += dot->vx;
    dot->y += dot->vy;
}

void SnapDot(Dot* dot) {
    if ((dot->x >= SCREEN_WIDTH) || (dot->x <= 0)) {
        dot->vx = dot->vx * (-1);
    }
    if ((dot->y >= SCREEN_HEIGHT) || (dot->y <= 0)) {
        dot->vy = dot->vy * (-1);
    }
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

    Dot d[numDots] = {};

    for (int i = 0; i < numDots; i++) {
        d[i].x = rand() % SCREEN_WIDTH + 1;
        d[i].y = rand() % SCREEN_HEIGHT + 1;
        d[i].vx = (rand() % 3) - 1;
        d[i].vy = (rand() % 3) - 1;
        d[i].radius = 3;
        d[i].color = (Color) {17, 80, 90, 230} ;
        // d[i].color = WHITE ;
    }


    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground((Color) {24, 24, 24, 255});
            for (int i = 0; i < numDots; ++i)
            {
                DrawDot(&d[i]);
                MoveDot(&d[i-1]);
                ConnectDots(&d[i]);
                SnapDot(&d[i]);
            }
        EndDrawing();
    }
    return 0;
}