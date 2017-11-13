#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string.h>

using namespace std;


int checklvl(char czahl){
        switch(czahl){
                        case 'I':
                                //1
                                return 1;
                        break;
                        
                        case 'V':
                                //2
                                return 2;
                        break;

                        case 'X':
                                //3
                                return 3;
                        break;

                        case 'L':
                                //4
                                return 4;
                        break;

                        case 'C':
                                //5
                                return 5;
                        break;

                        case 'D':
                                //6
                                return 6;
                        break;

                        case 'M':
                                //7
                                return 7;
                        break;
                }
}


int main(int argc, char* argv[]) {
        printf("Hallo ich bin ein Wandler der römische Zahlen in decimale Zahlen wandelt!\n\n");

        char czahl[128];
        printf("Römische Zahl eingeben: ");
        int scanerr = scanf("%s",czahl);

        printf("\n\n");
        
        if(scanerr != 1){
                printf("Fehler beim einlesen!\n");
                return 0;
        }

        

        char cromseq[128];
        int ii = -1;
        
        for(int i = 0; i < strlen(czahl); i++){

                czahl[i] = toupper(czahl[i]);
                
                switch(czahl[i]){
                        case 'I':
                                //1
                                ii++;
                                cromseq[ii] = czahl[i];
                        break;
                        
                        case 'V':
                                //5
                                ii++;
                                cromseq[ii] = czahl[i];
                        break;

                        case 'X':
                                //10
                                ii++;
                                cromseq[ii] = czahl[i];
                        break;

                        case 'L':
                                //50
                                ii++;
                                cromseq[ii] = czahl[i];
                        break;

                        case 'C':
                                //100
                                ii++;
                                cromseq[ii] = czahl[i];
                        break;

                        case 'D':
                                //500
                                ii++;
                                cromseq[ii] = czahl[i];
                        break;

                        case 'M':
                                //1000
                                ii++;
                                cromseq[ii] = czahl[i];
                        break;
                }
        }

       
        for(int i = ii + 1; i < strlen(cromseq); i++){
                cromseq[i] = ' ';
        }


         for(int i = 0; i < strlen(cromseq); i++){

                 if(cromseq[i] != ' '){
                 int curlvl = checklvl(cromseq[i]);
                 if(i > 1){
                         //printf("Cur lvl %d \n ", curlvl);
                         if(curlvl > checklvl(cromseq[i-1]) && curlvl > checklvl(cromseq[i-2])){
                                 printf("\nFehler, gegebene Zahl ist keine legitime römische Zahl\n\n");
                                 return 0;
                         }
                
                 }
                 }
         }

         

         printf("Die römische Zahl lautet:  %s \n", cromseq);

        int lvl = 7;
        int len =  strlen(cromseq) - 1;
        int buf = 0;
        
         for(int i = 0; i <= len; i++){
                
                switch(cromseq[i]){
                        case 'I':
                                //1 -> lvl 1
                               if(lvl > 1 && i < len){
                                        int tmplvl = checklvl(cromseq[i + 1]);
                                        if(tmplvl > 1){
                                                buf = buf - 1;
                                        }else{
                                                buf = buf + 1;
                                        }
                                }else{
                                        buf = buf + 1;
                                }
                        break;
                        
                        case 'V':
                                //5 -> lvl 2
                                if(lvl > 2 && i < len){
                                        int tmplvl = checklvl(cromseq[i + 1]);
                                        if(tmplvl > 2){
                                                buf = buf - 5;
                                        }else{
                                                buf = buf + 5;
                                        }
                                }else{
                                        buf = buf + 5;
                                }
                                
                        break;

                        case 'X':
                                //10 -> lvl 3
                                if(lvl > 3 && i < len){
                                        int tmplvl = checklvl(cromseq[i + 1]);
                                        if(tmplvl > 3){
                                                buf = buf - 10;
                                        }else{
                                                buf = buf + 10;
                                        }
                                }else{
                                        buf = buf + 10;
                                }
                        break;

                        case 'L':
                                //50 -> lvl 4
                                if(lvl > 4 && i < len){
                                        int tmplvl = checklvl(cromseq[i + 1]);
                                        if(tmplvl > 4){
                                                buf = buf - 50;
                                        }else{
                                                buf = buf + 50;
                                        }
                                }else{
                                        buf = buf + 50;
                                }
                        break;

                        case 'C':
                                //100 -> lvl 5
                                if(lvl > 5 && i < len){
                                        int tmplvl = checklvl(cromseq[i + 1]);
                                        if(tmplvl > 5){
                                                buf = buf - 100;
                                        }else{
                                                buf = buf + 100;
                                        }
                                }else{
                                        buf = buf + 100;
                                }
                        break;

                        case 'D':
                                //500 -> lvl 6
                                if(lvl > 6 && i < len){
                                        int tmplvl = checklvl(cromseq[i + 1]);
                                        if(tmplvl > 6){
                                                buf = buf - 500;
                                        }else{
                                                buf = buf + 500;
                                        }
                                }else{
                                        buf = buf + 500;
                                }
                        break;

                        case 'M':
                                //1000 -> lvl 7
                                buf = buf + 1000;
                        break;
                }
        }

         printf("Die decimal Zahl lautet: %d \n\n", buf);
        return 0;
}
