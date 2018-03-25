/*****************************************************************************/
/* CT60A0220 C-ohjelmoinnin ja testauksen periaatteet 
 * Tekij�: Juho Kontiainen
 * Opiskelijanumero: 0503209
 * P�iv�m��r�: 06.03.2018
 * Yhteisty� ja l�hteet, nimi ja yhteisty�n muoto: harjoitusryhmiss� ty�skentely, cprogramming.com, stackoverflow, 
 */
/*****************************************************************************/
struct Node {
	char nimi[30];
	long int luku;
	struct Node *pNext;
};
typedef struct Node Solmu;


Solmu* tdstoluku(Solmu *pAlku);
void tulostalista(Solmu *pAlku);
Solmu* tyhjenna(Solmu *pAlku);

/* EOF */