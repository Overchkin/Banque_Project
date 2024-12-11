//Ce projet vise à concevoir un outil pour un Régime Enregistré d'Épargne Retraite (REÉR) pour Andréas et Sophia
#include <iostream>
#include<iomanip>

using namespace std;

int main()
{
	//Déclaration des variables
	short anneesSophia, anneesAndreas;
	double  montantSophia, montantAndreas, tauxRendement;
	double valeurSophia = 0.0, valeurAndreas = 0.0;
	double SommeVersementSophia = 0.0, SommeVersementAndreas = 0.0;
	double SommeRendementSophia = 0.0, SommeRendementAndreas = 0.0;
	short ageDebut = 25; short ageFin = 65;
	
// Demande à l'utilisateur de saisir les informations nécessaires pour effectuer les calculs :
// - Nombre d'années de contribution pour Sophia (entre 1 et 41).
// - Nombre d'années de contribution pour Andreas (entre 1 et 41).
// - Montant annuel des versements de Sophia.
// - Montant annuel des versements de Andreas.
// - Taux de rendement annuel (en pourcentage).
// Les valeurs saisies sont stockées dans les variables correspondantes.
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
// Vérification des conditions d'entrée pour s'assurer que les données fournies sont valides.
// Les validations incluent :
// - "anneesSophia" et "anneesAndreas" doivent être comprises entre 1 et 41 (incluses).
// - "montantSophia" et "montantAndreas" doivent être supérieurs ou égaux à 1.
// - "tauxRendement" doit être supérieur ou égal à 0.
// Si l'une de ces conditions n'est pas respectée, un message d'erreur est affiché
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

	//Simulation pour Andréas
	for (short age = ageFin - anneesAndreas + 1; age <= ageFin; ++age)
	{
		valeurAndreas += montantAndreas;
		SommeVersementAndreas += montantAndreas;
		valeurAndreas += valeurAndreas * tauxRendement;
		SommeRendementAndreas += valeurAndreas * tauxRendement;
	}

	//Affichage des résultats avec 2 décimales
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