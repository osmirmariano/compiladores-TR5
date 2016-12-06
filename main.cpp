#include <iostream>
#include "AnalisadorSintatico.cpp"
using namespace std;

int main(int argc, char const *argv[]){
	int op;
    string entrada;
	AnalisadorSintatico *sintatico =  new AnalisadorSintatico();

	do{
        cout << "---------------------------------------------------" << endl;
        cout << "\t MENU DE OPÇÃO" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << " 1 -- DEFINIR TABELA" << endl;
        cout << " 2 -- ENTRADA CÓDIGO FONTE" << endl;
        cout << " 0 -- SAIR" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << " OPÇÃO: ";
        cin >> op;
        cout << "---------------------------------------------------" << endl;

        switch(op){
            case 1:
                cout << "---------------------------------------------------" << endl;
                cout << "\t DEFININDO A TABELA" << endl;
                cout << "---------------------------------------------------" << endl;
                sintatico->definindoTabela();
                break;

            case 2:
                cout << "---------------------------------------------------" << endl;
                cout << "\t ENTRADA CÓDIGO FONTE" << endl;
                cout << "---------------------------------------------------" << endl;
                cout << " ENTRADA: ";
                cin.ignore();
                getline (cin, entrada);
                cout << "---------------------------------------------------" << endl;
                sintatico->analisandoEntrada(entrada);
                cout << "---------------------------------------------------" << endl;
                break;

            case 0:
                cout << "\tAPLICAÇÃO ENCERRADA COM SUCESSO!" << endl << endl;
                break;

            default:
                cout << "\tOPÇÃO INVÁLIDA, POR FAVOR ESCOLHA UMA VÁLIDA" << endl;
        }
        cout << endl << "  PARA VOLTAR AO MENU PRESSIONE ENTER" << endl;
        cin.ignore().get();//Comando para Pausa no terminal
        cout << "\e[H\e[2J";//Comando para limpar a tela
    }while(op != 0);
	return 0;
}