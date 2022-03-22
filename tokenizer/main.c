
/*

Ýsim : Berat
Soyisim : Navruz
Öðrenci Numarasý : 02200201026
Bilgisayar Mühendisliði Örgün Öðretim 2. Sýnýf

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	/* pc'deki dosyanýn yolunu bulan kod kýsmý  */
	
	FILE *dosya;
	char yol[100] = "";
	printf("Dosya yolunu giriniz: ");
	scanf("%s", &yol);
	dosya = fopen(yol, "r");
	char kelime[1000000], kopya[1000000];

	char karakter;
	int i = 1;

	/* dosyayý bulduysa içerisini okuyan kod kýsmý
       dosyayý bulamazsa ise uyarý veriyor */

	if (dosya != NULL)
	{
		karakter = fgetc(dosya);
		kelime[0] = karakter;
		while (karakter != EOF)
		{
			karakter = fgetc(dosya);
			kelime[i] = karakter;
			i += 1;
		}
		
		
	}
	else
	{
		printf("\n");
		printf("Dosya bulunamadi. ");
	}

	/* burada dosya içerisindeki metni kelimeleþtirmeden cmd ekranýna yazan kod kýsmý */
	printf("\n");
	printf("--------------------------------");
	printf("\n");
	printf("Dosyadaki metin: ");
	printf("\n\n");

	int t;
	for (t = 0; t < i; t++)
	{
		printf("%c", kelime[t]);
	}
	printf("\n");
	printf("--------------------------------");
	printf("\n\n");
	printf("Dosyadaki metnin kelimelestirilmis hali: ");
	//printf("\n");

	/* burada dosyadaki metnin space enter ve tab boþluklarýný yok etmek amaçlý kaydýrma iþlemi uygulandý */

	int k, j, bosluk = 0;

	for (k = 0; k < i - 1; k++)
	{
		for (j = 0; j < i - 1; j++)
		{
			if (kelime[j] == 32 || kelime[j] == 10 || kelime[j] == 9)
			{
				bosluk++;

				while (j < i - 1)
				{
					kelime[j] = kelime[j + 1];
					j++;
				}
			}
		}
	}
	
	/* kaydýrma iþleminden sonra ufak tefek boþluk pürüzlerini yok etmek için kelime dizisini boþluk karakterini kontrol ederek kopya dizisine attým  */
	
	int diziboyut = 0;
	for (j = 0; j < i - 1 - bosluk; j++)
	{
		if (kelime[j] != 32)
		{
			diziboyut++;
			kopya[j] = kelime[j];
		}
	}
	printf("\n\n");

	printf("{ ");

	int l = 0;
	for (l = 0; l < diziboyut; l++)
	{
		/* kod yazarken tanýnmasý gereken bazý karakterleri kodda tanýttým */
		
		if (kopya[l] == 40 || kopya[l] == 41 || kopya[l] == 61 || kopya[l] == 43 || kopya[l] == 45 || kopya[l] == 47 || kopya[l] == 92 ||
			kopya[l] == 42 || kopya[l] == 123 || kopya[l] == 125 || kopya[l] == 59 || kopya[l] == 58 || kopya[l] == 60 || kopya[l] == 62 ||
			kopya[l] == 33 || kopya[l] == 63 || kopya[l] == 91 || kopya[l] == 93 || kopya[l] == 94 || kopya[l] == 37 || kopya[l] == 39 ||
			kopya[l] == 34 || kopya[l] == 46 || kopya[l] == 124 || kopya[l] == 38 || kopya[l] == 44)
		{
			/* kelimeleþtirirken çýkan pürüzleri düzeltmek için (araya virgül koyma pürüzü) yazdýðým kod kýsmý */
			
			if ((kopya[l] == 40 || kopya[l] == 41 || kopya[l] == 61 || kopya[l] == 43 || kopya[l] == 45 || kopya[l] == 47 || kopya[l] == 92 ||
				 kopya[l] == 42 || kopya[l] == 123 || kopya[l] == 125 || kopya[l] == 59 || kopya[l] == 58 || kopya[l] == 60 || kopya[l] == 62 ||
				 kopya[l] == 33 || kopya[l] == 63 || kopya[l] == 91 || kopya[l] == 93 || kopya[l] == 94 || kopya[l] == 37 || kopya[l] == 39 ||
				 kopya[l] == 34 || kopya[l] == 46 || kopya[l] == 124 || kopya[l] == 38 || kopya[l] == 44) &&
				(kopya[l + 1] == 40 || kopya[l + 1] == 41 ||
				 kopya[l + 1] == 61 || kopya[l + 1] == 43 || kopya[l + 1] == 45 || kopya[l + 1] == 47 || kopya[l + 1] == 92 ||
				 kopya[l + 1] == 42 || kopya[l + 1] == 123 || kopya[l + 1] == 125 || kopya[l + 1] == 59 || kopya[l + 1] == 58 || kopya[l + 1] == 60 || kopya[l + 1] == 62 ||
				 kopya[l + 1] == 33 || kopya[l + 1] == 63 || kopya[l + 1] == 91 || kopya[l + 1] == 93 || kopya[l + 1] == 94 || kopya[l + 1] == 37 || kopya[l + 1] == 39 ||
				 kopya[l + 1] == 34 || kopya[l + 1] == 46 || kopya[l + 1] == 124 || kopya[l + 1] == 38 || kopya[l + 1] == 44))
			{
				/* özel durumlarý (++ , -- gibi) kontrol ettiðim kod kýsmý */
				
				if ((kopya[l - 1] == 61 && kopya[l] == 61) || (kopya[l - 1] == 45 && kopya[l] == 45) || (kopya[l - 1] == 43 && kopya[l] == 43) ||
					(kopya[l - 1] == 62 && kopya[l] == 61) || (kopya[l - 1] == 60 && kopya[l] == 61) || (kopya[l - 1] == 33 && kopya[l] == 61) ||
					(kopya[l - 1] == 63 && kopya[l] == 61) || (kopya[l - 1] == 124 && kopya[l] == 124) || (kopya[l - 1] == 38 && kopya[l] == 38) ||
					(kopya[l - 1] == 43 && kopya[l] == 61) || (kopya[l - 1] == 45 && kopya[l] == 61) || (kopya[l - 1] == 42 && kopya[l] == 61) ||
					(kopya[l - 1] == 47 && kopya[l] == 61) || (kopya[l - 1] == 37 && kopya[l] == 61))
				{
					printf("%c", kopya[l]);
				}
				else
				{
					printf(",%c", kopya[l]);
				}
			}
			    /* yukarýdaki pürüzleri düzelttiðim kod kýsmýna girmemesi durumunda bir daha özel durumu kontrolü yaptým */
			
			else if ((kopya[l - 1] == 61 && kopya[l] == 61) || (kopya[l - 1] == 45 && kopya[l] == 45) || (kopya[l - 1] == 43 && kopya[l] == 43) ||
					 (kopya[l - 1] == 62 && kopya[l] == 61) || (kopya[l - 1] == 60 && kopya[l] == 61) || (kopya[l - 1] == 33 && kopya[l] == 61) ||
					 (kopya[l - 1] == 63 && kopya[l] == 61) || (kopya[l - 1] == 124 && kopya[l] == 124) || (kopya[l - 1] == 38 && kopya[l] == 38) ||
					 (kopya[l - 1] == 43 && kopya[l] == 61) || (kopya[l - 1] == 45 && kopya[l] == 61) || (kopya[l - 1] == 42 && kopya[l] == 61) ||
					 (kopya[l - 1] == 47 && kopya[l] == 61) || (kopya[l - 1] == 37 && kopya[l] == 61))
			{
				/* kelimeleþtirdikten sonraki son kýsýmda çýkan ufak pürüzleri (virgül sorunu) düzelten kod kýsmý */
				
				if (l == diziboyut - 1)
				{
					printf("%c", kopya[l]);
				}
				else
				{
					printf("%c,", kopya[l]);
				}
			}
			else
			{
				if (l == diziboyut - 1)
				{
					printf(",%c", kopya[l]);
				}
				else
				{
					printf(",%c,", kopya[l]);
				}
			}
		}
		else
		{
			printf("%c", kopya[l]);
		}
	}
	printf(" }");
	printf("\n");
	fclose(dosya);

	return 0;
}
