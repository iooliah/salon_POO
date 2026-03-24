#include "Angajat.h"
#include <cstring>

int Angajat::numarAngajati = 0;

//constr implicit
Angajat::Angajat()
{
    nume = nullptr;
    prenume = nullptr;
    experienta = 0;
    salariu = 0.0f;
    specializare = nullptr;
    numarAngajati++;
}

//constr de initializare
Angajat::Angajat(const char* nume, const char* prenume, int experienta, float salariu, const char* specializare)
{
    if(nume){
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }else
        this->nume = nullptr;
    if(prenume){
        this->prenume = new char[strlen(prenume) + 1];
        strcpy(this->prenume, prenume);
    }else
        this->prenume = nullptr;

    this->experienta = experienta;
    this->salariu = salariu;

    if(specializare){
        this->specializare = new char[strlen(specializare) + 1];
        strcpy(this->specializare, specializare);
    } else
        this->specializare = nullptr;
    numarAngajati++;
}

//constr de copiere
Angajat::Angajat(const Angajat& other)
{
    if(other.nume){
        nume = new char[strlen(other.nume) + 1];
        strcpy(nume, other.nume);
    } else
        nume = nullptr;
    if(other.prenume){
        prenume = new char[strlen(other.prenume) + 1];
        strcpy(prenume, other.prenume);
    } else
        prenume = nullptr;

    experienta = other.experienta;
    salariu = other.salariu;
    if(other.specializare){
        specializare = new char[strlen(other.specializare) + 1];
        strcpy(specializare, other.specializare);
    }else
        specializare = nullptr;
    numarAngajati++;
}

//operator de copiere
Angajat& Angajat::operator=(const Angajat& other)
{
    if(this != &other){
        delete[] nume;
        delete[] prenume;
        delete[] specializare;

        if(other.nume){
            nume = new char[strlen(other.nume) + 1];
            strcpy(nume, other.nume);
        } else
            nume = nullptr;

        if(other.prenume){
            prenume = new char[strlen(other.prenume) + 1];
            strcpy(prenume, other.prenume);
        } else
            prenume = nullptr;

        experienta = other.experienta;
        salariu = other.salariu;

        if(other.specializare){
            specializare = new char[strlen(other.specializare) + 1];
            strcpy(specializare, other.specializare);
        } else
            specializare = nullptr;
    }
    return *this;
}

// destructor
Angajat::~Angajat()
{
    delete[] nume;
    delete[] prenume;
    delete[] specializare;
    numarAngajati--;
}

// getters
const char* Angajat::getNume() const
{
    return nume;
}
const char* Angajat::getPrenume() const
{
    return prenume;
}
int Angajat::getExperienta() const
{
    return experienta;
}
float Angajat::getSalariu() const
{
    return salariu;
}
const char* Angajat::getSpecializare() const
{
    return specializare;
}

//setters
void Angajat::setNume(const char* nume)
{
    delete[] this->nume;

    if(nume){
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    } else
        this->nume = nullptr;
}
void Angajat::setPrenume(const char* prenume)
{
    delete[] this->prenume;

    if(prenume){
        this->prenume = new char[strlen(prenume) + 1];
        strcpy(this->prenume, prenume);
    } else
        this->prenume = nullptr;
}
void Angajat::setSpecializare(const char* specializare)
{
    delete[] this->specializare;

    if(specializare){
        this->specializare = new char[strlen(specializare) + 1];
        strcpy(this->specializare, specializare);
    } else
        this->specializare = nullptr;
}
void Angajat::setExperienta(int experienta)
{
    this->experienta = experienta;
}
void Angajat::setSalariu(float salariu)
{
    this->salariu = salariu;
}

//functii
bool Angajat::areExperienta() const
{
    return (experienta>=5);
}

float Angajat::calcBonus(float procent) const
{
    return salariu*procent/100.0f;
}

void Angajat::afiseazaTotalAngajati()
{
    std::cout<<"Numar total de angajati: "<<numarAngajati<<std::endl;
}

//operator <<
std::ostream& operator<<(std::ostream& os, const Angajat& a)
{
    os<< "Nume: "<< (a.nume)<<", Prenume: "<<(a.prenume)<<", Telefon: "<<(a.telefon)
    <<", Experienta: "<<a.experienta<<" ani"<< ", Salariu: "<< a.salariu<<", Specializare: "<<(a.specializare);
    return os;
}
