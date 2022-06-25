#include <iostream>
using namespace std;

typedef struct {
  unsigned int biSize;				//Wielkosc naglowka informacyjnego
  unsigned int  biWidth;			//Szerokosc obrazu w px
  unsigned int  biHeight;			//Wysokosc obrazu w px
  unsigned short  biPlanes;			//Liczba warstw kolorow
  unsigned short  biBitCount;		//Liczba bitow na piksel
  unsigned int biCompression;		//Algorytm kompresji
  unsigned int biSizeImage;			//Rozmiar obrazu
  unsigned int  biXPelsPerMeter;	//Rozdzielczosc pozioma
  unsigned int  biYPelsPerMeter;	//Rozdzielczosc pionowa
  unsigned int biClrUsed;			//Liczba kolorow w palecie
  unsigned char biClrImportant;		//Liczba waznych kolorow w palecie
  unsigned char biClrRotation;		//Flaga rotacji palety
} BITMAPINFOHEADER;

int main()
{
    FILE* plik  = fopen("test.bmp", "rb");
    
	BITMAPINFOHEADER naglowek;
    unsigned short poczatek;
    
    fread(&poczatek, 2, 1, plik);
    cout << poczatek <<"\n";
    if(poczatek!=19778) //Wartosc "BM" zapisana jako liczba
    {
    	cout << "Wskazany plik nie jest plikiem BMP lub jest uszkodzony.";
	}
	else
	{
	fseek(plik,14,SEEK_SET);
    fread(&naglowek, 40, 1, plik);
    cout << "Wielkosc naglowka informacyjnego: " << naglowek.biSize << "\n";
    cout << "Szerokosc obrazu w px: " << naglowek.biWidth << "\n";
    cout << "Szerokosc obrazu w px: " << naglowek.biHeight << "\n";
    cout << "Liczba warstw kolorow: " << naglowek.biPlanes << "\n";
    cout << "Liczba bitow na piksel: " << naglowek.biBitCount << "\n";
    cout << "Algorytm kompresji: " << naglowek.biCompression << "\n";
    cout << "Rozmiar bitmapy w bajtach: " << naglowek.biSizeImage << "\n";
    cout << "Rozdzielczosc pozioma w px na metr: " << naglowek.biXPelsPerMeter << "\n";
    cout << "Rozdzielczosc pionowa w px na metr: " << naglowek.biYPelsPerMeter << "\n";
    cout << "Liczba kolorow w palecie: " << naglowek.biClrUsed << "\n";
    cout << "Liczba waznych kolorow w palecie: " << (int)naglowek.biClrImportant << "\n";
    cout << "Flaga rotacji palety: " << (int)naglowek.biClrRotation << "\n";
	}
return 0;
}
