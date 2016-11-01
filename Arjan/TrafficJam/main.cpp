/* 
 * File:   main.cpp
 * Author: arjan
 *
 * Created on 18 september 2016, 22:40
 */

#include <cstdlib>
#include <stdio.h>
#include "CAuto.h"
using namespace std;

const long int aantalIteraties = 10000000; 
const int aantalAutos = 10;
const double deltaT = 0.00001;     // seconde
const double beginSnelheid = 50.0;      // meter per seconde

const double reactietijd = 0.1;         // seconde
const double afstandTotVolgende = 30.0; // meter
               




void wagenInit (CAuto *iArray)
{
    for (int i=0; i<aantalAutos; i++)               // beginpositie en snelheid
        {
        iArray[i].plaats = -1*i*afstandTotVolgende;  // -1 zodat wagen[0] voorop rijdt
        iArray[i].snelheid = 50;   
        iArray[i].versnelling = 0;
        }
}

void verplaatsing(CAuto *iArray)
{
   
   
   for (int i=0; i<aantalAutos; i++)       // nieuwe plaats
            {
                iArray[i].plaats= iArray[i].plaats + deltaT*iArray[i].snelheid;
            } 

}
void nieuweSnelheid(CAuto *iArray)
{
    //iArray[0].versnelling = -1;
    //iArray[0].snelheid = iArray[0].snelheid + deltaT*iArray[0].versnelling;
    //if (iArray[0].snelheid < 0) iArray[0].snelheid = 0;
    for (int i=1; i<aantalAutos; i++)
    {
      if (iArray[i-1].plaats - iArray[i].plaats < 29)iArray[i].versnelling = -1;
      //if (iArray[i-1].plaats - iArray[i].plaats < 28)iArray[i].versnelling = -2;
      //if (iArray[i-1].plaats - iArray[i].plaats < 27)iArray[i].versnelling = -3;
      if (iArray[i-1].plaats - iArray[i].plaats > 29)iArray[i].versnelling =  0;
      if (iArray[i-1].plaats - iArray[i].plaats > 35)iArray[i].versnelling =  1;
      
      
    iArray[i].snelheid = iArray[i].snelheid + deltaT*iArray[i].versnelling;
    
    if (iArray[i].snelheid < 0) iArray[i].snelheid = 0;
    }
}

bool botsingCheck (CAuto *iArray)
{
    bool tgeenBotsing = true;
  
    
   for (int i=1; i<aantalAutos; i++)       // botsingcheck
            {
                if (iArray[i].plaats > iArray[i-1].plaats) 
                {
                    tgeenBotsing = false;
                   
                }
            }    
    return(tgeenBotsing);
}  


int main(int argc, char** argv) 
{
    bool geenBotsing = false; // hoofd loop uitschakelen.
    CAuto wagen[aantalAutos];
   
    wagenInit(wagen);
    wagen[0].rijden();
    wagen[0].testrit(deltaT);
   
    int t=0;
    while (geenBotsing && t < aantalIteraties)
    {
        verplaatsing(wagen);
        geenBotsing = botsingCheck(wagen);
        if (geenBotsing) {
            //if (t*deltaT > 10)wagen[0].versnelling = 0;  
           // if (t*deltaT < 10)wagen[0].versnelling = +1;
           // if (t*deltaT < 5)wagen[0].versnelling = -1;
          if (t*deltaT < 5)wagen[0].versnelling = -1;
            else { if (wagen[0].snelheid < 50)wagen[0].versnelling = 1;
                    else wagen[0].versnelling = 0;}  
            wagen[0].snelheid = wagen[0].snelheid + deltaT*wagen[0].versnelling;
            if (wagen[0].snelheid < 0) wagen[0].snelheid = 0;
            nieuweSnelheid(wagen);}
        t++;
        //printf("V: %g \n",wagen[1].snelheid);
    }    
       
    if(geenBotsing)printf("helaas geen BOEM \n");
    else printf("BOEM: %g \n",t*deltaT);
      printf("TIME: %g \n",t*deltaT);  
      
      for (int i=1; i<aantalAutos+1; i++){
      printf("Snelheid: %g \n",wagen[i-1].snelheid);
      printf("Versnelling: %g \n\n",wagen[i-1].versnelling);
      printf("Afstand: %g \n",wagen[i-1].plaats - wagen[i].plaats);
      }
    return 0;
}






/*
 * wagen[aantalAutos] = testArray(wagen);
   wagen[aantalAutos] = testArray(wagen);
 * CAuto testArray (CAuto iArray[])
{
    for(int i =0; i<aantalAutos; i++) 
    {
        printf ("%f \n", iArray[i].plaats);
        iArray[i].plaats +=1;
    }
   return (iArray[aantalAutos]);
}
void verpla??atsing(){
    float nieuweSnelheid;
    
    for (int i = 0; i< aantalAutos; i++){
       nieuweSnelheid = auto[i].snelheid + versnelling * deltaT; 
       auto[i].snelheid = nieuweSnelheid;
    }
}
 * auto[i].snelheid = 42;
 * auto[i].plaats = 3.1315926;
 * 
 * printf("%d " , i);      
        printf("hello world \n");
 * 
 *  CAuto mercedes(10.5,50.6);
    CAuto golf(8, 80);
    float dt=0.005;
    int i=0;
 * 
 * // for(int i=0;i<200;i++)
       // {
            mercedes.plaats=mercedes.plaats+dt*mercedes.snelheid;
            golf.plaats =golf.plaats+dt*golf.snelheid;
            if (golf.plaats>mercedes.plaats) {
                geenBotsing=false;
                printf("Boem");
            }
        
        i++;
       // }
        
 * 
 *  // printf("%d " , i); 
       //printf("%f  " , wagen[i].plaats); 
      //  printf("%f  " , wagen[i].snelheid); 
      //  printf("\n");
 * 
    //geenBotsing = false;
 * //printf("%d gb1" , geenBotsing);
 * // printf("%d \n" , t);
 * 
 * //printf("%f  " , wagen[1].plaats);
            //printf("%d gb2" , geenBotsing);
            } // botsing check}
 * 
 */

/*bool boemIsHo()
{
    bool geenBotsing = true;
    for (int i=1; i<aantalAutos; i++)       // botsingcheck
            {
                if (wagen[i].plaats > wagen[i-1].plaats) 
                {
                    geenBotsing = false;                    
                }                
            }
 return(geenBotsing);   
}   
    
*/

