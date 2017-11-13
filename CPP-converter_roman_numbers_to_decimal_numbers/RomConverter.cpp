/*
    This program converts roman numbers to decimal numbers

    Copyright (C) 2017  Hold Alexander

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/


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
        printf("Hello I convert roman numbers to decimal numbers\n\n");

        char czahl[128];
        printf("Enter roman number: ");
        int scanerr = scanf("%s",czahl);

        printf("\n\n");
        
        if(scanerr != 1){
                printf("Error (read input)!\n");
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
                                 printf("\nError, the input is not a legit roman number!\n\n");
                                 return 0;
                         }
                
                 }
                 }
         }

         

         printf("The roman number:  %s \n", cromseq);

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

         printf("The decimal number: %d \n\n", buf);
        return 0;
}
