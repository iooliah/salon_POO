#ifndef PROGRAMARE_H_INCLUDED
#define PROGRAMARE_H_INCLUDED
#include <iostream>

#include "Client.h"
#include "Angajat.h"
#include "Serviciu.h"

enum TipPlata
{
    CASH,
    CARD,
    TRANSFER
};

class Programare
{
private:
    Client client;
    Angajat angajat;
    Serviciu serviciu;

    char* data;
    char* ora;
    TipPlata tipPlata;
    char* produseRecomandate;

public:
    //constructor implicit
    Programare();
    //constructor de initializare
    Programare(const Client& client, const Angajat& angajat, const Serviciu& serviciu,
               const char* data, const char* ora, TipPlata tipPlata,
               const char* produseRecomandate);

    //constructor de copiere
    Programare(const Programare& other);

    //operator
    Programare& operator=(const Programare& other);

    //destructor
    ~Programare();

    //get-eri
    Client getClient() const;
    Angajat getAngajat() const;
    Serviciu getServiciu() const;
    const char* getData() const;
    const char* getOra() const;
    TipPlata getTipPlata() const;
    const char* getProduseRecomandate() const;

    //set-eri
    void setData(const char* data);
    void setOra(const char* ora);
    void setTipPlata(TipPlata tipPlata);
    void setProduseRecomandate(const char* produse);


    float calcCostFinal() const;
    bool esteUrgenta() const;

    friend std::ostream& operator<<(std::ostream& os, const Programare& p);
};



#endif // PROGRAMARE_H_INCLUDED
