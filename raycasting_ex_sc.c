#include <stdio.h>
#include <math.h>

// 2D ortam boyutu
#define MAP_WIDTH 8
#define MAP_HEIGHT 8

// 2D ortam (0 = boş, 1 = duvar)
int map[MAP_HEIGHT][MAP_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1},
};

// Işını döndürür ve çarptığı yeri bulur
void cast_ray(float startX, float startY, float dirX, float dirY) {
    int mapX = (int)startX;
    int mapY = (int)startY;

    // Işın yönüne göre adımlar
    float deltaDistX = fabs(1 / dirX);
    float deltaDistY = fabs(1 / dirY);

    float sideDistX, sideDistY;
    int stepX, stepY;

    // Işının başlangıç noktasındaki ilk kesişim uzaklıkları
    if (dirX < 0) {
        stepX = -1;
        sideDistX = (startX - mapX) * deltaDistX;
    } else {
        stepX = 1;
        sideDistX = (mapX + 1.0 - startX) * deltaDistX;
    }
    if (dirY < 0) {
        stepY = -1;
        sideDistY = (startY - mapY) * deltaDistY;
    } else {
        stepY = 1;
        sideDistY = (mapY + 1.0 - startY) * deltaDistY;
    }

    // Çarpma durumunu takip et
    int hit = 0;
    int side; // Hangi duvar yönüne çarptığını tutar (0 = X, 1 = Y)

    while (!hit) {
        // X veya Y yönünde ilerle
        if (sideDistX < sideDistY) {
            sideDistX += deltaDistX;
            mapX += stepX;
            side = 0;
        } else {
            sideDistY += deltaDistY;
            mapY += stepY;
            side = 1;
        }

        // Çarpma kontrolü
        if (map[mapY][mapX] == 1) hit = 1;
    }

    // Çarpma mesafesini hesapla
    float perpWallDist;
    if (side == 0)
        perpWallDist = (mapX - startX + (1 - stepX) / 2) / dirX;
    else
        perpWallDist = (mapY - startY + (1 - stepY) / 2) / dirY;

    printf("Hit at (%d, %d), distance: %f\n", mapX, mapY, perpWallDist);
}

int main() {
    // Başlangıç pozisyonu ve yönü
    float posX = 3.5, posY = 3.5; // Başlangıç noktası
    float dirX = -1.0, dirY = 0.0; // Işın yönü

    // Işını döndür ve sonucu yazdır
    cast_ray(posX, posY, dirX, dirY);

    return 0;
}

//2D raycasting Algorithm