#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct Samochod;
struct Silnik{
    short moc_m;
    unsigned short zuzycie_paliwa_m;
    Samochod* samochod;
    Silnik(){
    }
    Silnik(short moc, unsigned short zuzycie, Samochod& samochod1){
        moc_m=moc;
        zuzycie_paliwa_m=zuzycie;
        samochod=&samochod1;
    }
    string na_napis_silnik(){
        stringstream ss_silnik;
        ss_silnik << "\nMoc silnika: " << moc_m << "KM" <<  "\nZuzycie paliwa: " << zuzycie_paliwa_m << "L/100km";
        return ss_silnik.str();
    }
};
struct Samochod{
string marka_m;
int rok_produkcji_m;
Silnik silnik;
Samochod(){
}
Samochod(string marka, int rok_produkcji, short power, unsigned short fuel, Samochod& car){
    marka_m=marka;
    rok_produkcji_m=rok_produkcji;
    silnik=Silnik(power,fuel,car);
}
string na_napis_samochod(){
    stringstream ss_samochod;
    ss_samochod << "\nMarka: " << marka_m << "\nRok produkcji: " << rok_produkcji_m << "\nMoc silnika: " <<
    silnik.moc_m << "KM" << "\nZuzycie paliwa: " << silnik.zuzycie_paliwa_m << "L/100km" <<"\n";
    return ss_samochod.str();
}
};
int main() {
    Samochod samochod_test = Samochod("Opel",1990, 100, 8, samochod_test);
    cout << samochod_test.na_napis_samochod();
    cout << samochod_test.silnik.na_napis_silnik();
}
