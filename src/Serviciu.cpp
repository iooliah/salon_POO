#include "Serviciu.h"
#include <cstring>

//constr implicit
Serviciu::Serviciu()
{
    nume = nullptr;
    pret = 0.0;
    durata = 0;
}

//constr de initializare
Serviciu::Serviciu(const char* nume, float pret, int durata)
{
    if(nume){
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
    }else
        this->nume = nullptr;

    this->pret = pret;
    this->durata = durata;
}

//constr de copiere
Serviciu::Serviciu(const Serviciu& other):pret(other.pret), durata(other.durata))
{
    if(other.nume){
        nume = new char[strlen(other.nume) + 1];
        strcpy(nume, other.nume);
    }else
        nume = nullptr;
}

//operator de copiere
Serviciu& Serviciu::operator=(const Serviciu& other)
{
    if(this!=&other){
        delete[] nume;              //eliberez memoria

        pret = other.pret;          //copiez datele vechi
        durata = other.durata;
        reducere10 = other.reducere10;

        if(other.nume){             //aloc spatiu si copiez noul nume
            nume = new char[strlen(other.nume) +1];
            strcpy(nume, other.nume);
        }else
            nume = nullptr;
    }
    return *this;
}

//destructor
Serviciu::~Serviciu()
{
    delete[] nume;          //asa memoria se elibereaza corect
}

//operator >>
std::ostream& operator<<(std::ostream& os, const Serviciu& s)
{
    os<<"Nume: "<<(s.nume)<<", Pret: "<<s.pret<<", Durata: "<< s.durata<< " minute";
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
int Serviciu::getDurata() const
{
    return durata;
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
void Serviciu::setReducere10(bool reducere)
{
    this->reducere10 = reducere;
}
void Serviciu::setDurata(int durata)
{
    this->durata = durata;
}
