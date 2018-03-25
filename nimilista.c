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
#include "nimilista.h"

Solmu* tyhjenna(Solmu *pAlku) {
	/* Muistin vapautus */
	Solmu *ptr = pAlku;
	while (ptr!= NULL) {
		pAlku = ptr->pNext;
		free(ptr);
		ptr = pAlku;
	}	

	return pAlku;
}

Solmu* tdstoluku(Solmu *pAlku) {
	int laskuri=0;
	char nimi[100], muisti[121];
	printf("Anna luettavan tiedoston nimi: ");
	scanf("%s", nimi);
	
	if (pAlku != NULL) {
		/* Muistin vapauttaminen */
		printf("Poistetaan aiemmat tiedot ja luetaan uudet.\n");
		pAlku = tyhjenna(pAlku);
	}
	Solmu *ptr, *ptrUusi;


	FILE *tiedosto;
	if ((tiedosto = fopen(nimi, "r")) == NULL) {
		perror("Tiedoston avaaminen ep�onnistui.");
		exit(1);
	}
	printf("Luetaan tiedosto %s.\n", nimi);
	fgets(muisti,120,tiedosto);	/* eka rivi luetaan, jotta se ei h�iritse tuloksia */

		/* Rivi rivilt� luku */
        while (fgets(muisti,120,tiedosto)) {

		/* Rivien lasku */
        laskuri++;	

		/* Muistin varaus */	
		if ((ptrUusi=(Solmu*)malloc(sizeof(Solmu))) == NULL) {
			printf("Muistin varaus ep�onnistui.");
			exit(1);
		}
		/* SOLMUN ALUSTUS */

		strcpy (ptrUusi->nimi, strtok(muisti, ";"));
		ptrUusi->luku = atoi(strtok(NULL, "\n"));
		ptrUusi->pNext = NULL;

		/*UUDEN ALKION LIS�YS LISTAAN*/
	
		if (pAlku == NULL) {
			pAlku = ptrUusi;
		} else { 
			ptr = pAlku;
			while (ptr->pNext != NULL)
				ptr = ptr->pNext;
			ptr->pNext = ptrUusi;
		}	
	}
	printf("Tiedosto %s luettu, %d nimirivi�.\n", nimi, laskuri);
	fclose(tiedosto);
	return pAlku;
}

void tulostalista(Solmu *pAlku) {
	Solmu *ptr = pAlku;
	if (ptr == NULL) {
		printf("Lista on tyhj�.\n");
	} else {
		printf("Listassa on seuraavat tiedot.\n");
		while (ptr != NULL) {
			printf("%s %li\n", ptr->nimi, ptr->luku);
			ptr = ptr->pNext;
		}
	}
}

/*EOF*/