#ifndef AMPHIBIANS_H
#define AMPHIBIANS_H

#include <iostream>
#include <string>

using namespace std;

class Amphibian {
protected:
    string species;
    bool isPoisonous;
public:
    Amphibian();
    Amphibian(string spec, bool poison);
    virtual ~Amphibian(); // Destructor
    
    virtual void MakeSound(); 
    void DisplayInfo();
    void DisplayInfo(string habitat);
};

class Frog : virtual public Amphibian {
protected:
    double jumpHeight;
public:
    Frog();
    Frog(string spec, bool poison, double jump);
    ~Frog();
    void MakeSound() override;
};

class Salamander : virtual public Amphibian {
protected:
    bool canRegenerate;
public:
    Salamander();
    Salamander(string spec, bool poison, bool regen);
    ~Salamander();
    void MakeSound() override;
};

class Newt : virtual public Amphibian {
public:
    Newt() : Amphibian("Newt", false) { cout << "[Constructor] Newt branch initialized" << endl; }
    ~Newt() { cout << "[Destructor] Newt destroyed" << endl; }
    void MakeSound() override { cout << "Newt squeaks!" << endl; }
};

class FrogSalamander : public Frog, public Salamander {
protected:
    string hybridName;
public:
    FrogSalamander(string name);
    virtual ~FrogSalamander();
    void MakeSound() override;
    void ShowHybridStatus();
};

class TripleHybrid : public Frog, public Salamander, public Newt {
private:
    string name;
public:
    TripleHybrid(string n) : Amphibian("Triple", true), Frog(), Salamander(), Newt(), name(n) {
        cout << "[Constructor] Triple Hybrid '" << name << "' created!" << endl;
    }
    ~TripleHybrid() { cout << "[Destructor] Triple Hybrid destroyed" << endl; }
    void MakeSound() override { cout << name << " makes a triple mixed sound!" << endl; }
};

int runProgram();

#endif