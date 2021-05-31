#include <iostream>
#include <fstream>
#include "tree.hpp"
#include "helptoip.hpp"
#include <string.h>
#include <sstream>
int operator-(const std::string& str1, const std::string& str2){
	return strcmp(str1.c_str(),str2.c_str());
}

Node<int, std::string> Print(Node<int, std::string> elem){
	std::cout << elem.key << " " << inttoip(elem.value)  << std::endl;
	return elem;
}

void help(){
	std::cout << "add [sitename] [ip] - for add site in database" <<std::endl;
	std::cout << "delete [sitename] - for delete site in database" <<std::endl;
	std::cout << "find [arg] -for search in database " << std::endl;
	std::cout << "list -for print database" << std::endl;
	std::cout << "help -for this massage" << std::endl;
	std::cout << "q - for exit" << std::endl;
}

int main(int argc, char ** argv){
	Tree<int, std::string> IP;
	bool exist = false;
	char Buffer[1024];
	std::ifstream ins("database.db");
	if(!ins.is_open()){
		std::cout << "File not found" << std::endl;
	} else {
		while(!ins.eof()){
			std::string sitename;
			std::string ipstr;
			ins >> sitename;
			ins >> ipstr;
			IP.addNode(sitename, iptoint(ipstr.c_str()));
		}
		ins.close();
	}
	while(!exist){
			std::cout << "Enter command" << std::endl;
			std::cin.getline(Buffer,1024);
			std::stringstream stream;
			stream << Buffer;
			std::string funct;
			stream >> funct;
			if(funct == "find"){
				std::string param;
				stream >> param;
				Node<int,std::string> * ptr = IP.foundNode(param);
				if(ptr){
					std::cout << ptr->key << " " << inttoip(ptr->value) << std::endl; 
				}else {
					std::cout << "Site not found" << std::endl;
				}
			} else if(funct == "q"){
				exist = true;
			}else if(funct == "delete"){
				std::string param;
				stream >> param;
				try{
					IP.deleteNode(param);
				}catch(const char * s){
					std::cerr << s << std::endl;
				}
			}else if(funct == "add"){
				std::string sitename;
				std::string ipstr;
				stream >> sitename;
				stream >> ipstr;
				IP.addNode(sitename, iptoint(ipstr.c_str()));
			} else if(funct == "help"){
				help();
			}else if(funct == "list"){
				IP.mapNode(Print);
			} else {
				std::cout << "Error command, command \"help\" for help)" << std::endl;
			}
		}
		
	return 0;
}
