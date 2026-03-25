#ifndef SERVICIU_H_INCLUDED
#define SERVICIU_H_INCLUDED
#include <iostream>

class Serviciu
{
private:
    char* nume;
    float pret;
    int durata;

public:
    Serviciu();                                                  //constructor impicit
    Serviciu(const char* nume, float pret, int durata);          //constructor de initializare
    Serviciu(const Serviciu& other);                             //constructor de copiere
    Serviciu& operator=(const Serviciu& other);                  //operator =
    ~Serviciu();                                                 //destructor


    //getters
    const char* getNume() const;
    float getPret() const;
    int getDurata() const;

    friend std::ostream& operator<<(std::ostream& os, const Serviciu& s);
 //   friend std::istream& operator>>(std::istream& is, Serviciu& s);

};


#endif // SERVICIU_H_INCLUDED
