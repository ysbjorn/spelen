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
}

CAuto::CAuto(double iplaats, double isnelheid, double iversnelling){
    plaats=iplaats;
    snelheid=isnelheid;
    versnelling=iversnelling;
}
void CAuto::rijden(){
    printf("yippie \n");
 
}

void CAuto::testrit(double ideltaT)
{ snelheid = 16+snelheid + ideltaT*versnelling;
}

CAuto::CAuto(const CAuto& orig) {
    printf("Warning... copy constructor not implemented!! zegt Krista");
}

CAuto::~CAuto() {
}

