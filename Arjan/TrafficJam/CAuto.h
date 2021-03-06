/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CAuto.h
 * Author: arjan
 *
 * Created on 19 september 2016, 17:24
 */

#ifndef CAUTO_H
#define CAUTO_H

class CAuto {
public:
    CAuto();
    CAuto(double iplaats, double isnelheid, double iversnelling, double ilengte);
    CAuto(const CAuto& orig);
    virtual ~CAuto();
    double plaats;
    double snelheid;
    double versnelling;
    double lengte;
    
    void beginpositie(int iautonummer);
    void snelheidVeranderen(double ideltaT);
    void verplaatsing(double ideltaT);
    bool botsing(CAuto& iother);
private:

};

#endif /* CAUTO_H */

