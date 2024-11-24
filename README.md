
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

4. **Neden kullanılır?**  
   Hızlı ve doğru bir şekilde 3D görüntü oluşturmak için.

---

Sorularınız olursa sormaktan çekinmeyin!
