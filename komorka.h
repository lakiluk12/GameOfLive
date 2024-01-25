#ifndef KOMORKA_H
#define KOMORKA_H


class komorka{
private:
    bool status_komorki;
public:
    komorka();
    void SetStatusKomorki(bool status){
        status_komorki = status;
    }
    bool GetStatusKomorki(){
        return status_komorki;
    }
};

#endif // KOMORKA_H
