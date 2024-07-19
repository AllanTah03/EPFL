// EPFL_devoir.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.

#include <iostream>
#include<string>

using namespace std;


class EPFL
{
public:
	int nombreEPFL;
	int nombreSecretaires, nombreEnseignant, nombreEtudiant;

    EPFL() :nombreSecretaires(0), nombreEnseignant(0), nombreEtudiant(0) {}

	virtual int getAnnee() const = 0;

	void afficherNombreEPFL()
	{
		nombreEPFL = nombreEnseignant + nombreEtudiant + nombreSecretaires;
		cout << "Nombre EPFLiens : " << nombreEPFL;
	}

	virtual void afficherInfos() const = 0;
};

class Secretaire : public EPFL
{
public:
	string nom;
	int annee;
	string nomLab;
	int salaire;

	Secretaire(string name, int ans, string Lab, int money)
	{
		nom = name;
		annee = ans;
		nomLab = Lab;
		salaire = money;
	}

	Secretaire(): annee(0),salaire(0){}

	void entrerSecretaire()
	{
		cout << "Nom : ";
		cin >> nom;
		cout << "Annee d'entree : ";
		cin >> annee;
		cout << "Nom du laboratoire : ";
		cin >> nomLab;
		cout << "Salaire : ";
		cin >> salaire;
		nombreSecretaires++;
	}

	void afficherInfos() const override
	{
		cout << "Nom : " << nom << "\nAnnee d'arrivee : " << annee << "\nNom du laboratoire ou de l'institut : " << nomLab << "\nSalaire : " << salaire << endl << endl;
	}

	int getAnnee() const override
	{
		return annee;
	}

};

class Enseignant : public EPFL
{
public: 
	string nom;
	int annee;
	string nomLab;
	string nomSection;
	int salaire;

	Enseignant(string name, int ans, string Lab, string section, int money)
	{
		nom = name;
		annee = ans;
		nomLab = Lab;
		nomSection = section;
		salaire = money;;
	}

	Enseignant(){}

	void entrerEnseignant()
	{
		cout << "Nom : ";
		cin >> nom;
		cout << "Annee d'entree: ";
		cin >> annee;
		cout << "Nom du laboratoire : ";
		cin >> nomLab;
		cout << "Nom de la section: ";
		cin >> nomSection;
		cout << "Salaire : ";
		cin >> salaire;
		nombreEnseignant++;
	}

	void afficherInfos() const override 
	{
		cout << "Nom : " << nom << "\nAnnee d'arrivee : " << annee << "\nNom du laboratoire ou de l'institut : " << nomLab << "\nSection : " << nomSection << "\nSalaire : " << salaire << endl << endl;

	}

	int getAnnee() const override
	{
		return annee;
	}
};

class Etudiant : public virtual EPFL
{
public:
	int nombreEtudiant, etudiantRegulier, etudiantEchange;

	Etudiant() :nombreEtudiant(0), etudiantRegulier(0), etudiantEchange(0), annee(0) {}

	string nom;
	int annee;
	string nomSection;

	Etudiant(string name, int ans, string section) 
	{
		nom = name;
		annee = ans;
		nomSection = section;
	}

	void afficherNombreEtudiant() 
	{
		nombreEtudiant = etudiantEchange + etudiantRegulier;
		cout << "Nombre Etudiant : " << nombreEtudiant;
	};
	int getAnnee() const override
	{
		return annee;
	}
	
	void afficherInfos() const override
	{
		cout << "Nom : " << nom << "\nAnnee d'arrivee : " << annee << "\nSection : " << nomSection << endl << endl;
	}

};

class Echange : public Etudiant
{
public:
	string universiteOrigine;

	Echange(string name, int ans, string section, string origine) : Etudiant(name, ans, section) 
	{
		universiteOrigine = origine;
	}

	Echange(): Etudiant (){}

	void entrerEtudiantEchange() 
	{
		cout << "Nom : ";
		cin >> nom;
		cout << "Annee d'entree: ";
		cin >> annee;
		cout << "Nom de la section: ";
		cin >> nomSection;
		cout << "Universite d'origine : ";
		cin >> universiteOrigine;
		etudiantEchange++;
	}

	void afficherInfos() const override 
	{
		cout << "Nom : " << nom << "\nAnnee d'arrivee : " << annee << "\nSection : " << nomSection << "\nUniversite d'origine : " << universiteOrigine << endl << endl;

	}

};

class Regulier : public Etudiant
{
public:
	int resultatPrope1;

	Regulier(string name, int ans, string section, int resultat) :Etudiant(name, ans, section) 
	{
		resultatPrope1 = resultat;
	}

	Regulier(): Etudiant(),resultatPrope1(0) {}

	void entrerEtudiantRegulier() 
	{
		cout << "Nom : ";
		cin >> nom;
		cout << "Annee d'entree: ";
		cin >> annee;
		cout << "Nom de la section: ";
		cin >> nomSection;
		cout << "resultat prope 1 : ";
		cin >> resultatPrope1;
		etudiantRegulier++;
	}

	void afficherInfos()const override 
	{
		cout << "Nom : " << nom << "\nAnnee d'arrivee : " << annee << "\nSection : " << nomSection << "\nresultat prope 1 : " << resultatPrope1 << endl << endl;

	}

};

int main()
{
	int n=0, choix1=0, choix2=0;
	string choix3;
	EPFL* epfliens[100];//Tableau de poiteurs vers objets EPFL
	int nombrePersonne=0;
	
	do
	{
		cout << "Entrer le nombre de personne a enregistrer : ";
		cin >> n;
		for (int i = 0; i < n + 1; ++i)
		{
			cout << "\nMenu: " << endl;
			cout << "1. Ajouter une secretaire" << endl;
			cout << "2. Ajouter un enseignant" << endl;
			cout << "3. Ajouter un etudiant" << endl;
			cout << "4. Afficher nombre de personnes a l'EPFL" << endl;
			cout << "5. Afficher nombre d'etudiants" << endl;
			cout << "6. Afficher annee moyenne d'arrivee" << endl;
			cout << "Choix : ";
			cin >> choix1;


			switch (choix1)
			{
			case 1:
			{
				cout << endl;
				if (nombrePersonne < 100)
				{
					Secretaire* secretaires = new Secretaire(); // Déclarer le tableau de secrétaires
					secretaires->entrerSecretaire();
					epfliens[nombrePersonne++] = secretaires; // Faire rentrer dans le tableau epfliens les donnees des secretaires et incrementation de nombrePersonne pour selectionner une nouvelle case du tableau avec une personne est egale a une case du tableau
				}
				else
				{
					cout << "Nombre de secretaires atteint la capacite maximale." << endl;
				}
				break;

			}
			case 2:
			{
				cout << endl;
				if (nombrePersonne < 100)
				{
					Enseignant* enseignant = new Enseignant();// Déclarer le tableau d'enseignant
					enseignant->entrerEnseignant();
					epfliens[nombrePersonne++] = enseignant;// Faire rentrer dans le tableau epfliens les donnees des enseignants et incrementation de nombrePersonne pour selectionner une nouvelle case du tableau avec une personne est egale a une case du tableau
				}
				else
				{
					cout << "Nombre d'enseignant atteint la capacite maximale." << endl;
				}

				break;

			}
			case 3:
			{
				cout << endl;
				cout << "Est-ce un etudiant :" << endl;
				cout << "1. Regulier" << endl;
				cout << "2. En échange" << endl;
				cout << "Réponse : ";
				cin >> choix2;
				cout << endl;

				switch (choix2)
				{
				case 1:
				{
					if (nombrePersonne < 100)
					{
						Regulier* regulier = new Regulier();// Déclarer le tableau d'etudiant regulier
						regulier->entrerEtudiantRegulier();
						epfliens[nombrePersonne++] = regulier;// Faire rentrer dans le tableau epfliens les donnees d'etudiant regulier et incrementation de nombrePersonne pour selectionner une nouvelle case du tableau avec une personne est egale a une case du tableau
					}
					else
					{
						cout << "Nombre d'etudiant regulier atteint la capacite maximale." << endl;
					}
					break;
				}
				case 2:
				{
					if (nombrePersonne < 100)
					{
						Echange* echange = new Echange();// Déclarer le tableau d'etudiant en echange
						echange->entrerEtudiantEchange();
						epfliens[nombrePersonne++] = echange;// Faire rentrer dans le tableau epfliens les donnees des etudiants en echange et incrementation de nombrePersonne pour selectionner une nouvelle case du tableau avec une personne est egale a une case du tableau
					}
					else
					{
						cout << "Nombre d'etudiant en echange atteint la capacite maximale." << endl;
					}
					break;

				}
				default:
					cout << "Choix invalide.";
					break;
				}

				break;

			}
			case 4:
			{
				cout << endl;
				cout << "Nombre de personnes a l'EPFL : " << nombrePersonne << endl;
				break;
			}
			case 5:
			{
				cout << endl;
				Etudiant etudiant;
				etudiant.afficherNombreEtudiant();
				break;
			}
			case 6:
			{
				int sommeAnnee = 0;
				int anneeMoyenne = 0;
				cout << endl;
				for (int i = 0; i < nombrePersonne; ++i)
				{
					sommeAnnee += (2024 - epfliens[i]->getAnnee()); // Fait la somme des années d'entrer de tout les epfliens en les prenant dans le tableau grâce à getAnnee()
				}

				if (nombrePersonne > 0)
				{
					anneeMoyenne = (1 * sommeAnnee) / n; // Calcule de l'année moyenne d'entrer à l'EPFL de tout les epfliens
					cout << "Annee moyenne : " << anneeMoyenne << endl;
				}
				else
				{
					cout << "Aucune donnee pour calculer l'annee moyenne" << endl;
				}
				break;

			}
			default:
			{
				cout << "\nChoix invalide." << endl;
				break;
			}


			}
		}
		cout << "\nVoulez-vous continuer ? ";
		cout << "\nReponse : ";
		cin >> choix3;

		while (choix3 != "oui" && choix3 != "Oui" && choix3 != "OUI" && choix3 != "non" && choix3 != "Non" && choix3 != "NON")
		{
			cout << "\nReponse invalide. Voulez-vous continuer ? \nChoix : ";
			cin >> choix3;
		}

	}while (choix3 == "oui" || choix3 == "Oui" || choix3 == "OUI");
	
	if (choix3 == "non" || choix3 == "Non" || choix3 == "NON")
	{
		cout << "\nListe des personnes enregistrees : " << endl<< endl;
		for (int i = 0; i < nombrePersonne; i++)
		{
			epfliens[i]->afficherInfos(); // Affichage des informations de toutes les personnes enregistrées
		}
		return 0;
	}

}

