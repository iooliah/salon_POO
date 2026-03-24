#ifndef SERVICIU_H_INCLUDED
#define SERVICIU_H_INCLUDED
#include <iostream>

class Serviciu
{
private:
    char* nume;
    float pret;
    bool reducere10;
    int durata;

public:
    //constructor impicit
    Serviciu()
    //constructor de initializare
    Serviciu(const char* nume, float pret,bool reducere10, int durata);
    Serviciu(const Serviciu& other);                             //constructor de copiere
    Serviciu& operator=(const Serviciu& other);                  //operator
    ~Serviciu();                                                 //destructor


    //getters
    const char* getNume() const;
    float getPret() const;
    bool getReducere10() const;
    int getDurata() const;

    //setters
    void setNume(const char* nume);
    void setPret(float pret);
    void setReducere10(bool reducere);
    void setDurata(int durata);

    float calcPretRedus(float procent) const;

    friend std::ostream& operator<<(std::ostream& os, const Serviciu& s);
    friend std::istream& operator>>(std::istream& is, Serviciu& s);

};


#endif // SERVICIU_H_INCLUDED
