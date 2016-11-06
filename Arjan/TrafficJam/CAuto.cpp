/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CAuto.cpp
 * Author: arjan
 * 
 * Created on 19 september 2016, 17:24
 */
#include <stdio.h>
#include "CAuto.h"

CAuto::CAuto() {
    printf("Calling default constructor... zegt Krista \n");
   }

CAuto::CAuto(const CAuto& orig) {
    printf("Warning... copy constructor not implemented!! zegt Krista \n");
}

CAuto::~CAuto() {
    printf("Warning... virtual constructor not implemented!! zegt Krista \n");
}


const double beginSnelheid = 50.0;      // meter per seconde
const double afstandTotVolgende = 30.0; // meter
const double autolengte = 3.0;          // meter



CAuto::CAuto(double iplaats, double isnelheid, double iversnelling, double ilengte)
{
    plaats=iplaats;
    snelheid=isnelheid;
    versnelling=iversnelling;
    lengte=ilengte;
}
void CAuto::beginpositie(int iautonummer)
{
    plaats = -1*iautonummer*afstandTotVolgende;
    snelheid = beginSnelheid;
    lengte = autolengte;
    versnelling = 0;
    printf(" %d \n",iautonummer);
}

void CAuto::snelheidVeranderen(double ideltaT)
{
    snelheid = snelheid + ideltaT*versnelling;    
}

void CAuto::verplaatsing(double ideltaT)
{ 
    plaats = plaats + snelheid*ideltaT;
}

bool CAuto::botsing(CAuto& iother)
{
  bool tBotsing = false;

    if (iother.plaats > plaats) 
                {
                    tBotsing = true;
                }
    return tBotsing;
}

//double CAuto/::afstand(CAuto& iOther) {
  //  return iOther.plaats-plaats;
//}



