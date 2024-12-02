
## Raycasting ve DDA Algoritması

### Raycasting: Işın Atma
Raycasting, bir sahnedeki nesneleri tespit etmek ve görselleştirmek için kullanılan bir tekniktir. Örneğin, bir labirent oyunu oynarken, el fenerinden çıkan ışıkların önünüzdeki duvarlara çarpması ve bu bilgilerin ekranda görüntülenmesi Raycasting ile sağlanır.

### DDA Algoritması ile Harita Üzerinde İlerleme
Raycasting sırasında, ışığın bir harita üzerindeki karelerden (hücrelerden) nasıl geçtiğini hesaplamak için DDA algoritması kullanılır. Bu algoritma:

1. Işığın bir sonraki hücreye geçtiği noktayı hesaplar.
2. Işığın bir duvara çarpıp çarpmadığını kontrol eder.

### DDA Algoritmasının Raycasting ile Kullanımı
DDA algoritması, ışığın hücreler arasında adım adım ilerlemesini sağlar. Her adımda:
- Duvara çarpma kontrolü yapılır.
- Çarptığı duvarın oyuncuya olan mesafesi hesaplanır.

Bu bilgiler kullanılarak 3D bir görüntü oluşturulur. Yakın duvarlar daha büyük, uzak duvarlar ise daha küçük görünür.

### Raycasting İş Akışı (Execution Order)
1. **Girdi İşleme**:
   - Oyuncunun hangi yöne baktığını (fare veya klavye girdileriyle) belirle.
2. **Işın Hesaplama**:
   - Her ışın için DDA algoritmasını kullanarak ışının hangi hücrelerden geçtiğini ve bir duvara çarptığı noktayı hesapla.
3. **Mesafe Hesaplama**:
   - Işığın duvara çarptığı noktaya olan uzaklığı hesapla.
4. **Görselleştirme**:
   - Duvarın mesafesine göre yüksekliğini hesapla ve ekrana çiz.
5. **Ekranı Güncelle**:
   - Çizim işlemini tamamladıktan sonra ekranı güncelle.

### Örnek Kod
Aşağıdaki basit bir ışın izleme algoritmasının temel adımlarını gösterir:

```cpp
float x = oyuncunun_x; // Başlangıç noktası
float y = oyuncunun_y; 

while (duvara_carpana_kadar) {
    x += adim_x; // Işını biraz ilerlet
    y += adim_y;
    if (duvar_bulundu) {
        ışığın_uzaklığını_hesapla();
        break; // İşlem tamam!
    }
}
```

### Neden Önemli?
- Raycasting ve DDA algoritması, özellikle eski tarz 3D oyunlar (örn. Wolfenstein 3D, DOOM) için temel teknolojilerden biridir.
- Günümüzde modern oyun motorlarında farklı yöntemler kullanılsa da, bu teknikler oyun geliştirme tarihindeki yerlerini korumaktadır.

---
