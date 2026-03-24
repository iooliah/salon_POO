#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
#include <iostream>

class Client
{
private:
    char* nume;
    char* prenume;
    char* telefon;
    char* email;
    char* gen;
    int varsta;
    char** istoric;   //???
    int nrIstoric;
    static int numarClienti;

public:
    //constructor implicit
    Client();
    //constructor de initializare
    Client(const char* nume, const char* prenume, const char* telefon,
           const char* email, const char* gen, int varsta);

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
    const char* getEmail() const;
    const char* getGen() const;
    int getVarsta() const;

    //setters
    void setNume(const char* nume);
    void setPrenume(const char* prenume);
    void setTelefon(const char* telefon);
    void setEmail(const char* email);
    void setGen(const char* gen);
    void setVarsta(int varsta);

    void adaugaIstoric(const char* procedura);

    bool esteMajor() const;
    bool esteFidel() const;
    float calcDiscountFidelitate() const;
    static void afiseazaTotalClienti();

    friend std::ostream& operator<<(std::ostream& os, const Client& c);
};
#endif // CLIENT_H_INCLUDED
