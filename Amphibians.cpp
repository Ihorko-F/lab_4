#include "Amphibians.h"

// Amphibian
Amphibian::Amphibian() : species("Unknown Amphibian"), isPoisonous(false) {}
Amphibian::Amphibian(string spec, bool poison) : species(spec), isPoisonous(poison) {}

void Amphibian::MakeSound() {
    cout << species << " makes weird noise." << endl;
}

void Amphibian::DisplayInfo() {
    cout << "Species: " << species << (isPoisonous ? " (Poisonous)" : " (Safe)") << endl;
}

void Amphibian::DisplayInfo(string habitat) {
    cout << species << " typically dwells in: " << habitat << endl;
}

// Frog
Frog::Frog() : Amphibian("Common Frog", false), jumpHeight(0.5) {}
Frog::Frog(string spec, bool poison, double jump) : Amphibian(spec, poison), jumpHeight(jump) {}

void Frog::MakeSound() {
    cout << species << " emits: Kwa-Kwa!" << endl;
}

void Frog::Jump() {
    cout << species << " leaps for " << jumpHeight << " meters." << endl;
}

// Salamander
Salamander::Salamander() : Amphibian("Fire Salamander", true) {}
Salamander::Salamander(string spec, bool poison) : Amphibian(spec, poison) {}
void Salamander::MakeSound() {
    cout << species << " quietly hisses..." << endl;
}

// Axolotl
Axolotl::Axolotl() : Salamander("Axolotl", false), regeneration(true) {}
Axolotl::Axolotl(string spec, bool poison, bool regeneration) : Salamander(spec, poison), regeneration(regeneration) {}
void Axolotl::MakeSound() {
    cout << species << " quietly barks" << endl;
}
void Axolotl::RegrowLimbs() {
    cout << species << (regeneration ? " (Can regenerate limbs)" : " (Can't heal big wounds)") << endl;
}

// TreeFrog
TreeFrog::TreeFrog(string spec, bool poison, double jump, string color) 
    : Frog(spec, poison, jump) {
    skinColor = color;
}

void TreeFrog::MakeSound() {
    cout << species << " (color: " << skinColor << ") emits loud 'Ribbit!'" << endl;
}

void TreeFrog::Climb() {
    cout << species << " masterfully climbs on trees and even glass." << endl;
}

// PoisonDartFrog
PoisonDartFrog::PoisonDartFrog(string spec, double jump, string color, int tox)
    : TreeFrog(spec, true, jump, color) {
    toxicityLevel = tox;
}

void PoisonDartFrog::MakeSound() {
    cout << species << " emits loud whistle. Warning!" << endl;
}

void PoisonDartFrog::Warn() {
    cout << "WARNING! Poison dart frog toxicity level is: " << toxicityLevel << "/10" << endl;
}

int runProgram() {

    cout << "~~~ Cool Amphibians ~~~\n\n";

    Amphibian* zoo[6];
    
    zoo[0] = new Frog("Pool frog", false, 1.2);
    zoo[1] = new Salamander();
    zoo[2] = new TreeFrog("Tree frog", false, 0.8, "bright-green");
    zoo[3] = new PoisonDartFrog("Blue poison dart frog", 0.5, "blue", 9);
    zoo[4] = new Axolotl();

    for(int i = 0; i <= 4; i++) {
        cout << "[" << i + 1 << "] ";
        zoo[i]->DisplayInfo();
        zoo[i]->MakeSound();
        cout << "---" << endl;
    }

    cout << "\nMethod overloading (DisplayInfo)" << endl;
    zoo[5] = new TreeFrog("Tree frog", false, 0.7, "green");
    zoo[5]->DisplayInfo();
    zoo[5]->DisplayInfo("Tropical forest");

    cout << "\nSubclass-specific method" << endl;
    PoisonDartFrog* dart = (PoisonDartFrog*)zoo[3];
    dart->Warn();

    for(int i = 0; i <= 5; i++) delete zoo[i];

    return 0;
}