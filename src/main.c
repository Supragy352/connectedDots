#include <math.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCREEN_HEIGHT 800
#define SCREEN_WIDTH 800
#define numDots 30
#define lineThreshold 0.2

//-------------------------------------------------------------------------

typedef struct Dot {
    Vector2 pos;
    Vector2 vel;
    int radius;
    Color color;
} Dot;

void DrawDot(Dot *dot) {
    DrawCircle((int)dot->pos.x,(int) dot->pos.y,(int) dot->radius, dot->color);
}

int calculateDistance(Dot* dot1, Dot* dot2) {
    return sqrt(pow(abs((int)(dot1->pos.x - dot2->pos.x)), 2) + pow(abs((int)(dot1->pos.y - dot2->pos.y)), 2));
}

void ConnectDots(Dot* dot) {
    for (int i = 0; i < numDots; i++)
    {
        Dot *dot1 = dot;
        Dot *dot2 = dot + i;

        if (calculateDistance(dot1, dot2) <= (lineThreshold * SCREEN_WIDTH)) {
            // DrawLineEx((Vector2)(10,10), (Vector2)(10,10), 1.0f, WHITE);
           DrawLine((int) dot1->pos.x,(int) dot1->pos.y,(int) dot2->pos.x,(int) dot2->pos.y, (Color) {17, 63, 86, 120});
        }
    }
}

void MoveDot(Dot *dot) {
    dot->pos.x += dot->vel.x;
    dot->pos.y += dot->vel.y;
}

void SnapDot(Dot* dot) {
    if ((int)(dot->pos.x >= SCREEN_WIDTH) || (int) (dot->pos.x <= 0)) {
        dot->vel.x = dot->vel.x * (-1);
    }
    if ((int)(dot->pos.y >= SCREEN_HEIGHT) || (int)(dot->pos.y <= 0)) {
        dot->vel.y = dot->vel.y * (-1);
    }
}

// void connectDots(Dot* dot1, Dot* dot2) {
//     if (calculateDistance(dot1, dot2) <= 300) {
//         DrawLine(dot1->pos.x, dot1->pos.y, dot2->pos.x, dot2->pos.y, WHITE);
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
        d[i].pos.x = rand() % SCREEN_WIDTH + 1;
        d[i].pos.y = rand() % SCREEN_HEIGHT + 1;
        d[i].vel.x = (rand() % 5) - 2;
        d[i].vel.y = (rand() % 5) - 2;
        d[i].radius = 3;
        d[i].color = (Color) {17, 80, 90, 230} ;
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