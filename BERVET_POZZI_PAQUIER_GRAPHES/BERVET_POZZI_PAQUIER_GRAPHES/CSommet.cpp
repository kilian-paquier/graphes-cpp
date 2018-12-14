#include "stdafx.h"
#include "CSommet.h"

/**************************************************************************************************************************
***	Cette fonction est un constructeur de confort d'un sommet, il permet d'initaliser l'ID par celui passé en paramètre	***
*** @param uiID l'id du sommet à donner au sommet																		***
**************************************************************************************************************************/
CSommet::CSommet(unsigned int uiID)
{
	uiSOMIdSommet = uiID;
}

/******************************************************************************************************
***	Cette fonction est le constructeur par défaut d'un sommet, il permet d'initialiser son ID à 0	***
******************************************************************************************************/
CSommet::CSommet()
{
	uiSOMIdSommet = 0;
}

/**************************************************************************************************************
***	Cette fonction est le constructeur de recopie, il permet de recopier un sommet dans le sommet en cours	***
*** @param sommet le sommet à recopier dans le sommet en cours												***
**************************************************************************************************************/
CSommet::CSommet(const CSommet & sommet)
{
	uiSOMIdSommet = sommet.uiSOMIdSommet;
	for (CArc * arc : sommet.ARCSOMPartant)
		SOMAjouterArcPartant(arc->ARClireDestination());
	for (CArc * arc : sommet.ARCSOMArrivant)
		SOMAjouterArcArrivant(arc->ARClireDestination());
}

/******************************************************************************************************************************
***	Cette fonction est le destructeur par défaut d'un sommet, il supprime tous les éléments de la liste des vecteurs d'arcs	***
******************************************************************************************************************************/
CSommet::~CSommet()
{
	for (CArc * arc : ARCSOMPartant)
		delete arc;
	for (CArc * arc : ARCSOMArrivant)
		delete arc;
}

/******************************************************************************************************
***	Cette fonction permet d'ajouter un arc aux vecteurs contenant les arcs d'arrivées et de départs	***
*** @param uiSommet le numéro du sommet vers lequel l'arc part										***
******************************************************************************************************/
void CSommet::SOMAjouterArcPartant(unsigned int uiSommet)
{
	ARCSOMPartant.push_back(new CArc(uiSommet));
}

/******************************************************************************************************
***	Cette fonction permet d'ajouter un arc aux vecteurs contenant les arcs d'arrivées et de départs	***
*** @param uiSommet le numéro du sommet depuis lequel l'arc arrive									***
******************************************************************************************************/
void CSommet::SOMAjouterArcArrivant(unsigned int uiSommet)
{
	ARCSOMArrivant.push_back(new CArc(uiSommet));
}

/**************************************************************************************************************************
***	Cette fonction permet de modifier la destination d'un arc faisant parti de la liste des arc partants ou arrivants	***
*** @param uiDestination le numéro du sommet vers lequel l'arc part	ou arrive											***
*** @param uiNouvelleDestination le numéro de la nouvelle destination de l'arc											***
**************************************************************************************************************************/
void CSommet::SOMModifierArc(unsigned int uiDestination, unsigned int uiNouvelleDestination)
{
	for (CArc * pArc : ARCSOMPartant)
	{
		if (pArc->ARClireDestination() == uiDestination)
		{
			pArc->ARCmodifierDestination(uiNouvelleDestination);
			break;
		}
	}
	for (CArc * pArc : ARCSOMArrivant)
	{
		if (pArc->ARClireDestination() == uiDestination)
		{
			pArc->ARCmodifierDestination(uiNouvelleDestination);
			break;
		}
	}
}

/**********************************************************************************************************
***	Cette fonction permet de supprimer un arc de la liste des arcs arrivants ou partants				***
*** @param uiDestination le numéro du sommet vers lequel l'arc part										***
*** @param bOrientation désigne l'orientation de l'arc : vrai l'arc est arrivant/faux l'arc est partant ***
**********************************************************************************************************/
void CSommet::SOMSupprimerArc(unsigned int uiDestination, bool bOrientation)
{
	unsigned int uiPosition = 0;
	if (bOrientation)
	{
		for (CArc * pArc : ARCSOMArrivant)
		{
			if (pArc->ARClireDestination() == uiDestination)
			{
				ARCSOMArrivant.erase(ARCSOMArrivant.begin() + uiPosition);
				delete pArc;
				break;
			}
			uiPosition++;
		}
	}
	else
	{
		uiPosition = 0;
		for (CArc * pArc : ARCSOMPartant)
		{
			if (pArc->ARClireDestination() == uiDestination)
			{
				ARCSOMPartant.erase(ARCSOMPartant.begin() + uiPosition);
				delete pArc;
				break;
			}
			uiPosition++;
		}
	}
}

/******************************************************************
***	Cette fonction permet de récupérer l'ID du sommet en cours	***
******************************************************************/
unsigned int CSommet::SOMlireIDSommet()
{
	return uiSOMIdSommet;
}

/**********************************************************************
***	Cette fonction permet de récuperer la liste des arcs arrivants	***
**********************************************************************/
std::vector<CArc*> & CSommet::SOMlireArrivant()
{
	return ARCSOMArrivant;
}

/**********************************************************************
***	Cette fonction permet de récuperer la liste des arcs partants	***
**********************************************************************/
std::vector<CArc*> & CSommet::SOMlirePartant()
{
	return ARCSOMPartant;
}
