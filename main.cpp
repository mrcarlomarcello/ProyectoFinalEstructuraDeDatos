#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	int num;
	int opcion;
	
	 do{
        cout << "\nMenú Principal"
             << "\n1. Algoritmos sobre Arboles"
             << "\n2. Algoritmos sobre Grafos"
             << "\n3. Salir" << endl;
        cin >> num;
        
        if (num == 1){
        	do{
	        	cout << "\nAlgoritmos sobre Arboles"
	             << "\n1. Codificador de Huffman"
	             << "\n2. Decodificador de Huffman"
	             << "\n3. Regresar al Menu Principal" << endl;
	        	cin >> opcion;
			}while (opcion < 3);
        }
        
        if (num == 2){
        	do{
	        	cout << "\nAlgoritmos sobre Grafos"
	             << "\n1. Leer grafo de un archivo"
	             << "\n2. Prim"
	             << "\n3. Floyd"
	             << "\n4. Regresar al Menu Principal" << endl;
	        	cin >> opcion;
			}while (opcion < 4);
        }
        	
	}while (num < 3);
	
	return 0;
}