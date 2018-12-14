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
	***	Cette fonction est le constructeur par d�faut d'un sommet, il permet d'initialiser son ID � 0	***
	******************************************************************************************************/
	CSommet();

	/**************************************************************************************************************
	***	Cette fonction est le constructeur de recopie, il permet de recopier un sommet dans le sommet en cours	***
	*** @param sommet le sommet � recopier dans le sommet en cours												***
	**************************************************************************************************************/
	CSommet(const CSommet & sommet);

	/**************************************************************************************************************************
	***	Cette fonction est un constructeur de confort d'un sommet, il permet d'initaliser l'ID par celui pass� en param�tre	***
	*** @param uiID l'id du sommet � donner au sommet																		***
	**************************************************************************************************************************/
	CSommet(unsigned int uiID);

	/******************************************************************************************************************************
	***	Cette fonction est le destructeur par d�faut d'un sommet, il supprime tous les �l�ments de la liste des vecteurs d'arcs	***
	******************************************************************************************************************************/
	~CSommet();

	/******************************************************************************************************
	***	Cette fonction permet d'ajouter un arc aux vecteurs contenant les arcs d'arriv�es et de d�parts	***
	*** @param uiSommet le num�ro du sommet vers lequel l'arc part										***
	******************************************************************************************************/
	void SOMAjouterArcPartant(unsigned int uiSommet);

	/******************************************************************************************************
	***	Cette fonction permet d'ajouter un arc aux vecteurs contenant les arcs d'arriv�es et de d�parts	***
	*** @param uiSommet le num�ro du sommet depuis lequel l'arc arrive									***
	******************************************************************************************************/
	void SOMAjouterArcArrivant(unsigned int uiSommet);

	/**************************************************************************************************************************
	***	Cette fonction permet de modifier la destination d'un arc faisant parti de la liste des arc partants ou arrivants	***
	*** @param uiDestination le num�ro du sommet vers lequel l'arc part														***
	*** @param uiNouvelleDestination le num�ro de la nouvelle destination de l'arc											***
	**************************************************************************************************************************/
	void SOMModifierArc(unsigned int uiDestination, unsigned int uiNouvelleDestination);

	/**********************************************************************************************************
	***	Cette fonction permet de supprimer un arc de la liste des arcs arrivants ou partants				***
	*** @param uiDestination le num�ro du sommet vers lequel l'arc part										***
	*** @param bOrientation d�signe l'orientation de l'arc : vrai l'arc est arrivant/faux l'arc est partant ***
	**********************************************************************************************************/
	void SOMSupprimerArc(unsigned int uiDestination, bool bOrientation);

	/******************************************************************
	***	Cette fonction permet de r�cup�rer l'ID du sommet en cours	***
	******************************************************************/
	unsigned int SOMlireIDSommet();

	/**********************************************************************
	***	Cette fonction permet de r�cuperer la liste des arcs arrivants	***
	**********************************************************************/
	std::vector<CArc*> & SOMlireArrivant();

	/**********************************************************************
	***	Cette fonction permet de r�cuperer la liste des arcs partants	***
	**********************************************************************/
	std::vector<CArc*> & SOMlirePartant();
};
#endif
