#include "stdafx.h"
#include "CArc.h"

/**********************************************************************************************************
***	Cette fonction est le constructeur de confort d'un arc prenant en paramètre un id de destination	***
*** @param uiID l'id de destination à copier dans l'arc													***
**********************************************************************************************************/
CArc::CArc(unsigned int uiID)
{
	uiARCIdDestination = uiID;
}

/**************************************************************
***	Cette fonction est le constructeur par défaut d'un arc	***
**************************************************************/
CArc::CArc()
{
}

/**************************************************************
***	Cette fonction est le destructeur par défaut d'un arc	***
**************************************************************/
CArc::~CArc()
{
}

/**************************************************************************
***	Cette fonction permet de retourner la destination de l'arc en cours	***
**************************************************************************/
unsigned int & CArc::ARClireDestination()
{
	return uiARCIdDestination;
}


/**************************************************************************
***	Cette fonction permet de modifier le sommet de destination de l'arc	***
**** @param uiDestination le nouvel id du sommet de destination			***
**************************************************************************/
void CArc::ARCmodifierDestination(unsigned int uiDestination)
{
	uiARCIdDestination = uiDestination;
}
