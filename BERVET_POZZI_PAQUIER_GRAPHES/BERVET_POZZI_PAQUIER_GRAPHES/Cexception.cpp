#include "stdafx.h"
#include "Cexception.h"

/****************************
***Constructeur par defaut***
*****************************
***E:neant***
***Necessite:neant***
***S:neant***
***Entraine:(L'objet est initialise a ses valeurs par defaut)***
*****************************/
Cexception::Cexception() : uiEXCIndexErreur(0), sEXCMessage(NULL)
{

}

/****************************
***Constructeur de recopie***
*****************************
***E:EXCexcep un objet Cexception***
***Necessite:l'objet en argument est initialisé***
***S:neant***
***Entraine:(L'objet est initialise aux valeurs de l'argument)***
*****************************/
Cexception::Cexception(const Cexception &EXCexcep)
{
	uiEXCIndexErreur = EXCexcep.EXCgetIndex();
	sEXCMessage = EXCexcep.EXCgetMessage();
}

/*****************************
***Constructeur de confort a 1 argument***
*****************************
***E:uiIndex l'index de l'erreur***
***Necessite:neant***
***S:neant***
***Entraine:(L'objet est initialise a la valeur de l'erreur)***
*****************************/
Cexception::Cexception(unsigned int uiIndex)
{
	uiEXCIndexErreur = uiIndex;
	sEXCMessage = NULL;
}

/*****************************
***Constructeur de confort a 2 argument***
*****************************
***E:uiIndex l'index de l'erreur, sMessage le message de l'erreur***
***Necessite:neant***
***S:neant***
***Entraine:(L'objet est initialise a la valeur de l'erreur)***
*****************************/
Cexception::Cexception(unsigned int uiIndex, char* sMessage)
{
	uiEXCIndexErreur = uiIndex;
	sEXCMessage = sMessage;
}

/*****************************
***Destructeur par defaut***
*****************************
***E:neant***
***Necessite:neant***
***S:neant***
***Entraine:(L'objet est est detruit)***
*****************************/
Cexception::~Cexception()
{

}

/*****************************
***Affichage de l'erreur***
*****************************
***E:neant***
***Necessite:neant***
***S:neant***
***Entraine:(L'erreur est affiche)***
*****************************/
void Cexception::EXCPrintError() const
{
	cout << "Erreur num " << uiEXCIndexErreur << " : " << sEXCMessage << endl;
}