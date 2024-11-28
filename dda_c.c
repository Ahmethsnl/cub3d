#include <stdio.h>
#include <math.h>

void dda(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;
    int k;
    float xIncrement, yIncrement;
    float x = x1;
    float y = y1;

    if (abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }

    xIncrement = dx / (float)steps;
    yIncrement = dy / (float)steps;

    printf("x = %f, y = %f\n", x, y);

    for (k = 0; k < steps; k++)
    {
        x += xIncrement;
        y += yIncrement;
        printf("x = %f, y = %f\n", x, y);
    }
}

int main()
{
    dda(1, 1, 5, 5);
    return 0;
}
