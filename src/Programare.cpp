#include "Programare.h"
#include <cstring>

//constructor implicit
Programare::Programare()
{
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

//metode

int Programare::numaraProgramariClientInZi(Programare programari[],int nrProgramari,const Client& client,const char* data)
{
    int nr = 0;
    for(int i = 0; i < nrProgramari; i++){
        if(strcmp(programari[i].getData(),data) == 0 &&
           strcmp(programari[i].getClient().getNume(),client.getNume()) == 0 &&
           strcmp(programari[i].getClient().getPrenume(),client.getPrenume()) == 0){
            nr++;
        }
    }
    return nr;
}

float Programare::calcCostFinalCuReduceri(Programare programari[],int nrProgramari) const
{
    float cost = serviciu.getPret();
    if(client.esteFidel()){
        cost = cost - cost * 0.02f;
    }
    if(strcmp(data,"11.09")==0){
        cost = cost - cost * 0.10f;
    }
    if(tipPlata == CASH){
        cost = cost - 2;
    }


    int nr = numaraProgramariClientInZi(programari,nrProgramari,client,data);
    if(nr >= 2){
        cost = cost - cost *0.10f;
    }
    return cost;
}

float Programare::calcIncasariZi(Programare programari[],int nrProgramari,const char* data)
{
    float suma = 0.0f;
    for(int i = 0; i < nrProgramari; i++){
        if(strcmp(programari[i].getData(), data) == 0){
            suma += programari[i].calcCostFinalCuReduceri(programari,nrProgramari);
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
