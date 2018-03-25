/*****************************************************************************/
/* CT60A0220 C-ohjelmoinnin ja testauksen periaatteet 
 * Tekijä: Juho Kontiainen
 * Opiskelijanumero: 0503209
 * Päivämäärä: 06.03.2018
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: harjoitusryhmissä työskentely, cprogramming.com, stackoverflow, 
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