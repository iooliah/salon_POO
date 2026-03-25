#include "Programare.h"
#include <cstring>

//constructor implicit
Programare::Programare(){
    data = nullptr;
    ora = nullptr;
    tipPlata = CASH;
}

//constructor de initializare
Programare::Programare(const Client& client,const Angajat& angajat,const Serviciu& serviciu,const char* data,const char* ora,TipPlata tipPlata): client(client), angajat(angajat), serviciu(serviciu)
{
    if(data){
        this->data = new char[strlen(data) + 1];
        strcpy(this->data,data);
    }else
        this->data = nullptr;

    if(ora){
        this->ora = new char[strlen(ora) + 1];
        strcpy(this->ora,ora);
    }else
        this->ora = nullptr;
    this->tipPlata = tipPlata;
}

//constructor de copiere
Programare::Programare(const Programare& other): client(other.client), angajat(other.angajat), serviciu(other.serviciu){
    if(other.data){
        data = new char[strlen(other.data) + 1];
        strcpy(data,other.data);
    }else
        data = nullptr;
    if(other.ora){
        ora = new char[strlen(other.ora) + 1];
        strcpy(ora,other.ora);
    }else
        ora = nullptr;
    tipPlata = other.tipPlata;
}

//operator =
Programare& Programare::operator=(const Programare& other){
    if(this != &other){
        client = other.client;
        angajat = other.angajat;
        serviciu = other.serviciu;

        delete[] data;
        delete[] ora;

        if(other.data){
            data = new char[strlen(other.data) + 1];
            strcpy(data,other.data);
        }else
            data = nullptr;
        if(other.ora){
            ora = new char[strlen(other.ora) + 1];
            strcpy(ora,other.ora);
        }else
            ora = nullptr;
        tipPlata = other.tipPlata;
    }
    return *this;
}

//destructor
Programare::~Programare()
{
    delete[] data;
    delete[] ora;
}

//getters
Client Programare::getClient() const{
    return client;
}
Angajat Programare::getAngajat() const{
    return angajat;
}
Serviciu Programare::getServiciu() const{
    return serviciu;
}
const char* Programare::getData() const{
    return data;
}
const char* Programare::getOra() const{
    return ora;
}
TipPlata Programare::getTipPlata() const{
    return tipPlata;
}

//setters
void Programare::setData(const char* data)
{
    delete[] this->data;
    if(data){
        this->data = new char[strlen(data) + 1];
        strcpy(this->data,data);
    }else
        this->data = nullptr;
}
void Programare::setOra(const char* ora)
{
    delete[] this->ora;
    if(ora){
        this->ora = new char[strlen(ora) + 1];
        strcpy(this->ora,ora);
    }else
        this->ora = nullptr;
}
void Programare::setTipPlata(TipPlata tipPlata){
    this->tipPlata = tipPlata;
}

//functie pentru a afla cate programari are un client intr-o zi
int Programare::numaraProgramariClientZi(Programare programari[], int nrprog, const Client& client, const char* data){
    int nr = 0;    //contor
    for(int i = 0; i < nrprog; i++){       //nrprog il vom creste in main dupa fiecare programare realizata
        if(strcmp(programari[i].getData(), data) == 0 &&strcmp(programari[i].getClient().getNume(), client.getNume()) == 0
           &&strcmp(programari[i].getClient().getPrenume(), client.getPrenume()) == 0){            //compar data, nume, prenume din vectorul cu toate programarile cu datele unei anumite programari dintr-o zi
            nr++;                                 //daca gasesc, cresc contorul
        }
    }
    return nr;
}

float Programare::calcCostFinal(Programare programari[],int nrprog) const{                                   //calculez costul unei programari in urma reducerilor/surplusurilor adaugate
    float cost = serviciu.getPret();          //costul unei programari este costul serviciului
    if (angajat.areExperienta()){
        cost += 10;                 //daca angajatul are experienta >=5 ani, costul este mai mare cu 10 lei
    }
    if(strcmp(data,"11.09")==0){    //daca ziua programarii este in ziua deschiderii salonului, reducere 10%
        cost = cost - cost*0.10f;
    }
    if(tipPlata == CASH){           //daca este aleasa optiunea de a plati cash, se scad 2 lei din total
        cost = cost - 2;
    }

    if(numaraProgramariClientZi(programari,nrprog,client,data) >= 2){   //daca sunt mai mult de 2 programari intr-o zi
        cost = cost - cost*0.10f;                                             //de la acelasi client, reducere 10%
    }
    return cost;
}

float Programare::calcIncasariZi(Programare programari[], int nrprog, const char* data)
{                                               //calculez profitul dintr-o zi aleasa
    float suma = 0.0f;
    for(int i = 0; i<nrprog; i++){
        if(strcmp(programari[i].getData(), data) == 0){          //compar data aleasa cu datele tuturor programarilor
            suma += programari[i].calcCostFinal(programari,nrprog);   //adaug la suma costul final al programarii gasite
        }
    }
    return suma;
}

//operator <<
std::ostream& operator<<(std::ostream& os,const Programare& p)
{
    os<< "Client: "<<p.client<<", Angajat: "<< p.angajat<<", Serviciu: " << p.serviciu<< ", Data: " << (p.data)<<", Ora: " << (p.ora)
    << ", Tip plata: ";
    if(p.tipPlata == CASH)
        os << "CASH";
    else if(p.tipPlata == CARD)
        os << "CARD";
    else
        os << "TRANSFER";
    return os;
}
