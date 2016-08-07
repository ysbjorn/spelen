#ifndef CScrollKrant_H
#define CScrollKrant_H

#include <Arduino.h>

class CScrollKrant {
  public:
    CScrollKrant(const String iTekst, const int iSchermLengte, const int iDelay, const int iSpaties);

    void setNieuweTekst(const String iTekst);

    String getTekst() const;
    String getVolgende();

    int getIndex() const { return deIndex;}
    void setIndex(const int iIndex) { deIndex=iIndex;}

    int getVertraging() const {return deVertraging;}

    bool getVoorwaarts() const {return deVoorwaarts;}
    void setVoorwaarts(bool iVoorwaarts) {deVoorwaarts = iVoorwaarts;}

    int getVersnelling() const {return deVersnelling;}
    void setVersnelling(int iVersnelling) {deVersnelling = iVersnelling;}

    bool versnel();
    bool vertraag();

    String getScrollTekst() { return deScrollTekst;}
    String getDeTekst() {return deTekst;}

 private:
    String deTekst;
    int deSchermLengte;
    int deVertraging; //millisecs
    int deSpaties;
    String deScrollTekst;
    int deTekstLengte;
    int deIndex;
    bool deVoorwaarts;
    int deVersnelling;
};

#endif

