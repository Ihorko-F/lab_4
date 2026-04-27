#ifndef AMPHIBIANS_H
#define AMPHIBIANS_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Батьківський клас
class Amphibian {
protected:
    string species;
    bool isPoisonous;
public:
    Amphibian();
    Amphibian(string spec, bool poison);
    
    virtual void MakeSound(); 
    
    void DisplayInfo();
    void DisplayInfo(string habitat);
};

// Похідний клас (Жаби)
class Frog : public Amphibian {
protected:
    double jumpHeight;
public:
    Frog();
    Frog(string spec, bool poison, double jump);
    void MakeSound() override;
    void Jump();
};

// Похідний клас (Саламандри)
class Salamander : public Amphibian {
public:
    Salamander();
    Salamander(string spec, bool poison);
    void MakeSound() override;
};

// Похідний клас від Salamander
class Axolotl : public Salamander {
protected:
    bool regeneration;
public:
    Axolotl ();
    Axolotl (string spec, bool poison, bool regeneration);
    void MakeSound() override;
    void RegrowLimbs();
};

// Похідний клас від Frog (Квакші)
class TreeFrog : public Frog {
protected:
    string skinColor;
public:
    TreeFrog(string spec, bool poison, double jump, string color);
    void MakeSound() override;
    void Climb();
};

// Похідний клас від TreeFrog (Дереволази)
class PoisonDartFrog : public TreeFrog {
private:
    int toxicityLevel; // Рівень токсичності від 1 до 10
public:
    PoisonDartFrog(string spec, double jump, string color, int tox);
    void MakeSound() override;
    void Warn();
};

int runProgram ();

#endif