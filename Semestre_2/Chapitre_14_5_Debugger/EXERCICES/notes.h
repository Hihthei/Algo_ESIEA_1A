#ifndef _NOTES_H_
#define _NOTES_H_

#define BMI 0
#define BPE 1
#define BFH 2

struct Etudiant_s
{
	char *nom;
	char *prenom;
	float notes[3];
	float moy;
	int credits;
};
typedef struct Etudiant_s Etudiant;

void afficheEtudiant(Etudiant etu);

#endif
