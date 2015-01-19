
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
char getLetter(char digit, int letter){
	char output;
	switch(digit){
		case '2':
			switch(letter){
				case 0: output = 'A';break;
				case 1: output = 'B';break;
				case 2: output = 'C';break;
				default: break;
			}
			break;

		case '3':
			switch(letter){
				case 0: output = 'D';break;
				case 1: output = 'E';break;
				case 2: output = 'F';break;
				default: break;
			}
			break;

		case '4':
			switch(letter){
				case 0: output = 'G';break;
				case 1: output = 'H';break;
				case 2: output = 'I';break;
				default: break;
			}
			break;

			case '5':
				switch(letter){
					case 0: output = 'J';break;
					case 1: output = 'K';break;
					case 2: output = 'L';break;
					default: break;
				}
				break;

			case '6':
				switch(letter){
					case 0: output = 'M';break;
					case 1: output = 'N';break;
					case 2: output = 'O';break;
					default: break;
				}
				break;

			case '7':
				switch(letter){
					case 0: output = 'P';break;
					case 1: output = 'Q';break;
					case 2: output = 'R';break;
					case 3: output = 'S';break;
					default: break;
				}
				break;

			case '8':
				switch(letter){
					case 0: output = 'T';break;
					case 1: output = 'U';break;
					case 2: output = 'V';break;
					default: break;
				}
				break;

			case '9':
				switch(letter){
					case 0: output = 'W';break;
					case 1: output = 'X';break;
					case 2: output = 'Y';break;
					case 3: output = 'Z';break;
					default: break;
				}
				break;

			default: output = ' ';break;
	}
	return output;
}

std::vector<std::string> getWords(std::string input){
	std::vector<std::string> output;
	std::string buffer = "";
	int loop1 = 3;
	int loop2 = 3;
	int loop3 = 3;
	int loop4 = 3;
	int loop5 = 3;
	int loop6 = 3;
	int loop7 = 3;

	if(input[0] == '7' || input[0] == '9'){
		loop1 = 4;
	}
	if(input[1] == '7' || input[1] == '9'){
		loop2 = 4;
	}
	if(input[2] == '7' || input[2] == '9'){
		loop3 = 4;
	}
	if(input[3] == '7' || input[3] == '9'){
		loop4 = 4;
	}
	if(input[4] == '7' || input[4] == '9'){
		loop5 = 4;
	}
	if(input[5] == '7' || input[5] == '9'){
		loop6 = 4;
	}
	if(input[6] == '7' || input[6] == '9'){
		loop7 = 4;
	}


		for(int a = 0; a < loop1; a ++){
			for(int b = 0; b < loop2; b ++){
				for(int c = 0; c < loop3; c ++){
					for(int d = 0; d < loop4; d ++){
						for(int e = 0; e < loop5; e ++){
							for(int f = 0; f < loop6; f ++){
								for(int g = 0; g < loop7; g ++){
									buffer += getLetter(input[0], a);
									buffer += getLetter(input[1], b);
									buffer += getLetter(input[2], c);
									buffer += getLetter(input[3], d);
									buffer += getLetter(input[4], e);
									buffer += getLetter(input[5], f);
									buffer += getLetter(input[6], g);
									output.push_back(buffer);
									buffer = "";
								}
							}
						}
					}
				}
			}
		}
	return output;
}

int main(){
	std::string input;
	std::vector<std::string> output;
	std::ofstream outNumbers( "numbers.dat" );

	if ( !outNumbers ){
		std::cerr << "Unable to open numbers.dat\n";
	  exit( 1 );
	}

	std::cout << "Enter your seven digit phone number without dashes (Ex:3334444):";
	std::cin >> input;
	input = input.substr(0,7);
	std::cout << std::endl << "Phone Number: " << input.substr(0,3) << '-' << input.substr(3,4) << std::endl;

	output = getWords(input);
	int columns = 0;
	int words = 0;
	for(std::string word: output){
		if(columns < 10){
			outNumbers << word << " | ";
			columns ++;
		}
		else{
			outNumbers << word << std::endl;
			columns = 0;
		}
		words ++;
	}

	outNumbers.close();

	std::cout << words << " words generated";
	return 0;
}
