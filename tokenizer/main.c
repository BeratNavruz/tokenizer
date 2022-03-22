
/*

�sim : Berat
Soyisim : Navruz
��renci Numaras� : 02200201026
Bilgisayar M�hendisli�i �rg�n ��retim 2. S�n�f

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	/* pc'deki dosyan�n yolunu bulan kod k�sm�  */
	
	FILE *dosya;
	char yol[100] = "";
	printf("Dosya yolunu giriniz: ");
	scanf("%s", &yol);
	dosya = fopen(yol, "r");
	char kelime[1000000], kopya[1000000];

	char karakter;
	int i = 1;

	/* dosyay� bulduysa i�erisini okuyan kod k�sm�
       dosyay� bulamazsa ise uyar� veriyor */

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

	/* burada dosya i�erisindeki metni kelimele�tirmeden cmd ekran�na yazan kod k�sm� */
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

	/* burada dosyadaki metnin space enter ve tab bo�luklar�n� yok etmek ama�l� kayd�rma i�lemi uyguland� */

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
	
	/* kayd�rma i�leminden sonra ufak tefek bo�luk p�r�zlerini yok etmek i�in kelime dizisini bo�luk karakterini kontrol ederek kopya dizisine att�m  */
	
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
		/* kod yazarken tan�nmas� gereken baz� karakterleri kodda tan�tt�m */
		
		if (kopya[l] == 40 || kopya[l] == 41 || kopya[l] == 61 || kopya[l] == 43 || kopya[l] == 45 || kopya[l] == 47 || kopya[l] == 92 ||
			kopya[l] == 42 || kopya[l] == 123 || kopya[l] == 125 || kopya[l] == 59 || kopya[l] == 58 || kopya[l] == 60 || kopya[l] == 62 ||
			kopya[l] == 33 || kopya[l] == 63 || kopya[l] == 91 || kopya[l] == 93 || kopya[l] == 94 || kopya[l] == 37 || kopya[l] == 39 ||
			kopya[l] == 34 || kopya[l] == 46 || kopya[l] == 124 || kopya[l] == 38 || kopya[l] == 44)
		{
			/* kelimele�tirirken ��kan p�r�zleri d�zeltmek i�in (araya virg�l koyma p�r�z�) yazd���m kod k�sm� */
			
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
				/* �zel durumlar� (++ , -- gibi) kontrol etti�im kod k�sm� */
				
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
			    /* yukar�daki p�r�zleri d�zeltti�im kod k�sm�na girmemesi durumunda bir daha �zel durumu kontrol� yapt�m */
			
			else if ((kopya[l - 1] == 61 && kopya[l] == 61) || (kopya[l - 1] == 45 && kopya[l] == 45) || (kopya[l - 1] == 43 && kopya[l] == 43) ||
					 (kopya[l - 1] == 62 && kopya[l] == 61) || (kopya[l - 1] == 60 && kopya[l] == 61) || (kopya[l - 1] == 33 && kopya[l] == 61) ||
					 (kopya[l - 1] == 63 && kopya[l] == 61) || (kopya[l - 1] == 124 && kopya[l] == 124) || (kopya[l - 1] == 38 && kopya[l] == 38) ||
					 (kopya[l - 1] == 43 && kopya[l] == 61) || (kopya[l - 1] == 45 && kopya[l] == 61) || (kopya[l - 1] == 42 && kopya[l] == 61) ||
					 (kopya[l - 1] == 47 && kopya[l] == 61) || (kopya[l - 1] == 37 && kopya[l] == 61))
			{
				/* kelimele�tirdikten sonraki son k�s�mda ��kan ufak p�r�zleri (virg�l sorunu) d�zelten kod k�sm� */
				
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
