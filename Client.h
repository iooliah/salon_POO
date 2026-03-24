#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <iostream>

class Client
{
private:
    char* nume;
    char* prenume;
    char* telefon;

    char istoric[100][100];
    int nrIstoric;
    static int numarClienti;

public:
    //constructor implicit
    Client();
    //constructor de initializare
    Client(const char* nume, const char* prenume, const char* telefon);

    //constructor de copiere
    Client(const Client& other);

    //operator
    Client& operator=(const Client& other);

    //destructor
    ~Client();

    //getters
    const char* getNume() const;
    const char* getPrenume() const;
    const char* getTelefon() const;
    int getNrIstoric() const;
    const char* getIstoricItem(int index) const;

    //setters
    void setNume(const char* nume);
    void setPrenume(const char* prenume);
    void setTelefon(const char* telefon);
    void adaugaIstoric(const char* procedura);

    bool esteFidel() const;
    static void afiseazaTotalClienti();

    friend std::ostream& operator<<(std::ostream& os, const Client& c);
};
#endif // CLIENT_H_INCLUDED
