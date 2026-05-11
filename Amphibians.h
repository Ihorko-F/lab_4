#ifndef AMPHIBIANS_H
#define AMPHIBIANS_H

#include <iostream>
#include <string>

using namespace std;

// Base Class
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

// Branch 1: Frog (Virtual inheritance to solve diamond problem)
class Frog : virtual public Amphibian {
protected:
    double jumpHeight;
public:
    Frog();
    Frog(string spec, bool poison, double jump);
    ~Frog();
    void MakeSound() override;
};

// Branch 2: Salamander (Virtual inheritance)
class Salamander : virtual public Amphibian {
protected:
    bool canRegenerate;
public:
    Salamander();
    Salamander(string spec, bool poison, bool regen);
    ~Salamander();
    void MakeSound() override;
};

// Diamond Class: FrogSalamander (Multiple Inheritance)
class FrogSalamander : public Frog, public Salamander {
private:
    string hybridName;
public:
    FrogSalamander(string name);
    ~FrogSalamander();
    void MakeSound() override;
    void ShowHybridStatus();
};

int runProgram();

#endif