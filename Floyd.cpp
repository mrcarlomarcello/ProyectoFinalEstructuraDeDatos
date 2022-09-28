#include "Floyd.h"
#include "Vertice.h"
#include <iostream>
using namespace std;

Floyd::Floyd(int size){
	this->size=size;
	this->matriz=new Vertice*[size];
	for (int i=0; i<size; i++){
		matriz[i]=new Vertice[size];
	}
	this->costos=new int*[size];
	for (int i=0; i<size; i++){
		costos[i]=new int [size];
	}
	llenado_prueba();
	for(int i = 0; i < size; i++){ 
        for (int j = 0; j < size; j++) { 
            if(i == j){ 
                this->matriz[i][j].setPeso(nan); 
            } 
        } 
    }
}

void Floyd::almacenarCostos(){
	for(int i = 0; i < size; i++){ 
        for (int j = 0; j < size; j++) { 
       	    if(i == j) 
                this->costos[i][j] = 0; 
            else 
                this->costos[i][j] = matriz[i][j].getPeso(); 
        } 
	}
}

void Floyd::algoritmoFloyd(){
	almacenarCostos(); 
    for(int i = 0; i < size; i++){ 
        for(int j = 0; j < size; j++){ 
            for(int k = 0; k < size; k++){ 
                if(this->costos[j][i] + this->costos[i][k] < this->costos[j][k]){ 
                    this->costos[j][k] = this->costos[j][i] + this->costos[i][k]; 
                } 
            } 
        } 
    }
    cout<<("Matriz Adyacencia: ") << endl; 
        for(int i = 0; i < size; i++){ 
            for(int j = 0; j < size; j++){ 
                if(this->matriz[i][j].getPeso() == nan) 
                    cout<<("I"); 
                else 
                    cout<<(this->matriz[i][j].getPeso()); cout << (" ");
            } 
            cout<<endl; 
        } 
        cout<< "" <<endl; 
        cout << ("Costos Minimos: ") << endl; 
        for(int i = 0; i < size; i++){ 
			for(int j = 0; j < size; j++){
            	if(this->costos[i][j] == 0) 
                	cout << ("I"); 
            	else 
                	cout << (this->costos[i][j]); cout << (" ");
        	} 
        cout << endl;
        } 
}