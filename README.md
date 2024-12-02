
# Bresenham Algoritması ve DDA Karşılaştırması

## Bresenham Algoritması

Bresenham algoritması, iki nokta arasında bir çizgi çizmek için kullanılan bir rasterleştirme yöntemidir. Bu algoritma, çizgi boyunca hangi pikselin çizileceğini belirlemek için yalnızca tam sayı aritmetiği kullanır ve bu nedenle oldukça hızlıdır.

### Algoritma Adımları
1. Başlangıç ve bitiş noktalarını (\(x_0, y_0\)) ve (\(x_1, y_1\)) alın.
2. Çizginin eğimini hesaplayın: \(\Delta x = x_1 - x_0\) ve \(\Delta y = y_1 - y_0\).
3. Hata terimini (\(decision variable\)) başlatın: \(p = 2\Delta y - \Delta x\).
4. İlk noktayı çizin: (\(x_0, y_0\)).
5. \(\Delta x\) kadar adımla ilerleyerek her piksel için:
   - Eğer \(p < 0\), bir sonraki piksel yatay yönde olur ve hata terimi \(p = p + 2\Delta y\) olarak güncellenir.
   - Eğer \(p \geq 0\), bir sonraki piksel çapraz yönde olur ve hata terimi \(p = p + 2\Delta y - 2\Delta x\) olarak güncellenir.

### Özellikleri
- **Tam sayı aritmetiği** kullanır, kayan noktalı işlem gerektirmez.
- Performansı yüksektir ve donanım düzeyinde kolayca uygulanabilir.
- Özellikle düşük çözünürlüklü grafiklerde yaygın olarak kullanılır.

---

## Digital Differential Analyzer (DDA) Algoritması

DDA algoritması, çizgi boyunca her bir pikselin konumunu belirlemek için eğim tabanlı bir yönteme dayanır. Kayan noktalı işlemler kullanılır.

### Algoritma Adımları
1. Başlangıç ve bitiş noktalarını (\(x_0, y_0\)) ve (\(x_1, y_1\)) alın.
2. Çizginin uzunluğunu belirleyin: \(	ext{steps} = \max(|x_1 - x_0|, |y_1 - y_0|)\).
3. Her bir adımda artış miktarını hesaplayın: \(\Delta x = rac{x_1 - x_0}{	ext{steps}}\), \(\Delta y = rac{y_1 - y_0}{	ext{steps}}\).
4. İlk noktayı çizin: (\(x_0, y_0\)).
5. \(	ext{steps}\) kadar iterasyon yaparak:
   - Bir sonraki pikseli hesaplayın: \(x = x + \Delta x\), \(y = y + \Delta y\).
   - Sonuçları yuvarlayarak ekrana çizin.

### Özellikleri
- Kayan noktalı aritmetiğe dayanır.
- Daha fazla işlem gerektirir ve bu nedenle daha yavaştır.
- Basit bir yapıya sahiptir, ancak modern donanımlarda genellikle tercih edilmez.

---

## Bresenham ve DDA Karşılaştırması

| **Özellik**          | **Bresenham Algoritması**      | **DDA Algoritması**           |
|-----------------------|--------------------------------|--------------------------------|
| **Aritmetik Türü**    | Tam sayı                      | Kayan nokta                   |
| **Hesaplama Hızı**    | Daha hızlı                    | Daha yavaş                    |
| **Hassasiyet**        | Yuvarlama hatası yoktur       | Yuvarlama hatası olabilir     |
| **Karmaşıklık**       | Daha karmaşık                 | Daha basit                    |
| **Kullanım Alanı**    | Performans kritik yerlerde    | Genel ve basit uygulamalarda  |

---

## Özet
- Bresenham algoritması, çizgiler için daha hızlı ve daha verimli bir yöntemdir. Tam sayı hesaplamaları sayesinde modern grafik sistemlerinde yaygın olarak kullanılır.
- DDA algoritması, teorik olarak daha basit ancak daha az performanslıdır. Kayan noktalı aritmetiğe dayanır ve daha fazla hesaplama gerektirir.

---


---


# DDA Algoritması ve Raycasting Nedir?

## Raycasting: Işın Atma
Diyelim ki bir oyun oynuyorsun ve bir labirentin içindesin. Elinde bir el feneri var ve karanlıkta sadece baktığın yönü aydınlatabiliyorsun. Fenerden çıkan ışıklar (ışınlar), önüne çıkan duvarlara çarpıyor ve onları görmeni sağlıyor.  
İşte bu ışıkların duvarlara nasıl ulaştığını ve ekrana nasıl yansıtıldığını anlamak için **Raycasting** kullanılır.

---

## DDA Algoritması ile Harita Üzerinde İlerleme
El fenerinden çıkan ışığın bir harita üzerindeki karelerden (hücrelerden) nasıl geçtiğini bulmamız gerekiyor. Işığın yolunu takip etmek için bir rehbere ihtiyacımız var. İşte burada **DDA Algoritması** devreye giriyor.

**DDA, ışığın izlediği yolu doğru ve hızlı bir şekilde hesaplamak için kullanılan bir yöntemdir.**  

Bu algoritma, ışığın hangi hücrelerden geçtiğini bulmak için küçük adımlarla ilerler. Her adımda:
- Işığın bir sonraki kareye (hücreye) geçtiği noktayı hesaplar.
- Işığın bir duvara çarpıp çarpmadığını kontrol eder.

---

## DDA Algoritması Nasıl Çalışır?

DDA algoritmasını bir oyun tahtasında hareket eden bir çocuğa benzetelim:
1. Çocuk, bir kareden diğerine adım adım ilerliyor.
2. Her adımda bakıyor: **"Burada duvar var mı?"**
3. Duvara çarptığı an duruyor ve "Bu duvara çarptım!" diyor.
4. Çarptığı duvara olan uzaklığını ölçüp ekrana çiziyor.

---

## Bu Sistemi Programlamak
Bir oyun ya da görselleştirme programı yazarken, bu adımları bilgisayara öğretmen gerekiyor. İşte programın çalışması için gereken ana adımlar:

1. **Girişleri Oku:**  
   Oyuncunun hangi yöne baktığını (fare ya da klavye girdileriyle) oku.
2. **Işınları Gönder:**  
   Oyuncunun baktığı yönde, fenerden çıkan ışıkları (ray) gönder.  
   Her bir ışın için DDA algoritmasını kullanarak hangi hücrelerden geçtiğini hesapla.
3. **Duvarları Bul:**  
   Işığın hangi hücrede bir duvara çarptığını tespit et.
4. **Ekranı Çiz:**  
   Işığın duvara çarptığı mesafeyi kullanarak ekrana 3D benzeri bir görüntü çiz.

---

## Execution Order (Çalışma Sırası)

Bir DDA algoritmasını kullanan raycasting programında, işlem sırası çok önemlidir. İşte doğru bir **execution order**:

1. **Girdi İşleme:**  
   Kullanıcının hangi yöne baktığını (açıyı) belirlemek için fare ve klavye girdilerini oku.
   
2. **Işın Hesaplama:**  
   Her ışın için:
   - Oyuncunun bulunduğu konumdan başlayarak DDA algoritması ile ışının hangi karelerden geçtiğini hesapla.
   - Işığın bir duvara çarptığı noktayı belirle.
   
3. **Mesafe Hesaplama:**  
   Işığın duvara çarptığı noktaya olan uzaklığını hesapla. Bu bilgi, duvarın ekranda nasıl görüneceğini belirler.

4. **Görselleştirme:**  
   - Duvara olan uzaklığa göre duvarın yüksekliğini hesapla (yakın duvarlar daha büyük, uzak duvarlar daha küçük görünür).
   - Her ışını temsil eden bir çubuk (column) çizerek duvarları ekrana yansıt.

5. **Ekranı Güncelle:**  
   - Çizim işlemi bittikten sonra ekranı güncelle ve bir sonraki kareyi (frame) işlemeye hazır ol.

---

## Basit Bir Örnek
**Örnek Durum:**  
El feneriyle bir labirentin içinde duruyorsun. Labirent karelerden oluşuyor ve fenerden çıkan ışık, önündeki duvara çarpıyor.  

Bilgisayar şu işlemleri yapar:
1. "Oyuncu şu karede ve bu yöne bakıyor."
2. "Işın gönderiyorum ve hücreleri tek tek kontrol ediyorum."
3. "Burada bir duvar buldum! Bu duvar oyuncuya şu kadar uzaklıkta."
4. "Duvarın ekrandaki yüksekliğini hesaplıyorum (uzak duvarlar küçük görünür)."
5. "Bunu ekrana çiziyorum."

---

## DDA Algoritması Nasıl Kodlanır?
Bu işlemleri kodlamak için, ışığın adım adım ilerleyişini matematiksel olarak hesaplarız. Örneğin:

```c
// Basit bir ışın izleme algoritması
float x = oyuncunun_x; // Başlangıç noktası
float y = oyuncunun_y; 

while (duvara_carpana_kadar) {
    x += adim_x; // Işını biraz ilerlet
    y += adim_y;
    eğer (duvar_bulundu) {
        ışığın_uzaklığını_hesapla();
        dur(); // İşlem tamam!
    }
}
```

---

## Neden Bu Kadar Önemli?
DDA algoritması ve raycasting, eski tarz 3D oyunlar (ör. **DOOM** veya **Wolfenstein 3D**) yapımında kullanıldı. Modern oyun motorlarında farklı yöntemler kullanılsa da, bu teknikler hâlâ oyun ve görselleştirme sistemlerinin temel taşlarından biridir.

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

https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Transformable.php#a4dbfb1a7c80688b0b4c477d706550208

Sorularınız olursa sormaktan çekinmeyin!
