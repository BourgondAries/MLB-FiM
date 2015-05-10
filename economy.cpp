#include <SFML/Graphics.hpp>
#include "globals.hpp"
#include <string>
#include <cstdio>

extern sf::RectangleShape backGround;
extern std::string instream;
double yeastPG, sucrosePG, juicePL, waterPL, yeastPL; //Needs to be exported to recipe for calculation.
extern double hydrogenM, carbonM, oxygenM;
extern double carbondioxideM, ethanolM, waterM,
            monosaccharideM, disaccharideM;
extern double monosaccharidegL, disaccharidegL, carbondioxidegL, ethanolgL, watergL;
std::string n2s(double);
double molarMass(int,int,int);
void compute();
double yeastP, sucroseP, juiceP, waterP,
        yeastMass, sucroseMass, juiceLitre, waterLitre;
extern sf::Sprite screenS;
void load();
void save();

double ethanolEoC, sucroseEoC;

double enthalpyC = 1000 * sucroseEoC - 1000 * ethanolEoC * 4;

namespace
{
    char selection = (char) 0;
    bool enterN = false, hasPer = false;
    const double posDeviation = 150;

    sf::Text
    input, price, amount,
    yeastP_, sucroseP_, juiceP_, waterP_,
    yeastMass_, sucroseMass_, juiceLitre_, waterLitre_, yeastPL_, atomicM_, hydrogenM_, carbonM_, oxygenM_,
    densities, monosaccharidegL_, disaccharidegL_, carbondioxidegL_, ethanolgL_, watergL_,
    enthalpyOfCombustion, ethanolEoC_, sucroseEoC_,
    informa;

    std::string
    yeast_0 = "Yeast: ", sucrose_0 = "Disaccharide: ", juice_0 = "Juice: ", water_0 = "Water: ", yeastPL_0 = "YPL: ";

    sf::Texture BGET, BET;
    sf::Sprite BGES, BES;
}

void compute2()
{
    yeastPG = yeastP / yeastMass;
    sucrosePG = sucroseP / sucroseMass;
    juicePL = juiceP / juiceLitre;
    waterPL = waterP / waterLitre;

    ///Visual update:
    yeastP_.setString(yeast_0 + n2s(yeastP));
    sucroseP_.setString(sucrose_0 + n2s(sucroseP));
    juiceP_.setString(juice_0 + n2s(juiceP));
    waterP_.setString(water_0 + n2s(waterP));

    yeastMass_.setString(yeast_0 + n2s(yeastMass) + std::string(" g"));
    sucroseMass_.setString(sucrose_0 + n2s(sucroseMass) + std::string(" g"));
    juiceLitre_.setString(juice_0 + n2s(juiceLitre) + std::string(" L"));
    waterLitre_.setString(water_0 + n2s(waterLitre) + std::string(" L"));

    yeastPL_.setString(yeastPL_0 + n2s(yeastPL));
    hydrogenM_.setString("Hydrogen: " + n2s(hydrogenM));
    carbonM_.setString("Carbon: " + n2s(carbonM));
    oxygenM_.setString("Oxygen: " + n2s(oxygenM));

    monosaccharidegL_.setString("Monosaccharide: " + n2s(monosaccharidegL));
    disaccharidegL_.setString("Disaccharide: " + n2s(disaccharidegL));
    carbondioxidegL_.setString("Carbondioxide: " + n2s(carbondioxidegL));
    ethanolgL_.setString("Ethanol: " + n2s(ethanolgL));
    watergL_.setString("Water: " + n2s(watergL));

    ethanolEoC_.setString("Ethanol: " + n2s(ethanolEoC));
    sucroseEoC_.setString("Disaccharide: " + n2s(sucroseEoC));
}

void initializeEconomy()
{
    input.setString(std::string("Input")); price.setString(std::string("price")); amount.setString(std::string("amount")); enthalpyOfCombustion.setString("Enthalpy of Combustion in kilo Joule per Mol");

    input.setFont(font); price.setFont(font); amount.setFont(font);
    yeastP_.setFont(font); sucroseP_.setFont(font); juiceP_.setFont(font); waterP_.setFont(font);
    yeastMass_.setFont(font); sucroseMass_.setFont(font); juiceLitre_.setFont(font); waterLitre_.setFont(font); yeastPL_.setFont(font); atomicM_.setFont(font); hydrogenM_.setFont(font); carbonM_.setFont(font); oxygenM_.setFont(font);
    densities.setFont(font); monosaccharidegL_.setFont(font); disaccharidegL_.setFont(font); carbondioxidegL_.setFont(font); ethanolgL_.setFont(font); watergL_.setFont(font);
    enthalpyOfCombustion.setFont(font); ethanolEoC_.setFont(font); sucroseEoC_.setFont(font);
    informa.setFont(font);

    input.setCharacterSize(10); price.setCharacterSize(10); amount.setCharacterSize(10);
    yeastP_.setCharacterSize(10); sucroseP_.setCharacterSize(10); juiceP_.setCharacterSize(10); waterP_.setCharacterSize(10);
    yeastMass_.setCharacterSize(10); sucroseMass_.setCharacterSize(10); juiceLitre_.setCharacterSize(10); waterLitre_.setCharacterSize(10); yeastPL_.setCharacterSize(10); atomicM_.setCharacterSize(10); hydrogenM_.setCharacterSize(10); carbonM_.setCharacterSize(10); oxygenM_.setCharacterSize(10);
    densities.setCharacterSize(10); monosaccharidegL_.setCharacterSize(10); disaccharidegL_.setCharacterSize(10); carbondioxidegL_.setCharacterSize(10); ethanolgL_.setCharacterSize(10); watergL_.setCharacterSize(10);
    enthalpyOfCombustion.setCharacterSize(10); ethanolEoC_.setCharacterSize(10); sucroseEoC_.setCharacterSize(10);
    informa.setCharacterSize(10);

    input.setPosition(800 * (15. / 48.), 0 + posDeviation); price.setPosition(800 * (15. / 48.), 10 + posDeviation); amount.setPosition(800 / 2., 10 + posDeviation);
    yeastP_.setPosition(800 * (15. / 48.), 20 + posDeviation); sucroseP_.setPosition(800 * (15. / 48.), 30 + posDeviation); juiceP_.setPosition(800 * (15. / 48.), 40 + posDeviation); waterP_.setPosition(800 * (15. / 48.), 50 + posDeviation); yeastPL_.setPosition(800 * (15. / 48.), 70 + posDeviation);
    yeastMass_.setPosition(800 / 2., 20 + posDeviation); sucroseMass_.setPosition(800 / 2., 30 + posDeviation); juiceLitre_.setPosition(800 / 2., 40 + posDeviation); waterLitre_.setPosition(800 / 2., 50 + posDeviation); atomicM_.setPosition(800 * (15. / 48.), 90 + posDeviation); hydrogenM_.setPosition(800 * (15. / 48.), 100 + posDeviation); carbonM_.setPosition(800 * (15. / 48.), 110 + posDeviation); oxygenM_.setPosition(800 * (15. / 48.), 120 + posDeviation);
    densities.setPosition(800 / 2., 70 + posDeviation); monosaccharidegL_.setPosition(800 / 2., 80 + posDeviation); disaccharidegL_.setPosition(800 / 2., 90 + posDeviation); carbondioxidegL_.setPosition(800 / 2., 100 + posDeviation); ethanolgL_.setPosition(800 / 2., 110 + posDeviation); watergL_.setPosition(800 / 2., 120 + posDeviation);
    enthalpyOfCombustion.setPosition(800 * (15. / 48.), 140 + posDeviation); ethanolEoC_.setPosition(800 * (15. / 48.), 150 + posDeviation); sucroseEoC_.setPosition(800 / 2., 150 + posDeviation);
    informa.setPosition(800 * (15. / 48.), 170 + posDeviation);

    yeastP_.setColor(sf::Color::Yellow); sucroseP_.setColor(sf::Color(127,127,127)); juiceP_.setColor(sf::Color(127,127,127)); waterP_.setColor(sf::Color(127,127,127));
    yeastMass_.setColor(sf::Color(127,127,127)); sucroseMass_.setColor(sf::Color(127,127,127)); juiceLitre_.setColor(sf::Color(127,127,127)); waterLitre_.setColor(sf::Color(127,127,127)); yeastPL_.setColor(sf::Color(127,127,127));
    hydrogenM_.setColor(sf::Color(127,127,127)); carbonM_.setColor(sf::Color(127,127,127)); oxygenM_.setColor(sf::Color(127,127,127));
    monosaccharidegL_.setColor(sf::Color(127,127,127)); disaccharidegL_.setColor(sf::Color(127,127,127)); carbondioxidegL_.setColor(sf::Color(127,127,127)); ethanolgL_.setColor(sf::Color(127,127,127)); watergL_.setColor(sf::Color(127,127,127));
    ethanolEoC_.setColor(sf::Color(127,127,127)); sucroseEoC_.setColor(sf::Color(127,127,127));

    compute2();

    atomicM_.setString("Atomic Mass");
    densities.setString("Density");
    informa.setString("The prices are for bulks in your desired currency.\nThese bulks then need to be specified as masses\nor volumes. By dividing the price by the bulk\ncontainments, we get a price per gram or litre\nvalue, which we apply to the recipe screen to\ngenerate a total cost of the specific recipe.\n\nYPL: Yeast (gram) per Litre\nDensity in gram per litre (raw material)\nAtomic mass in u (average for all isotopes)\n\nThe enthalpy of combustion is included to reveal\nthe energy lost converting sugar to ethanol, and\nto indicate an average wattage, which may be useful\nin larger installations because most of the power is\nconverted into heat.");

    BGET.loadFromFile("data/economy0.png"); BET.loadFromFile("data/economy1.png");
    BGES.setTexture(BGET); BES.setTexture(BET); BES.setPosition(200,0);
}

int economy()
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
                                selection = (char) 18;
                                yeastP_.setColor(sf::Color(127,127,127));
                                sucroseEoC_.setColor(sf::Color::Yellow);
                                break;
                            case 1:
                                selection--;
                                sucroseP_.setColor(sf::Color(127,127,127));
                                yeastP_.setColor(sf::Color::Yellow);
                                break;
                            case 2:
                                selection--;
                                juiceP_.setColor(sf::Color(127,127,127));
                                sucroseP_.setColor(sf::Color::Yellow);
                                break;
                            case 3:
                                selection--;
                                waterP_.setColor(sf::Color(127,127,127));
                                juiceP_.setColor(sf::Color::Yellow);
                                break;
                            case 4:
                                selection--;
                                yeastPL_.setColor(sf::Color(127,127,127));
                                waterP_.setColor(sf::Color::Yellow);
                                break;
                            case 5:
                                selection--;
                                hydrogenM_.setColor(sf::Color(127,127,127));
                                yeastPL_.setColor(sf::Color::Yellow);
                                break;
                            case 6:
                                selection--;
                                carbonM_.setColor(sf::Color(127,127,127));
                                hydrogenM_.setColor(sf::Color::Yellow);
                                break;
                            case 7:
                                selection--;
                                oxygenM_.setColor(sf::Color(127,127,127));
                                carbonM_.setColor(sf::Color::Yellow);
                                break;
                            case 8:
                                selection--;
                                ethanolEoC_.setColor(sf::Color(127,127,127));
                                oxygenM_.setColor(sf::Color::Yellow);
                                break;
                            case 9:
                                selection--;
                                yeastMass_.setColor(sf::Color(127,127,127));
                                ethanolEoC_.setColor(sf::Color::Yellow);
                                break;
                            case 10:
                                selection--;
                                sucroseMass_.setColor(sf::Color(127,127,127));
                                yeastMass_.setColor(sf::Color::Yellow);
                                break;
                            case 11:
                                selection--;
                                juiceLitre_.setColor(sf::Color(127,127,127));
                                sucroseMass_.setColor(sf::Color::Yellow);
                                break;
                            case 12:
                                selection--;
                                waterLitre_.setColor(sf::Color(127,127,127));
                                juiceLitre_.setColor(sf::Color::Yellow);
                                break;
                            case 13:
                                selection--;
                                monosaccharidegL_.setColor(sf::Color(127,127,127));
                                waterLitre_.setColor(sf::Color::Yellow);
                                break;
                            case 14:
                                selection--;
                                disaccharidegL_.setColor(sf::Color(127,127,127));
                                monosaccharidegL_.setColor(sf::Color::Yellow);
                                break;
                            case 15:
                                selection--;
                                carbondioxidegL_.setColor(sf::Color(127,127,127));
                                disaccharidegL_.setColor(sf::Color::Yellow);
                                break;
                            case 16:
                                selection--;
                                ethanolgL_.setColor(sf::Color(127,127,127));
                                carbondioxidegL_.setColor(sf::Color::Yellow);
                                break;
                            case 17:
                                selection--;
                                watergL_.setColor(sf::Color(127,127,127));
                                ethanolgL_.setColor(sf::Color::Yellow);
                                break;
                            case 18:
                                selection--;
                                sucroseEoC_.setColor(sf::Color(127,127,127));
                                watergL_.setColor(sf::Color::Yellow);
                                break;
                            default: break;
                        }
                        compute2();
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
                                yeastP_.setColor(sf::Color(127,127,127));
                                sucroseP_.setColor(sf::Color::Yellow);
                                break;
                            case 1:
                                selection++;
                                sucroseP_.setColor(sf::Color(127,127,127));
                                juiceP_.setColor(sf::Color::Yellow);
                                break;
                            case 2:
                                selection++;
                                juiceP_.setColor(sf::Color(127,127,127));
                                waterP_.setColor(sf::Color::Yellow);
                                break;
                            case 3:
                                selection++;
                                waterP_.setColor(sf::Color(127,127,127));
                                yeastPL_.setColor(sf::Color::Yellow);
                                break;
                            case 4:
                                selection++;
                                yeastPL_.setColor(sf::Color(127,127,127));
                                hydrogenM_.setColor(sf::Color::Yellow);
                                break;
                            case 5:
                                selection++;
                                hydrogenM_.setColor(sf::Color(127,127,127));
                                carbonM_.setColor(sf::Color::Yellow);
                                break;
                            case 6:
                                selection++;
                                carbonM_.setColor(sf::Color(127,127,127));
                                oxygenM_.setColor(sf::Color::Yellow);
                                break;
                            case 7:
                                selection++;
                                oxygenM_.setColor(sf::Color(127,127,127));
                                ethanolEoC_.setColor(sf::Color::Yellow);
                                break;
                            case 8:
                                selection++;
                                ethanolEoC_.setColor(sf::Color(127,127,127));
                                yeastMass_.setColor(sf::Color::Yellow);
                                break;
                            case 9:
                                selection++;
                                yeastMass_.setColor(sf::Color(127,127,127));
                                sucroseMass_.setColor(sf::Color::Yellow);
                                break;
                            case 10:
                                selection++;
                                sucroseMass_.setColor(sf::Color(127,127,127));
                                juiceLitre_.setColor(sf::Color::Yellow);
                                break;
                            case 11:
                                selection++;
                                juiceLitre_.setColor(sf::Color(127,127,127));
                                waterLitre_.setColor(sf::Color::Yellow);
                                break;
                            case 12:
                                selection++;
                                waterLitre_.setColor(sf::Color(127,127,127));
                                monosaccharidegL_.setColor(sf::Color::Yellow);
                                break;
                            case 13:
                                selection++;
                                monosaccharidegL_.setColor(sf::Color(127,127,127));
                                disaccharidegL_.setColor(sf::Color::Yellow);
                                break;
                            case 14:
                                selection++;
                                disaccharidegL_.setColor(sf::Color(127,127,127));
                                carbondioxidegL_.setColor(sf::Color::Yellow);
                                break;
                            case 15:
                                selection++;
                                carbondioxidegL_.setColor(sf::Color(127,127,127));
                                ethanolgL_.setColor(sf::Color::Yellow);
                                break;
                            case 16:
                                selection++;
                                ethanolgL_.setColor(sf::Color(127,127,127));
                                watergL_.setColor(sf::Color::Yellow);
                                break;
                            case 17:
                                selection++;
                                watergL_.setColor(sf::Color(127,127,127));
                                sucroseEoC_.setColor(sf::Color::Yellow);
                                break;
                            case 18:
                                selection = (char) 0;
                                sucroseEoC_.setColor(sf::Color(127,127,127));
                                yeastP_.setColor(sf::Color::Yellow);
                                break;
                            default: break;
                        }
                        compute2();
                        if (enterN)
                            instream.clear();
                        enterN = false;
                        hasPer = false;
                        break;
                    case sf::Keyboard::Left:
                        switch ((int)selection)
                        {
                            case 0:
                                yeastP--;
                                break;
                            case 1:
                                sucroseP--;
                                break;
                            case 2:
                                juiceP--;
                                break;
                            case 3:
                                waterP--;
                                break;
                            case 4:
                                yeastPL -= .1;
                                break;
                            case 5:
                                hydrogenM -= 0.00001;
                                break;
                            case 6:
                                carbonM -= 0.0001;
                                break;
                            case 7:
                                oxygenM -= 0.0001;
                                break;
                            case 8:
                                ethanolEoC -= 0.01;
                                break;
                            case 9:
                                yeastMass -= 0.1;
                                break;
                            case 10:
                                sucroseMass -= 1.;
                                break;
                            case 11:
                                juiceLitre -= 0.05;
                                break;
                            case 12:
                                waterLitre -= 0.05;
                                break;
                            case 13:
                                monosaccharidegL -= 0.1;
                                break;
                            case 14:
                                disaccharidegL -= 0.1;
                                break;
                            case 15:
                                carbondioxidegL -= 0.0001;
                                break;
                            case 16:
                                ethanolgL -= .1;
                                break;
                            case 17:
                                watergL -= .1;
                                break;
                            case 18:
                                sucroseEoC -= 0.01;
                                break;
                        }
                        compute2();
                        if (enterN)
                            instream.clear();
                        enterN = false;
                        hasPer = false;
                        break;
                    case sf::Keyboard::Right:
                        switch ((int)selection)
                        {
                            case 0:
                                yeastP++;
                                break;
                            case 1:
                                sucroseP++;
                                break;
                            case 2:
                                juiceP++;
                                break;
                            case 3:
                                waterP++;
                                break;
                            case 4:
                                yeastPL += .1;
                                break;
                            case 5:
                                hydrogenM += 0.00001;
                                break;
                            case 6:
                                carbonM += 0.0001;
                                break;
                            case 7:
                                oxygenM += 0.0001;
                                break;
                            case 8:
                                ethanolEoC += 0.01;
                                break;
                            case 9:
                                yeastMass += 0.1;
                                break;
                            case 10:
                                sucroseMass += 1.;
                                break;
                            case 11:
                                juiceLitre += 0.05;
                                break;
                            case 12:
                                waterLitre += 0.05;
                                break;
                            case 13:
                                monosaccharidegL += 0.1;
                                break;
                            case 14:
                                disaccharidegL += 0.1;
                                break;
                            case 15:
                                carbondioxidegL += 0.0001;
                                break;
                            case 16:
                                ethanolgL += .1;
                                break;
                            case 17:
                                watergL += .1;
                                break;
                            case 18:
                                sucroseEoC += 0.01;
                                break;
                        }
                        compute2();
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
                                case 0: yeastP = std::atof(instream.c_str()); yeastP_.setString(yeastP_.getString() + "0"); break;
                                case 1: sucroseP = std::atof(instream.c_str()); sucroseP_.setString(sucroseP_.getString() + "0"); break;
                                case 2: juiceP = std::atof(instream.c_str()); juiceP_.setString(juiceP_.getString() + "0"); break;
                                case 3: waterP = std::atof(instream.c_str()); waterP_.setString(waterP_.getString() + "0"); break;
                                case 4: yeastPL = std::atof(instream.c_str()); yeastPL_.setString(yeastPL_.getString() + "0"); break;
                                case 5: hydrogenM = std::atof(instream.c_str()); hydrogenM_.setString(hydrogenM_.getString() + "0"); break;
                                case 6: carbonM = std::atof(instream.c_str()); carbonM_.setString(carbonM_.getString() + "0"); break;
                                case 7: oxygenM = std::atof(instream.c_str()); oxygenM_.setString(oxygenM_.getString() + "0"); break;
                                case 8: ethanolEoC = std::atof(instream.c_str()); ethanolEoC_.setString(ethanolEoC_.getString() + "0"); break;
                                case 9: yeastMass = std::atof(instream.c_str()); {std::string temp = yeastMass_.getString(); temp.erase(temp.end() - 2, temp.end()); yeastMass_.setString(temp + "0 G");} break;
                                case 10: sucroseMass = std::atof(instream.c_str()); {std::string temp = sucroseMass_.getString(); temp.erase(temp.end() - 2, temp.end()); sucroseMass_.setString(temp + "0 G");} break;
                                case 11: juiceLitre = std::atof(instream.c_str()); {std::string temp = juiceLitre_.getString(); temp.erase(temp.end() - 2, temp.end()); juiceLitre_.setString(temp + "0 L");} break;
                                case 12: waterLitre = std::atof(instream.c_str()); {std::string temp = waterLitre_.getString(); temp.erase(temp.end() - 2, temp.end()); waterLitre_.setString(temp + "0 L");} break;
                                case 13: monosaccharidegL = std::atof(instream.c_str()); monosaccharidegL_.setString(monosaccharidegL_.getString() + "0"); break;
                                case 14: disaccharidegL = std::atof(instream.c_str()); disaccharidegL_.setString(disaccharidegL_.getString() + "0"); break;
                                case 15: carbondioxidegL = std::atof(instream.c_str()); carbondioxidegL_.setString(carbondioxidegL_.getString() + "0"); break;
                                case 16: ethanolgL = std::atof(instream.c_str()); ethanolgL_.setString(ethanolgL_.getString() + "0"); break;
                                case 17: watergL = std::atof(instream.c_str()); watergL_.setString(watergL_.getString() + "0"); break;
                                case 18: sucroseEoC = std::atof(instream.c_str()); sucroseEoC_.setString(sucroseEoC_.getString() + "0"); break;
                                default: break;
                            }
                        else
                        {
                            switch ((int)selection)
                            {
                                case 0: yeastP = std::atof(instream.c_str()); break;
                                case 1: sucroseP = std::atof(instream.c_str()); break;
                                case 2: juiceP = std::atof(instream.c_str()); break;
                                case 3: waterP = std::atof(instream.c_str()); break;
                                case 4: yeastPL = std::atof(instream.c_str()); break;
                                case 5: hydrogenM = std::atof(instream.c_str()); break;
                                case 6: carbonM = std::atof(instream.c_str()); break;
                                case 7: oxygenM = std::atof(instream.c_str()); break;
                                case 8: ethanolEoC = std::atof(instream.c_str()); break;
                                case 9: yeastMass = std::atof(instream.c_str()); break;
                                case 10: sucroseMass = std::atof(instream.c_str()); break;
                                case 11: juiceLitre = std::atof(instream.c_str()); break;
                                case 12: waterLitre = std::atof(instream.c_str()); break;
                                case 13: monosaccharidegL = std::atof(instream.c_str()); break;
                                case 14: disaccharidegL = std::atof(instream.c_str()); break;
                                case 15: carbondioxidegL = std::atof(instream.c_str()); break;
                                case 16: ethanolgL = std::atof(instream.c_str()); break;
                                case 17: watergL = std::atof(instream.c_str()); break;
                                case 18: sucroseEoC = std::atof(instream.c_str()); break;
                                default: break;
                            }
                            compute2();
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
                            case 0: yeastP = std::atof(instream.c_str()); break;
                            case 1: sucroseP = std::atof(instream.c_str()); break;
                            case 2: juiceP = std::atof(instream.c_str()); break;
                            case 3: waterP = std::atof(instream.c_str()); break;
                            case 4: yeastPL = std::atof(instream.c_str()); break;
                            case 5: hydrogenM = std::atof(instream.c_str()); break;
                            case 6: carbonM = std::atof(instream.c_str()); break;
                            case 7: oxygenM = std::atof(instream.c_str()); break;
                            case 8: ethanolEoC = std::atof(instream.c_str()); break;
                            case 9: yeastMass = std::atof(instream.c_str()); break;
                            case 10: sucroseMass = std::atof(instream.c_str()); break;
                            case 11: juiceLitre = std::atof(instream.c_str()); break;
                            case 12: waterLitre = std::atof(instream.c_str()); break;
                            case 13: monosaccharidegL = std::atof(instream.c_str()); break;
                            case 14: disaccharidegL = std::atof(instream.c_str()); break;
                            case 15: carbondioxidegL = std::atof(instream.c_str()); break;
                            case 16: ethanolgL = std::atof(instream.c_str()); break;
                            case 17: watergL = std::atof(instream.c_str()); break;
                            case 18: sucroseEoC = std::atof(instream.c_str()); break;
                            default: break;
                        }
                        compute2();
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
                                case 0: yeastP = 0; break;
                                case 1: sucroseP = 0; break;
                                case 2: juiceP = 0; break;
                                case 3: waterP = 0; break;
                                case 4: yeastPL = 0; break;
                                case 5: hydrogenM = 0; break;
                                case 6: carbonM = 0; break;
                                case 7: oxygenM = 0; break;
                                case 8: ethanolEoC = 0; break;
                                case 9: yeastMass = 0; break;
                                case 10: sucroseMass = 0; break;
                                case 11: juiceLitre = 0; break;
                                case 12: waterLitre = 0; break;
                                case 13: monosaccharidegL = 0; break;
                                case 14: disaccharidegL = 0; break;
                                case 15: carbondioxidegL = 0; break;
                                case 16: ethanolgL = 0; break;
                                case 17: watergL = 0; break;
                                case 18: sucroseEoC = 0; break;
                                default: break;
                            }
                            compute2();
                            enterN = true;
                            switch ((int)selection)
                            {
                                case 0: yeastP_.setString("Yeast: " + n2s(yeastP) + std::string(".")); break;
                                case 1: sucroseP_.setString("Disaccharide: " + n2s(sucroseP) + std::string(".")); break;
                                case 2: juiceP_.setString("Juice: " + n2s(juiceP) + std::string(".")); break;
                                case 3: waterP_.setString("Water: " + n2s(waterP) + std::string(".")); break;
                                case 4: yeastPL_.setString("YPL: " + n2s(yeastPL) + std::string(".")); break;
                                case 5: hydrogenM_.setString("Hydrogen: " + n2s(hydrogenM) + std::string(".")); break;
                                case 6: carbonM_.setString("Carbon: " + n2s(carbonM) + std::string(".")); break;
                                case 7: oxygenM_.setString("Oxygen: " + n2s(oxygenM) + std::string(".")); break;
                                case 8: ethanolEoC_.setString("Ethanol: " + n2s(ethanolEoC) + "."); break;
                                case 9: yeastMass_.setString("Yeast: " + n2s(yeastMass) + std::string(".") + " G"); break;
                                case 10: sucroseMass_.setString("Disaccharide: " + n2s(sucroseMass) + std::string(".") + " G"); break;
                                case 11: juiceLitre_.setString("Juice: " + n2s(juiceLitre) + std::string(".") + " L"); break;
                                case 12: waterLitre_.setString("Water: " + n2s(waterLitre) + std::string(".") + " L"); break;
                                case 13: monosaccharidegL_.setString("Monosaccharide: " + n2s(monosaccharidegL) + std::string(".")); break;
                                case 14: disaccharidegL_.setString("Disaccharide: " + n2s(disaccharidegL) + std::string(".")); break;
                                case 15: carbondioxidegL_.setString("Carbondioxide: " + n2s(carbondioxidegL) + std::string(".")); break;
                                case 16: ethanolgL_.setString("Ethanol: " + n2s(ethanolgL) + std::string(".")); break;
                                case 17: watergL_.setString("Water: " + n2s(watergL) + std::string(".")); break;
                                case 18: sucroseEoC_.setString("Disaccharide: " + n2s(sucroseEoC) + "."); break;
                                default: break;
                            }
                        }
                        else //When we are adding a "." to an already being-written number
                        {
                            switch ((int)selection)
                            {
                                case 0: yeastP_.setString("Yeast: " + n2s(yeastP) + std::string(".")); break;
                                case 1: sucroseP_.setString("Disaccharide: " + n2s(sucroseP) + std::string(".")); break;
                                case 2: juiceP_.setString("Juice: " + n2s(juiceP) + std::string(".")); break;
                                case 3: waterP_.setString("Water: " + n2s(waterP) + std::string(".")); break;
                                case 4: yeastPL_.setString("YPL: " + n2s(yeastPL) + std::string(".")); break;
                                case 5: hydrogenM_.setString("Hydrogen: " + n2s(hydrogenM) + std::string(".")); break;
                                case 6: carbonM_.setString("Carbon: " + n2s(carbonM) + std::string(".")); break;
                                case 7: oxygenM_.setString("Oxygen: " + n2s(oxygenM) + std::string(".")); break;
                                case 8: ethanolEoC_.setString("Ethanol: " + n2s(ethanolEoC) + "."); break;
                                case 9: yeastMass_.setString("Yeast: " + n2s(yeastMass) + std::string(".") + " G"); break;
                                case 10: sucroseMass_.setString("Disaccharide: " + n2s(sucroseMass) + std::string(".") + " G"); break;
                                case 11: juiceLitre_.setString("Juice: " + n2s(juiceLitre) + std::string(".") + " L"); break;
                                case 12: waterLitre_.setString("Water: " + n2s(waterLitre) + std::string(".") + " L"); break;
                                case 13: monosaccharidegL_.setString("Monosaccharide: " + n2s(monosaccharidegL) + std::string(".")); break;
                                case 14: disaccharidegL_.setString("Disaccharide: " + n2s(disaccharidegL) + std::string(".")); break;
                                case 15: carbondioxidegL_.setString("Carbondioxide: " + n2s(carbondioxidegL) + std::string(".")); break;
                                case 16: ethanolgL_.setString("Ethanol: " + n2s(ethanolgL) + std::string(".")); break;
                                case 17: watergL_.setString("Water: " + n2s(watergL) + std::string(".")); break;
                                case 18: sucroseEoC_.setString("Disaccharide: " + n2s(sucroseEoC) + "."); break;
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
                                case 0: yeastP = 0; break;
                                case 1: sucroseP = 0; break;
                                case 2: juiceP = 0; break;
                                case 3: waterP = 0; break;
                                case 4: yeastPL = 0; break;
                                case 5: hydrogenM = 0; break;
                                case 6: carbonM = 0; break;
                                case 7: oxygenM = 0; break;
                                case 8: ethanolEoC = 0; break;
                                case 9: yeastMass = 0; break;
                                case 10: sucroseMass = 0; break;
                                case 11: juiceLitre = 0; break;
                                case 12: waterLitre = 0; break;
                                case 13: monosaccharidegL = 0; break;
                                case 14: disaccharidegL = 0; break;
                                case 15: carbondioxidegL = 0; break;
                                case 16: ethanolgL = 0; break;
                                case 17: watergL = 0; break;
                                case 18: sucroseEoC = 0; break;
                                default: break;
                            }
                            compute2();
                            enterN = true;
                            hasPer = false;
                    }
                    break;
                    case sf::Keyboard::Return:
                    compute2();
                    if (enterN)
                        instream.clear();
                    enterN = false;
                    hasPer = false;
                        break;
                    case sf::Keyboard::Escape:
                        enthalpyC = 1000 * sucroseEoC -  1000 * ethanolEoC * 4;
                        carbondioxideM = molarMass(0,1,2); ethanolM = molarMass(6,2,1); waterM = molarMass(2,0,1);
                        monosaccharideM = molarMass(12,6,6); disaccharideM = molarMass(22,12,11);
                        compute();
                        if (enterN)
                            instream.clear();
                        enterN = false;
                        hasPer = false;
                        return 0;
                    case sf::Keyboard::L:
                    {
                        window.clear(sf::Color(255,255,255));

                        window.draw(BGES);
                        window.draw(backGround);

                        window.draw(input);
                        window.draw(price);
                        window.draw(yeastP_);
                        window.draw(sucroseP_);
                        window.draw(juiceP_);
                        window.draw(waterP_);

                        window.draw(amount);
                        window.draw(yeastMass_);
                        window.draw(sucroseMass_);
                        window.draw(juiceLitre_);
                        window.draw(waterLitre_);
                        window.draw(yeastPL_);

                        window.draw(atomicM_);
                        window.draw(hydrogenM_);
                        window.draw(carbonM_);
                        window.draw(oxygenM_);

                        window.draw(densities);
                        window.draw(monosaccharidegL_);
                        window.draw(disaccharidegL_);
                        window.draw(carbondioxidegL_);
                        window.draw(ethanolgL_);
                        window.draw(watergL_);

                        window.draw(enthalpyOfCombustion);
                        window.draw(ethanolEoC_);
                        window.draw(sucroseEoC_);

                        window.draw(informa);
                        window.draw(BES);

                        window.display();


                        sf::Image screen = window.capture();
                        sf::Texture screenT; screenT.loadFromImage(screen);
                        screenS.setTexture(screenT);
                        load();
                    }
                        break;
                    case sf::Keyboard::S:
                    {
                        window.clear(sf::Color(255,255,255));

                        window.draw(BGES);
                        window.draw(backGround);

                        window.draw(input);
                        window.draw(price);
                        window.draw(yeastP_);
                        window.draw(sucroseP_);
                        window.draw(juiceP_);
                        window.draw(waterP_);

                        window.draw(amount);
                        window.draw(yeastMass_);
                        window.draw(sucroseMass_);
                        window.draw(juiceLitre_);
                        window.draw(waterLitre_);
                        window.draw(yeastPL_);

                        window.draw(atomicM_);
                        window.draw(hydrogenM_);
                        window.draw(carbonM_);
                        window.draw(oxygenM_);

                        window.draw(densities);
                        window.draw(monosaccharidegL_);
                        window.draw(disaccharidegL_);
                        window.draw(carbondioxidegL_);
                        window.draw(ethanolgL_);
                        window.draw(watergL_);

                        window.draw(enthalpyOfCombustion);
                        window.draw(ethanolEoC_);
                        window.draw(sucroseEoC_);

                        window.draw(informa);
                        window.draw(BES);

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
            default: break;
        }
    }
    window.clear(sf::Color(255,255,255));

    window.draw(BGES);
    window.draw(backGround);

    window.draw(input);
    window.draw(price);
    window.draw(yeastP_);
    window.draw(sucroseP_);
    window.draw(juiceP_);
    window.draw(waterP_);

    window.draw(amount);
    window.draw(yeastMass_);
    window.draw(sucroseMass_);
    window.draw(juiceLitre_);
    window.draw(waterLitre_);
    window.draw(yeastPL_);

    window.draw(atomicM_);
    window.draw(hydrogenM_);
    window.draw(carbonM_);
    window.draw(oxygenM_);

    window.draw(densities);
    window.draw(monosaccharidegL_);
    window.draw(disaccharidegL_);
    window.draw(carbondioxidegL_);
    window.draw(ethanolgL_);
    window.draw(watergL_);

    window.draw(enthalpyOfCombustion);
    window.draw(ethanolEoC_);
    window.draw(sucroseEoC_);

    window.draw(informa);
    window.draw(BES);

    window.display();
    goto begin;
    return 1;
}

