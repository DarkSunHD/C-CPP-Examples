
/*
    A litte FIFO with pointer written in C

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



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct {
	uint8_t *read;
	uint8_t *write;
	size_t size;
	uint8_t *start;
	uint8_t *end;
	uint8_t data;
	uint8_t empty;
} FIFO;


FIFO uart_FIFO;


FIFO FIFO_setup(FIFO fifo, size_t size){
	fifo.size = size;
	fifo.start = malloc(fifo.size * sizeof(uint8_t));	//use 8 bit int
	fifo.end = fifo.start + size;
	fifo.write = fifo.start;
	fifo.read = fifo.start;
	return fifo;
}

FIFO FIFO_write(FIFO fifo, uint8_t data){
	if(fifo.write == fifo.end){
		if(fifo.read != fifo.start){
			fifo.write = fifo.start;
		}else{
			//FIFO full
			return fifo;
		}
	}else{
		if((fifo.write + 1) != fifo.read){	//other types 
			fifo.write = fifo.write + 1;
		}else{
			//FIFO full
			return fifo;
		}
	}
	*fifo.write = data;
	return fifo;
}


FIFO FIFO_read(FIFO fifo){
	if(fifo.read == fifo.end){
		if(fifo.write != fifo.end){
			fifo.read = fifo.start;
		}else{
			//FIFO empty
			fifo.empty = 1;
			return fifo;
		}
	}else{
		if(fifo.read != fifo.write){	//other types 
			fifo.read = fifo.read + 1;
		}else{
			//FIFO empty
			fifo.empty = 1;
			return fifo;
		}
	}
	fifo.data = *fifo.read;
	fifo.empty = 0;
	return fifo;
}


int main(int argc, char *argv[]){

	uart_FIFO = FIFO_setup(uart_FIFO, 16);
	printf("StartAddress = %u\n", uart_FIFO.start);
	printf("EndAddress = %u\n", uart_FIFO.end);

	printf("\n");

	uart_FIFO = FIFO_write(uart_FIFO, 5);
	printf("Write!       Adress: %u\n", uart_FIFO.write);
	uart_FIFO = FIFO_write(uart_FIFO, 6);
	printf("Write!       Adress: %u\n", uart_FIFO.write);
	uart_FIFO = FIFO_write(uart_FIFO, 7);
	printf("Write!       Adress: %u\n", uart_FIFO.write);
	uart_FIFO = FIFO_write(uart_FIFO, 8);
	printf("Write!       Adress: %u\n", uart_FIFO.write);
	uart_FIFO = FIFO_write(uart_FIFO, 360);
        printf("Write!       Adress: %u\n", uart_FIFO.write);


	printf("\n\n");

	uart_FIFO = FIFO_read(uart_FIFO);
	printf("Data: %d   Empty: %d       Adress: %u\n", uart_FIFO.data, uart_FIFO.empty, uart_FIFO.read);
	uart_FIFO = FIFO_read(uart_FIFO);
	printf("Data: %d   Empty: %d       Adress: %u\n", uart_FIFO.data, uart_FIFO.empty, uart_FIFO.read);
	uart_FIFO = FIFO_read(uart_FIFO);
	printf("Data: %d   Empty: %d       Adress: %u\n", uart_FIFO.data, uart_FIFO.empty, uart_FIFO.read);
	uart_FIFO = FIFO_read(uart_FIFO);
	printf("Data: %d   Empty: %d       Adress: %u\n", uart_FIFO.data, uart_FIFO.empty, uart_FIFO.read);
	uart_FIFO = FIFO_read(uart_FIFO);
	printf("Data: %d   Empty: %d       Adress: %u\n", uart_FIFO.data, uart_FIFO.empty, uart_FIFO.read);
	uart_FIFO = FIFO_read(uart_FIFO);
	printf("Data: %d   Empty: %d       Adress: %u\n", uart_FIFO.data, uart_FIFO.empty, uart_FIFO.read);

}
