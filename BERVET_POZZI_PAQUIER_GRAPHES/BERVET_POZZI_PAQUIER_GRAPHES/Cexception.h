#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#include<iostream>

using namespace std;

/*Cexception

*/

class Cexception
{
//Attributs
private:
	//Naturel désignant le type de l'erreur
	unsigned int uiEXCIndexErreur;
	//Message facultatif pour l'utilisateur specifiant l'erreur
	char* sEXCMessage;

//Constructeurs et destructeurs
public:
	/*****************************
	 ***Constructeur par defaut***
	 *****************************
	 ***E:neant***
	 ***Necessite:neant***
	 ***S:neant***
	 ***Entraine:(L'objet est initialise a ses valeurs par defaut)***
	 *****************************/
	Cexception();

	/****************************
	***Constructeur de recopie***
	*****************************
	***E:EXCexcep un objet Cexception***
	***Necessite:l'objet en argument est initialisé***
	***S:neant***
	***Entraine:(L'objet est initialise aux valeurs de l'argument)***
	*****************************/
	Cexception(const Cexception &EXCexcep);

	/*****************************
	***Constructeur de confort a 1 argument***
	*****************************
	***E:uiIndex l'index de l'erreur***
	***Necessite:neant***
	***S:neant***
	***Entraine:(L'objet est initialise a la valeur de l'erreur)***
	*****************************/
	Cexception(unsigned int uiIndex);

	/*****************************
	***Constructeur de confort a 2 argument***
	*****************************
	***E:uiIndex l'index de l'erreur, sMessage le message de l'erreur***
	***Necessite:neant***
	***S:neant***
	***Entraine:(L'objet est initialise a la valeur de l'erreur)***
	*****************************/
	Cexception(unsigned int uiIndex, char* sMessage);

	/*****************************
	***Destructeur par defaut***
	*****************************
	***E:neant***
	***Necessite:neant***
	***S:neant***
	***Entraine:(L'objet est est detruit)***
	*****************************/
	~Cexception();

//Méthodes
public:
	/*****************************
	***Accesseur en ecriture de l'index de l'erreur***
	*****************************
	***E:uiIndex l'index de l'erreur***
	***Necessite:neant***
	***S:neant***
	***Entraine:(L'index de l'erreur est modifier a la valeur passer en argument)***
	*****************************/
	void EXCsetIndex(unsigned int uiIndex) { uiEXCIndexErreur = uiIndex; }

	/*****************************
	***Accesseur en lecture de l'index de l'erreur***
	*****************************
	***E:neant***
	***Necessite:neant***
	***S:l'index de l'erreur***
	***Entraine:(L'index de l'erreur est retourne)***
	*****************************/
	unsigned int EXCgetIndex() const { return uiEXCIndexErreur; }

	/*****************************
	***Accesseur en ecriture du message***
	*****************************
	***E:smsg le message de l'erreur***
	***Necessite:neant***
	***S:neant***
	***Entraine:(Le message de l'erreur est modifier a la valeur passer en argument)***
	*****************************/
	void EXCsetMessage(char* smsg) { sEXCMessage = smsg; }

	/*****************************
	***Accesseur en lecture du message***
	*****************************
	***E:neant***
	***Necessite:neant***
	***S:le message de l'erreur***
	***Entraine:(Le message de l'erreur est retourne)***
	*****************************/
	char* EXCgetMessage() const { return sEXCMessage; }

	/*****************************
	***Affichage de l'erreur***
	*****************************
	***E:neant***
	***Necessite:neant***
	***S:neant***
	***Entraine:(L'erreur est affiche)***
	*****************************/
	void EXCPrintError() const;
};

#endif
