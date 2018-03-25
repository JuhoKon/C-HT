/*****************************************************************************/
/* CT60A0220 C-ohjelmoinnin ja testauksen periaatteet 
 * Tekij�: Juho Kontiainen
 * Opiskelijanumero: 0503209
 * P�iv�m��r�: 06.03.2018
 * Yhteisty� ja l�hteet, nimi ja yhteisty�n muoto: harjoitusryhmiss� ty�skentely, cprogramming.com, stackoverflow, 
 */
/*****************************************************************************/
#include "nimilista.h"
struct Node2 {
	int keskiarvo, minpituus, maxpituus, muistip, rivimaara, muistim;
	char nimi2[30];
	struct Node2 *pNext2;
};
typedef struct Node2 Solmu2;

Solmu2* tyhjennatulos(Solmu2 *pAlku2);
void tulostakaikki(Solmu2 *pAlku2);
void tallennus(Solmu2 *pAlku2);
Solmu2* analysoi(Solmu *pAlku, Solmu2 *pAlku2);
/* EOF */