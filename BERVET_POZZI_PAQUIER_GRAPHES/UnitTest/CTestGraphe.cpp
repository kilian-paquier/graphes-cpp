#include "stdafx.h"
#include "CppUnitTest.h"
#include "../BERVET_POZZI_PAQUIER_GRAPHES/CSommet.h"
#include "../BERVET_POZZI_PAQUIER_GRAPHES/CGraphe.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CTestGraphe
{		
	TEST_CLASS(GrapheTest)
	{
	public:
		TEST_METHOD(testAjouterSommet)
		{
			CGraphe graphe;
			CSommet sommet1(1);
			CSommet sommet2(2);
			CSommet sommet3(3);
			graphe.GPHAjouterSommet(sommet1);
			graphe.GPHAjouterSommet(sommet2);
			graphe.GPHAjouterSommet(sommet3);
			Assert::AreEqual(3, graphe.GPHNbSommets());

			try
			{
				Assert::AreEqual(true, graphe.GPHRechercherSommet(1));
				Assert::AreEqual(true, graphe.GPHRechercherSommet(2));
				Assert::AreEqual(true, graphe.GPHRechercherSommet(3));
			}
			catch (const Cexception & e)
			{
				e.EXCPrintError();
			}
		}

		TEST_METHOD(testAjouterArcs)
		{
			CGraphe graphe;

			// Vérifié dans testAjouterSommets
			CSommet sommet1(1);
			CSommet sommet2(2);
			CSommet sommet3(3);
			graphe.GPHAjouterSommet(sommet1);
			graphe.GPHAjouterSommet(sommet2);
			graphe.GPHAjouterSommet(sommet3);


			try {
				graphe.GPHAjouterArc(1, 2);
				Assert::AreEqual(true, graphe.GPHRechercherArcPartant(1, 2));
				Assert::AreEqual(true, graphe.GPHRechercherArcArrivant(2, 1));

				graphe.GPHAjouterArc(2, 3);
				Assert::AreEqual(true, graphe.GPHRechercherArcPartant(2, 3));
				Assert::AreEqual(true, graphe.GPHRechercherArcArrivant(3, 2));

				graphe.GPHAjouterArc(3, 1);
				Assert::AreEqual(true, graphe.GPHRechercherArcPartant(3, 1));
				Assert::AreEqual(true, graphe.GPHRechercherArcArrivant(1, 3));
			}
			catch (const Cexception & e)
			{
				e.EXCPrintError();
			}
		}

		TEST_METHOD(testSupprimerSommet)
		{
			CGraphe graphe;

			// Vérifié dans testAjouterSommets
			CSommet sommet1(1);
			CSommet sommet2(2);
			CSommet sommet3(3);
			graphe.GPHAjouterSommet(sommet1);
			graphe.GPHAjouterSommet(sommet2);
			graphe.GPHAjouterSommet(sommet3);

			try {
				// Vérifié dans testAjouterArc
				graphe.GPHAjouterArc(1, 2);
				graphe.GPHAjouterArc(2, 3);
				graphe.GPHAjouterArc(3, 1);

				// OK
				graphe.GPHSupprimerSommet(1);
				Assert::AreEqual(2, graphe.GPHNbSommets());
				Assert::AreEqual(false, graphe.GPHRechercherSommet(1));
				Assert::AreEqual(false, graphe.GPHRechercherArcPartant(3, 1));
				Assert::AreEqual(false, graphe.GPHRechercherArcArrivant(2, 1));

				graphe.GPHSupprimerSommet(2);
				Assert::AreEqual(1, graphe.GPHNbSommets());
				Assert::AreEqual(false, graphe.GPHRechercherSommet(2));
				Assert::AreEqual(false, graphe.GPHRechercherArcArrivant(3, 2));

				graphe.GPHSupprimerSommet(3);
				Assert::AreEqual(0, graphe.GPHNbSommets());
				Assert::AreEqual(false, graphe.GPHRechercherSommet(3));
			}
			catch(const Cexception & e)
			{
				e.EXCPrintError();
			}
		}

		TEST_METHOD(testSupprimerArcs)
		{
			CGraphe graphe;

			// Vérifié dans testAjouterSommets
			CSommet sommet1(1);
			CSommet sommet2(2);
			CSommet sommet3(3);
			graphe.GPHAjouterSommet(sommet1);
			graphe.GPHAjouterSommet(sommet2);
			graphe.GPHAjouterSommet(sommet3);

			try {
				// Vérifié dans testAjouterArc
				graphe.GPHAjouterArc(1, 2);
				graphe.GPHAjouterArc(2, 3);
				graphe.GPHAjouterArc(3, 1);

				// A vérifier après testAjouterArcs
				graphe.GPHSupprimerArc(1, 2);
				Assert::AreEqual(false, graphe.GPHRechercherArcPartant(1, 2));
				Assert::AreEqual(false, graphe.GPHRechercherArcArrivant(2, 1));

				graphe.GPHSupprimerArc(2, 3);
				Assert::AreEqual(false, graphe.GPHRechercherArcPartant(2, 3));
				Assert::AreEqual(false, graphe.GPHRechercherArcArrivant(3, 2));

				graphe.GPHSupprimerArc(3, 1);
				Assert::AreEqual(false, graphe.GPHRechercherArcPartant(3, 1));
				Assert::AreEqual(false, graphe.GPHRechercherArcArrivant(1, 3));
			}
			catch(const Cexception & e)
			{
				e.EXCPrintError();
			}
		}

		TEST_METHOD(testModifierArcsPartants)
		{
			CGraphe graphe;

			// Vérifié dans testAjouterSommets
			CSommet sommet1(1);
			CSommet sommet2(2);
			CSommet sommet3(3);
			graphe.GPHAjouterSommet(sommet1);
			graphe.GPHAjouterSommet(sommet2);
			graphe.GPHAjouterSommet(sommet3);

			try {
				// Vérifié dans testAjouterArc
				graphe.GPHAjouterArc(1, 2);
				graphe.GPHAjouterArc(2, 3);
				graphe.GPHAjouterArc(3, 1);

				// A vérifier après testAjouterArcs
				graphe.GPHModifierArcPartant(1, 2, 3);
				Assert::AreEqual(true, graphe.GPHRechercherArcPartant(1, 3));
				Assert::AreEqual(true, graphe.GPHRechercherArcArrivant(3, 1));
				Assert::AreEqual(false, graphe.GPHRechercherArcPartant(1, 2));
				Assert::AreEqual(false, graphe.GPHRechercherArcArrivant(2, 1));

				graphe.GPHModifierArcPartant(2, 3, 1);
				Assert::AreEqual(true, graphe.GPHRechercherArcPartant(2, 1));
				Assert::AreEqual(true, graphe.GPHRechercherArcArrivant(1, 2));
				Assert::AreEqual(false, graphe.GPHRechercherArcPartant(2, 3));
				Assert::AreEqual(false, graphe.GPHRechercherArcArrivant(3, 2));

				graphe.GPHModifierArcPartant(3, 1, 2);
				Assert::AreEqual(true, graphe.GPHRechercherArcPartant(3, 2));
				Assert::AreEqual(true, graphe.GPHRechercherArcArrivant(2, 3));
				Assert::AreEqual(false, graphe.GPHRechercherArcPartant(3, 1));
				Assert::AreEqual(false, graphe.GPHRechercherArcArrivant(1, 3));
			} 
			catch(const Cexception & e)
			{
				e.EXCPrintError();
			}
		}

		TEST_METHOD(testModifierArcsArrivants)
		{
			CGraphe graphe;

			// Vérifié dans testAjouterSommets
			CSommet sommet1(1);
			CSommet sommet2(2);
			CSommet sommet3(3);
			graphe.GPHAjouterSommet(sommet1);
			graphe.GPHAjouterSommet(sommet2);
			graphe.GPHAjouterSommet(sommet3);

			try {
				// Vérifié dans testAjouterArc
				graphe.GPHAjouterArc(1, 2);
				graphe.GPHAjouterArc(2, 3);
				graphe.GPHAjouterArc(3, 1);

				// A vérifier après testAjouterArcs
				graphe.GPHModifierArcArrivant(1, 2, 3);
				Assert::AreEqual(true, graphe.GPHRechercherArcPartant(3, 2));
				Assert::AreEqual(true, graphe.GPHRechercherArcArrivant(2, 3));
				Assert::AreEqual(false, graphe.GPHRechercherArcPartant(1, 2));
				Assert::AreEqual(false, graphe.GPHRechercherArcArrivant(2, 1));

				graphe.GPHModifierArcArrivant(2, 3, 1);
				Assert::AreEqual(true, graphe.GPHRechercherArcPartant(1, 3));
				Assert::AreEqual(true, graphe.GPHRechercherArcArrivant(3, 1));
				Assert::AreEqual(false, graphe.GPHRechercherArcPartant(2, 3));
				Assert::AreEqual(false, graphe.GPHRechercherArcArrivant(3, 2));
			}
			catch (Cexception & e)
			{
				e.EXCPrintError();
			}
		}
	};
}
