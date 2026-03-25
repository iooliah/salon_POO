#ifndef PROGRAMARE_H_INCLUDED
#define PROGRAMARE_H_INCLUDED
#include <iostream>
#include "Client.h"
#include "Angajat.h"
#include "Serviciu.h"

enum TipPlata                    //enumerare de moduri de plata pt a putea oferi reducere la cash
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

    //operator =
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

    float calcCostFinal(Programare programari[],int nrprog) const;  //functie pentru a calcula cat trebuie sa plateasca un client dupa aplicarea reducerilor
    static int numaraProgramariClientZi(Programare programari[],int nrprog,const Client& client,const char* data);  //pt a afla daca clientul a avut mai multe programari intr-o zi pentru reducere
    static float calcIncasariZi(Programare programari[],int nrprog,const char* data);  //cat s-a castigat intr-o zi anume

    friend std::ostream& operator<<(std::ostream& os, const Programare& p);  //operator <<
};

#endif // PROGRAMARE_H_INCLUDED
