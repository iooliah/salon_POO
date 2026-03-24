#ifndef ANGAJAT_H_INCLUDED
#define ANGAJAT_H_INCLUDED

#include <iostream>

class Angajat
{
private:
    char* nume;
    char* prenume;
    int experienta;
    float salariu;
    char* specializare;
    static int numarAngajati;

public:
    //constructor implicit
    Angajat();
    //constructor de initializare
    Angajat(const char* nume, const char* prenume, int experienta, float salariu, const char* specializare);

    //constructor de copiere
    Angajat(const Angajat& other);

    //operator
    Angajat& operator=(const Angajat& other);

    //destructor
    ~Angajat();

    //getters
    const char* getNume() const;
    const char* getPrenume() const;
    int getExperienta() const;
    float getSalariu() const;
    const char* getSpecializare() const;

    //setters
    void setNume(const char* nume);
    void setPrenume(const char* prenume);
    void setExperienta(int experienta);
    void setSalariu(float salariu);
    void setSpecializare(const char* specializare);

    bool areExperienta() const;
    float calcBonus(float procent) const;
    static void afiseazaTotalAngajati();

    friend std::ostream& operator<<(std::ostream& os, const Angajat& a);
};

#endif // ANGAJAT_H_INCLUDED
