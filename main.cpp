#include <iostream>
#include <string>
#include <locale.h>
#include <iomanip>
#include <Windows.h>
#include <fstream>
#include <algorithm>

using namespace std;

struct Musteri {
    string ad, soyad, musteriNumarasi, tckn;
};

struct Oda {
    string odaNo, ucret;
};

// Fonksiyon prototipleri
void odaEkle();
void odaSil();
void odalariListele();
void musteriEkle();
void musteriSil();
void musterileriListele();
void odaKayitEkle();
void odaKayitListele();
void menuGoster();
void musteriIslemleri();
void odaKayitIslemleri();

int main() {
   
    setlocale(LC_ALL, "turkish");
    string anaSecim;

    do {
        menuGoster();
        cin >> anaSecim;

        if (anaSecim == "1") {
            string odaSecim;
            do {
                system("cls");
                cout << "ODA ISLEMLERI\n";
                cout << string(20, '-') << endl;
                cout << "1- Oda Ekle\n";
                cout << "2- Oda Sil\n";
                cout << "3- Odalari Listele\n";
                cout << "99- Ust Menu\n";
                cout << "Seciminiz: ";
                cin >> odaSecim;

                if (odaSecim == "1") {
                    odaEkle();
                } else if (odaSecim == "2") {
                    odaSil();
                } else if (odaSecim == "3") {
                    odalariListele();
                }
            } while (odaSecim != "99");
        } else if (anaSecim == "2") {
            musteriIslemleri();
        } else if (anaSecim == "3") {
            odaKayitIslemleri();
        }
    } while (anaSecim != "99");

    return 0;
}

void odaEkle() {
    ofstream dosyaYaz;
    ifstream dosyaOku;
    Oda oda;
    string devam;

    do {
        system("cls");
        string odaNoKontrol;
        bool odaNoGecerli = false;

        while (!odaNoGecerli) {
            cout << "4 haneli oda numarasi girin: ";
            cin >> oda.odaNo;
            odaNoKontrol = oda.odaNo;

            if (odaNoKontrol.length() != 4 || !all_of(odaNoKontrol.begin(), odaNoKontrol.end(), ::isdigit)) {
                cout << "Oda numarasi 4 haneli ve rakamlardan olusmali.\n";
                continue;
            }

            dosyaOku.open("odaKayit.txt");
            bool odaVar = false;

            while (dosyaOku >> oda.odaNo >> oda.ucret) {
                if (oda.odaNo == odaNoKontrol) {
                    odaVar = true;
                    break;
                }
            }

            dosyaOku.close();

            if (odaVar) {
                cout << "Bu oda numarasi kullaniliyor, baska bir numara girin.\n";
            } else {
                odaNoGecerli = true;
            }
        }

        cout << "Odanin ucretini girin: ";
        cin >> oda.ucret;

        dosyaYaz.open("odaKayit.txt", ios::app);
        dosyaYaz << oda.odaNo << "\t" << oda.ucret << endl;
        dosyaYaz.close();

        cout << "Oda kaydi basariyla yapildi.\n";
        cout << "Kayit islemine devam etmek istiyor musunuz (e/h)? ";
        cin >> devam;
    } while (devam == "e");
}

void odaSil() {
    ofstream dosyaYaz;
    ifstream dosyaOku;
    Oda oda;
    string odaNo, devam;

    do {
        system("cls");
        cout << "Silinecek odanin numarasini girin: ";
        cin >> odaNo;

        dosyaOku.open("odaKayit.txt");
        dosyaYaz.open("odaKayitTmp.txt");

        bool odaBulundu = false;

        while (dosyaOku >> oda.odaNo >> oda.ucret) {
            if (oda.odaNo == odaNo) {
                odaBulundu = true;
            } else {
                dosyaYaz << oda.odaNo << "\t" << oda.ucret << endl;
            }
        }

        dosyaOku.close();
        dosyaYaz.close();

        if (odaBulundu) {
            remove("odaKayit.txt");
            rename("odaKayitTmp.txt", "odaKayit.txt");
            cout << "Silme islemi basarili.\n";
        } else {
            cout << "Bu numarada bir oda bulunmamaktadir.\n";
            remove("odaKayitTmp.txt");
        }

        cout << "Silme islemine devam etmek istiyor musunuz (e/h)? ";
        cin >> devam;
    } while (devam == "e");
}

void odalariListele() {
    ifstream dosyaOku;
    Oda oda;

    system("cls");
    cout << "Oda Numarasi\tUcreti\n";
    cout << string(40, '-') << endl;

    dosyaOku.open("odaKayit.txt");

    while (dosyaOku >> oda.odaNo >> oda.ucret) {
        cout << oda.odaNo << "\t" << oda.ucret << endl;
    }

    dosyaOku.close();
    system("pause");
}

void musteriEkle() {
    ofstream dosyaYaz;
    Musteri musteri;
    string devam;

    do {
        system("cls");

        cout << "Musteri adini girin: ";
        cin >> musteri.ad;
        cout << "Musteri soyadini girin: ";
        cin >> musteri.soyad;
        cout << "Musteri numarasini girin: ";
        cin >> musteri.musteriNumarasi;
        cout << "Musteri TCKN'sini girin: ";
        cin >> musteri.tckn;

        dosyaYaz.open("musteriKayit.txt", ios::app);
        dosyaYaz << musteri.ad << "\t" << musteri.soyad << "\t" << musteri.musteriNumarasi << "\t" << musteri.tckn << endl;
        dosyaYaz.close();
		    cout << "Musteri kaydi basariyla yapildi.\n";
    cout << "Kayit islemine devam etmek istiyor musunuz (e/h)? ";
    cin >> devam;
} while (devam == "e");
}

void musteriSil() {
ofstream dosyaYaz;
ifstream dosyaOku;
Musteri musteri;
string musteriNumarasi, devam;
do {
    system("cls");
    cout << "Silinecek musteri numarasini girin: ";
    cin >> musteriNumarasi;

    dosyaOku.open("musteriKayit.txt");
    dosyaYaz.open("musteriKayitTmp.txt");

    bool musteriBulundu = false;

    while (dosyaOku >> musteri.ad >> musteri.soyad >> musteri.musteriNumarasi >> musteri.tckn) {
        if (musteri.musteriNumarasi == musteriNumarasi) {
            musteriBulundu = true;
        } else {
            dosyaYaz << musteri.ad << "\t" << musteri.soyad << "\t" << musteri.musteriNumarasi << "\t" << musteri.tckn << endl;
        }
    }

    dosyaOku.close();
    dosyaYaz.close();

    if (musteriBulundu) {
        remove("musteriKayit.txt");
        rename("musteriKayitTmp.txt", "musteriKayit.txt");
        cout << "Silme islemi basarili.\n";
    } else {
        cout << "Bu numarada bir musteri bulunmamaktadir.\n";
        remove("musteriKayitTmp.txt");
    }

    cout << "Silme islemine devam etmek istiyor musunuz (e/h)? ";
    cin >> devam;
} while (devam == "e");
}

void musterileriListele() {
ifstream dosyaOku;
Musteri musteri;
system("cls");
cout << "Ad\tSoyad\tMusteri Numarasi\tTCKN\n";
cout << string(40, '-') << endl;

dosyaOku.open("musteriKayit.txt");

while (dosyaOku >> musteri.ad >> musteri.soyad >> musteri.musteriNumarasi >> musteri.tckn) {
    cout << musteri.ad << "\t" << musteri.soyad << "\t" << musteri.musteriNumarasi << "\t" << musteri.tckn << endl;
}

dosyaOku.close();
system("pause");
}

void odaKayitEkle() {
ofstream dosyaYaz;
ifstream dosyaOku;
string musteriNumarasi, odaNo, devam;
Musteri musteri;
Oda oda;
do {
    system("cls");

    cout << "Musteri numarasini girin: ";
    cin >> musteriNumarasi;

    bool musteriBulundu = false;
    dosyaOku.open("musteriKayit.txt");
    while (dosyaOku >> musteri.ad >> musteri.soyad >> musteri.musteriNumarasi >> musteri.tckn) {
        if (musteri.musteriNumarasi == musteriNumarasi) {
            musteriBulundu = true;
            break;
        }
    }
    dosyaOku.close();

    if (!musteriBulundu) {
        cout << "Bu numarada bir musteri bulunamadi.\n";
        cout << "Devam etmek istiyor musunuz (e/h)? ";
        cin >> devam;
        continue;
    }

    cout << "Oda numarasini girin: ";
    cin >> odaNo;

    bool odaBulundu = false;
    dosyaOku.open("odaKayit.txt");
    while (dosyaOku >> oda.odaNo >> oda.ucret) {
        if (oda.odaNo == odaNo) {
            odaBulundu = true;
            break;
        }
    }
    dosyaOku.close();

    if (!odaBulundu) {
        cout << "Bu numarada bir oda bulunamadi.\n";
        cout << "Devam etmek istiyor musunuz (e/h)? ";
        cin >> devam;
        continue;
    }

    dosyaYaz.open("odaMusteriKayit.txt", ios::app);
    dosyaYaz << musteriNumarasi << "\t" << odaNo << endl;
    dosyaYaz.close();

    cout << "Oda kaydi basariyla yapildi.\n";
    cout << "Kayit islemine devam etmek istiyor musunuz (e/h)? ";
    cin >> devam;
} while (devam == "e");
}

void odaKayitListele() {
ifstream dosyaOku;
string musteriNumarasi, odaNo;
system("cls");
cout << "Musteri Numarasi\tOda Numarasi\n";
cout << string(40, '-') << endl;

dosyaOku.open("odaMusteriKayit.txt");

while (dosyaOku >> musteriNumarasi >> odaNo) {
    cout << musteriNumarasi << "\t" << odaNo << endl;
}

dosyaOku.close();
system("pause");
}

void menuGoster() {
system("cls");
cout << "OTEL ISLEMLERI\n";
cout << string(20, '-') << endl;
cout << "1- Oda Islemleri\n";
cout << "2- Musteri Islemleri\n";
cout << "3- Oda Kayit Islemleri\n";
cout << "99- Cikis\n";
cout << "Seciminiz: ";
}

void musteriIslemleri() {
string musteriSecim;
do {
system("cls");
cout << "MUSTERI ISLEMLERI\n";
cout << string(20, '-') << endl;
cout << "1- Musteri Ekle\n";
cout << "2- Musteri Sil\n";
cout << "3- Musterileri Listele\n";
cout << "99- Ust Menu\n";
cout << "Seciminiz: ";
cin >> musteriSecim;
    if (musteriSecim == "1") {
        musteriEkle();
    } else if (musteriSecim == "2") {
        musteriSil();
    } else if (musteriSecim == "3") {
        musterileriListele();
    }
} while (musteriSecim != "99");
}

void odaKayitIslemleri() {
string odaKayitSecim;
do {
system("cls");
cout << "ODA KAYIT ISLEMLERI\n";
cout << string(20, '-') << endl;
cout << "1- Oda Kaydi Ekle\n";
cout << "2- Oda Kayitlarini Listele\n";
cout << "99- Ust Menu\n";
cout << "Seciminiz: ";
cin >> odaKayitSecim;
 if (odaKayitSecim == "1") {
        odaKayitEkle();
    } else if (odaKayitSecim == "2") {
        odaKayitListele();
    }
} while (odaKayitSecim != "99");
}
