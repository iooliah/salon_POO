#include "Client.h"
#include <cstring>

int Client::numarClienti = 0;

//constr implicit
Client::Client()
{
    nume = nullptr;
    prenume = nullptr;
    telefon = nullptr;
    nrIstoric = 0;
    numarClienti++;
    for(int i = 0; i < 100; i++){
        istoric[i][0] = '\0';
    }
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
    nrIstoric = 0;
    for(int i = 0; i < 100; i++){
        istoric[i][0] = '\0';
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
    nrIstoric = other.nrIstoric;
    for(int i = 0; i < nrIstoric; i++){
        strcpy(istoric[i], other.istoric[i]);
    }
    for(int i = nrIstoric; i < 100; i++){
        istoric[i][0] = '\0';
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

        for(int i = 0; i < nrIstoric; i++){
            delete[] istoric[i];
        }
        delete[] istoric;

        if(other.nume){
            nume = new char[strlen(other.nume)+1];
            strcpy(nume, other.nume);
        }else
            nume = nullptr;

        if(other.prenume){
            prenume = new char[strlen(other.prenume)+1];
            strcpy(prenume, other.prenume);
        }else
            prenume = nullptr;

        if(other.telefon){
            telefon = new char[strlen(other.telefon)+1];
            strcpy(telefon, other.telefon);
        }else
            telefon = nullptr;

        nrIstoric = other.nrIstoric;
        for(int i = 0; i < nrIstoric; i++){
            strcpy(istoric[i], other.istoric[i]);
        }
        for(int i = nrIstoric; i < 100; i++){
            istoric[i][0] = '\0';
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
    numarClienti--;
}

//getters
const char* Client::getNume() const{return nume;}
const char* Client::getPrenume() const{return prenume;}
const char* Client::getTelefon() const{return telefon;}
int Client::getNrIstoric() const{return nrIstoric;}

const char* Client::getIstoricItem(int index) const{
    if(index >= 0 && index < nrIstoric){
        return istoric[index];
    }else {
        return nullptr;
    }
}

// setters
void Client::setNume(const char* nume)
{
    delete[] this->nume;
    if(nume){
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume, nume);
    } else{
        this->nume = nullptr;
    }
}
void Client::setPrenume(const char* prenume)
{
    delete[] this->prenume;
    if(prenume){
        this->prenume = new char[strlen(prenume)+1];
        strcpy(this->prenume, prenume);
    }else{
        this->prenume = nullptr;
    }
}
void Client::setTelefon(const char* telefon)
{
    delete[] this->telefon;
    if(telefon){
        this->telefon = new char[strlen(telefon)+1];
        strcpy(this->telefon, telefon);
    }else {
        this->telefon = nullptr;
    }
}
void Client::adaugaIstoric(const char* procedura){      //setter istoric
    if(procedura && nrIstoric < 100){
        strcpy(istoric[nrIstoric], procedura);
        nrIstoric++;
    }
}

bool Client::esteFidel() const{return nrIstoric >= 10;}

void Client::afiseazaTotalClienti()
{
    std::cout<<"Numar total clienti: "<<numarClienti<<std::endl;
}

//operator <<
std::ostream& operator<<(std::ostream& os,const Client& c)
{
    os<<"Nume: "<<(c.nume)<<", Prenume: "<<(c.prenume)<<", Telefon: "<<(c.telefon ? c.telefon : "necunoscut")<<", Istoric("<<c.nrIstoric<<"): ";

    for(int i = 0; i < c.nrIstoric; i++){
        os<<c.istoric[i];
        if(i < c.nrIstoric - 1) os<<"; ";
    }
    return os;
}
