#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point p1;
    Point p2;
} Line;

double distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    Line l;
    printf("Enter x1: ");
    scanf("%lf", &l.p1.x);
    printf("Enter y1: ");
    scanf("%lf", &l.p1.y);
    printf("Enter x2: ");
    scanf("%lf", &l.p2.x);
    printf("Enter y2: ");
    scanf("%lf", &l.p2.y);
    printf("Distance between points: %.2f\n", distance(l.p1, l.p2));
    printf("Press any key to exit...");
    scanf("%c");
    return 0;
}
// the program calculates the distance between two points