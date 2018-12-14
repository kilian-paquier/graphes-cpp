#ifndef C_ARC_H
#define C_ARC_H

class CArc
{
private:
	unsigned int uiARCIdDestination;

public:
	/**********************************************************************************************************
	***	Cette fonction est le constructeur de confort d'un arc prenant en paramètre un id de destination	***
	*** @param uiID l'id de destination à copier dans l'arc													***
	**********************************************************************************************************/
	CArc(unsigned int uiID);

	/**************************************************************
	***	Cette fonction est le constructeur par défaut d'un arc	***
	**************************************************************/
	CArc();

	/**************************************************************
	***	Cette fonction est le destructeur par défaut d'un arc	***
	**************************************************************/
	~CArc();

	/**************************************************************************
	***	Cette fonction permet de retourner la destination de l'arc en cours	***
	**************************************************************************/
	unsigned int & ARClireDestination();

	/**************************************************************************
	***	Cette fonction permet de modifier le sommet de destination de l'arc	***
	*** @param uiDestination le nouvel id du sommet de destination			***
	**************************************************************************/
	void ARCmodifierDestination(unsigned int uiDestination);
};
#endif
