/*
 * tortoiseHare.cpp
 *  Week 8: 8.12
 *   Created on: Mar 5, 2014
 *    Author: Grayson Lorenz
 */
#include <iostream>
#include <cstdlib>

void moveTortoise(char *, char *);
void moveHare(char *, char *);
void resetPointer(char *, char *);

int main(){

	srand(time(0));
	char line[70];
	char * race = line;

	for(int i = 0; i < 70; i++){ // set blank line
		line[i] = '-';
	}

	line[0] = 'O'; // place both at start of line

	std::cout << "READY!\nSET!!\nGO!!!" << std::endl;

	for(int i = 0; i < 70; i++){ // print first line of race
		switch(race[i]){
			case '-': std::cout << "-";
				break;
			case 'H': std::cout << "H";
				break;
			case 'T': std::cout << "T";
				break;
			case 'O': std::cout << "OUCH!!";
				break;
		}
	}

	std::cout << std::endl;

	while(race[69] == '-'){ // do the race
		resetPointer(race, line);
		moveTortoise(race, line);

		resetPointer(race, line);
		moveHare(race, line);

		resetPointer(race, line);

		for(int i = 0; i < 70; i++){
			switch(race[i]){
				case '-': std::cout << "-";
					break;
				case 'H': std::cout << "H";
					break;
				case 'T': std::cout << "T";
					break;
				case 'O': std::cout << "OUCH!!";
					break;
			}
		}

		std::cout << std::endl;
	}

	switch(race[69]){ // declare winner
		case 'O': std::cout << "IT'S A TIE!"; break;
		case 'T': std::cout << "TORTOISE WINS!!"; break;
		case 'H': std::cout << "HARE WINS!!"; break;
	}
	// ????
	// profit
	return 0;
}

void moveTortoise(char * race, char * line){
	int chance = rand()%10;
	chance ++;
	for( ; *race != 'O' && *race != 'T' && race <= line + 69; race++){

	}

	if(chance >= 1 && chance <= 5){ // move forward 3 50% of the time
		switch(*race){
			case 'T': *race = '-'; break;
			case 'O': *race = 'H'; break;
		}

		for(int i = 0; i < 3 && race != line + 69; i ++){
			race ++;
		}

		switch(*race){
			case 'H': *race = 'O'; break;
			case '-': *race = 'T'; break;
		}
	}

	if(chance >= 6 && chance <=7){ // move back 6 20% of the time
		switch(*race){
			case 'T': *race = '-'; break;
			case 'O': *race = 'H'; break;
		}

		for(int i = 0; i < 6 && race != line + 0; i ++){
			race --;
		}

		switch(*race){
			case 'H': *race = 'O'; break;
			case '-': *race = 'T'; break;
		}
	}

	if(chance >= 8 && chance <=10){ // move forward 1 30% of the time
		switch(*race){
			case 'T': *race = '-'; break;
			case 'O': *race = 'H'; break;
		}

		for(int i = 0; i < 1 && race != line + 69; i ++){
			race ++;
		}

		switch(*race){
			case 'H': *race = 'O'; break;
			case '-': *race = 'T'; break;
		}
	}
}

void moveHare(char * race, char * line){
	int chance = rand()%10;
	chance ++;
	for( ; *race != 'O' && *race != 'H' && race <= line + 69; race++){
	}

	if(chance >= 1 && chance <= 3){ // move forward 1 30% of the time
		switch(*race){
			case 'H': *race = '-'; break;
			case 'O': *race = 'T'; break;
		}

		for(int i = 0; i < 1 && race != line + 69; i ++){
			race ++;
		}

		switch(*race){
			case 'T': *race = 'O'; break;
			case '-': *race = 'H'; break;
		}
	}

	if(chance >= 4 && chance <= 5){ // move forward 9 20% of the time
		switch(*race){
				case 'H': *race = '-'; break;
				case 'O': *race = 'T'; break;
			}

		for(int i = 0; i < 9 && race != line + 69; i ++){
			race ++;
		}

		switch(*race){
			case 'T': *race = 'O'; break;
			case '-': *race = 'H'; break;
		}
	}

	if(chance >= 6 && chance <= 7){ // move back 2 20% of the time
		switch(*race){
			case 'H': *race = '-'; break;
			case 'O': *race = 'T'; break;
		}

		for(int i = 0; i < 2 && race != line + 0; i ++){
			race --;
		}

		switch(*race){
			case 'T': *race = 'O'; break;
			case '-': *race = 'H'; break;
		}
	}

	if(chance == 8){ // move back 10 10% of the time
		switch(*race){
			case 'H': *race = '-'; break;
			case 'O': *race = 'T'; break;
		}

		for(int i = 0; i < 10 && race != line + 0; i ++){
			race --;
		}

		switch(*race){
			case 'T': *race = 'O'; break;
			case '-': *race = 'H'; break;
		}
	}
}

void resetPointer(char * line, char * race){
	while(race < line){
		race --;
	}
}
