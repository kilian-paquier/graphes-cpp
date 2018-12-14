#ifndef C_GRAPHE_H
#define C_GRAPHE_H

#include <vector>
#include <iostream>
using namespace std;

#include "Cexception.h"
#include "CSommet.h"

#define SOMMET_NOT_FOUND 500
#define ARC_NOT_FOUND 501

class CGraphe
{
private:
	std::vector<CSommet> SOMGPHSommets;

public:
	/**************************************************************************************************
	***	Cette fonction est le constructeur de recopie qui prend en paramètre une liste de sommets	***
	*** @param sommets la liste de sommets (sous forme vector) à recopie dans le graphe				***
	**************************************************************************************************/
	CGraphe(std::vector<CSommet> & sommets);

	/******************************************************************************************
	***	Cette fonction est le constructeur par défaut d'un graphe, celui-ci ne fait rien	***
	******************************************************************************************/
	CGraphe();

	/******************************************************************************************
	***	Cette fonction est le constructeur par défaut d'un graphe, celui-ci ne fait rien	***
	******************************************************************************************/
	CGraphe(CGraphe & graphe);

	/******************************************************************************************************************************
	***	Cette fonction est le destructeur par défaut d'un graphe, celui-ci vide la liste des sommets et libère tous les arcs	***
	******************************************************************************************************************************/
	~CGraphe();

	/**********************************************************************************
	***	Cette fonction permet d'ajouter un sommet à la liste des sommets du graphe	***
	*** @param SOMsommet le sommet à ajouter à la liste de sommets					***
	**********************************************************************************/
	void GPHAjouterSommet(CSommet & SOMsommet);

	/**************************************************************
	***	Cette fonction permet de supprimer un sommet du graphe	***
	*** @param uiID l'id du sommet à supprimer					***
	**************************************************************/
	void GPHSupprimerSommet(unsigned int uiID);

	/**************************************************************
	***	Cette fonction permet d'ajouter un arc au graphe		***
	*** @param uiPartant l'id du sommet duquel part l'arc		***
	*** @param uiArrivant l'id du sommet auquel va l'arc		***
	**************************************************************/
	void GPHAjouterArc(unsigned int uiPartant, unsigned int uiArrivant);

	/**************************************************************************
	***	Cette fonction permet de modifier un arc du graphe					***
	*** @param uiIDSommetPartant l'id du sommet depuis lequel l'arc part	***
	*** @param uiIDSommetArrivant l'id du sommet vers lequel l'arc va		***
	*** @param uiIDNouveauSommet l'id du nouveau sommet						***
	**************************************************************************/
	void GPHModifierArcPartant(unsigned int uiIDSommetPartant, unsigned int uiIDSommetArrivant, unsigned int uiIDNouveauSommet);

	/**************************************************************************
	***	Cette fonction permet de modifier un arc du graphe					***
	*** @param uiIDSommetPartant l'id du sommet depuis lequel l'arc part	***
	*** @param uiIDSommetArrivant l'id du sommet vers lequel l'arc va		***
	*** @param uiIDNouveauSommet l'id du nouveau sommet						***
	**************************************************************************/
	void GPHModifierArcArrivant(unsigned int uiIDSommetPartant, unsigned int uiIDSommetArrivant, unsigned int uiIDNouveauSommet);

	/**********************************************************************
	***	Cette fonction permet de supprimer un arc du graphe				***
	*** @param uiIDsommetUn l'id du sommet depuis lequel l'arc part		***
	*** @param uiIDsommetDeux l'id du sommet vers lequel l'arc va		***
	**********************************************************************/
	void GPHSupprimerArc(unsigned int uiIDsommetUn, unsigned int uiIDsommetDeux);

	/******************************************************
	***	Cette fonction permet d'afficher le graphe		***
	******************************************************/
	void GPHAfficher();

	/**************************************************************************
	***	Cette fonction permet de recupérer la liste des sommets du graphe	***
	*** @return La liste des sommets										***
	**************************************************************************/
	std::vector<CSommet> & GPHlireSommets();

	/**************************************************************************
	***	Cette fonction permet de recupérer le nombre de sommets du graphe	***
	*** @return la taille de la liste des sommets							***
	**************************************************************************/
	int GPHNbSommets();

	/******************************************************************************
	***	Cette fonction permet de rechercher un sommet dans la liste des sommets	***
	*** @param uiIDSommet l'id du sommet à rechercher							***
	*** @return vrai si le sommet a été trouvé, faux sinon						***
	******************************************************************************/
	bool GPHRechercherSommet(unsigned int uiIDSommet);

	/******************************************************************************************
	***	Cette fonction permet de rechercher un arc de la liste des arcs partants			***
	*** @param uiDestination l'id du sommet vers lequel va l'arc ou depuis lequel il part	***
	*** @param uiIDSommet le numéro du sommet dans lequel chercher l'arc					***
	*** @return vrai si l'arc a été trouvé, faux sinon										***
	******************************************************************************************/
	bool GPHRechercherArcPartant(unsigned int uiIDSommet, unsigned int uiDestination);

	/******************************************************************************************
	***	Cette fonction permet de rechercher un arc de la liste des arcs arrivants			***
	*** @param uiDestination l'id du sommet vers lequel va l'arc ou depuis lequel il part	***
	*** @param uiIDSommet le numéro du sommet dans lequel chercher l'arc					***
	*** @return vrai si l'arc a été trouvé, faux sinon										***
	******************************************************************************************/
	bool GPHRechercherArcArrivant(unsigned int uiIDSommet, unsigned int uiDestination);

	/**********************************************************
	***	Cette fonction d'inverser tous les sens des arcs	***
	**********************************************************/
	void GPHInverserLesSens();

	CSommet & GPHRetournerSommet(unsigned int uID);

	CGraphe & GPHExtract(unsigned int uID, unsigned int uTaille);

	void GPHViderArcsInexistants();

};
#endif
