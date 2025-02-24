#include <stdio.h>
#include <math.h>

// İki nokta arasında DDA algoritması ile bir çizgi çizin
void drawLine(float x0, float y0, float x1, float y1) {
    float dx = x1 - x0;
    float dy = y1 - y0;

    // Adım sayısını belirle
    int steps = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);

    // Artış değerlerini hesapla
    float xIncrement = dx / steps;
    float yIncrement = dy / steps;

    // Çizgi boyunca ilerle
    float x = x0;
    float y = y0;

    printf("Çizilen noktalar:\n");
    for (int i = 0; i <= steps; i++) {
        printf("(%d, %d)\n", (int)round(x), (int)round(y));
        x += xIncrement;
        y += yIncrement;
    }
}

int main() {
    float x0 = 2, y0 = 3; // Başlangıç noktası
    float x1 = 8, y1 = 6; // Bitiş noktası

    drawLine(x0, y0, x1, y1);
    return 0;
}

//DDA ile Çizgi İzleme