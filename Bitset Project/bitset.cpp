#include "bitset.hpp"

// TODO
Bitset::Bitset(){
    bitsetsize=8;
bitArray=new std::string[bitsetsize-1];
validity=1;
}

Bitset::Bitset(intmax_t size){
    bitsetsize=size;
    bitArray=new std::string[size-1];
    if(size>0){
for(int i=0;i<size;i++){
    bitArray[i]="0";
}
validity=1;
    }
    else validity=0;
}
Bitset::Bitset(const std::string & value){
*bitArray=value;
bitsetsize=8;
for(int i=0;i<8;i++){
    if(bitArray[i]!="0"||bitArray[i]!="1"){
        validity=0;
    }
    else validity=1;
}
}
Bitset::~Bitset(){
delete [] bitArray;
}

intmax_t Bitset::size() const{
return bitsetsize;
}
bool Bitset::good() const{
if(validity==0){
    return false;
}
else return true;
}
void Bitset::set(intmax_t index){

if(index<0||index>(bitsetsize-1)){
    validity=0;
}
else {validity=1;
bitArray[index]="1";}
}
void Bitset::reset(intmax_t index){

if(index<0||index>(bitsetsize-1)){
    validity=0;
}
else {validity=1;
bitArray[index]="0";}
}
void Bitset::toggle(intmax_t index){
    if(bitArray[index]=="0"){
if(index<0||index>(bitsetsize-1)){
    validity=0;
}
else{ validity=1;
bitArray[index]="1";}
}
else if(bitArray[index]=="1"){
   
    if(index<0||index>(bitsetsize-1)){
    validity=0;
}
else {validity=1;
 bitArray[index]="0";}
}
}
bool Bitset::test(intmax_t index){
if(bitArray[index]=="1"){
    return true;
}
else return false;
if(index<0||index>(bitsetsize-1)){
    validity=0;
}
}
std::string Bitset::asString() const{
    std::string str;
    for(int i=0;i<=bitsetsize;i++){
        str+=bitArray[i];
    }
    return str;

}
