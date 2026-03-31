/*Tema aleasa: Salon de infrumusetare

Date de intrare:
- numele si prenumele clientului
- serviciul ales
- data si ora programarii
- angajatul ales
- tipul de plata

Operatii posibile:
- cautarea unui client existent
- realizarea unei programari
- afisarea angajatilor disponibili pentru un serviciu
- calculul incasarilor dintr-o zi
- calculul sumei pe care trebuie sa o plateasca un client intr-o zi
- calcul reduceri*/

#include <iostream>
#include <cstring>
#include "Client.h"
#include "Angajat.h"
#include "Serviciu.h"
#include "Programare.h"

//functie care verifica daca un angajat cu o anumita specializare este valabil la o ora+data aleasa
bool angajatDisponibil(const Programare programari[], int nrprog, const Angajat& angajat, const char* data, const char* ora){
    for(int i = 0; i < nrprog; i++) {
        if(std::strcmp(programari[i].getData(),data)==0 && std::strcmp(programari[i].getOra(),ora)==0 &&
            std::strcmp(programari[i].getAngajat().getNume(), angajat.getNume())==0 && std::strcmp(programari[i].getAngajat().getPrenume(),angajat.getPrenume())==0){
            return false;    //daca se gaseste o programare existenta care are aceeasi data,ora si angajat(nume,prenume), atunci nu este valabil pentru o alta programare
        }
    }
    return true;
}

int main()
{                                                   //introduc clienti, angajati, servicii deja existente
    Client clienti[] ={
        Client("Toader", "Ana", "0712345678"),
        Client("Belceanu", "Maria", "0798765432"),
        Client("Boros", "Eliza", "0701928356")
    };
    Angajat angajati[] ={
        Angajat("Vladescu", "Ioana", 6, "manichiura"),
        Angajat("Barbu", "Eric", 2, "coafor"),
        Angajat("Trandafir", "Dana", 8, "coafor")
    };

    Serviciu servicii[] ={
        Serviciu("manichiura", 120, 60),
        Serviciu("coafor", 50, 30),
        Serviciu("tratamente", 100, 25)
    };

    Programare programari[100];            //creez vectorul care sa mentina toate programarile pe durata unei rulari
    int nrprog = 0;                        //pentru a tine cont de total
    const int nrclienti = 3, nrangajati = 3, nrservicii = 3;

    char continua = 'd';                   //pentru raspunsul da, daca este aleasa optiunea pozitiva, continua
    do{
        char nume[20], prenume[30], data[11], ora[6];
        int optiuneServiciu, optiuneAngajat, optiunePlata;

        Client* gasit = nullptr;
        Serviciu* serviciuales = nullptr;
        Angajat* angajatbun[10];

        std::cout << "Introdu numele clientului: ";             //cer nume, prenume pt programare
        std::cin >> nume;
        std::cout << "Introdu prenumele clientului: ";
        std::cin >> prenume;

        //caut clientul printre cei existenti
        for(int i = 0; i < nrclienti; i++){
            if(std::strcmp(clienti[i].getNume(), nume) == 0 && std::strcmp(clienti[i].getPrenume(), prenume) == 0) {
                gasit = &clienti[i];
                break;
            }
        }
        if(gasit == nullptr){                                             //daca nu exista, intreb daca mai vrea sa incerce o data
            std::cout << "Clientul nu exista.\n";
            std::cout << "Vrei sa mai adaugi o programare? (d/n): ";
            std::cin >> continua;                         //daca da, continua, de nu, iese din do while
            continue;
        }

        std::cout << "\nAlege serviciul:\n";
        for(int i = 0; i < nrservicii; i++){
            std::cout << i+1 << ". " << servicii[i] << '\n';
        }
        std::cin >> optiuneServiciu;

        //caut prin serviciile existente
        if(optiuneServiciu<1 || optiuneServiciu>nrservicii){
            std::cout << "Serviciu invalid.\n";
            std::cout << "Vrei sa mai adaugi o programare? (d/n): ";
            std::cin >> continua;
            continue;
        }
        serviciuales = &servicii[optiuneServiciu - 1];

        std::cout << "Introdu data: ";                  //cer data si ora
        std::cin >> data;
        std::cout << "Introdu ora: ";
        std::cin >> ora;

        //afisez doar angajatii care au specializarea buna si sunt liberi
        //optiunile bune le pun intr-un vector (trebuie sa aiba specializarea aleasa de client)
        int nrangajatbun = 0;          //index
        for(int i = 0; i < nrangajati; i++){
            if(std::strcmp(angajati[i].getSpecializare(), serviciuales->getNume()) == 0 && angajatDisponibil(programari, nrprog, angajati[i], data, ora)){
                angajatbun[nrangajatbun++] = &angajati[i];
            }
        }

        if(nrangajatbun==0){   //daca nu exista nicio varianta, mai intreb o data daca vrea sa mai incerce
            std::cout << "Nu exista niciun angajat disponibil pentru serviciul ales la data si ora introduse.\n";
            std::cout << "Vrei sa mai adaugi o programare? (d/n): ";
            std::cin >> continua;
            continue;
        }

        std::cout << "\nAngajatii disponibili sunt:\n";
        for(int i = 0; i < nrangajatbun; i++){                           //afisez din vector optiunile valabile
            std::cout << i + 1 << ". " << *angajatbun[i] <<std::endl;
        }

        std::cout << "Alege angajatul: ";                                //cer sa se aleaga din nou
        std::cin >> optiuneAngajat;
        if(optiuneAngajat<1 || optiuneAngajat>nrangajatbun){             //daca e ales ceva ce nu exista, dau eroare
            std::cout << "Optiune invalida.\n";
            std::cout << "Vrei sa mai adaugi o programare? (d/n): ";
            std::cin >> continua;
            continue;
        }

        std::cout << "Tip plata (0 = CASH, 1 = CARD, 2 = TRANSFER): ";     //alegere metoda de plata
        std::cin >> optiunePlata;
        if(optiunePlata < 0 || optiunePlata > 2){                          //dau eroare daca nu exista varianta aleasa
            std::cout << "Tip de plata invalid.\n";
            std::cout << "Vrei sa mai adaugi o programare? (d/n): ";
            std::cin >> continua;
            continue;
        }

        programari[nrprog++] = Programare(*gasit, *angajatbun[optiuneAngajat - 1],*serviciuales,data,ora,(TipPlata)optiunePlata);  //salvez programarea si o adaug in istoric
        //asa pot tine seama de ea pt viitoarele programari

        std::cout << "\nProgramarea a fost adaugata.\n";
        std::cout << programari[nrprog-1] << std::endl;    //afisez datele programarii realizate

        std::cout << "\nVrei sa mai adaugi o programare? (d/n): ";
        std::cin >> continua;

    }while((continua == 'd') && nrprog<100);               //cat timp raspund cu da

    char rasp;
    std::cout << "\nVrei sa vezi cati bani s-au facut intr-o zi? (d/n): ";     //afisez functia calcIncasareZi
    std::cin >> rasp;
    if(rasp == 'd'){
        char zic[11];                     //intreb ziua de interes
        std::cout << "Introdu ziua: ";
        std::cin >> zic;
        std::cout << "Incasarile din ziua " << zic << " sunt: " << Programare::calcIncasariZi(programari, nrprog, zic)<< " lei.\n";
    }


    std::cout << "\nVrei sa afli cat trebuie sa plateasca un client intr-o zi? (d/n): "; //cu tot cu toate reducerile posibile si multiple programari
    std::cin >> rasp;
    if(rasp == 'd'){
        char numec[20],prenumec[30],zic[11];
        float total = 0;

        std::cout << "Introdu numele clientului: ";
        std::cin >> numec;
        std::cout << "Introdu prenumele clientului: ";
        std::cin >> prenumec;
        std::cout << "Introdu ziua: ";
        std::cin >> zic;

        for(int i = 0; i < nrprog; i++){
            if(std::strcmp(programari[i].getData(),zic) == 0 && std::strcmp(programari[i].getClient().getNume(), numec) == 0
               &&std::strcmp(programari[i].getClient().getPrenume(),prenumec) == 0){
                total += programari[i].calcCostFinal(programari, nrprog);
            }
        }
        std::cout << "Clientul trebuie sa plateasca: " << total << " lei.\n";
    }

    std::cout << "\nMultumim ca ati ales salonul nostru! Echipa noastra de "<< nrangajati << " angajati pune zambetul pe "<< nrclienti << " fete!\n";
    return 0;
}
