#include <SFML/Graphics.hpp>
#include <string>
#include "globals.hpp"

sf::RectangleShape backGround;

void compute();
double molarMass(int,int,int);
std::string n2s(double);

void load();
void save();

extern double yeastPG, sucrosePG, juicePL, waterPL, yeastPL;
extern sf::Sprite screenS;
double carbondioxideM = molarMass(0,1,2), ethanolM = molarMass(6,2,1), waterM = molarMass(2,0,1),
            monosaccharideM = molarMass(12,6,6), disaccharideM = molarMass(22,12,11);
double monosaccharidegL, disaccharidegL, carbondioxidegL, ethanolgL, watergL;
extern std::string instream;
extern double enthalpyC;
double hydrogenM, carbonM, oxygenM;

double totalVolume, totalDiSugarPerLitre, juiceVolume, juiceMonoSugarPerLitre, juiceDiSugarPerLitre, timeSpan;

namespace
{
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
}
//Function definitions

double molarMass(int H, int C, int O)
{
    return (H * hydrogenM + C * carbonM + O * oxygenM);
}

void initializer()
{
    input.setString(std::string("Input - Litres & Grams")); mol.setString(std::string("Mol")); mass.setString(std::string("Mass")); volume.setString(std::string("Volume")); misc.setString(std::string("Misc.")); info.setString(std::string("\n\nPress 'esc' to return.\n\nTotal Volume: pre-fermenting volume\nDesired DPL: Desired Disaccharides (gram) per Litre\nJuice Volume: Volume of the added juice\n - MPL: Juice Monosaccharides Per Litre content\n - DPL: Juice Disaccharides Per Litre content\nTimeSpan: Fermentation Time\n\nJD Equivalent: Juice Disaccharide Equivalent Per Litre\nEABV: Expected Alcohol By Volume\nEPL: Ethanol (gram) Per Litre\nYTA: Yeast (gram) to add\n\nHold shift whilst changing time to change days.\nYou can type values."));

    input.setFont(font); mol.setFont(font); mass.setFont(font); volume.setFont(font); misc.setFont(font); info.setFont(font);
    totalVolume_.setFont(font); totalDiSugarPerLitre_.setFont(font); juiceVolume_.setFont(font); juiceMonoSugarPerLitre_.setFont(font); juiceDiSugarPerLitre_.setFont(font); timeSpan_.setFont(font);
    monosaccharideMol_.setFont(font); disaccharideMol_.setFont(font);
    totalSugarMass_.setFont(font); totalSugarsVolume_.setFont(font);
    carbondioxideMol_.setFont(font); carbondioxideMass_.setFont(font); carbondioxideVolume_.setFont(font);
    ethanolMol_.setFont(font); ethanolMass_.setFont(font); ethanolVolume_.setFont(font);
    waterMol_.setFont(font); waterMass_.setFont(font); waterVolume_.setFont(font);
    volumeToAdd_.setFont(font); juiceSugarPerLitreEquivalent_.setFont(font); disaccharideToAdd_.setFont(font); enthalpyCo_.setFont(font); watt_.setFont(font); EABV_.setFont(font),
    cost_.setFont(font); EPL_.setFont(font); YTA_.setFont(font);

    input.setCharacterSize(10); mol.setCharacterSize(10); mass.setCharacterSize(10); volume.setCharacterSize(10); misc.setCharacterSize(10); info.setCharacterSize(10);
    totalVolume_.setCharacterSize(10); totalDiSugarPerLitre_.setCharacterSize(10); juiceVolume_.setCharacterSize(10); juiceMonoSugarPerLitre_.setCharacterSize(10); juiceDiSugarPerLitre_.setCharacterSize(10); timeSpan_.setCharacterSize(10);
    monosaccharideMol_.setCharacterSize(10); disaccharideMol_.setCharacterSize(10);
    totalSugarMass_.setCharacterSize(10); totalSugarsVolume_.setCharacterSize(10);
    carbondioxideMol_.setCharacterSize(10); carbondioxideMass_.setCharacterSize(10); carbondioxideVolume_.setCharacterSize(10);
    ethanolMol_.setCharacterSize(10); ethanolMass_.setCharacterSize(10); ethanolVolume_.setCharacterSize(10);
    waterMol_.setCharacterSize(10); waterMass_.setCharacterSize(10); waterVolume_.setCharacterSize(10);
    volumeToAdd_.setCharacterSize(10); juiceSugarPerLitreEquivalent_.setCharacterSize(10); disaccharideToAdd_.setCharacterSize(10); enthalpyCo_.setCharacterSize(10); watt_.setCharacterSize(10); EABV_.setCharacterSize(10),
    cost_.setCharacterSize(10); EPL_.setCharacterSize(10); YTA_.setCharacterSize(10);

    input.setPosition(800 * (15. / 48.),0 + posDeviation);
    totalVolume_.setPosition(800 * (15. / 48.),10 + posDeviation); totalDiSugarPerLitre_.setPosition(800 * (15. / 48.),20 + posDeviation); juiceVolume_.setPosition(800 * (15. / 48.),30 + posDeviation); juiceMonoSugarPerLitre_.setPosition(800 * (15. / 48.),40 + posDeviation); juiceDiSugarPerLitre_.setPosition(800 * (15. / 48.),50 + posDeviation); timeSpan_.setPosition(800 * (15. / 48.),60 + posDeviation);

    mol.setPosition(800 / 2.,0 + posDeviation);
    monosaccharideMol_.setPosition(800 / 2,10 + posDeviation);
    disaccharideMol_.setPosition(800 / 2,20 + posDeviation);
    carbondioxideMol_.setPosition(800 / 2,30 + posDeviation);
    ethanolMol_.setPosition(800 / 2,40 + posDeviation);
    waterMol_.setPosition(800 / 2,50 + posDeviation);

    mass.setPosition(800 * (15. / 48.), 80 + posDeviation);
    totalSugarMass_.setPosition(800 * (15. / 48.), 90 + posDeviation);
    carbondioxideMass_.setPosition(800 * (15. / 48.), 100 + posDeviation);
    ethanolMass_.setPosition(800 * (15. / 48.), 110 + posDeviation);
    waterMass_.setPosition(800 * (15. / 48.), 120 + posDeviation);

    volume.setPosition(800 / 2, 80 + posDeviation);
    totalSugarsVolume_.setPosition(800 / 2, 90 + posDeviation);
    carbondioxideVolume_.setPosition(800 / 2, 100 + posDeviation);
    ethanolVolume_.setPosition(800 / 2, 110 + posDeviation);
    waterVolume_.setPosition(800 / 2, 120 + posDeviation);

    misc.setPosition(800 * (15. / 48.), 140 + posDeviation);
    volumeToAdd_.setPosition(800 * (15. / 48.), 150 + posDeviation);
    disaccharideToAdd_.setPosition(800 / 2, 150 + posDeviation);
    juiceSugarPerLitreEquivalent_.setPosition(800 * (15. / 48.), 160 + posDeviation);
    enthalpyCo_.setPosition(800 / 2, 160 + posDeviation);
    watt_.setPosition(800 * (15. / 48.), 170 + posDeviation);
    EABV_.setPosition(800 / 2, 170 + posDeviation);
    cost_.setPosition(800 * (15. / 48.), 180 + posDeviation);
    EPL_.setPosition(800 / 2., 180 + posDeviation);
    YTA_.setPosition(800 * (15. / 48.), 190 + posDeviation);
    info.setPosition(800 * (15. / 48.), 210 + posDeviation);

    totalVolume_.setColor(sf::Color::Yellow);
    totalDiSugarPerLitre_.setColor(sf::Color(127,127,127));
    juiceVolume_.setColor(sf::Color(127,127,127));
    juiceMonoSugarPerLitre_.setColor(sf::Color(127,127,127));
    juiceDiSugarPerLitre_.setColor(sf::Color(127,127,127));
    timeSpan_.setColor(sf::Color(127,127,127));

    backGround.setSize(sf::Vector2f(800 / 2., 600));
    backGround.setPosition(800 / 4., 0.);
    backGround.setFillColor(sf::Color(170,170,170,215));

    backGround1.loadFromFile("data/recipe0.png");
    backGround1t.loadFromImage(backGround1);
    backGround1s.setTexture(backGround1t);

    banner1.loadFromFile("data/recipe1.png");
    banner1t.loadFromImage(banner1);
    banner1s.setTexture(banner1t); banner1s.setPosition(800 / 4., 0.);

    compute();
}

void compute()
{
    //Misc. first because other functions may use them. Checked
    volumeToAdd = totalVolume - juiceVolume;
    volumeToAdd = (volumeToAdd>0.09 || volumeToAdd<-0.09)?volumeToAdd:0.0;
    juiceSugarPerLitreEquivalent = juiceDiSugarPerLitre + (juiceMonoSugarPerLitre / (2 * monosaccharideM)) * disaccharideM;
    disaccharideToAdd = totalVolume * totalDiSugarPerLitre - juiceVolume * juiceSugarPerLitreEquivalent;
    //Sugar calculation: Checked
    monosaccharideMol = (juiceMonoSugarPerLitre * juiceVolume) / monosaccharideM; monosaccharideMass = monosaccharideMol * monosaccharideM; monosaccharideVolume = monosaccharideMass / monosaccharidegL;
    disaccharideMol = (juiceDiSugarPerLitre * juiceVolume + disaccharideToAdd) / disaccharideM; disaccharideMass = disaccharideMol * disaccharideM; disaccharideVolume = disaccharideMass / disaccharidegL;
    totalSugarMass = monosaccharideMass + disaccharideMass; totalSugarVolume = monosaccharideVolume + disaccharideVolume;
    //Carbondioxide calculations: Checked
    carbondioxideMol = disaccharideMol * 4 + monosaccharideMol * 2; carbondioxideMass = carbondioxideMol * carbondioxideM; carbondioxideVolume = carbondioxideMass / carbondioxidegL;
    //Ethanol calculations: Checked
    ethanolMol = disaccharideMol * 4 + monosaccharideMol * 2; ethanolMass = ethanolMol * ethanolM; ethanolVolume = ethanolMass / ethanolgL;
    //Water calculations: Checked
    waterMol = -(juiceVolume * juiceDiSugarPerLitre + disaccharideToAdd) / disaccharideM; waterMass = waterMol * waterM; waterVolume = waterMass / watergL;

    //Other: Checked
    enthalpyCo = enthalpyC * disaccharideMol + (enthalpyC / 2.) * monosaccharideMol;
    watt = enthalpyCo / timeSpan;
    EABV = 100. * (ethanolVolume / (totalVolume - monosaccharideVolume - disaccharideVolume + waterVolume + ethanolVolume));
    YTA = totalVolume * yeastPL;
    cost = yeastPG * (YTA) + sucrosePG * disaccharideToAdd + juicePL * juiceVolume + waterPL * volumeToAdd;
    EPL = ethanolMass / (totalVolume - monosaccharideVolume - disaccharideVolume + waterVolume + ethanolVolume);

    ///Visual Update:
    totalVolume_.setString(totalVolume_0 + n2s(totalVolume));
    totalDiSugarPerLitre_.setString(totalDiSugarPerLitre_0 + n2s(totalDiSugarPerLitre));
    juiceVolume_.setString(juiceVolume_0 + n2s(juiceVolume));
    juiceMonoSugarPerLitre_.setString(juiceMonoSugarPerLitre_0 + n2s(juiceMonoSugarPerLitre));
    juiceDiSugarPerLitre_.setString(juiceDiSugarPerLitre_0 + n2s(juiceDiSugarPerLitre));
    unsigned int weeks = ((int)timeSpan) / 604800; unsigned int days = ((int)timeSpan - weeks * 604800) / 86400; unsigned int hours = ((int)timeSpan - weeks * 604800 - days * 86400) / 3600;
    timeSpan_.setString(timeSpan_0 + n2s(weeks) + std::string(" w ") + n2s(days) + std::string(" d ") + n2s(hours) + std::string(" h"));

    monosaccharideMol_.setString(monosaccharideMol_0 + n2s(monosaccharideMol));
    disaccharideMol_.setString(disaccharideMol_0 + n2s(disaccharideMol));
    carbondioxideMol_.setString(carbondioxide_0 + n2s(carbondioxideMol));
    ethanolMol_.setString(ethanol_0 + n2s(ethanolMol));
    waterMol_.setString(water_0 + n2s(waterMol));
    if (waterMol > 0.0)
    {
        waterMol_.setColor(sf::Color::Red); waterMass_.setColor(sf::Color::Red); waterVolume_.setColor(sf::Color::Red);
    }
    else
    {
        waterMol_.setColor(sf::Color::White); waterMass_.setColor(sf::Color::White); waterVolume_.setColor(sf::Color::White);
    }

    if (EABV > 100. || EABV < 0.)
        EABV_.setColor(sf::Color::Red);
    else
        EABV_.setColor(sf::Color::White);

    if (carbondioxideMol < 0.001)
    {
        carbondioxideMol_.setColor(sf::Color::Red); carbondioxideMass_.setColor(sf::Color::Red); carbondioxideVolume_.setColor(sf::Color::Red);
        ethanolMol_.setColor(sf::Color::Red); ethanolMass_.setColor(sf::Color::Red); ethanolVolume_.setColor(sf::Color::Red);
    }
    else
    {
        carbondioxideMol_.setColor(sf::Color::White); carbondioxideMass_.setColor(sf::Color::White); carbondioxideVolume_.setColor(sf::Color::White);
        ethanolMol_.setColor(sf::Color::White); ethanolMass_.setColor(sf::Color::White); ethanolVolume_.setColor(sf::Color::White);
    }

    if (enthalpyCo < 0.)
    {
        enthalpyCo_.setColor(sf::Color::Red); watt_.setColor(sf::Color::Red);
    }
    else
    {
        enthalpyCo_.setColor(sf::Color::White); watt_.setColor(sf::Color::White);
    }

    totalSugarMass_.setString(totalSugars_0 + n2s(totalSugarMass));
    carbondioxideMass_.setString(carbondioxide_0 + n2s(carbondioxideMass));
    ethanolMass_.setString(ethanol_0 + n2s(ethanolMass));
    waterMass_.setString(water_0 + n2s(waterMass));

    totalSugarsVolume_.setString(totalSugars_0 + n2s(totalSugarVolume));
    carbondioxideVolume_.setString(carbondioxide_0 + n2s(carbondioxideVolume));
    ethanolVolume_.setString(ethanol_0 + n2s(ethanolVolume));
    waterVolume_.setString(water_0 + n2s(waterVolume));

    volumeToAdd < 0.0 ? volumeToAdd_.setColor(sf::Color::Red):volumeToAdd_.setColor(sf::Color::White);
    volumeToAdd_.setString(volumeToAdd_0 + n2s(volumeToAdd));
    disaccharideToAdd < 0.0 ? disaccharideToAdd_.setColor(sf::Color::Red):disaccharideToAdd_.setColor(sf::Color::White);
    disaccharideToAdd_.setString(disaccharideToAdd_0 + n2s(disaccharideToAdd));
    juiceSugarPerLitreEquivalent_.setString(juiceSugarPerLitreEquivalent_0 + n2s(juiceSugarPerLitreEquivalent));
    enthalpyCo_.setString(enthalpyCo_0 + n2s(enthalpyCo) + std::string(" J"));
    watt_.setString(watt_0 + n2s(watt));
    EABV_.setString(EABV_0 + n2s(EABV) + std::string("%"));
    cost_.setString(cost_0 + n2s(cost));
    EPL_.setString(std::string("EPL: ") + n2s(EPL));
    YTA_.setString("YTA: " + n2s(YTA));
}

int recipe()
{
    begin:
    if (window.waitEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                    case sf::Keyboard::Up:
                        switch ((int)selection)
                        {
                            case 0:
                                selection = (char) 5;
                                totalVolume_.setColor(sf::Color(127,127,127));
                                timeSpan_.setColor(sf::Color::Yellow);
                                break;
                            case 1:
                                selection--;
                                totalDiSugarPerLitre_.setColor(sf::Color(127,127,127));
                                totalVolume_.setColor(sf::Color::Yellow);
                                break;
                            case 2:
                                selection--;
                                juiceVolume_.setColor(sf::Color(127,127,127));
                                totalDiSugarPerLitre_.setColor(sf::Color::Yellow);
                                break;
                            case 3:
                                selection--;
                                juiceMonoSugarPerLitre_.setColor(sf::Color(127,127,127));
                                juiceVolume_.setColor(sf::Color::Yellow);
                                break;
                            case 4:
                                selection--;
                                juiceDiSugarPerLitre_.setColor(sf::Color(127,127,127));
                                juiceMonoSugarPerLitre_.setColor(sf::Color::Yellow);
                                break;
                            case 5:
                                selection--;
                                timeSpan_.setColor(sf::Color(127,127,127));
                                juiceDiSugarPerLitre_.setColor(sf::Color::Yellow);
                                break;
                            default: selection = (char) 0; break;
                        }
                        compute();
                        if (enterN)
                            instream.clear();
                        enterN = false;
                        hasPer = false;
                        break;
                    case sf::Keyboard::Down:
                        switch ((int)selection)
                        {
                            case 0:
                                selection++;
                                totalVolume_.setColor(sf::Color(127,127,127));
                                totalDiSugarPerLitre_.setColor(sf::Color::Yellow);
                                break;
                            case 1:
                                selection++;
                                totalDiSugarPerLitre_.setColor(sf::Color(127,127,127));
                                juiceVolume_.setColor(sf::Color::Yellow);
                                break;
                            case 2:
                                selection++;
                                juiceVolume_.setColor(sf::Color(127,127,127));
                                juiceMonoSugarPerLitre_.setColor(sf::Color::Yellow);
                                break;
                            case 3:
                                selection++;
                                juiceMonoSugarPerLitre_.setColor(sf::Color(127,127,127));
                                juiceDiSugarPerLitre_.setColor(sf::Color::Yellow);
                                break;
                            case 4:
                                selection++;
                                juiceDiSugarPerLitre_.setColor(sf::Color(127,127,127));
                                timeSpan_.setColor(sf::Color::Yellow);
                                break;
                            case 5:
                                selection = (char) 0;
                                timeSpan_.setColor(sf::Color(127,127,127));
                                totalVolume_.setColor(sf::Color::Yellow);
                                break;
                            default: selection = (char) 0; break;
                        }
                        compute();
                        if (enterN)
                            instream.clear();
                        enterN = false;
                        hasPer = false;
                        break;
                    case sf::Keyboard::Left:
                        switch ((int)selection)
                        {
                            case 0:
                            if (totalVolume >= 0.11)
                                totalVolume -= 0.1;
                            else
                                totalVolume = 0.0;
                                break;
                            case 1:
                            if (totalDiSugarPerLitre >= 0.11)
                                totalDiSugarPerLitre -= 0.1;
                            else
                                totalDiSugarPerLitre = 0.0;
                                break;
                            case 2:
                            if (juiceVolume >= 0.11)
                                juiceVolume -= 0.1;
                            else
                                juiceVolume = 0.0;
                                break;
                            case 3:
                            if (juiceMonoSugarPerLitre >= 0.11)
                                juiceMonoSugarPerLitre -= 0.1;
                            else
                                juiceMonoSugarPerLitre = 0.0;
                                compute();
                                break;
                            case 4:
                            if (juiceDiSugarPerLitre >= 0.11)
                                juiceDiSugarPerLitre -= 0.1;
                            else
                                juiceDiSugarPerLitre = 0.0;
                                break;
                            case 5:
                                if (event.key.shift)
                                {
                                    if (timeSpan >= 86400.)
                                        timeSpan -= 86400;
                                }
                                else
                                {
                                    if (timeSpan > 0.0)
                                        timeSpan -= 3600.;
                                }
                                break;
                            default: selection = (char) 0; break;
                        }
                        if (enterN)
                            instream.clear();
                        enterN = false;
                        hasPer = false;
                        compute();
                        break;
                    case sf::Keyboard::Right:
                        switch ((int)selection)
                        {
                            case 0:
                                totalVolume += 0.1;
                                break;
                            case 1:
                                totalDiSugarPerLitre += 0.1;
                                break;
                            case 2:
                                juiceVolume += 0.1;
                                break;
                            case 3:
                                juiceMonoSugarPerLitre += 0.1;
                                break;
                            case 4:
                                juiceDiSugarPerLitre += 0.1;
                                break;
                            case 5:
                                if (event.key.shift)
                                    timeSpan += 86400;
                                else
                                    timeSpan += 3600.;
                                break;
                            default: selection = (char) 0; break;
                        }
                        if (enterN)
                            instream.clear();
                        enterN = false;
                        hasPer = false;
                        compute();
                        break;
                    case sf::Keyboard::Return:
                        compute();
                        if (enterN)
                            instream.clear();
                        enterN = false;
                        hasPer = false;
                        break;
                    case sf::Keyboard::Num0:
                    {

                        instream.push_back(event.key.code + (char) 22);
                        enterN = true;
                        if (hasPer)
                            switch ((int)selection)
                            {
                                case 0: totalVolume = std::atof(instream.c_str()); totalVolume_.setString(totalVolume_.getString() + "0"); break;
                                case 1: totalDiSugarPerLitre = std::atof(instream.c_str()); totalDiSugarPerLitre_.setString(totalDiSugarPerLitre_.getString() + "0"); break;
                                case 2: juiceVolume = std::atof(instream.c_str()); juiceVolume_.setString(juiceVolume_.getString() + "0"); break;
                                case 3: juiceMonoSugarPerLitre = std::atof(instream.c_str()); juiceMonoSugarPerLitre_.setString(juiceMonoSugarPerLitre_.getString() + "0"); break;
                                case 4: juiceDiSugarPerLitre = std::atof(instream.c_str()); juiceDiSugarPerLitre_.setString(juiceDiSugarPerLitre_.getString() + "0"); break;
                                default: break;
                            }
                        else
                        {
                            switch ((int)selection)
                            {
                                case 0: totalVolume = std::atof(instream.c_str()); break;
                                case 1: totalDiSugarPerLitre = std::atof(instream.c_str()); break;
                                case 2: juiceVolume = std::atof(instream.c_str()); break;
                                case 3: juiceMonoSugarPerLitre = std::atof(instream.c_str()); break;
                                case 4: juiceDiSugarPerLitre = std::atof(instream.c_str()); break;
                                default: break;
                            }
                            compute();
                        }
                    }
                        break;
                    case sf::Keyboard::Num1:
                    case sf::Keyboard::Num2:
                    case sf::Keyboard::Num3:
                    case sf::Keyboard::Num4:
                    case sf::Keyboard::Num5:
                    case sf::Keyboard::Num6:
                    case sf::Keyboard::Num7:
                    case sf::Keyboard::Num8:
                    case sf::Keyboard::Num9:
                    {

                        instream.push_back(event.key.code + (char) 22);
                        enterN = true;
                        switch ((int)selection)
                        {
                            case 0: totalVolume = std::atof(instream.c_str()); break;
                            case 1: totalDiSugarPerLitre = std::atof(instream.c_str()); break;
                            case 2: juiceVolume = std::atof(instream.c_str()); break;
                            case 3: juiceMonoSugarPerLitre = std::atof(instream.c_str()); break;
                            case 4: juiceDiSugarPerLitre = std::atof(instream.c_str()); break;
                            default: break;
                        }
                        compute();
                    }
                        break;
                    case sf::Keyboard::Period:
                    {
                        if (hasPer)
                            goto localExit;
                        instream.push_back((char) 46);
                        hasPer = true;
                        if (!enterN) // If there is a re-newal.
                        {
                            switch ((int)selection)
                            {
                                case 0: totalVolume = std::atof(instream.c_str()); break;
                                case 1: totalDiSugarPerLitre = std::atof(instream.c_str()); break;
                                case 2: juiceVolume = std::atof(instream.c_str()); break;
                                case 3: juiceMonoSugarPerLitre = std::atof(instream.c_str()); break;
                                case 4: juiceDiSugarPerLitre = std::atof(instream.c_str()); break;
                                default: break;
                            }
                            compute();
                            enterN = true;
                            switch ((int)selection)
                            {
                                case 0: totalVolume_.setString(totalVolume_0 + n2s(totalVolume) + std::string(".")); break;
                                case 1: totalDiSugarPerLitre_.setString(totalDiSugarPerLitre_0 + n2s(totalDiSugarPerLitre) + std::string(".")); break;
                                case 2: juiceVolume_.setString(juiceVolume_0 + n2s(juiceVolume) + std::string(".")); break;
                                case 3: juiceMonoSugarPerLitre_.setString(juiceMonoSugarPerLitre_0 + n2s(juiceMonoSugarPerLitre) + std::string(".")); break;
                                case 4: juiceDiSugarPerLitre_.setString(juiceDiSugarPerLitre_0 + n2s(juiceDiSugarPerLitre) + std::string(".")); break;
                                default: break;
                            }
                        }
                        else //When we are adding a "." to an already being-written number
                        {
                            switch ((int)selection)
                            {
                                case 0: totalVolume_.setString(totalVolume_0 + n2s(totalVolume) + std::string(".")); break;
                                case 1: totalDiSugarPerLitre_.setString(totalDiSugarPerLitre_0 + n2s(totalDiSugarPerLitre) + std::string(".")); break;
                                case 2: juiceVolume_.setString(juiceVolume_0 + n2s(juiceVolume) + std::string(".")); break;
                                case 3: juiceMonoSugarPerLitre_.setString(juiceMonoSugarPerLitre_0 + n2s(juiceMonoSugarPerLitre) + std::string(".")); break;
                                case 4: juiceDiSugarPerLitre_.setString(juiceDiSugarPerLitre_0 + n2s(juiceDiSugarPerLitre) + std::string(".")); break;
                                default: break;
                            }
                        }
                        localExit:;
                    }
                    break;
                    case sf::Keyboard::BackSpace:
                    {
                        instream.clear();
                        switch ((int)selection)
                        {
                            case 0: totalVolume = std::atof(instream.c_str()); break;
                            case 1: totalDiSugarPerLitre = std::atof(instream.c_str()); break;
                            case 2: juiceVolume = std::atof(instream.c_str()); break;
                            case 3: juiceMonoSugarPerLitre = std::atof(instream.c_str()); break;
                            case 4: juiceDiSugarPerLitre = std::atof(instream.c_str()); break;
                            default: break;
                        }
                        compute();
                        enterN = true;
                        hasPer = false;
                    }
                    break;
                    case sf::Keyboard::Escape:
                        if (enterN)
                            instream.clear();
                        return 0;
                        break;
                    case sf::Keyboard::L:
                        {
                            window.clear();

                            window.draw(backGround1s);
                            window.draw(backGround);
                            window.draw(banner1s);

                            window.draw(input);
                            window.draw(totalVolume_);
                            window.draw(totalDiSugarPerLitre_);
                            window.draw(juiceVolume_);
                            window.draw(juiceMonoSugarPerLitre_);
                            window.draw(juiceDiSugarPerLitre_);
                            window.draw(timeSpan_);

                            window.draw(mol);
                            window.draw(monosaccharideMol_);
                            window.draw(disaccharideMol_);
                            window.draw(carbondioxideMol_);
                            window.draw(ethanolMol_);
                            window.draw(waterMol_);

                            window.draw(mass);
                            window.draw(totalSugarMass_);
                            window.draw(carbondioxideMass_);
                            window.draw(ethanolMass_);
                            window.draw(waterMass_);

                            window.draw(volume);
                            window.draw(totalSugarsVolume_);
                            window.draw(carbondioxideVolume_);
                            window.draw(ethanolVolume_);
                            window.draw(waterVolume_);

                            window.draw(misc);
                            window.draw(volumeToAdd_);
                            window.draw(disaccharideToAdd_);
                            window.draw(juiceSugarPerLitreEquivalent_);
                            window.draw(enthalpyCo_);
                            window.draw(watt_);
                            window.draw(EABV_);
                            window.draw(cost_);
                            window.draw(EPL_);
                            window.draw(YTA_);

                            window.draw(info);

                            window.display();


                            sf::Image screen = window.capture();
                            sf::Texture screenT; screenT.loadFromImage(screen);
                            screenS.setTexture(screenT);
                            load();
                        }
                        break;
                    case sf::Keyboard::S:
                        {
                            window.clear();

                            window.draw(backGround1s);
                            window.draw(backGround);
                            window.draw(banner1s);

                            window.draw(input);
                            window.draw(totalVolume_);
                            window.draw(totalDiSugarPerLitre_);
                            window.draw(juiceVolume_);
                            window.draw(juiceMonoSugarPerLitre_);
                            window.draw(juiceDiSugarPerLitre_);
                            window.draw(timeSpan_);

                            window.draw(mol);
                            window.draw(monosaccharideMol_);
                            window.draw(disaccharideMol_);
                            window.draw(carbondioxideMol_);
                            window.draw(ethanolMol_);
                            window.draw(waterMol_);

                            window.draw(mass);
                            window.draw(totalSugarMass_);
                            window.draw(carbondioxideMass_);
                            window.draw(ethanolMass_);
                            window.draw(waterMass_);

                            window.draw(volume);
                            window.draw(totalSugarsVolume_);
                            window.draw(carbondioxideVolume_);
                            window.draw(ethanolVolume_);
                            window.draw(waterVolume_);

                            window.draw(misc);
                            window.draw(volumeToAdd_);
                            window.draw(disaccharideToAdd_);
                            window.draw(juiceSugarPerLitreEquivalent_);
                            window.draw(enthalpyCo_);
                            window.draw(watt_);
                            window.draw(EABV_);
                            window.draw(cost_);
                            window.draw(EPL_);
                            window.draw(YTA_);

                            window.draw(info);

                            window.display();


                            sf::Image screen = window.capture();
                            sf::Texture screenT; screenT.loadFromImage(screen);
                            screenS.setTexture(screenT);
                            save();
                        }
                        break;
                    default: break;
                }
                break;
            case sf::Event::Closed:
                return 1;
                break;
            default: break;
        }
    }
    window.clear();

    window.draw(backGround1s);
    window.draw(backGround);
    window.draw(banner1s);

    window.draw(input);
    window.draw(totalVolume_);
    window.draw(totalDiSugarPerLitre_);
    window.draw(juiceVolume_);
    window.draw(juiceMonoSugarPerLitre_);
    window.draw(juiceDiSugarPerLitre_);
    window.draw(timeSpan_);

    window.draw(mol);
    window.draw(monosaccharideMol_);
    window.draw(disaccharideMol_);
    window.draw(carbondioxideMol_);
    window.draw(ethanolMol_);
    window.draw(waterMol_);

    window.draw(mass);
    window.draw(totalSugarMass_);
    window.draw(carbondioxideMass_);
    window.draw(ethanolMass_);
    window.draw(waterMass_);

    window.draw(volume);
    window.draw(totalSugarsVolume_);
    window.draw(carbondioxideVolume_);
    window.draw(ethanolVolume_);
    window.draw(waterVolume_);

    window.draw(misc);
    window.draw(volumeToAdd_);
    window.draw(disaccharideToAdd_);
    window.draw(juiceSugarPerLitreEquivalent_);
    window.draw(enthalpyCo_);
    window.draw(watt_);
    window.draw(EABV_);
    window.draw(cost_);
    window.draw(EPL_);
    window.draw(YTA_);

    window.draw(info);

    window.display();
    goto begin;
    return 1;
}
