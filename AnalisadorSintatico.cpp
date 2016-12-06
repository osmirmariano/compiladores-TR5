#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class AnalisadorSintatico{
      public:
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
			for(x = 0; x < 5; x++){
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
			stack<string> pilha;
			int x, i;
                  vector<string> vetor;
                  string aux= "", aux2="";
			pilha.push("$");
			pilha.push(terminais[0]);

                  for(i=0; i<entrada.length();i++){
                        if(isalnum(entrada[i])){ //verifica se é alfanumérico
                              aux += entrada[i];
                        }else{
                              aux2 = entrada[i];
                              vetor.push_back(aux);
                              vetor.push_back(aux2);
                              aux.clear();
                        }
                  }

                  for(i=0; i<vetor.size();i++){
                        cout<<"V:"<<vetor[i]<<endl;
                  }
		}
};
