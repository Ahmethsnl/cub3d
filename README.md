# Bresenham ve DDA Algoritmaları: Karşılaştırma ve Kullanım Alanları

## 1. Bresenham Algoritması
Bresenham algoritması, iki nokta arasında bir çizgi oluşturmak için kullanılan etkili bir rasterleştirme yöntemidir. Bu algoritma, hangi piksellerin çizileceğini tam sayı aritmetiği kullanarak belirler. Kayan noktalı işlemler gerektirmediği için hızlı ve verimlidir.

### Algoritmanın Adımları
1. Başlangıç ve bitiş noktalarını (\(x_0, y_0\)) ve (\(x_1, y_1\)) belirleyin.
2. Çizginin eğimini hesaplayın:  
   \(\Delta x = x_1 - x_0\), \(\Delta y = y_1 - y_0\).  
3. Hata terimini başlatın:  
   \(p = 2\Delta y - \Delta x\).  
4. İlk noktayı çizin: (\(x_0, y_0\)).  
5. Çizgi boyunca ilerleyerek her piksel için:  
   - Eğer \(p < 0\): Bir sonraki piksel yatay yönde olur, \(p = p + 2\Delta y\) ile güncellenir.  
   - Eğer \(p \geq 0\): Bir sonraki piksel çapraz yönde olur, \(p = p + 2\Delta y - 2\Delta x\) ile güncellenir.

### Özellikler
- Tam sayı aritmetiği kullanılır, bu sayede hızlıdır.
- Donanım düzeyinde kolayca uygulanabilir.
- Özellikle düşük çözünürlüklü grafiklerde performansı yüksektir.

---

## 2. Digital Differential Analyzer (DDA) Algoritması
DDA algoritması, bir çizgi üzerindeki her pikselin koordinatını adım adım hesaplamak için kullanılan eğim tabanlı bir yöntemdir. Bu yöntem kayan noktalı işlemleri içerir.

### Algoritmanın Adımları
1. Başlangıç ve bitiş noktalarını (\(x_0, y_0\)) ve (\(x_1, y_1\)) belirleyin.
2. Çizginin uzunluğunu bulun:  
   \(\text{steps} = \max(|x_1 - x_0|, |y_1 - y_0|)\).  
3. Her bir adımda artış miktarını hesaplayın:  
   \(\Delta x = \frac{x_1 - x_0}{\text{steps}}\), \(\Delta y = \frac{y_1 - y_0}{\text{steps}}\).  
4. İlk noktayı çizin: (\(x_0, y_0\)).  
5. Çizgi boyunca \(\text{steps}\) kadar iterasyon yaparak:  
   - Bir sonraki pikseli hesaplayın: \(x = x + \Delta x\), \(y = y + \Delta y\).  
   - Koordinatları yuvarlayarak ekrana çizin.

### Özellikler
- Kayan noktalı hesaplamalar nedeniyle daha fazla işlem gerektirir.
- Daha basit bir yapıya sahiptir ancak modern donanımlarda genelde tercih edilmez.

---

## 3. Bresenham ve DDA Algoritmalarının Karşılaştırması
| **Özellik**           | **Bresenham Algoritması**      | **DDA Algoritması**           |
|------------------------|--------------------------------|--------------------------------|
| **Aritmetik Türü**     | Tam sayı                      | Kayan nokta                   |
| **Hesaplama Hızı**     | Daha hızlı                    | Daha yavaş                    |
| **Hassasiyet**         | Yuvarlama hatası yoktur       | Yuvarlama hatası olabilir     |
| **Karmaşıklık**        | Daha karmaşık                 | Daha basit                    |
| **Kullanım Alanı**     | Performans kritik yerlerde    | Genel ve basit uygulamalarda  |

---

## 4. DDA Algoritması ve Raycasting
Raycasting, oyun geliştirme ve görselleştirme alanında 3D sahneleri simüle etmek için kullanılan bir yöntemdir. Basitçe ifade etmek gerekirse, bir labirentte el feneriyle baktığınız yönü aydınlatmayı sağlayan bir tekniktir.

### DDA Algoritması ile Raycasting
Bir ışın (ray), harita üzerindeki hücreler (kareler) arasında adım adım ilerler. Bu ilerleme sırasında:  
1. Işının hangi hücrelerden geçtiği hesaplanır.  
2. Işının bir duvara çarpıp çarpmadığı kontrol edilir.  
3. Duvara çarptığı mesafe hesaplanır ve ekrana yansıtılır.  

---

## 5. Bresenham Algoritması ve Raycasting
Bresenham algoritması, raycasting sırasında ışının harita üzerinde hangi hücrelerden geçtiğini hızlı ve doğru bir şekilde hesaplamak için de kullanılabilir.  
- **Avantajı:** Tam sayı tabanlı hesaplamalar yaparak ışının izlediği yolu belirler ve performans açısından avantaj sağlar.

### Örnek Kod
Bresenham algoritması ile ışın ilerlemesini hesaplayan bir örnek:  

```c
int x = oyuncunun_x;
int y = oyuncunun_y;

int delta_x = hedef_x - oyuncunun_x;
int delta_y = hedef_y - oyuncunun_y;

int p = 2 * delta_y - delta_x;

while (x != hedef_x) {
    x += x_adimi; // X ekseninde ilerle
    if (p >= 0) {
        y += y_adimi; // Y ekseninde ilerle
        p += 2 * (delta_y - delta_x);
    } else {
        p += 2 * delta_y;
    }

    // Hücre kontrolü: Duvara çarptı mı?
    if (harita[x][y] == DUVAR) {
        ışık_uzaklığını_hesapla();
        break; // İşlem tamam
    }
}
```

## 6. Execution Order (Çalışma Sırası) ve Önemi
Raycasting algoritmalarında işlem sırası, ışınların doğru hesaplanması ve görselleştirilmesi için kritik önem taşır. İşlem sırası şu şekilde ilerler:

1. **Girdi İşleme:**  
   Oyuncunun yönü ve bakış açısı belirlenir.

2. **Işın Hesaplama:**  
   Işının geçtiği hücreler Bresenham veya DDA algoritması ile hesaplanır.

3. **Mesafe Hesaplama:**  
   Işının duvara çarptığı noktaya olan mesafesi belirlenir.

4. **Görselleştirme:**  
   Mesafeye göre duvarın yüksekliği hesaplanır.

5. **Ekranı Güncelle:**  
   Çizim tamamlanır ve bir sonraki kareye geçilir.

### Neden Önemlidir?
Bresenham ve DDA algoritmaları, eski 3D oyunlar (ör. **DOOM**, **Wolfenstein 3D**) için temel taşlardır. Günümüzde daha gelişmiş yöntemler kullanılsa da, bu teknikler oyun geliştirme dünyasında tarihsel bir öneme sahiptir.

---

## Özet
1. **Raycasting nedir?**  
   Oyuncunun baktığı yönde ışıklar göndermek ve duvarları bulmak.

2. **DDA Algoritması nedir?**  
   Işığın bir harita üzerindeki karelerden nasıl geçtiğini hesaplayan bir yöntem.

3. **Nasıl çalışır?**  
   Adım adım ilerler, bir duvara çarptığında durur ve mesafeyi hesaplar.

4. **Execution Order:**  
   Girdi al, ışını hesapla, mesafeyi bul, duvarı çiz ve ekranı güncelle.

5. **Neden kullanılır?**  
   Hızlı ve doğru bir şekilde 3D görüntü oluşturmak için.

---
### Yardımcı Olabilicek Dökümanlar ve Videolar
1. **https://www.sfml-dev.org/documentation/2.6.2/classsf_1_1Transformable.php**
2. **https://www.youtube.com/watch?v=NbSee-XM7WA&t=1489s**
3. **https://www.youtube.com/watch?v=W5P8GlaEOSI**
4. **https://www.youtube.com/watch?v=ebzlMOw79Yw**
5. **https://www.youtube.com/watch?v=pTAUx-uYNjM**
6. **https://www.youtube.com/watch?v=RGB-wlatStc**
