#ifndef SERVICIU_H_INCLUDED
#define SERVICIU_H_INCLUDED
#include <iostream>

class Serviciu
{
private:
    char* nume;
    float pret;
    bool avans;
    bool reducere10;
    int durata;
    char* locatie;

public:
    //constructor impicit
    Serviciu()
    //constructor de initializare
    Serviciu(const char* nume, float pret, bool avans, bool reducere10, int durata, const char* locatie);
    Serviciu(const Serviciu& other);                             //constructor de copiere
    Serviciu& operator=(const Serviciu& other);                  //operator
    ~Serviciu();                                                 //destructor


    //getters
    const char* getNume() const;
    float getPret() const;
    bool getAvans() const;
    bool getReducere10() const;
    int getDurata() const;
    const char* getLocatie() const;

    //setters
    void setNume(const char* nume);
    void setPret(float pret);
    void setAvans(bool avans);
    void setReducere10(bool reducere);
    void setDurata(int durata);
    void setLocatie(const char* locatie);

    float calcPretRedus(float procent) const;
    float calcAvans(float procent) const;

    friend std::ostream& operator<<(std::ostream& os, const Serviciu& s);
    friend std::istream& operator>>(std::istream& is, Serviciu& s);

};


#endif // SERVICIU_H_INCLUDED
