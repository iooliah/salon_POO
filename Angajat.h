#ifndef ANGAJAT_H_INCLUDED
#define ANGAJAT_H_INCLUDED

#include <iostream>

class Angajat
{
private:
    char* nume;
    char* prenume;
    int experienta;
    char* specializare;          //pentru a putea face programarea in functie de ce poate face fiecare angajat
    static int numarAngajati;

public:
    Angajat();                                                                                //constructor implicit
    Angajat(const char* nume, const char* prenume, int experienta, const char* specializare); //constructor de initializare
    Angajat(const Angajat& other);                                                            //constructor de copiere
    Angajat& operator=(const Angajat& other);                                                 //operator =
    ~Angajat();                                                                               //destructor

    //getters
    const char* getNume() const;
    const char* getPrenume() const;
    int getExperienta() const;
    const char* getSpecializare() const;

    bool areExperienta() const;               //functie pt a putea creste pretul daca angajatul are mai multa experienta

    friend std::ostream& operator<<(std::ostream& os, const Angajat& a);
};

#endif  // ANGAJAT_H_INCLUDED
