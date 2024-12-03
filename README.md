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

...

