#include "Serviciu.h"
#include <cstring>


//constr implicit
Serviciu::Serviciu()
{
    nume = nullptr;
    pret = 0.0;
    durata = 0;
    locatie = nullptr;
    avans = false;
    reducere10 = false;
}

//constr de initializare
Serviciu::Serviciu(const char* nume, float pret, int durata, const char* locatie, bool avans, bool reducere10)
{
    if(nume){
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
    }else
        this->nume = nullptr;

    this->pret = pret;
    this->durata = durata;
    if(locatie){
        this->locatie = new char[strlen(locatie)+1];
        strcpy(this->locatie, locatie);
    }else
        this->locatie = nullptr;

    avans = false;
    reducere = false;
}

//constr de copiere
Serviciu::Serviciu(const Serviciu& other):pret(other.pret), durata(other.durata), avans(other.avans), reducere10(other.reducere10)
{
    if(other.nume){
        nume = new char[strlen(other.nume) + 1];
        strcpy(nume, other.nume);
    }else
        nume = nullptr;

    if(other.locatie){
        locatie = new char[strlen(other.locatie) + 1];
        strcpy(locatie, other.locatie);
    }else
        locatie = nullptr;
}

//operator de copiere
Serviciu& Serviciu::operator=(const Serviciu& other)
{
    if(this!=&other){
        delete[] nume;              //eliberez memoria
        delete[] locatie;

        pret = other.pret;          //copiez datele vechi
        durata = other.durata;
        avans = other.avans;
        reducere10 = other.reducere10;

        if(other.nume){             //aloc spatiu si copiez noul nume
            nume = new char[strlen(other.nume) +1];
            strcpy(nume, other.nume);
        }else
            nume = nullptr;

        if(other.locatie){           //aloc spatiu si copiez noua locatie
            locatie = new char[strlen(other.locatie) + 1];
            strcpy(locatie, other.locatie);
        }
        else
            locatie = nullptr;
    }
    return *this;
}

//destructor
Serviciu::~Serviciu()
{
    delete[] nume;          //asa memoria se elibereaza corect
    delete[] locatie;
}

//operator >>
std::ostream& operator<<(std::ostream& os, const Serviciu& s)
{
    os<<"Nume: "<<(s.nume)<<", Pret: "<<s.pret<<", Durata: "<< s.durata<< " minute"
    <<", Locatie: "<<(s.locatie ? s.locatie : "necunoscuta")<< ", Avans: "<< (s.avans ? "da" : "nu")
    <<", Reducere: " << (s.reducere10 ? "da" : "nu");
    return os;
}

//getters
const char* Serviciu::getNume() const
{
    return nume;
}
float Serviciu::getPret() const
{
    return pret;
}
bool Serviciu::getAvans() const
{
    return avans;
}
bool Serviciu::getReducere10() const
{
    return reducere10;
}
int Serviciu::getDurata() const
{
    return durata;
}
const char* Serviciu::getLocatie() const
{
    return locatie;
}

//setters
void Serviciu::setNume(const char* nume)
{
    delete[] this->nume;
    if(nume){
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    } else{
        this->nume = nullptr;
    }
}
void Serviciu::setPret(float pret)
{
    this->pret = pret;
}
void Serviciu::setAvans(bool avans)
{
    this->avans = avans;
}
void Serviciu::setReducere10(bool reducere)
{
    this->reducere10 = reducere;
}
void Serviciu::setDurata(int durata)
{
    this->durata = durata;
}
void Serviciu::setLocatie(const char* locatie)
{
    delete[] this->locatie;
    if (locatie) {
        this->locatie = new char[strlen(locatie) + 1];
        strcpy(this->locatie, locatie);
    }else{
        this->locatie = nullptr;
    }
}
float Serviciu::calcPretRedus(float procent) const
{
    return pret - (pret * procent / 100.0f);
}

float Serviciu::calcAvans(float procent) const
{
    return pret * procent / 100.0f;
}

/*
std::istream& operator>>(std::istream& is, Serviciu& s)
{
    char copie[100];
    std::cout << "Nume: ";
    is >> copie;
    s.setNume(copie);

    std::cout << "Pret: ";
    is >> s.pret;

    std::cout << "Avans (1/0): ";
    is >> s.avans;

    std::cout << "Reducere10 (1/0): ";
    is >> s.reducere10;

    std::cout << "Durata: ";
    is >> s.durata;

    std::cout << "Locatie: ";
    is >> copie;
    s.setLocatie(copie);
    return is;
}
*/
