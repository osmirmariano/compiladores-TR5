#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class AnalisadorSintatico{
      public:
            stack<string> pilha;    
      public:
            //Os que seria E' substitui por A e os que seria T' substitui por B
            string terminais[5] = {"E", "E'", "T", "T'", "F"};
	      string variaveis[6] = {"id", "+", "*", "(", ")", "$"};
	      string tabela[5][6];

	public:
		AnalisadorSintatico(){
			void definindoTabela();
		};
		~AnalisadorSintatico();

		void definindoTabela(){
			int x, y;
			tabela[0][0] = {"TE'"};
                  tabela[0][1] = {" "};
                  tabela[0][2] = {" "};
                  tabela[0][3] = {"TE'"};
                  tabela[0][4] = {" "};
                  tabela[0][5] = {" "};

                  tabela[1][0] = {" "};
                  tabela[1][1] = {"+TE'"};
                  tabela[1][2] = {" "};
                  tabela[1][3] = {" "};
                  tabela[1][4] = {"&"};
                  tabela[1][5] = {"&"};

                  tabela[2][0] = {"FT'"};
                  tabela[2][1] = {" "};
                  tabela[2][2] = {" "};
                  tabela[2][3] = {"FT'"};
                  tabela[2][4] = {" "};
                  tabela[2][5] = {" "};

                  tabela[3][0] = {" "};
                  tabela[3][1] = {"&"};
                  tabela[3][2] = {"*FT'"};
                  tabela[3][3] = {" "};
                  tabela[3][4] = {"&"};
                  tabela[3][5] = {"&"};

                  tabela[4][0] = {"id"};
                  tabela[4][1] = {" "};
                  tabela[4][2] = {" "};
                  tabela[4][3] = {"(E)"};
                  tabela[4][4] = {" "};
                  tabela[4][5] = {" "};

			cout << "-----------------------------------------------------" << endl;
			cout << "\t TABELA SINTÁTICA" << endl;
			cout << "-----------------------------------------------------" << endl;
			cout << "TERMINAIS";
			for(x = 0; x < 6; x++){
				cout << "  |  " << variaveis[x];
			}
			cout << endl << "-----------------------------------------------------" << endl;

			for(x = 0; x < 5; x++){
				cout << "    " << terminais[x] << "     ";
				for(y = 0; y < 6; y++){
					cout << " |  " << tabela[x][y];
				}
				cout << endl<< "-----------------------------------------------------" << endl;
			}
            };

            
            

		void analisandoEntrada(string entrada){
			int x, y, i, z = 0;
                  vector<string> novoVetor, valores;
                  string palavra = "";

                  novoVetor = tratamentoEntrada(entrada);

                  pilha.push("$");
                  pilha.push(terminais[0]);
                  string quebra, value;
                  int b;
                  vector<string> resultado;
                  for(b = 0; b < novoVetor.size(); b++){
                        for(x = 0; x < 5; x++){
                              for(y = 0; y < 6; y++){
                                    //Corresponde ao primeiro caso do algoritmo presente no slide
                                    if(pilha.top() == "$" && novoVetor[b] == "$"){
                                          cout << "ANÁLISE SINTÁTICA VÁLIDA" << endl;
                                          b = novoVetor.size();
                                          x = 5;
                                          y = 6;
                                    }
                                    else{
                                          //Para verificar se pilha.top() é variável
                                          if(){

                                          }
                                          else{
                                                //Para verificar caso o pilha.topo() != $ e novoVetor[] != $
                                                if(pilha.top() == terminais[x] && variaveis[y] == novoVetor[b]){
                                                      cout << " " << tabela[x][y] << endl;
                                                      if(pilha.top() != novoVetor[b]){
                                                            pilha.pop();
                                                            palavra = tabela[x][y];  
                                                            tratamentoVariaveis(palavra);
                                                      }
                                                      else{
                                                            pilha.pop();
                                                            cout << "É VÁLIDO" << endl;
                                                      }

                                                } 
                                          }
                                    }
                              }
                        }
                  }
                  imprimirResultado();

		};

            

            vector<string> tratamentoEntrada(string entrada){
                  vector<string> novoVetor;
                  string aux = "", aux2 = "";
                  int i;
                  for( i = 0; i < entrada.length(); i++){
                        if(isalnum(entrada[i])){ //verifica se é alfanumérico
                              aux += entrada[i];
                        }
                        else{
                              aux2 = entrada[i];
                              novoVetor.push_back(aux);
                              novoVetor.push_back(aux2);
                              aux.clear();
                        }
                  }
                  return novoVetor;
            };

            void tratamentoVariaveis(string palavra){
                  string usa1="", usa2 ="";
                  int i;
                  for(i = palavra.length(); i > 0; i--){
                        //cout << "PALAVRA: " << palavra[i-1] << endl;
                        if(palavra[i] != isalnum(palavra[i])){
                              usa1 = palavra[i-1];
                              pilha.push(usa1);
                              //cout << "VALOR 1: " << usa1 << endl;
                              usa1.clear();
                        }
                        else{
                              usa1 += palavra[i-2];
                              usa1 += palavra[i-1];
                              //cout << "VALOR 2: " << usa1 << endl;
                              pilha.push(usa1);
                              usa1.clear();
                              i--;
                        }
                        //imprimirResultado();
                  }
            };

            void imprimirResultado(){
                  cout << "TAMANHO: " << pilha.size() << endl;
                  while(!pilha.empty()){
                        cout << " PILHA: " << pilha.top() << " " << endl;
                        pilha.pop();
                  }
            };
};
