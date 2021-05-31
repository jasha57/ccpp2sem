#ifndef HELPTOIP_HPP
#define HELPTOIP_HPP
#include <string>
#include <cstring>


unsigned int iptoint(const char* ipAddress){
    uint8_t ipbytes[4]={};
    int i =0;
    int8_t j=3;
    while (ipAddress+i && i<strlen(ipAddress))
    {
       char digit = ipAddress[i];
       if ((!isdigit(digit)) && digit !='.'){
           return 0;
       }
        j=digit=='.'?j-1:j;
       ipbytes[j]= ipbytes[j]*10 + atoi(&digit);

        i++;
    }

    uint32_t a = ipbytes[0];
    uint32_t b =  ( uint32_t)ipbytes[1] << 8;
    uint32_t c =  ( uint32_t)ipbytes[2] << 16;
    uint32_t d =  ( uint32_t)ipbytes[3] << 24;
    return a+b+c+d;
}

std::string inttoip(int ip){
    unsigned char bytes[4];
    bytes[0] = ip & 0xFF;
    bytes[1] = (ip >> 8) & 0xFF;
    bytes[2] = (ip >> 16) & 0xFF;
    bytes[3] = (ip >> 24) & 0xFF;   
    return std::to_string(bytes[3]) + "." + std::to_string(bytes[2]) + "." + std::to_string(bytes[1]) + "." + std::to_string(bytes[0]);   
}

#endif