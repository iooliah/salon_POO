#include "Angajat.h"
#include <cstring>

int Angajat::numarAngajati = 0;

Angajat::Angajat()                 //constr implicit
{
    nume = nullptr;
    prenume = nullptr;
    experienta = 0;
    specializare = nullptr;
    numarAngajati++;
}

Angajat::Angajat(const char* nume, const char* prenume, int experienta, const char* specializare)   //constr initilizare
{
    if(nume){
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }else{
        this->nume = nullptr;
    }
    if(prenume){
        this->prenume = new char[strlen(prenume) + 1];
        strcpy(this->prenume, prenume);
    }else{
        this->prenume = nullptr;
    }
    this->experienta = experienta;

    if(specializare){
        this->specializare = new char[strlen(specializare) + 1];
        strcpy(this->specializare, specializare);
    }else{
        this->specializare = nullptr;
    }
    numarAngajati++;
}

Angajat::Angajat(const Angajat& other)                           //constr copiere
{
    if(other.nume){
        nume = new char[strlen(other.nume) + 1];
        strcpy(nume, other.nume);
    }else{
        nume = nullptr;
    }
    if(other.prenume){
        prenume = new char[strlen(other.prenume) + 1];
        strcpy(prenume, other.prenume);
    }else{
        prenume = nullptr;
    }
    experienta = other.experienta;

    if(other.specializare){
        specializare = new char[strlen(other.specializare) + 1];
        strcpy(specializare, other.specializare);
    }else{
        specializare = nullptr;
    }
    numarAngajati++;
}

Angajat& Angajat::operator=(const Angajat& other)               //operator =
{
    if(this != &other){
        delete[] nume;
        delete[] prenume;
        delete[] specializare;

        if(other.nume){
            nume = new char[strlen(other.nume) + 1];
            strcpy(nume, other.nume);
        }else{
            nume = nullptr;
        }
        if(other.prenume){
            prenume = new char[strlen(other.prenume) + 1];
            strcpy(prenume, other.prenume);
        }else{
            prenume = nullptr;
        }
        experienta = other.experienta;
        if(other.specializare){
            specializare = new char[strlen(other.specializare) + 1];
            strcpy(specializare, other.specializare);
        }else{
            specializare = nullptr;
        }
    }
    return *this;
}

Angajat::~Angajat()              //destructor
{
    delete[] nume;
    delete[] prenume;
    delete[] specializare;
    numarAngajati--;             //daca sterg un angajat, logic ca scade si nr-ul tuturor angajatilor
}

//getters
const char* Angajat::getNume() const { return nume; }
const char* Angajat::getPrenume() const { return prenume; }
int Angajat::getExperienta() const { return experienta; }
const char* Angajat::getSpecializare() const { return specializare; }


bool Angajat::areExperienta() const              //functie pt a putea creste pretul daca angajatul are mai multa experienta
{
    return experienta >= 5;
}

//operator <<
std::ostream& operator<<(std::ostream& os, const Angajat& a)
{
    os << "Nume: " << (a.nume)<< ", Prenume: " << (a.prenume)<< ", Experienta: " << a.experienta<< ", Specializare: " << (a.specializare);
    return os;
}
