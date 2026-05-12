#include "Amphibians.h"

//Amphibian
Amphibian::Amphibian() : species("Generic Amphibian"), isPoisonous(false) {
    cout << "[Constructor] Amphibian created" << endl;
}
Amphibian::Amphibian(string spec, bool poison) : species(spec), isPoisonous(poison) {
    cout << "[Constructor] Amphibian created" << endl;
}
Amphibian::~Amphibian() { cout << "[Destructor] Amphibian destroyed" << endl; }

void Amphibian::MakeSound() { cout << species << " makes a sound." << endl; }

void Amphibian::DisplayInfo() {
    cout << "Species: " << species << (isPoisonous ? " (Poisonous)" : " (Safe)") << endl;
}

void Amphibian::DisplayInfo(string habitat) {
    cout << species << " lives in: " << habitat << endl;
}

//Frog
Frog::Frog() : Amphibian("Frog", false), jumpHeight(1.0) {
    cout << "[Constructor] Frog branch initialized" << endl;
}
Frog::~Frog() { cout << "[Destructor] Frog destroyed" << endl; }
void Frog::MakeSound() { cout << "Frog says: Ribbit!" << endl; }

//Salamander
Salamander::Salamander() : Amphibian("Salamander", true), canRegenerate(true) {
    cout << "[Constructor] Salamander branch initialized" << endl;
}
Salamander::~Salamander() { cout << "[Destructor] Salamander destroyed" << endl; }
void Salamander::MakeSound() { cout << "Salamander hisses..." << endl; }

//FrogSalamander
FrogSalamander::FrogSalamander(string name) : Amphibian("Hybrid", true), Frog(), Salamander(), hybridName(name) {
    cout << "[Constructor] Hybrid Frog-Salamander '" << hybridName << "' created!" << endl;
}
FrogSalamander::~FrogSalamander() { cout << "[Destructor] Hybrid destroyed" << endl; }

void FrogSalamander::MakeSound() {
    cout << "Hybrid " << hybridName << " makes a strange mixed sound!" << endl;
}

void FrogSalamander::ShowHybridStatus() {
    cout << "I am a hybrid! I can jump and regenerate limbs." << endl;
}

int runProgram() {
    cout << "--- Structure 1-2-1 ---" << endl;
    FrogSalamander* diamond = new FrogSalamander("Glitchy");
    diamond->MakeSound();
    delete diamond;

    cout << "\n--- Structure 1-3-1 ---" << endl;
    TripleHybrid* triple = new TripleHybrid("Chimera");
    triple->MakeSound();
    triple->DisplayInfo("Secret Lab");
    delete triple;

    return 0;
}