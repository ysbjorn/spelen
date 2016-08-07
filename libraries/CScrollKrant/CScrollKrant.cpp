#include <Arduino.h>
#include <CScrollKrant.h>

//constructor
CScrollKrant::CScrollKrant(const String iTekst, const int iSchermLengte, const int iDelay, const int iSpaties) {
  deTekst = iTekst;
  deSchermLengte = iSchermLengte;
  deVertraging = iDelay;
  deSpaties = iSpaties;
  deScrollTekst = deTekst;
  deVoorwaarts = true;
  for (int i=0; i<deSpaties; i++) {
    deScrollTekst.concat(" ");
  }
  deTekstLengte = deScrollTekst.length();
  deIndex = 0;
  deVersnelling = 10;//millisecs
}

void CScrollKrant::setNieuweTekst(const String iTekst) {
  deTekst = iTekst;
  deIndex = 0;
  deScrollTekst = deTekst;
  for (int i=0; i<deSpaties; i++) {
    deScrollTekst.concat(" ");
  }
}

String CScrollKrant::getTekst() const{
  String tmpTekst;
  if (deIndex < deTekstLengte-16 ) {
    tmpTekst = deScrollTekst.substring(deIndex, deIndex+16);
  } else {
    tmpTekst = deScrollTekst.substring(deIndex);
    int tmpRestant = 16-tmpTekst.length();
    String tmpRestantTekst = deScrollTekst.substring(0, tmpRestant);
    tmpTekst.concat(tmpRestantTekst);
  }
  return tmpTekst;
}

String CScrollKrant::getVolgende(){
  if (deVoorwaarts) {
    deIndex++;
    if (deIndex >= deTekstLengte) {
      deIndex = 0;
    }
  } else {
    deIndex--;
    if (deIndex<0) {
      deIndex = deTekstLengte-1;
    }
  }
  return getTekst();
}

bool CScrollKrant::versnel() {
  deVertraging = deVertraging - deVersnelling;
  if (deVertraging < 0) {
    deVertraging = 0;
    return false;
  } else {
    return true;
  }
}

bool CScrollKrant::vertraag() {
  deVertraging = deVertraging + deVersnelling;
  if (deVertraging>800) {
    deVertraging = 800;
    return false;
  } else {
    return true;
  }
}

