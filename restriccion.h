#include <string>
#include <conio.h>
#include<iostream>


class Restriccion{

    private:
        int tamano;
        int cantidad;
        int infracciones[12];
        
    public:
        //constructor
	    Restriccion();
	    Restriccion(int _tamano, int _cantidad, int _infracciones []);
        //set and get
        void setTamano(int _tamano);
        int getTamano();    

        void setCantidad(int _cantidad);
        int getCantidad();
           
        void setInfraciones(int _infracciones []);
        int* getInfraciones();
	    //metodos
	    float promedio();
	    bool pruebaTeoria();
	    void imprimir();
        int infraccionesRealizadas ( int r1 [], int r2 []);
        bool comparaCiudades( Restriccion R2);

        int* estadoAmbasCiudades( Restriccion R1, Restriccion R2);

};

Restriccion :: Restriccion(){}

Restriccion :: Restriccion(int _tamano, int _cantidad, int _infracciones []){
	tamano = _tamano;
	cantidad = _cantidad;
	
	for (int i = 0; i < 12; i++){
		infracciones[i] = _infracciones[i];
    }
}

void Restriccion :: setTamano(int _tamano){
   tamano = _tamano;
}

int Restriccion :: getTamano(){
    return tamano;
}  

void Restriccion :: setCantidad(int _cantidad){
    cantidad = _cantidad;
}

int  Restriccion :: getCantidad(){
    return cantidad;
}
    
void Restriccion :: setInfraciones(int _infracciones []){
    for (int i = 0; i < 12; i++){
        infracciones[i] = _infracciones[i];
    }   
}

int* Restriccion :: getInfraciones(){
    return infracciones;
}

float Restriccion :: promedio(){
    float sum =0;
    float promedio = 0;

    for (int i = 0; i < 12; i++){
        sum += infracciones[i];
    }
    
    promedio =  sum/12;
    
    return promedio;
}

bool Restriccion :: pruebaTeoria(){
    bool flag = false;
    float promedio_meses = this->promedio();
    float promedio_meses_pares=0;
    int sum=0;
    

    for (int i = 0; i < 12; i++){
        //Se utilizan los numeros impares ya que el array inicia desde cero.
        if(  i %2 != 0){
            sum+=infracciones[i];
        }
    }

    promedio_meses_pares=sum/6;

    if (promedio_meses_pares>promedio_meses){
        flag=true;
    }
    
    return flag;
}

int Restriccion :: infraccionesRealizadas ( int r1 [], int r2 []){
    int numero = 0;

    for (int i = 0; i < 12; i++){
        if( r1[i] > r2[i]){
            numero++;
        }
    }
    
    //printf("%d\n", numero);

    return numero;
}

bool Restriccion :: comparaCiudades( Restriccion R2 ){
    /* utiliza como referencia la ciudad que invoca el metodo  = r1
      ciudad como parametro = r2
    */

    bool flag = false;

    if( infraccionesRealizadas( infracciones, R2.getInfraciones() ) >= 7){
        flag = true;
    }

    //printf(flag ? "true" : "false");

    return flag;
}

 int* Restriccion:: estadoAmbasCiudades( Restriccion R1, Restriccion R2){

     for (int i = 0; i < 12; i++){
        
        if( (R1.getInfraciones()[i] <= 300) && (R2.getInfraciones()[i] <= 300) ){
            // si ambas son menores a 300 infracciones = 0
            infracciones[i] = 0;
        } else if( (R1.getInfraciones()[i] >= 300) && (R2.getInfraciones()[i] >= 300) ){ 
            // si ambas superan 300 infracciones = -1
            infracciones[i] = -1;
        }else if( (R1.getInfraciones()[i] >= 300) || (R2.getInfraciones()[i] >= 300) ){ 
            // si solo una supera 300 infracciones = 1
            infracciones[i] = 1;
        }
     }
     
     return infracciones;
 }


void Restriccion:: imprimir(){
	
    //printf("%d\n", tamano);
    //printf("%d\n", cantidad);
      
    for (int i = 0; i < 12; i++){
        printf(" [ %d ]\n",infracciones[i]);
    }    
}
