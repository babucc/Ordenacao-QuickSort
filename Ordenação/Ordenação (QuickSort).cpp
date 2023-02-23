#include <iostream>

using namespace std;

	void menu(){
		cout<<"	 \n	MENU PRINCIPAL"				  <<endl<<endl;
		cout<<"1 - Cadastrar elementos no vetor." <<endl;
		cout<<"2 - Ordenar em ordem crescente."   <<endl;
		cout<<"3 - Exibir elementos ordenados."   <<endl;
		cout<<"4 - Sair."						  <<endl<<endl;
	}
	
	int troca(int vet[], int esq, int dir){
	int aux;
	int cont = esq;
	
	for(int i = esq+1; i < dir; i++){
		if(vet[i] < vet[esq]){
			aux = vet[i];
			vet[i] = vet[esq];
			vet[esq] = aux;

		}
	}
		aux = vet[esq];
		vet[esq] = vet[cont];
		vet[cont] = aux;
		return cont;
	}

	void quickS(int vet[], int esq, int dir ){
		int aux;
		if (esq < dir){
			aux = troca(vet, esq, dir);
			quickS(vet, esq, aux-1);
			quickS(vet, aux+1, dir);
		}
	
	}

	int main(){
		setlocale(LC_ALL,"portuguese");
		int op, aux, x;
		int vet[10] = {0};
		int n = 10;
		
		do{
			menu();
			cout<<"Informe a opção desejada: ";
			cin>>op;
			
			switch(op){
				case 1:
					for (int i = 0; i < 10; i++){
						cout<<"\nInforme um número "<<"["<<i+1<<"]: ";
						cin>>vet[i];
					}
				break;
				
				case 2:	
					quickS(vet, 0, n);
						cout<<"\nOrdenação Quicksort feita com sucesso!"<<endl<<endl;
						cout<<"Digite '3' para a exibição."<<endl<<endl;	
				break;
				
				case 3:
					cout<<"\n";
					cout<<"	    EXIBIÇÃO ORDENADA"<<endl<<endl;
					for (int i = 0; i < 10; i++){
						cout<<" - "<<vet[i];
					}
					cout<<"\n";
				break;	
			}	
			
		}while (op != 4);
		cout<<"\nPrograma Finalizado com Sucesso!";
	}
