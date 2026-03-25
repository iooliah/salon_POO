#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <iostream>

class Client
{
private:
    char* nume;
    char* prenume;
    char* telefon;

    static int numarClienti;

public:
    //constructor implicit
    Client();
    //constructor de initializare
    Client(const char* nume, const char* prenume, const char* telefon);

    //constructor de copiere
    Client(const Client& other);

    //operator =
    Client& operator=(const Client& other);

    //destructor
    ~Client();

    //getters
    const char* getNume() const;
    const char* getPrenume() const;
    const char* getTelefon() const;

    friend std::ostream& operator<<(std::ostream& os, const Client& c);    //operator <<
};
#endif // CLIENT_H_INCLUDED
