#include <iostream>
#include "Utils.h"
#include "Huffman.h"
#include "NodoArbol.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Utils util;
	int num = 0;
	char menu[5];
	bool continuar = true;
	bool seguir = true;
    Huffman* huffman = new Huffman();
	
	 do{
        cout << "\nMenú Principal"
             << "\n1. Algoritmos sobre Arboles"
             << "\n2. Algoritmos sobre Grafos"
             << "\n3. Salir" << endl;
        cin >> menu;

		if (!util.EsUnNumero(menu) || (stoi(menu) > 3))
            {num = 4;}
		else
            {num = stoi(menu);}

		switch (num){
			case 1:
			{
				do{
		        	cout << "\nAlgoritmos sobre Arboles"
		             << "\n1. Codificador de Huffman"
		             << "\n2. Decodificador de Huffman"
		             << "\n3. Regresar al Menu Principal" << endl;
		        	cin >> menu;
	
					if (!util.EsUnNumero(menu) || (stoi(menu) > 3))
                        {num = 4;}
					else
                        {num = stoi(menu);}

					switch(num){
						case 1:
						{
							//code
                            cout << endl;
                            string texto = util.leerArchivo("prueba.txt");
                            //string texto = util.leerArchivo("testcorto.txt");
                            int tam = huffman->contarCaracteres(texto);
                            cout << "Tamaño : " << tam << endl;
                            cout << endl;

                            //creamos hojas Huffman aquí
                            string textovirtual = huffman->crearHojas(texto);
                            cout << "Intentamos crear el Arbol: " << endl;
                            NodoArbol* huffmanTree = huffman->creaArbol();
                            //creamos hojas Huffman aquí

                            //Sumatoria final prueba de compresion
                            Simbolo* pruebaDeSuma = (Simbolo*)huffmanTree->getItem();
                            cout << "PRUEBA DE SUMA DE FRECUENCIAS EN RAIZ: " << pruebaDeSuma->getFreq() << endl;
                            cout << "PRUEBA DE VALOR EN RAIZ:               " << pruebaDeSuma->getSimbolo() << endl;
                            cout << "creamos el UN SOLO NODO EXITOSAMENTE!!! " << endl;
                            //Sumatoria final prueba de compresion


                            // vamos a crear la frase HUffman
                            cout << " Codificando el siguiente mensaje: "<< endl << textovirtual << endl;
                            string fraseSecretaHuffman = huffman->codificarTexto(huffmanTree, textovirtual);
                            cout << endl<< "FRASE SECRETA !!!! " << endl;
                            cout <<fraseSecretaHuffman <<endl << endl;
                            huffman->decodificadorHuffman(huffmanTree , fraseSecretaHuffman);
                            seguir = true;
							break;	
						}
						case 2:
						{
							//code
							seguir = true;
							break;
						}
						case 3:
						{
							seguir = false;
							break;
						}
						default:
						{
							cout << "\nEsa opcion es invalida" << endl;
							seguir = true;
							break;
						}
					}

				}while (seguir);
				break;
			}
			case 2:
			{
				do{
		        	cout << "\nAlgoritmos sobre Grafos"
		             << "\n1. Leer grafo de un archivo"
		             << "\n2. Prim"
		             << "\n3. Floyd"
		             << "\n4. Regresar al Menu Principal" << endl;
		        	cin >> menu;
	
					if (!util.EsUnNumero(menu) || (stoi(menu) > 4))
                        {num = 5;}
					else
                        {num = stoi(menu);}
					
					switch(num){
						case 1:
						{
							//code
							seguir = true;
							break;	
						}
						case 2:
						{
							//code
							seguir = true;
							break;
						}
						case 3:
						{
							//code
							seguir = true;
							break;
						}
						case 4:
						{
							seguir = false;
							break;
						}
						default:
						{
							cout << "\nEsa opcion es invalida" << endl;
							seguir = true;
							break;
						}
					}	
				}while (seguir);
				break;
			}
			case 3:
				continuar = false;
				break;
			default:
				cout << "\nEsa opcion es invalida" << endl;	
		}
        	
	}while (continuar);
	
	return 0;
}