// BERVET_POZZI_PAQUIER_GRAPHES.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "CParseur.h"
#include "vld.h"


int main(int argc, char * argv[])
{
	//Vérification de fichier 
	if (argc == 1) {
		cout << "Pas de fichier Graphe" << endl; 
	}
	else
	{
		try {
			CParseur parseur(argv[1]);

			//Création de Graphe à partir du fichier argv
			CGraphe graphe(parseur.PARLireGraph());
			graphe.GPHAfficher();
			std::cout << "Inversion de Graphe ..." << std::endl;

			//Recopie du graphe
			CGraphe inverseGraphe(graphe);
			inverseGraphe.GPHInverserLesSens();
			inverseGraphe.GPHAfficher();

			CGraphe & graphe2 = graphe.GPHExtract(2, 2);
			graphe2.GPHAfficher();

			CGraphe inverse(graphe2);
			inverse.GPHInverserLesSens();
			inverse.GPHAfficher();

			delete & graphe2;
		}
		catch (const Cexception & e) {
			e.EXCPrintError();
		}
		system("pause");
	}

    return 0;
}

