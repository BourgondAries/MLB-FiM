#include <SFML/Graphics.hpp>

class Recipe {
		char selection = (char)0;
		bool enterN = false, hasPer = false;
		//Constants:
		const double posDeviation = 140.;
		//Input variables (6):
		//Output variables (many):
		//Sugar
		double
		monosaccharideMol, monosaccharideMass, monosaccharideVolume,
		disaccharideMol, disaccharideMass, disaccharideVolume,
							totalSugarMass, totalSugarVolume,
		//Carbon dioxide
		carbondioxideMol, carbondioxideMass, carbondioxideVolume,
		//Ethanol
		ethanolMol, ethanolMass, ethanolVolume,
		//Water
		waterMol, waterMass, waterVolume,
		//Miscellaneous
		volumeToAdd, juiceSugarPerLitreEquivalent, disaccharideToAdd, enthalpyCo, watt, EABV,
		cost, EPL, YTA;
		///Equivalent of the above, but now the strings to display.
		//Input variables (6):
		sf::Text totalVolume_, totalDiSugarPerLitre_, juiceVolume_, juiceMonoSugarPerLitre_, juiceDiSugarPerLitre_, timeSpan_,
		//Output variables (many):
		//Sugar
		monosaccharideMol_, disaccharideMol_,
		totalSugarMass_, totalSugarsVolume_,
		//Carbon dioxide
		carbondioxideMol_, carbondioxideMass_, carbondioxideVolume_,
		//Ethanol
		ethanolMol_, ethanolMass_, ethanolVolume_,
		//Water
		waterMol_, waterMass_, waterVolume_,
		//Miscellaneous
		volumeToAdd_, juiceSugarPerLitreEquivalent_, disaccharideToAdd_, enthalpyCo_, watt_, EABV_,
		cost_, EPL_, YTA_;
		///The pre-set strings, for refreshing purposes, equivalent to above.
		std::string totalVolume_0 = "Total Volume: ", totalDiSugarPerLitre_0 = "Desired DPL: ", juiceVolume_0 = "Juice Volume: ", juiceMonoSugarPerLitre_0 = " - MPL: ", juiceDiSugarPerLitre_0 = " - DPL: ", timeSpan_0 = "Timespan: ",
		//Output variables (many):
		//Sugar
		monosaccharideMol_0 = "Monosaccharides: ", disaccharideMol_0 = "Disaccharides: ",
		totalSugars_0 = "Sugars: -",
		//Carbon dioxide
		carbondioxide_0 = "Carbondioxide: ",
		//Ethanol
		ethanol_0 = "Ethanol: ",
		//Water
		water_0 = "Water: ",
		//Miscellaneous
		volumeToAdd_0 = "Volume to Add: ", juiceSugarPerLitreEquivalent_0 = "JD Equivalent: ", disaccharideToAdd_0 = "Sucrose to Add: ", enthalpyCo_0 = "Energy Lost: ", watt_0 = "Watt: ", EABV_0 = "EABV: ",
		cost_0 = "Cost: ";

		sf::Text input, mol, mass, volume, misc, info;

		sf::Image backGround1, banner1;
		sf::Texture backGround1t, banner1t;
		sf::Sprite backGround1s, banner1s;

public:

	Recipe();
	void compute();
	int recipe();
	double molarMass(int H, int C, int O);
};
