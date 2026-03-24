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

class Programare{
private:
    Client client;
    Angajat angajat;
    Serviciu serviciu;
    char* data;
    char* ora;
    TipPlata tipPlata;

public:
    //constructor implicit
    Programare();
    //constructor de initializare
    Programare(const Client& client, const Angajat& angajat, const Serviciu& serviciu,
               const char* data, const char* ora, TipPlata tipPlata);

    //constructor de copiere
    Programare(const Programare& other);

    //operator
    Programare& operator=(const Programare& other);

    //destructor
    ~Programare();

    //getters
    Client getClient() const;
    Angajat getAngajat() const;
    Serviciu getServiciu() const;
    const char* getData() const;
    const char* getOra() const;
    TipPlata getTipPlata() const;

    //setters
    void setData(const char* data);
    void setOra(const char* ora);
    void setTipPlata(TipPlata tipPlata);

    float calcCostFinalCuReduceri(Programare programari[],int nrProgramari) const;

    static int numaraProgramariClientInZi(Programare programari[],int nrProgramari,const Client& client,const char* data);
    static float calcIncasariZi(Programare programari[],int nrProgramari,const char* data);

    friend std::ostream& operator<<(std::ostream& os, const Programare& p);
};

#endif // PROGRAMARE_H_INCLUDED
