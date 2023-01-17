/*******************************************************************************
 *                               SAKARYA ÜNİVERSİTESİ                          *
 *                       BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ             *
 *                            BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ                   *
 *                                 PROGRAMLAMAYA GİRİŞ                         *
 *                                                                             *
 *                             ÖĞRENCİ ADI KÜRŞAD EREN MADEN                   *
 *                             ÖĞRENCİ NUMARA G211210049                       *
 *                             DERS GRUBU 2A                                   *
 *                                                                             *
 * *****************************************************************************/






#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class FirmaArayüz  // class tanımı 
{   
    public:
    // urun degiskenleri
    int urunSecme;
    int kayitnumarasi;
    int urunkodu;
    string urunadi;
    int teminsuresi;
    int ozelFiyat;
    int fiyat;
    string ureticisi;
    int kdvorani;
    int stokadedi;
    int secilenkod;
    int control=0;
    int düzeltmekodu;
    string degisimsecimi;
    string istenilenad;
    int silinenkod; 
    // musteri islemleri
    int musterisecimi;
    int Firmano;
    double FirmaTelefon;
    string FirmaSorumlusu;
    string Musterikategorisi;
    string Adres;
    int secilenmusteri;
    int silinenmusteri;
    // siparis islemleri
    int siparissecimi;
    string siparistarihi;
    int siparistutar;
    string alankisi;
    int secilenurunkodu;
    string siparislistesi;
    int secilenfirma;
    int Silinenfirma;
    int degistirilecekNo;
    int düzeltilecekislem;
    int listeFirma;
    int tercih;
    

    





    void urunislemleri()   // ürün kısmında işlemler
    {   

        cout << "1) urun ekleme " << endl;
        cout << "2) urun listeleme " << endl;
        cout << "3) urun arama " << endl;
        cout << "4) urun duzeltme " << endl;
        cout << "5) urun silme " << endl;
        cout << "6) programdan cik: "<< endl;
        cin >> urunSecme;

       switch (urunSecme)
       {
       
       
            case 1:
            {
                    ofstream dosyaYazdir;
                    dosyaYazdir.open("urun.txt", ios::app);    // dosyaya  kullanıcıdan alınan veriler yazdırılır 
                    {
                 
                         cout <<"urun kodu: "; cin >> urunkodu;    // ürün kısmında istenilen veriler
                         cout <<"urun adi: "; cin>> urunadi;
                         cout <<"temin suresi(gun): "; cin >> teminsuresi;
                         cout <<"fiyat (genel musteri): "; cin >> fiyat;
                         cout <<"fiyat özel (iyi musterilere): "; cin >> ozelFiyat;
                         cout <<"ureticisi: "; cin >> ureticisi;         
                         cout <<"kdv orani: "; cin >> kdvorani;
                         cout <<"stok adedi: "; cin >> stokadedi;  

                       dosyaYazdir    << " " << urunkodu << " " << urunadi << " "  << teminsuresi << " "   << fiyat << " " 
                       << ozelFiyat << " "  << ureticisi << " "  << kdvorani  << " " 
                       << stokadedi << endl;
                       dosyaYazdir.close(); 
                    }
                    break;
            }        
            case 2:
            {
                    ifstream dosyaListeleme;
                    dosyaListeleme.open("urun.txt", ios::app);    // kullanıcıdan alınan verileri listelemeye yarar
                    {
                            if(!dosyaListeleme)               
                        {
                             cerr << "dosya acilamadi ";
                             exit(0);
                        }
                        cout << left  << setw(12) << "Urun kodu" << setw(11) << "Urun adi" << setw(20) <<"Temin suresi(gun)"                                   
                        << setw (8) << "Fiyat" << setw(13) << "Fiyat ozel" << setw(12) << "Ureticisi" << setw(13) << "kdv orani" << setw(10) << "stokadedi" << endl;
                         while( dosyaListeleme>> urunkodu >> urunadi >> teminsuresi >> fiyat >> ozelFiyat >> ureticisi >> kdvorani >> stokadedi )  // ürün okuma
                        {
                          cout << left  << setw(12) << urunkodu << setw(11) << urunadi << setw(20) << teminsuresi
                          << setw (8) << fiyat << setw(13) << ozelFiyat << setw(12) << ureticisi << setw(13) << kdvorani << setw(10) << stokadedi<< endl;
                        }
                    
                     }
                     dosyaListeleme.close();
             break;
            }
            
            case 3:
            {   

                  cout << "urun kodu kac olan urunu ariyorsunuz";   // arana ürünü bulmak için 
                  cin >> secilenkod; 
                  control=1;
                  ifstream dosyaArama;
                  dosyaArama.open("urun.txt", ios::app);
                  {
                    if(!dosyaArama)
                    {
                         cerr << "dosya acilamadi ";
                         exit(0);
                    }
                          

                    while(dosyaArama >> urunkodu >> urunadi >> teminsuresi >> fiyat >> ozelFiyat >> ureticisi >> kdvorani >> stokadedi )  // ürün dosyasını içini  satır satır okur 
                    {   
                        if(urunkodu == secilenkod)
                        {   
                            if(control==1)
                            {
                                  cout << left  << setw(12) << "Urun kodu" << setw(11) << "Urun adi" << setw(20) <<"Temin suresi(gun)"
                                  << setw (8) << "Fiyat" << setw(13) << "Fiyat ozel" << setw(12) << "Ureticisi" << setw(13) << "kdv orani" << setw(10) << "stokadedi" << endl;
                                  control=0;
                            }
                                  cout << left  << setw(12) << urunkodu << setw(11) << urunadi << setw(20) << teminsuresi
                                  << setw (8) << fiyat << setw(13) << ozelFiyat << setw(12) << ureticisi << setw(13) << kdvorani << setw(10) << stokadedi<< endl;
                               
                        }
                        
                            
                              
                    }
                    if(control == 1)
                    {
                        cout << " aradiginiz urun bulunamdi ";
                        exit(0);
                    }
                  }  
                     dosyaArama.close();
                    break;
                    
            } 
            case 4:
            {   
                 cout << "düzeltmek istediğiniz urunun urun kodu: "<< endl;  // ürün dosyasıın içine girilen yanlış dosyayı okumak için
                 cin >> düzeltmekodu;
                
                 control=1;

                ifstream dosyadüzeltme("urun.txt", ios::out);
                ofstream gecicidosya("gecici.txt");     // geçici olarak dosya için
                
                
                
                while(dosyadüzeltme >> urunkodu >> urunadi >> teminsuresi >> fiyat >> ozelFiyat >> ureticisi >> kdvorani >> stokadedi  ) // dosyanın içini satır satır okur 
                {
  
                  if(urunkodu == düzeltmekodu)
                  {    
                         cout <<"urun kodu: "; cin >> urunkodu;
                         cout <<"urun adi: "; cin>> urunadi;
                         cout <<"temin suresi(gun): "; cin >> teminsuresi;
                         cout <<"fiyat (genel musteri): "; cin >> fiyat;
                         cout <<"fiyat özel (iyi musterilere): "; cin >> ozelFiyat;
                         cout <<"ureticisi: "; cin >> ureticisi;
                         cout <<"kdv orani: "; cin >> kdvorani;
                         cout <<"stok adedi: "; cin >> stokadedi; 

                       gecicidosya << " " << urunkodu << " " << urunadi << " "  << teminsuresi << " "   << fiyat << " " 
                       << ozelFiyat << " "  << ureticisi << " "  << kdvorani  << " " 
                       << stokadedi << endl;
                       

                  }
                  else
                  {
                       gecicidosya << " " << urunkodu << " " << urunadi << " "  << teminsuresi << " "   << fiyat << " " 
                       << ozelFiyat << " "  << ureticisi << " "  << kdvorani  << " " 
                       << stokadedi << endl;
                       
                  }
 
                }
                dosyadüzeltme.close(); // dosyaları kapatan komut
                gecicidosya.close();
                
                remove("urun.txt");   // dosyayı silmeye
                rename("gecici.txt","urun.txt");  // dosyanın adını değiştimeye yarar
               
                break;
            }
            case 5:
            { 
                 

                 cout << "silmek istediginiz urun kodunu girin ";  // ürün  dosyasının içindeki kodu silmek için
                 cin >> silinenkod;
                 ifstream dosyasilme("urun.txt", ios::out);
                 ofstream silicidosya("silici.txt");   // geçici olarak açılan bir dosya

                 while(dosyasilme >> urunkodu >> urunadi >> teminsuresi >> fiyat >> ozelFiyat >> ureticisi >> kdvorani >> stokadedi)
                 {
                      if(!(urunkodu == silinenkod))
                      {
                        silicidosya << " " << urunkodu << " " << urunadi << " "  << teminsuresi << " "   << fiyat << " " 
                       << ozelFiyat << " "  << ureticisi << " "  << kdvorani  << " " 
                       << stokadedi << endl;
                      }
                 }
                 dosyasilme.close(); // dosyaları kapatan komut 
                 silicidosya.close();

                 remove("urun.txt");  // dosyayı silme 
                 rename("silici.txt", "urun.txt"); // dosyaya isim verme

              break;
            }
            case 6:
            {
              exit(0);
              break;
            }
         default:
             break; 
        }
        
         
    }

    void musteriIslemleri()  // müsteri oluşturmak icin fonksiyon
    {   
        while(1)
        {
            cout << "1) Musteri Ekle: " << endl;
            cout << "2) Musteri Arama: " << endl;
            cout << "3) Musteri Duzeltme: " << endl;
            cout << "4) Musteri Silme: " << endl;
            cout << "5) programdan cikis: " << endl;
            cin >> musterisecimi;
            
            switch (musterisecimi)
            {
            case 1:
              {   
                   ofstream musteriekle;
                   musteriekle.open("cari.txt", ios::app);   // müsteri bilgilerinn istenildiği kısım
                   
                   cout << "Firma No: " << endl; 
                   cin >> Firmano;
                   cout << "Firma Telefon: " << endl;
                   cin >> FirmaTelefon ;
                   cout << "Firma Sorumlusu: " << endl;
                   cin >> FirmaSorumlusu ;
                   cout << "Ozel/Genel: " << endl;
                   cin >> Musterikategorisi ;
                   cout << "Adres: " << endl;
                   cin >> Adres ;

                     musteriekle << " " << Firmano << " " << FirmaTelefon << " "  << FirmaSorumlusu << " "   << Musterikategorisi << " " 
                    << Adres <<  endl;
                   
                    musteriekle.close();

              }
              break;
              
              case 2:
              {
                control=1;

                cout << "Musterinizin Firma Numarasi nedir? ";    // müsterilei firma no suna göre arandıgı kısım
                cin >> secilenmusteri;

                ifstream musteriarama;
                musteriarama.open("cari.txt",ios::app);
                if(!musteriarama)
                {
                    cerr << "dosya acilamadi ";
                    exit(0);
                }
                while(musteriarama >> Firmano >> FirmaTelefon >> FirmaSorumlusu >> Musterikategorisi >> Adres )  //  dosya içindekileri satır satır okur aktarır
                    {   
                        if(Firmano == secilenmusteri)
                        {   
                            if(control==1)
                            {
                                  cout << left  << setw(10) << "Firmano" << setw(15) << "FirmaTelefon" << setw(17) <<"FirmaSorumlusu"
                                  << setw (20) << "Musterikategorisi" << setw(8) << "Adres" << endl;
                                  control=0;
                            }
                                  cout << left  << setw(10) << Firmano << setw(15) << FirmaTelefon << setw(17) << FirmaSorumlusu
                                  << setw (20) << Musterikategorisi << setw(8) << Adres<< endl;
                               
                        }
                        
                            
                              
                    }
                      if(control == 1)
                      {
                           cout << " aradiginiz musteri bulunamadi ";
                           exit(0);
                      }
                
                        musteriarama.close();



                break;
              }
              case 3:
              {
                cout << "duzeltmek istediginiz musterinin firma numarasini giriniz";
                cin >> secilenmusteri;
                 
                 ifstream musteriduzeltme("cari.txt",ios::app);
                 ofstream musteriduzeltici("duzeltici.txt");   // geçici dosya
                 
                 while(musteriduzeltme >> Firmano >> FirmaTelefon >> FirmaSorumlusu >> Musterikategorisi >> Adres)
                 {
                     if(Firmano == secilenmusteri)
                     {
                         cout << "Firma No: " << endl; 
                         cin >> Firmano;
                         cout << "Firma telefon: " << endl;
                         cin >> FirmaTelefon ;
                         cout << "Firma Sorumlusu: " << endl;
                         cin >> FirmaSorumlusu ;
                         cout << "Ozel/Genel: " << endl;
                         cin >> Musterikategorisi ;
                         cout << "Adres: " << endl;
                         cin >> Adres ; 

                          musteriduzeltici << " " << Firmano << " " << FirmaTelefon << " "  << FirmaSorumlusu << " "   << Musterikategorisi << " " 
                          << Adres <<  endl;
                      }
                      else
                      {
                          musteriduzeltici << " " << Firmano << " " << FirmaTelefon << " "  << FirmaSorumlusu << " "   << Musterikategorisi << " " 
                          << Adres <<  endl;
                      }
                  }
                  musteriduzeltme.close();
                  musteriduzeltici.close();
                  remove("cari.txt");  // cari dosyası silinir
                  rename("duzeltici.txt", "cari.txt");  // düzeltici dosyanın ismi değişir ve cari olur

                break;
              }
              case 4:
              { 
                  cout << "silinecek musterinin firma numarasini giriniz";
                  cin >> silinenmusteri;

                  ifstream musterisilme("cari.txt", ios::app);
                  ofstream musterisilici("silici.txt");   // silici dosya gecicidir
 
                  while(musterisilme >> Firmano >> FirmaTelefon >> FirmaSorumlusu >> Musterikategorisi >> Adres)
                  {
                      if(!(Firmano == silinenmusteri))
                      {
                          musterisilici << " " << Firmano << " " << FirmaTelefon << " "  << FirmaSorumlusu << " "   << Musterikategorisi << " " 
                          << Adres <<  endl;
                      }
                  }

                  musterisilme.close();
                  musterisilici.close();

                  remove("cari.txt");
                  rename("silici.txt", "cari.txt"); // silici dosya cari dosyanın yerini alır 

                break;
              } 
              case 5:
              {
                exit(0);

                break;
              }
            
            default:
              break;
            }

        }
  }
  void siparisislemleri()
  {
     
 
     cout << " Ne yapmak istersiniz? "<< endl;
     cout << "1) Siparis Ekle: "<< endl;
     cout << "2) Siparis Arama: "<< endl;
     cout << "3)Siparis Silme: "<< endl;
     cout << "4)Siparis Duzeltme: "<< endl;
     cout << "5)Siparis raporlama: "<< endl;
     cout << "6) programdan cik: " << endl;
     cin >> musterisecimi;

    switch (musterisecimi)
    {
    case 1:
      {    
           
      
        

         
         
             
             cout << "FirmaNO: " << endl;
             cin >> Firmano;
             cout << "Siparis Tarihi: "<< endl;
             cin >> siparistarihi;            
             cout << "Siparisi Alan Kisi: " << endl;
             cin >> alankisi;
             cout << "Siparis Listesine Eklenecek Urunun Kodunu Giriniz: ";
             cin >>  secilenurunkodu;
             cout << " Musteri Kategorisi (ozel/genel): ";
             cin >> Musterikategorisi;

             ofstream siparisekle("siparis.txt", ios::app);   // farklı dosyaların olmasının sebebi ürünleri tutmak
             ifstream siparisOku("urun.txt", ios::in | ios::out);
             ofstream siparisyazdir("siparisliste.txt",ios::app); // liste kısmında istenilen dosya 
             if(Musterikategorisi == "ozel")  // özel müşteri
             {
               while(siparisOku >> urunkodu >> urunadi >> teminsuresi >> fiyat >> ozelFiyat >> ureticisi >> kdvorani >> stokadedi)  //siparis dosyasına veri aktarır
               {  
                  if(urunkodu == secilenurunkodu)
                    {
                          siparistutar = ozelFiyat;
                          siparisyazdir<< " "<< Firmano << " " << urunkodu << " " << urunadi  << " " << siparistutar << "\n";
                          siparisekle << " " << Firmano << " " << siparistarihi << " " << siparistutar << " " << alankisi << " " << urunkodu << " "<< urunadi << endl;
                    }
               }
             }
              if(Musterikategorisi == "genel") //  genel müsteri
              {
               while(siparisOku >> urunkodu >> urunadi >> teminsuresi >> fiyat >> ozelFiyat >> ureticisi >> kdvorani >> stokadedi)
               {   
                  if(urunkodu == secilenurunkodu)
                  {
                        siparistutar = fiyat;
                        siparisyazdir<< " " << Firmano << " " << urunkodu << " " << urunadi  << siparistutar << "\n";
                        siparisekle << " " << Firmano << " " << siparistarihi << " " << siparistutar << " " << alankisi << " " << urunkodu << " "<< urunadi << endl;
                  } 
               }
              }
             
             
          


           siparisOku.close();
           siparisyazdir.close();
           siparisekle.close();

        break;
      }
      
      case 2:
      { 
        cout << "1) siparis bilgileri icin  "<< endl;
        cout << "2) siparis ettiğiniz ürün bilgileri icin: " << endl;
        cout << "3) cikis: " << endl;
        cin >> tercih;
        control=1;
        
        if(tercih==1)  // siparis bilgileri icin
        {     
          cout << "Aradiginiz Firma No: " << endl;   // aranlan siparisşe ulaşmak için 
          cin >> secilenfirma;
              ifstream siparisara("siparis.txt");
              

              while(siparisara >> Firmano >> siparistarihi >>siparistutar >> alankisi >> urunkodu >>urunadi  ) // dosyadan satir satir okur 
              { 

                
                if(Firmano == secilenfirma)
                {
                  
                
                      if(control==1)
                      {
                          cout << left  << setw(11) << "Firma No" << setw(17) << "Siparis Tarihi" << setw(16) << "Siparis Tutar"
                          << setw (12) << "Alan Kisi"<< setw(12) << "Urun Kodu: " << setw(11) << "Urun adi: " << endl;
                          control=0;
                                    
                      }
                          
                          cout << left  << setw(11) << Firmano << setw(17) << siparistarihi << setw(16) << siparistutar
                          << setw (12) << alankisi<< setw(12)  << urunkodu << setw(11) << urunadi << endl;
                          
                         
                           
                           
                      
                }

              }
              siparisara.close();
        }      
        else if(tercih==2) // ürün bilgileri icin
        {   
          cout << "Aradiginiz Firma No: " << endl;
          cin >> secilenfirma; 

            ifstream siparisistesii("siparisliste.txt");
            while( siparisistesii >> Firmano >> urunkodu >> urunadi >> siparistutar )
            {
                if(secilenfirma == Firmano)
                {
                      if(control==1)
                      {
                          cout << left  << setw(11) << "Firma No" << setw(12) << "Urun Kodu" << setw(11) << "Urun Adi"  << setw(17)<< "Siparis Tutari " <<endl;
                          
                          control=0;
                                    
                      }
                      
                          cout << left  << setw(11) << Firmano << setw(12) << urunkodu << setw(11) << urunadi<< setw(17) << siparistutar <<endl;
                }          
            }
  
            siparisistesii.close();
        }    
        else 
        {
          exit(0);
        }

        break;
      }
      case 3:
      {
            cout << "Silmek İstediginiz Firma No "<< endl;
            cin >> Silinenfirma;
          
            ifstream silinensiparis("siparis.txt", ios::app);
            ofstream gecicisiparis("silicisiparis.txt");  // silmek için gecici dosya
            
            while(silinensiparis >>Firmano >> siparistarihi >>siparistutar >> alankisi >> urunkodu >> urunadi )  // dosya satır satır okur 
            {
              if(!(Firmano == Silinenfirma))
              { 
                  

                gecicisiparis << Firmano << " " << siparistarihi << " " << siparistutar << alankisi << urunkodu << urunadi  << endl;
              }

            }
            silinensiparis.close();
            gecicisiparis.close();
          remove("siparis.txt"),
          rename("silicisiparis.txt", "siparis.txt");
         
        break;
      }
      case 4:
      {   
          cout << "Ne yapmak istiyorsunuz"<< endl;
          cout << "1) Siparis bilgilerini degistir: "<< endl;
          cout << "2) Siparisteki Urunu Degistir: " << endl;
          cout << "3) cikis " << endl;
          cin >> düzeltilecekislem;
          if(düzeltilecekislem == 1)  // siparis bilgilerini degistirmek icin
          {
                cout << "Duzeltilecek siparisin  Firma No giriniz: "<< endl;
                cin >> degistirilecekNo;
          
                 ifstream siparisdüzeltme("siparis.txt", ios::app);
                 ofstream gecicidosya("degistirici.txt");  // degistirmek icin gecici dosya
                while(siparisdüzeltme >>Firmano >> siparistarihi >>siparistutar >> alankisi >> urunkodu >> urunadi )
                {
                    if(Firmano == degistirilecekNo)
                    {
                        cout << "FirmaNO: " << endl;
                        cin >> Firmano;
                        cout << "Siparis Tarihi: "<< endl;
                        cin >> siparistarihi;            
                        cout << "Siparisi Alan Kisi: " << endl;
                        cin >> alankisi;
                  
 
                        gecicidosya <<  Firmano << " " << siparistarihi << " " << siparistutar << " " << alankisi  << " " << urunkodu << " " << urunadi  << " " << endl ;
                    }
                    else
                    {               
                        gecicidosya <<  Firmano << " " << siparistarihi<< " " <<siparistutar<< " " << alankisi << " "  << urunkodu << " " << urunadi  <<endl  ;
                    }
                 }

                        siparisdüzeltme.close();
                        gecicidosya.close();
                        remove("siparis.txt");
                        rename("degistirici.txt", "siparis.txt");
          }
           if(düzeltilecekislem == 2) // ürünü degistirmek icin 
          {
              cout << " Siparisteki urnu Degistirmek Icin Firma NO Giriniz "<< endl;
              cin >> degistirilecekNo;

              ifstream siparisliste("siparisliste.txt", ios::app);
              ofstream geciciliste("geciciListe.txt");
 
              while(siparisliste >> Firmano >> urunkodu >> urunadi >> siparistutar  )
              {
                if(Firmano == degistirilecekNo)
                { 
                  cout << "Firma No giriniz" << endl;
                  cin >> Firmano;
                  cout << "Urun Kodu giriniz" << endl;
                  cin >> urunkodu;
                  cout << "Urun Adi Giriniz" << endl;
                  cin >> urunadi;
                  cout << "Siparis tutarini giriniz" << endl;
                  cin >> siparistutar;
                  

                  geciciliste << Firmano << " " << urunkodu << " " << urunadi << " " << siparistutar <<endl;
                }
                else
                {
                  geciciliste << Firmano << " " << urunkodu << " " << urunadi << " " << siparistutar  <<endl;
                }
              }
              siparisliste.close();
              geciciliste.close();
              remove("siparisliste.txt");
              rename("geciciListe.txt", "siparisliste.txt");
          }
        
        break;
      }
      case 5:
      { 
       // siparisleri lsitelemek icin
        control=1;

        ifstream listeleyenSiparis("siparis.txt", ios::app);
        ifstream siparislistesiListeleme("siparisliste.txt", ios::app);
        while(listeleyenSiparis >> Firmano >> siparistarihi >>siparistutar >> alankisi >> urunkodu >> urunadi )
        {
           siparislistesiListeleme >> Firmano >> urunkodu >> urunadi >> siparistutar;
          
          
            if(control==1)
            {
                  cout << left  << setw(11) << "Firma No" << setw(17) << "Siparis Tarihi" << setw(16) << "Siparis Tutar"
                  << setw (12) << "Alan Kisi" << setw(12) << "Urun Kodu" << setw(11) << "Urun Adi" <<  endl;
                   control=0;
            }
                  cout << left  << setw(11) << Firmano << setw(17) << siparistarihi << setw(16) << siparistutar
                  << setw (12) << alankisi << setw(12) << urunkodu << setw(11) << urunadi <<  endl;
                  cout << endl;
          
        }
        listeleyenSiparis.close();
        siparislistesiListeleme.close();

        break;
      }
      case 6:
      {
        exit(0);
        break;
      }
      
    default:
      break;
    }
     
  }
};   // Firmarayüz class sonu 
    

int main()
{   
    FirmaArayüz ASD;
    int islem_secimi;
        cout << "1 urun islemleri icin "<<  endl;
        cout << "2 musteri secimleri icin " << endl;
        cout << "3 siparis islemleri icin " << endl; // ana menü
        cout << "0 programdan cik " << endl;
        cin >> islem_secimi;

    while(1) // ana menünün yapısı
    {
        if(islem_secimi==1)
        ASD.urunislemleri();

        else if(islem_secimi==2)
        ASD.musteriIslemleri();

        else if(islem_secimi==3)
        ASD.siparisislemleri();

        else if(islem_secimi==0)
        {
            exit(0);
        }
        else
        {
          exit(0);
        }
    }    
}// program sonu 
