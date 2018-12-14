#ifndef C_SOMMET_H
#define C_SOMMET_H

#include "CArc.h"
#include <vector>

class CSommet
{
private:
	unsigned int uiSOMIdSommet;
	std::vector<CArc*> ARCSOMArrivant;
	std::vector<CArc*> ARCSOMPartant;


public:
	/******************************************************************************************************
	***	Cette fonction est le constructeur par défaut d'un sommet, il permet d'initialiser son ID à 0	***
	******************************************************************************************************/
	CSommet();

	/**************************************************************************************************************
	***	Cette fonction est le constructeur de recopie, il permet de recopier un sommet dans le sommet en cours	***
	*** @param sommet le sommet à recopier dans le sommet en cours												***
	**************************************************************************************************************/
	CSommet(const CSommet & sommet);

	/**************************************************************************************************************************
	***	Cette fonction est un constructeur de confort d'un sommet, il permet d'initaliser l'ID par celui passé en paramètre	***
	*** @param uiID l'id du sommet à donner au sommet																		***
	**************************************************************************************************************************/
	CSommet(unsigned int uiID);

	/******************************************************************************************************************************
	***	Cette fonction est le destructeur par défaut d'un sommet, il supprime tous les éléments de la liste des vecteurs d'arcs	***
	******************************************************************************************************************************/
	~CSommet();

	/******************************************************************************************************
	***	Cette fonction permet d'ajouter un arc aux vecteurs contenant les arcs d'arrivées et de départs	***
	*** @param uiSommet le numéro du sommet vers lequel l'arc part										***
	******************************************************************************************************/
	void SOMAjouterArcPartant(unsigned int uiSommet);

	/******************************************************************************************************
	***	Cette fonction permet d'ajouter un arc aux vecteurs contenant les arcs d'arrivées et de départs	***
	*** @param uiSommet le numéro du sommet depuis lequel l'arc arrive									***
	******************************************************************************************************/
	void SOMAjouterArcArrivant(unsigned int uiSommet);

	/**************************************************************************************************************************
	***	Cette fonction permet de modifier la destination d'un arc faisant parti de la liste des arc partants ou arrivants	***
	*** @param uiDestination le numéro du sommet vers lequel l'arc part														***
	*** @param uiNouvelleDestination le numéro de la nouvelle destination de l'arc											***
	**************************************************************************************************************************/
	void SOMModifierArc(unsigned int uiDestination, unsigned int uiNouvelleDestination);

	/**********************************************************************************************************
	***	Cette fonction permet de supprimer un arc de la liste des arcs arrivants ou partants				***
	*** @param uiDestination le numéro du sommet vers lequel l'arc part										***
	*** @param bOrientation désigne l'orientation de l'arc : vrai l'arc est arrivant/faux l'arc est partant ***
	**********************************************************************************************************/
	void SOMSupprimerArc(unsigned int uiDestination, bool bOrientation);

	/******************************************************************
	***	Cette fonction permet de récupérer l'ID du sommet en cours	***
	******************************************************************/
	unsigned int SOMlireIDSommet();

	/**********************************************************************
	***	Cette fonction permet de récuperer la liste des arcs arrivants	***
	**********************************************************************/
	std::vector<CArc*> & SOMlireArrivant();

	/**********************************************************************
	***	Cette fonction permet de récuperer la liste des arcs partants	***
	**********************************************************************/
	std::vector<CArc*> & SOMlirePartant();
};
#endif
