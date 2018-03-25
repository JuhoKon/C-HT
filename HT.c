/*****************************************************************************/
/* CT60A0220 C-ohjelmoinnin ja testauksen periaatteet 
 * Tekij�: Juho Kontiainen
 * Opiskelijanumero: 0503209
 * P�iv�m��r�: 06.03.2018
 * Yhteisty� ja l�hteet, nimi ja yhteisty�n muoto: harjoitusryhmiss� ty�skentely, cprogramming.com, stackoverflow, 
 */
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tuloslista.h"
/* Valikko. */
int valikko(void) {
	int valinta;
	printf("1) Lue nimi tiedosto\n");
	printf("2) Tulosta listassa olevat tiedot\n");
	printf("3) Analysoi tiedot\n");
	printf("4) Tulosta kaikki tulostiedot\n");
	printf("5) Tallenna kaikki tulostiedot tiedostoon\n");
	printf("6) Tyhjenn� tuloslista\n");
	printf("0) Lopeta\n");
	printf("Anna valintasi: ");
	scanf("%d", &valinta);
	return valinta;

}
int main(void) {
	Solmu *pAlku = NULL;
	Solmu2 *pAlku2 = NULL;
	int valinta = 1;
	printf("T�m� ohjelma tutkii nimitietoja sis�lt�vi� tiedostoja.\n");
	while (valinta !=0) {
		valinta = valikko();
		if (valinta == 0) {

		} else if (valinta == 1) {	
			pAlku = tdstoluku(pAlku);
		} else if (valinta == 2) {
			tulostalista(pAlku);
		} else if (valinta == 3) {
			 pAlku2 = analysoi(pAlku, pAlku2); 
		} else if (valinta == 4) {
			 tulostakaikki(pAlku2);
		} else if (valinta == 5) {
			 tallennus(pAlku2);
		} else if (valinta == 6) {
			 pAlku2 = tyhjennatulos(pAlku2);
		     printf("Tuloslista tyhjennetty.\n");
		} else {
			printf("V��r� sy�te.\n");
		}
	}
	printf("Kiitos ohjelman k�yt�st�.\n");
	return 0;
}
/*EOF*/