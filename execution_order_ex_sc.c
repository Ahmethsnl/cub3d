int main ()
{
    int gameRunning = 1;
    while (gameRunning) 
    {
        handleInput();   // 1. Giriş işleme
        updateWorld();   // 2. Oyun dünyasını güncelle
        castRays();      // 3. Raycasting hesapla
        renderFrame();   // 4. Görselleştir
        displayOutput(); // 5. Çıkış işle
        // gameRunning = 1; // Oyun devam etsin
        gameRunning = 0; // Oyunu sonlandır
    }
    return 0;
}

// Execution Order of Functions in a Game Loop