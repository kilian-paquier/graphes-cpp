#ifndef C_PARSEUR_H
#define C_PARSEUR_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>
#include <fstream>
#include "CGraphe.h"

#define FICHIER_NOT_OPEN 601


class CParseur
{
	// Attributs
private:
	std::string sPARNomFichier; //Nom du fichier avec le point .txt
	CGraphe  * graphe = nullptr;

	// Constructeurs
public:
	/******************************************************************************
	*** Constructeur par d�faut	d'un CParseur									***
	***	Initialise CParseur														***
	******************************************************************************/
	CParseur();

	/******************************************************************************
	*** Constructeur de confort avec nom du fichier � ouvrir					***
	*** @param string sNomfichier est le nom du fichier � ouvrir avc son .txt	***
	***	Initialise CParseur														***
	******************************************************************************/
	CParseur(std::string sNomFichier);

	/******************************************************************************
	*** Destructeur de CParseur													***
	***																			***
	******************************************************************************/
	~CParseur();

	// M�thodes

	/**************************************************************************************************************
	*** Lecture de fichier d'un graphe																		***
	***																											***
	*** retourne un CGraphe  																					***
	***																											***
	**************************************************************************************************************/
	CGraphe & PARLireGraph(void);
};
#endif
