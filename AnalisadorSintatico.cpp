#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class AnalisadorSintatico{
      public:
            stack<string> pilha;    
      public:
            //Os que seria E' substitui por A e os que seria T' substitui por B
            string terminais[5] = {"E", "E'", "T", "T'", "F"};
	      string variaveis[6] = {"id", "+", "*", "(", ")", "$"};//
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
			int x, y, i, z = 0, b, cont = 0, contador;
                  string quebra, value;
                  vector<string> novoVetor;
                  vector<string> resultado;

                  novoVetor = tratamentoEntrada(entrada);
                  pilha.push("$");
                  pilha.push(terminais[0]);

                  if(terminais[0] == " ")
                        pilha.pop();
                  //Primeiro for corresponde a lista de tokens de entradas fornecido pelo usuário
                  for(b = 0; b < novoVetor.size(); b++){
                        cout << " VETOR: <" << novoVetor[b] << "> "<< endl;
                        cout << "--------------------------------------------------------" << endl;
                        for(x = 0; x < 5; x++){
                              for(y = 0; y < 6; y++){
                                    //Corresponde ao primeiro caso do algoritmo presente no slide
                                    if(pilha.top() == "$" && novoVetor[b] == "$"){
                                          /*cout << " \tANÁLISE SINTÁTICA VÁLIDA" << endl;
                                          cout << "--------------------------------------------------------" << endl;
                                          */x = 5;
                                          y = 6;
                                    }
                                    else{
                                          cout << "TERMINAIS: " << terminais[x] << endl;
                                          //Para verificar caso o pilha.topo() != $ e novoVetor[] != $
                                          if(pilha.top() == terminais[x] && variaveis[y] == novoVetor[b]){
                                                cout << " TABELA: " << tabela[x][y] << endl;
                                                cout << " PILHA TOPO: " << pilha.top() << endl;
                                                cout << " VETOR: " << novoVetor[b] << endl;
                                                cout << "--------------------------------------------------------" << endl;

                                                if(pilha.top() != novoVetor[b]){
                                                      pilha.pop();
                                                      tratamentoVariaveis(tabela[x][y]);
                                                      x = 0;
                                                }
                                                else{
                                                      pilha.pop();
                                                      cout << " \tANÁLISE SINTÁTICA VÁLIDA" << endl;
                                                      cout << "--------------------------------------------------------" << endl;
                                                }

                                          } 
                                          

                                          cout << "--------------------------------------------------------" << endl;
                                          cout << " TOPO: " << pilha.top() << endl;
                                          if(pilha.top() == novoVetor[b]){//Não consegui identificar que pilha.top() == "&", sendo que é verdade
                                                cout << " ELEMENTO VAI SER DESEMPILHADO: " << pilha.top() << endl;
                                                cout << "--------------------------------------------------------" << endl;
                                                if(pilha.top() == "$"){
                                                     cout << " \tANÁLISE SINTÁTICA VÁLIDA" << endl;
                                                }
                                                else{
                                                      pilha.pop();
                                                      x = 5;
                                                      y = 6; 
                                                }
                                                cout << " NOVO ELEMENTO TOP: " << pilha.top() << endl;
                                                cout << "--------------------------------------------------------" << endl;
                                                //resultado.push_back(novoVetor[b]);
                                          }
                                    }
                                    imprimirResultado();
                              }
                        }
                  }
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
                  string divisao = "";
                  int x;
                  for(x = palavra.length(); x > 0; x--){
                        if(palavra[x] != isalnum(palavra[x])){
                              divisao = palavra[x-1];
                              if(divisao == "& ")
                                    x = palavra.length();
                              else{
                                    pilha.push(divisao);
                                    divisao.clear();
                              }
                        }
                        else{
                              divisao += palavra[x-2];
                              //if para identificar se não tem nada
                              if((int) divisao[0] == 0){
                                    divisao.clear();
                              }
                              divisao += palavra[x-1];
                              if(divisao == "&")
                                    x = palavra.length();
                              else{
                                    pilha.push(divisao);
                                    divisao.clear();
                                    x--;
                              }
                        }
                  }
                  //imprimirResultado();
            };

            void imprimirResultado(){
                  stack<string> printando;
                  printando = pilha;
                  while(!printando.empty()){
                        cout << " PILHA: " << printando.top() << " " << endl;
                        printando.pop();
                  }
            };
};
