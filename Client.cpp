#include "Client.h"
#include <cstring>

int Client::numarClienti = 0;

//constr implicit
Client::Client()
{
    nume = nullptr;
    prenume = nullptr;
    telefon = nullptr;
    numarClienti++;
}
//constr initializare
Client::Client(const char* nume, const char* prenume, const char* telefon)
{
    if(nume){
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
    }else{
        this->nume = nullptr;
    }
    if(prenume){
        this->prenume = new char[strlen(prenume)+1];
        strcpy(this->prenume, prenume);
    }else{
        this->prenume = nullptr;
    }
    if(telefon){
        this->telefon = new char[strlen(telefon)+1];
        strcpy(this->telefon, telefon);
    }else{
        this->telefon = nullptr;
    }
    numarClienti++;
}

//constr copiere
Client::Client(const Client& other)
{
    if(other.nume){
        nume = new char[strlen(other.nume)+1];
        strcpy(nume, other.nume);
    }else{
        nume = nullptr;
    }
    if(other.prenume){
        prenume = new char[strlen(other.prenume)+1];
        strcpy(prenume, other.prenume);
    }else{
        prenume = nullptr;
    }
    if(other.telefon){
        telefon = new char[strlen(other.telefon)+1];
        strcpy(telefon, other.telefon);
    }else{
        telefon = nullptr;
    }

    numarClienti++;
}

//operator =
Client& Client::operator=(const Client& other)
{
    if(this != &other){
        delete[] nume;
        delete[] prenume;
        delete[] telefon;

        if(other.nume){
            nume = new char[strlen(other.nume)+1];
            strcpy(nume, other.nume);
        }else{
            nume = nullptr;
        }
        if(other.prenume){
            prenume = new char[strlen(other.prenume)+1];
            strcpy(prenume, other.prenume);
        }else{
            prenume = nullptr;
        }
        if(other.telefon){
            telefon = new char[strlen(other.telefon)+1];
            strcpy(telefon, other.telefon);
        }else{
            telefon = nullptr;
        }
    }
    return *this;
}

//destructor
Client::~Client()
{
    delete[] nume;
    delete[] prenume;
    delete[] telefon;
    numarClienti--;         //daca un client este sters, numarul total de clienti scade
}

//getters
const char* Client::getNume() const{return nume;}
const char* Client::getPrenume() const{return prenume;}
const char* Client::getTelefon() const{return telefon;}

//operator <<
std::ostream& operator<<(std::ostream& os,const Client& c)
{
    os<<"Nume: "<<(c.nume)<<", Prenume: "<<(c.prenume)<<", Telefon: "<<(c.telefon);
    return os;
}
