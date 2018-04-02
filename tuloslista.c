/*****************************************************************************/
/* CT60A0220 C-ohjelmoinnin ja testauksen periaatteet 
 * Tekijä: Juho Kontiainen
 * Opiskelijanumero: 0503209
 * Päivämäärä: 06.03.2018
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: harjoitusryhmissä työskentely, cprogramming.com, stackoverflow, 
 */
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "nimilista.h"
#include "tuloslista.h"

void tulostakaikki(Solmu2 *pAlku2) {  /* KAIKKIEN TULOSTEN TULOSTUS */
	Solmu2 *ptr2 = pAlku2;
	if (ptr2 == NULL) {
		printf("Lista on tyhjä.\n");
	} else {

		printf("Datasetti Nimiä MinPit MaxPit KA Muistinkäyttö\n");
		while (ptr2 != NULL) {

			printf("%s      %d      %d     %d  %d  %d kB / %d%%\n", ptr2->nimi2, ptr2->rivimaara,ptr2->minpituus,
			ptr2->maxpituus, ptr2->keskiarvo, ptr2->muistim, ptr2->muistip);
			ptr2 = ptr2->pNext2;
		}
	}
}

void tallennus(Solmu2 *pAlku2) {  /* Tiedostoon tallennus*/
	Solmu2 *ptr2 = pAlku2;	
	char tnimi[102];
	printf("Anna tallennettavan tulostiedoston nimi: ");
	scanf("%s", tnimi);
	FILE *tdosto2;
	tdosto2=fopen(tnimi, "w"); 
	if (tdosto2 == NULL) {
		perror("Tiedostoon kirjoittaminen epäonnistui.");
		exit(2);
	}
	if (ptr2 == NULL) {
		printf("Lista on tyhjä.\n");
	} else {
		fprintf(tdosto2, "Datasetti Nimiä MinPit MaxPit KA Muistinkäyttö\n");				/* KIRJOITUS ALKAA */
		while (ptr2 != NULL) {
			fprintf(tdosto2,"%s      %d      %d     %d  %d  %d kB / %d%%\n", ptr2->nimi2, ptr2->rivimaara,ptr2->minpituus,
			ptr2->maxpituus, ptr2->keskiarvo, ptr2->muistim, ptr2->muistip);
			ptr2 = ptr2->pNext2;
		}
	}
	printf("Tiedosto tallennettu.\n");
	fclose(tdosto2);
}
Solmu2* analysoi(Solmu *pAlku, Solmu2 *pAlku2) {	
	int lukmr=0, pienin=1000, suurin=0;
	float tulos=0,musage;	
	char nimi[100];
	Solmu *ptr = pAlku;

	printf("Anna analysoitavalle datasetille nimi: ");
	scanf("%s", nimi);
	printf("Analysoidaan listassa olevat tiedot.\n");
	if (ptr == NULL) {
		printf("Lista on tyhjä.\n");
	} else {
		while (ptr != NULL) {
			if (strlen(ptr->nimi) < pienin) {
				pienin = strlen(ptr->nimi);
			} else if (strlen(ptr->nimi) > suurin) {
				suurin = strlen(ptr->nimi);
			}

			lukmr++;
			tulos = strlen(ptr->nimi) + tulos;
			ptr = ptr->pNext;
		}
	}
	musage = ((30 - ((tulos/lukmr)+1)) * lukmr)/ (sizeof(Solmu)*lukmr);
	printf("Datasetti Nimiä MinPit MaxPit KA Muistinkäyttö\n");
	printf("%s      %d      %d     %d  %.0f  %.0f kB / %.0f%%\n", nimi, lukmr, pienin, suurin, round((tulos/lukmr)), floor((sizeof(Solmu)*lukmr) / 1000), ceil((1-musage)*100));

	/* MUISTIN VARAUS*/

	Solmu2 *ptr2, *ptrUusi2;

	if ((ptrUusi2=(Solmu2*)malloc(sizeof(Solmu2))) == NULL) {
		printf("Muistin varaus epäonnistui.");
		exit(1);
	}
	/* SOLMUN ALUSTUS */

	strcpy(ptrUusi2->nimi2 , nimi);
	ptrUusi2 -> rivimaara = lukmr;
	ptrUusi2 -> keskiarvo = round((tulos/lukmr));
	ptrUusi2 -> minpituus = pienin;	
	ptrUusi2 -> maxpituus = suurin;
	ptrUusi2 -> muistip	  = ceil((1-musage)*100);
	ptrUusi2 -> muistim   = floor((sizeof(Solmu)*lukmr)) / 1000 ;
	ptrUusi2 -> pNext2 = NULL;

	/*UUDEN ALKION LISÄYS LISTAAN*/
	
	if (pAlku2 == NULL) {
		pAlku2 = ptrUusi2;
	} else { 
		ptr2 = pAlku2;
		while (ptr2->pNext2 != NULL)
			ptr2 = ptr2->pNext2;
		ptr2->pNext2 = ptrUusi2;
	}	
	return (pAlku2);
}
Solmu2* tyhjennatulos(Solmu2 *pAlku2) {
	/* Muistin vapautus */
	Solmu2 *ptr2 = pAlku2;
	while (ptr2!= NULL) {
		pAlku2 = ptr2->pNext2;
		free(ptr2);
		ptr2 = pAlku2;
	}	

	return pAlku2;
}
/*EOF*/
