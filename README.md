
# Otel Yönetim Sistemi

Bu program, bir otelin temel işlemlerini gerçekleştirmek için bir yönetim sistemi sağlar. Müşteri kaydı, oda kaydı, oda ekleme, oda silme gibi temel işlemleri yapabilirsiniz.

## Nasıl Çalıştırılır?

1. **C++ Derleyici Gereksinimi**: Program C++ dilinde yazılmıştır. Bu nedenle, bir C++ derleyicisine ihtiyacınız olacaktır. Önerilen derleyici [g++](https://gcc.gnu.org/) veya [Microsoft Visual Studio](https://visualstudio.microsoft.com/)'dur.

2. **Kaynak Kodun Derlenmesi**: Kaynak kodu bir dosyaya kopyalayın ve derleyici kullanarak derleyin. Örneğin, `main.cpp` olarak kaydettiyseniz, terminalde şu komutu kullanabilirsiniz:

   ```bash
   g++ -o otel_programi main.cpp
   ```

   Bu, derlenmiş bir dosya olan `otel_programi` adlı bir yürütülebilir dosya oluşturacaktır.


3. **Menü İşlemleri**: Program başladığında, bir menü göreceksiniz. Numaralı seçeneklere göre işlemleri seçin ve talimatları izleyin.

## Yapılar ve Fonksiyonlar

### Yapılar (Structs)

1. **Musteri**: Bu yapı, müşteri bilgilerini depolar. Ad, soyad, müşteri numarası ve TCKN (Türkiye Cumhuriyeti Kimlik Numarası) alanlarına sahiptir.

2. **Oda**: Bu yapı, oda bilgilerini depolar. Oda numarası ve oda ücreti alanlarına sahiptir.

### Fonksiyonlar

1. **main()**: Programın ana işlevini sağlar. Menüyü görüntüler ve kullanıcının seçimine göre ilgili işlevleri çağırır.

2. **menuGoster()**: Menüyü ekrana basar.

3. **odaEkle()**: Yeni bir oda kaydı eklemek için kullanılır.

4. **odaSil()**: Var olan bir oda kaydını silmek için kullanılır.

5. **odalariListele()**: Mevcut odaların listesini görüntüler.

6. **musteriEkle()**: Yeni bir müşteri kaydı eklemek için kullanılır.

7. **musteriSil()**: Var olan bir müşteri kaydını silmek için kullanılır.

8. **musterileriListele()**: Mevcut müşterilerin listesini görüntüler.

9. **odaKayitEkle()**: Bir müşteriyi bir odaya kaydetmek için kullanılır.

10. **odaKayitListele()**: Mevcut oda müşteri kayıtlarının listesini görüntüler.

11. **musteriIslemleri()**: Müşteri işlemlerini gerçekleştirmek için kullanılır (ekleme, silme, listeleme).

12. **odaKayitIslemleri()**: Oda kayıt işlemlerini gerçekleştirmek için kullanılır (ekleme, listeleme).

---
# Lisans 
Bu proje MIT Lisansı kapsamında lisanslanmıştır; ayrıntılar için [LICENSE](LICENSE) dosyasına bakın.

## Abdullah Ekşi

