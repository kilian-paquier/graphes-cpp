#include "stdafx.h"
#include "CParseur.h"



using namespace std;

/******************************************************************************
*** Constructeur par défaut	d'un CParseur									***
***	Initialise CParseur														***
******************************************************************************/
CParseur::CParseur()
{
	sPARNomFichier = nullptr;
}

/******************************************************************************
*** Constructeur de confort avec nom du fichier à ouvrir					***
*** @param string sNomfichier est le nom du fichier à ouvrir avc son .txt	***
***	Initialise CParseur														***
******************************************************************************/
CParseur::CParseur(std::string sNomFichier)
{
	sPARNomFichier = sNomFichier;
}

/******************************************************************************
*** Destructeur de CParseur													***
***																			***
******************************************************************************/
CParseur::~CParseur()
{
	delete graphe;
}

/**************************************************************************************************************
*** Lecture de fichier de graphique																			***
***																											***
*** retourne un CGraphe  																					***
***																											***
**************************************************************************************************************/
CGraphe & CParseur::PARLireGraph(void)
{
	ifstream fichier(sPARNomFichier, ios::in);  // on ouvre en lecture


	if (fichier)
	{

		string sContenu1, sContenu2, sVide;
		size_t sPosition1, sPosition2;
		unsigned int uiNbSommet, uiNbArc, uiSommet, uiArc, uiLecture,uiArrivant, uiPartant;
		getline(fichier, sContenu1);
		getline(fichier, sContenu2);
		sPosition1 = sContenu1.find("=");
		sContenu1 = sContenu1.substr(sPosition1 + 1);
		sPosition2 = sContenu2.find("=");
		sContenu2 = sContenu2.substr(sPosition2 + 1);
		uiNbSommet = stoi(sContenu1);
		uiNbArc = stoi(sContenu2);

		graphe = new CGraphe();
		getline(fichier, sVide);

		vector<CSommet>SOMTabSommet(uiNbSommet);
		for (uiSommet = 0; uiSommet < uiNbSommet; uiSommet++)
		{
			fichier >> uiLecture;
			SOMTabSommet[uiSommet] = CSommet(uiLecture);
			graphe->GPHAjouterSommet(SOMTabSommet[uiSommet]);
		}

		getline(fichier, sVide);
		getline(fichier, sVide);
		getline(fichier, sVide);

		for (uiArc = 0; uiArc < uiNbArc; uiArc++)
		{
			fichier >> uiLecture;
			uiPartant = uiLecture;
			fichier >> uiLecture;
			uiArrivant = uiLecture;
			graphe->GPHAjouterArc(uiPartant, uiArrivant);
		}
		fichier.close();
		return * graphe;
	}
	else
	{
		throw Cexception(FICHIER_NOT_OPEN, (char*) "Le fichier ne s'ouvre pas");
	}
}


