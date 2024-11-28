#include <stdio.h>

// Karekök hesaplama (Newton-Raphson)
double sqrt_manual(double x) {
    if (x < 0) return -1; // Negatif sayılar için hata

    double guess = x / 2.0; // İlk tahmin
    double epsilon = 0.000001; // Hassasiyet

    while (guess * guess - x > epsilon || x - guess * guess > epsilon) {
        guess = (guess + x / guess) / 2.0; // Newton-Raphson formülü
    }

    return guess;
}

// Sinüs hesaplama (Taylor serisi)
double sin_manual(double x) {
    double term = x; // İlk terim
    double sum = x;  // Toplam
    int n = 1;       // İlk faktöriyel çarpanı

    // Yaklaşımı 10 terime kadar genişlet
    for (int i = 1; i <= 10; i++) {
        n += 2; // Çift olmayan sayı artışı (3, 5, 7 ...)
        term *= -1 * x * x / (n * (n - 1)); // Yeni terimi hesapla
        sum += term; // Toplama ekle
    }

    return sum;
}

double cos_manual(double x) {
    double term = 1; // İlk terim
    double sum = 1;  // Toplam
    int n = 0;       // Faktöriyel çarpanı

    for (int i = 1; i <= 10; i++) {
        n += 2; // Çift katsayılar (2, 4, 6 ...)
        term *= -1 * x * x / (n * (n - 1)); // Yeni terimi hesapla
        sum += term; // Toplama ekle
    }

    return sum;
}

double cot_manual(double x) {
    double tan_x = tan_manual(x); // Önce tanjant hesaplanır

    if (tan_x == 0) {
        printf("Kotanjant tanımsız (tan(x) = 0)\n");
        return 0; // Tanımsız durumu
    }

    return 1 / tan_x; // Kotanjant hesaplanır
}

double tan_manual(double x) {
    double sin_x = sin_manual(x); // Önce sinüs hesaplanır
    double cos_x = cos_manual(x); // Sonra kosinüs hesaplanır

    if (cos_x == 0) {
        printf("Tanjant tanımsız (cos(x) = 0)\n");
        return 0; // Tanımsız durumu
    }

    return sin_x / cos_x; // Tanjant hesaplanır
}

int main() {
    double x, y;

    // Kullanıcıdan giriş al
    printf("x değerini girin: ");
    scanf("%lf", &x);

    printf("y değerini girin: ");
    scanf("%lf", &y);

    // Hipotenüsü hesapla
    double r = sqrt_manual(x * x + y * y);

    // Sinüs hesapla
    double z = sin_manual(r);

    printf("z = sin(sqrt(x^2 + y^2)) = %lf\n", z);

    return 0;
}

int secant_manual(double x) {
    return 1 / cos_manual(x);
}

int cosecant_manual(double x) {
    return 1 / sin_manual(x);
}

int main() {
    double angle;

    // Kullanıcıdan radyan cinsinden açı al
    printf("Açı (radyan) girin: ");
    scanf("%lf", &angle);

    // Hesaplamalar
    double sin_val = sin_manual(angle);
    double cos_val = cos_manual(angle);
    double tan_val = tan_manual(angle);
    double cot_val = cot_manual(angle);

    // Sonuçları yazdır
    printf("sin(%.2f) = %.6f\n", angle, sin_val);
    printf("cos(%.2f) = %.6f\n", angle, cos_val);
    printf("tan(%.2f) = %.6f\n", angle, tan_val);
    printf("cot(%.2f) = %.6f\n", angle, cot_val);

    return 0;
}
/*Bu program, kullanıcının girdiği açı için sinüs, kosinüs, tanjant ve kotanjant değerlerini hesaplar.
Programın çalışması için, kullanıcıdan bir açı girmesi beklenir. Program, bu açı için sinüs, kosinüs, tanjant ve kotanjant değerlerini hesaplar ve ekrana yazdırır.
Program, sinüs ve kosinüs değerlerini Taylor serisi kullanarak hesaplar. Tanjant ve kotanjant değerlerini ise sinüs ve kosinüs değerlerini kullanarak hesaplar.
Program, tanjant ve kotanjant fonksiyonlarının tanımsız olduğu durumları kontrol eder ve ekrana uygun bir hata mesajı yazdırır. */
// Programın çıktısı şu şekilde olacaktır:
// Açı (radyan) girin: 1
// sin(1.00) = 0.841471
// cos(1.00) = 0.540302
// tan(1.00) = 1.557408
// cot(1.00) = 0.642092