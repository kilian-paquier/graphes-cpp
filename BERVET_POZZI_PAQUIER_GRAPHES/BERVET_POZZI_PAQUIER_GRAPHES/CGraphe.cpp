#include "stdafx.h"
#include "CGraphe.h"
#include "vld.h"

/**************************************************************************************************
***	Cette fonction est le constructeur de recopie qui prend en paramètre une liste de sommets	***
*** @param sommets la liste de sommets (sous forme vector) à recopie dans le graphe				***
**************************************************************************************************/
CGraphe::CGraphe(std::vector<CSommet> & sommets)
{
	for (CSommet & sommet : sommets)
		GPHAjouterSommet(sommet);
}

/******************************************************************************************
***	Cette fonction est le constructeur par défaut d'un graphe, celui-ci ne fait rien	***
******************************************************************************************/
CGraphe::CGraphe()
{
}

/******************************************************************************************
***	Cette fonction est le constructeur par défaut d'un graphe, celui-ci ne fait rien	***
******************************************************************************************/
CGraphe::CGraphe(CGraphe & graphe)
{
	for (CSommet & sommet : graphe.GPHlireSommets())
		GPHAjouterSommet(sommet);
}

/**********************************************************************************************************************
***	Cette fonction est le destructeur par défaut d'un graphe, celui-ci vide la liste des sommets et libère les arcs	***
**********************************************************************************************************************/
CGraphe::~CGraphe()
{
	for (CSommet & sommet : SOMGPHSommets)
	{
		for (CArc * pArc : sommet.SOMlireArrivant())
			delete pArc;
		for (CArc * pArc : sommet.SOMlirePartant())
			delete pArc;
		sommet.SOMlireArrivant().clear();
		sommet.SOMlirePartant().clear();
	}
	SOMGPHSommets.clear();
}

/**********************************************************************************
***	Cette fonction permet d'ajouter un sommet à la liste des sommets du graphe	***
*** @param SOMsommet le sommet à ajouter à la liste de sommets					***
**********************************************************************************/
void CGraphe::GPHAjouterSommet(CSommet & SOMsommet)
{
	SOMGPHSommets.push_back(SOMsommet);
}

/**************************************************************
***	Cette fonction permet de supprimer un sommet du graphe	***
*** @param uiID l'id du sommet à supprimer					***
**************************************************************/
void CGraphe::GPHSupprimerSommet(unsigned int uiID)
{
	if (!GPHRechercherSommet(uiID))
		throw Cexception(SOMMET_NOT_FOUND, (char*) "Le sommet n'existe pas");
	unsigned int uiIndex = 0;
	for (CSommet & sommet : SOMGPHSommets) {
		if (sommet.SOMlireIDSommet() != uiID)
		{
			GPHSupprimerArc(uiID, sommet.SOMlireIDSommet());
			GPHSupprimerArc(sommet.SOMlireIDSommet(), uiID);
		}
	}
	for (CSommet & sommet : SOMGPHSommets)
	{
		if (sommet.SOMlireIDSommet() == uiID)
		{
			for (CArc * pArc : sommet.SOMlirePartant())
				delete pArc;
			for (CArc * pArc : sommet.SOMlireArrivant())
				delete pArc;
			sommet.SOMlireArrivant().clear();
			sommet.SOMlirePartant().clear();
			SOMGPHSommets.erase(SOMGPHSommets.begin() + uiIndex);
			break;
		}
		uiIndex++;
	}
}


/**************************************************************
***	Cette fonction permet d'ajouter un arc au graphe		***
*** @param uiPartant l'id du sommet duquel part l'arc		***
*** @param uiArrivant l'id du sommet auquel va l'arc		***
**************************************************************/
void CGraphe::GPHAjouterArc(unsigned int uiPartant, unsigned int uiArrivant)
{
	if (!GPHRechercherSommet(uiPartant) || !GPHRechercherSommet(uiArrivant))
		throw Cexception(SOMMET_NOT_FOUND, (char*) "Un des sommets n'existe pas");
	for (CSommet & sommet : SOMGPHSommets)
	{
		if (sommet.SOMlireIDSommet() == uiPartant) 
			sommet.SOMAjouterArcPartant(uiArrivant);
		if (sommet.SOMlireIDSommet() == uiArrivant)
			sommet.SOMAjouterArcArrivant(uiPartant);
	}
}


/**************************************************************************
***	Cette fonction permet de modifier un arc du graphe					***
*** @param uiIDSommetPartant l'id du sommet depuis lequel l'arc part	***
*** @param uiIDSommetArrivant l'id du sommet vers lequel l'arc va		***
*** @param uiIDNouveauSommet l'id du nouveau sommet						***
**************************************************************************/
void CGraphe::GPHModifierArcPartant(unsigned int uiIDSommetPartant, unsigned int uiIDSommetArrivant, unsigned int uiIDNouveauSommet)
{
	if (!GPHRechercherArcPartant(uiIDSommetPartant, uiIDSommetArrivant))
		throw Cexception(ARC_NOT_FOUND, (char*) "Arc innexistant");
	if (!GPHRechercherSommet(uiIDNouveauSommet))
		throw Cexception(SOMMET_NOT_FOUND, (char*) "Le sommet n'existe pas");
	for (CSommet & sommet : SOMGPHSommets)
	{
		if (sommet.SOMlireIDSommet() == uiIDSommetPartant)
			sommet.SOMModifierArc(uiIDSommetArrivant, uiIDNouveauSommet);
		if (sommet.SOMlireIDSommet() == uiIDSommetArrivant)
			sommet.SOMSupprimerArc(uiIDSommetPartant, true);
		if (sommet.SOMlireIDSommet() == uiIDNouveauSommet)
			sommet.SOMAjouterArcArrivant(uiIDSommetPartant);	
	}
}


/**************************************************************************
***	Cette fonction permet de modifier un arc du graphe					***
*** @param uiIDSommetPartant l'id du sommet depuis lequel l'arc part	***
*** @param uiIDSommetArrivant l'id du sommet vers lequel l'arc va		***
*** @param uiIDNouveauSommet l'id du nouveau sommet						***
**************************************************************************/
void CGraphe::GPHModifierArcArrivant(unsigned int uiIDSommetPartant, unsigned int uiIDSommetArrivant, unsigned int uiIDNouveauSommet)
{
	if (!GPHRechercherArcArrivant(uiIDSommetArrivant, uiIDSommetPartant))
		throw Cexception(ARC_NOT_FOUND, (char*) "Arc innexistant");
	if (!GPHRechercherSommet(uiIDNouveauSommet))
		throw Cexception(SOMMET_NOT_FOUND, (char*) "Le sommet n'existe pas");
	for (CSommet & sommet : SOMGPHSommets)
	{
		if (sommet.SOMlireIDSommet() == uiIDSommetArrivant)
			sommet.SOMModifierArc(uiIDSommetPartant, uiIDNouveauSommet);
		if (sommet.SOMlireIDSommet() == uiIDSommetPartant)
			sommet.SOMSupprimerArc(uiIDSommetArrivant, false);
		if (sommet.SOMlireIDSommet() == uiIDNouveauSommet)
			sommet.SOMAjouterArcPartant(uiIDSommetArrivant);
	}
}


/**********************************************************************
***	Cette fonction permet de supprimer un arc du graphe				***
*** @param uiIDsommetUn l'id du sommet depuis lequel l'arc part		***
*** @param uiIDsommetDeux l'id du sommet vers lequel l'arc va		***
**********************************************************************/
void CGraphe::GPHSupprimerArc(unsigned int uiIDsommetUn, unsigned int uiIDsommetDeux)
{
	if (!GPHRechercherArcPartant(uiIDsommetUn, uiIDsommetDeux))
		throw Cexception(501, (char*) "L'arc n'existe pas");
	for (CSommet & sommet : SOMGPHSommets)
	{
		if (sommet.SOMlireIDSommet() == uiIDsommetUn)
			sommet.SOMSupprimerArc(uiIDsommetDeux, false);
		if (sommet.SOMlireIDSommet() == uiIDsommetDeux)
			sommet.SOMSupprimerArc(uiIDsommetUn, true);
	}
}


/******************************************************
***	Cette fonction permet d'afficher le graphe		***
******************************************************/
void CGraphe::GPHAfficher()
{
	/*cout << "Liste des sommets du graphes : " << endl;
	for (CSommet & sommet : SOMGPHSommets)
	{
		cout << "Liste des arcs arrivants vers le sommet " << sommet.SOMlireIDSommet() << endl;
		for (CArc * pArc : sommet.SOMlireArrivant())
			cout << pArc->ARClireDestination() << " ";
		cout << endl;
		cout << "Liste des arcs partants du sommet " << sommet.SOMlireIDSommet() << endl;
		for (CArc * pArc : sommet.SOMlirePartant())
			cout << pArc->ARClireDestination() << " ";
		cout << endl;
	}*/

	cout << "Sommets" << "	" << "Arcs partants" << "	" << "Arcs arrivants" << endl;
	for (CSommet & sommet : SOMGPHSommets)
	{
		cout << sommet.SOMlireIDSommet() << "	";
		for (CArc * pArc : sommet.SOMlirePartant())
			cout << pArc->ARClireDestination() << "; ";
		cout << "		";
		for (CArc * pArc : sommet.SOMlireArrivant())
			cout << pArc->ARClireDestination() << "; ";
		cout << endl;
	}
	cout << endl;
	
}


/**************************************************************************
***	Cette fonction permet de recupérer la liste des sommets du graphe	***
**************************************************************************/
std::vector<CSommet> & CGraphe::GPHlireSommets()
{
	return SOMGPHSommets;
}


/**************************************************************************
***	Cette fonction permet de recupérer le nombre de sommets du graphe	***
**************************************************************************/
int CGraphe::GPHNbSommets()
{
	int count = 0;
	for (CSommet & sommet : SOMGPHSommets)
		count++;
	return count;
}


/******************************************************************************
***	Cette fonction permet de rechercher un sommet dans la liste des sommets	***
*** @param uiIDSommet l'id du sommet à rechercher							***
*** @return vrai si le sommet a été trouvé, faux sinon						***
******************************************************************************/
bool CGraphe::GPHRechercherSommet(unsigned int uiIDSommet)
{
	for (CSommet & sommet : SOMGPHSommets)
	{
		if (sommet.SOMlireIDSommet() == uiIDSommet)
			return true;
	}
	return false;
}


/******************************************************************************************
***	Cette fonction permet de rechercher un arc de la liste des arcs partants			***
*** @param uiDestination l'id du sommet vers lequel va l'arc ou depuis lequel il part	***
*** @param uiIDSommet le numéro du sommet dans lequel chercher l'arc					***
*** @return vrai si l'arc a été trouvé, faux sinon										***
******************************************************************************************/
bool CGraphe::GPHRechercherArcPartant(unsigned int uiIDSommet, unsigned int uiDestination)
{
	for (CSommet & sommet : SOMGPHSommets)
	{
		if (sommet.SOMlireIDSommet() == uiIDSommet)
		{
			for (CArc * arc : sommet.SOMlirePartant())
			{
				if (arc->ARClireDestination() == uiDestination)
					return true;
			}
		}
	}
	return false;
}

/******************************************************************************************
***	Cette fonction permet de rechercher un arc de la liste des arcs arrivants			***
*** @param uiDestination l'id du sommet vers lequel va l'arc ou depuis lequel il part	***
*** @param uiIDSommet le numéro du sommet dans lequel chercher l'arc					***
*** @return vrai si l'arc a été trouvé, faux sinon										***
******************************************************************************************/
bool CGraphe::GPHRechercherArcArrivant(unsigned int uiIDSommet, unsigned int uiDestination)
{
	for (CSommet & sommet : SOMGPHSommets)
	{
		if (sommet.SOMlireIDSommet() == uiIDSommet)
		{
			for (CArc * arc : sommet.SOMlireArrivant())
			{
				if (arc->ARClireDestination() == uiDestination)
					return true;
			}
		}
	}
	return false;
}


/**********************************************************
***	Cette fonction d'inverser tous les sens des arcs	***
**********************************************************/
void CGraphe::GPHInverserLesSens()
{
	for (CSommet & sommet : SOMGPHSommets)
	{
		vector<CArc*> temp = sommet.SOMlireArrivant();
		vector<CArc*> temp2 = sommet.SOMlirePartant();
		sommet.SOMlireArrivant().clear();
		sommet.SOMlirePartant().clear();
		for (CArc * pArc : temp)
		{
			sommet.SOMAjouterArcPartant(pArc->ARClireDestination());
			delete pArc;
		}
		for (CArc * pArc : temp2) {
			sommet.SOMAjouterArcArrivant(pArc->ARClireDestination());
			delete pArc;
		}
	}
}

CSommet& CGraphe::GPHRetournerSommet(unsigned uID)
{
	for (CSommet & sommet : SOMGPHSommets)
	{
		if (sommet.SOMlireIDSommet() == uID)
			return sommet;
	}
}

CGraphe& CGraphe::GPHExtract(unsigned uID, unsigned uTaille)
{
	CSommet sommet = GPHRechercherSommet(uID);
	CGraphe * graphe = new CGraphe();

	graphe->GPHAjouterSommet(GPHRetournerSommet(uID));
	while (uTaille > 0)
	{
		for (CArc * arc : GPHRetournerSommet(uID).SOMlirePartant())
		{
			graphe->GPHAjouterSommet(GPHRetournerSommet(arc->ARClireDestination()));
		}
		uTaille -= 1;
		uID = graphe->SOMGPHSommets.at(graphe->SOMGPHSommets.size() - 1).SOMlireIDSommet();
	}

	graphe->GPHViderArcsInexistants();
	return *graphe;
}

void CGraphe::GPHViderArcsInexistants()
{
	for (CSommet & sommet : SOMGPHSommets)
	{
		for (CArc * arc : sommet.SOMlireArrivant())
		{
			if (GPHRechercherSommet(arc->ARClireDestination()))
				continue;
			sommet.SOMSupprimerArc(arc->ARClireDestination(), true);
		}

		for (CArc * arc : sommet.SOMlirePartant())
		{
			if (GPHRechercherSommet(arc->ARClireDestination()))
				continue;
			sommet.SOMSupprimerArc(arc->ARClireDestination(), false);
		}
	}
}
