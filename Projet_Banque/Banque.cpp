//Ce projet vise � concevoir un outil pour un R�gime Enregistr� d'�pargne Retraite (RE�R) pour Andr�as et Sophia
#include <iostream>
#include<iomanip>

using namespace std;

int main()
{
	//D�claration des variables
	short anneesSophia, anneesAndreas;
	double  montantSophia, montantAndreas, tauxRendement;
	double valeurSophia = 0.0, valeurAndreas = 0.0;
	double SommeVersementSophia = 0.0, SommeVersementAndreas = 0.0;
	double SommeRendementSophia = 0.0, SommeRendementAndreas = 0.0;
	short ageDebut = 25; short ageFin = 65;
	
// Demande � l'utilisateur de saisir les informations n�cessaires pour effectuer les calculs :
// - Nombre d'ann�es de contribution pour Sophia (entre 1 et 41).
// - Nombre d'ann�es de contribution pour Andreas (entre 1 et 41).
// - Montant annuel des versements de Sophia.
// - Montant annuel des versements de Andreas.
// - Taux de rendement annuel (en pourcentage).
// Les valeurs saisies sont stock�es dans les variables correspondantes.
	cout << "Veuillez entrer le nombre d'annees de contribution pour Sophia (1-41): ", cin >> anneesSophia;
	cout << endl;
	cout << "Veuillez entrer le nombre d'annees de contribution pour Andreas (1-41): ", cin >> anneesAndreas;
	cout << endl;
	cout << "Veuillez entrer le montant annuel des versements de Sophia: ", cin >> montantSophia;
	cout << endl;
	cout << "Veuillez entrer le montant annuel des versements de Andreas: ", cin >> montantAndreas;
	cout << endl;
	cout << "Veuillez entrer le taux de rendement annuel (en pourcentage): ", cin >> tauxRendement;
	
	cout << endl;
	cout << endl;
// V�rification des conditions d'entr�e pour s'assurer que les donn�es fournies sont valides.
// Les validations incluent :
// - "anneesSophia" et "anneesAndreas" doivent �tre comprises entre 1 et 41 (incluses).
// - "montantSophia" et "montantAndreas" doivent �tre sup�rieurs ou �gaux � 1.
// - "tauxRendement" doit �tre sup�rieur ou �gal � 0.
// Si l'une de ces conditions n'est pas respect�e, un message d'erreur est affich�
// et le programme retourne une valeur de 1 pour indiquer une erreur.
	if (anneesSophia < 1 || anneesSophia > 41 || anneesAndreas < 1 || anneesAndreas > 41 || montantSophia < 1 || montantAndreas < 1 || tauxRendement < 0)
	{
		cout << "Les donnees entrer sont invalides. Veuillez reessayer" << endl;
		return 1;
	}

	tauxRendement /= 100.0;

	//Simulation pour Sophia
	for (short age = ageDebut; age < ageDebut + anneesSophia; ++age)
	{
		valeurSophia += montantSophia;
		SommeVersementSophia += montantSophia;
		valeurSophia += valeurSophia * tauxRendement;
		SommeRendementSophia += valeurSophia * tauxRendement;
	}

	//Simulation pour Andr�as
	for (short age = ageFin - anneesAndreas + 1; age <= ageFin; ++age)
	{
		valeurAndreas += montantAndreas;
		SommeVersementAndreas += montantAndreas;
		valeurAndreas += valeurAndreas * tauxRendement;
		SommeRendementAndreas += valeurAndreas * tauxRendement;
	}

	//Affichage des r�sultats avec 2 d�cimales
	cout << fixed << setprecision(2);
	cout << endl;
	cout << "Valeur finale du REER de Sophia: $" << valeurSophia << endl;
	cout << endl;
	cout << "Valeur finale du REER d'Andreas: $" << valeurAndreas << endl;
	cout << endl;
	cout << "Somme des versements de Sophia: $" << SommeVersementSophia << endl;
	cout << endl;
	cout << "Somme des versements d'Andreas: $" << SommeVersementSophia << endl;
	cout << endl;
	cout << "Somme des rendements de Sophia: $" << SommeRendementSophia << endl;
	cout << endl;
	cout << "Somme des rendements d'Andreas: $" << SommeRendementAndreas << endl;

	return 0;
}