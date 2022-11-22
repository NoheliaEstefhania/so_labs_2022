#include <iostream>
using namespace std;

class Laboratorio{
  int num;
};
class Practica{
  int a;
  Laboratorio lab;

  public:
  operator Laboratorio(){
    return lab;
  }
  operator int() {
    return a;
  }
};
void funcion (int a){
  cout<<"funcion (int) executada"<<endl;
}
void funcion (Laboratorio &la){
  cout<<"funcion (Laboratorio) executada"<<endl;
}
int main(){
  Practica p;
  funcion(p);
  return 0;
}
