#include <iostream>
#include <string>
#include <iomanip> //formatar valor de saida para 0,00

//Projeto Avaliativo Semestral - ALP
//Alunos: José Pereira Barros Junior, Maurício da Silva Alves

using namespace std;

float funcao_preco (float preco[]){ 

	preco[0] = 6.00;
	preco[1] = 5.50;
	preco[2] = 5.00;
	preco[3] = 6.50;
	preco[4] = 5.50;
	preco[5] = 5.75;
	preco[6] = 5.25;
	preco[7] = 5.00;
	preco[8] = 4.75;
	preco[9] = 4.50;

}

string funcao_estoque (std::string estoque[]){ 

	estoque [0] = "Refrigerante de Cola";
	estoque [1] = "Refrigerante de Guarana";
	estoque [2] = "Refrigerante de Soda";
	estoque [3] = "Suco de Laranja";
	estoque [4] = "Suco de Uva";
	estoque [5] = "Chips de Batata";
	estoque [6] = "Chips de Milho";
	estoque [7] = "Chips de Queijo";
	estoque [8] = "Chocolate ao Leite";
	estoque [9] = "Chocolate Branco";
}

//funcao modo admin	
char modoAdmin(char opcao_adm){
	
	cout << endl << "=== Modo Administrador! === " << endl;
	cout << endl << "Opcoes:" << endl;
	cout << "A) Listar produtos e estoque." << endl;
	cout << "B) Repor estoque." << endl; 
	cout << "C) Informar Lucro." << endl;
	cout << "D) Projetar Lucro (baseado no estoque atual)." << endl;
	cout << "E) Sair para modo Usuario." << endl;
	//char opcao_adm;
	cin >> opcao_adm;
	opcao_adm = toupper (opcao_adm);
	
	return opcao_adm;
}

int main(int argc, char** argv) {
	int estoque[10];
	int estoqueLucro [10];
	for ( int e = 0; e < 10; e++) {
    	estoque[e] = 10;
    	estoqueLucro[e] = estoque[e];
    }

	float lucro_acumulado = 0;
	
	//inicio do programa = funcao
	inicio:

	char inicio;
	
	cout << "=== Ola! ===" << endl << endl;
	cout << "A) Iniciar pedido." << endl;
	cout << "B) Modo Administrador." << endl;
	
	cout << endl << "Digite uma escolha acima: ";
	cin >> inicio;
	inicio = toupper (inicio); 
		
	//Interface inicial modo usuario
	if (inicio == 'A'){
		usuario:	
	
		cout << endl << "Bem vindo!" << endl; //.........................................................................................
		cout << endl << "Para iniciar seu pedido escolha um produto abaixo: " << endl;

		std::string exibir_estoque[10];
    	funcao_estoque(exibir_estoque);
    	float preco[10];
		funcao_preco(preco);
		
				//duas casas decimais
				// << std::fixed << std::setprecision(2) << preco[i]
    	
    	for (int i = 0; i < 10; i++) {
        	std::cout << i+1 << " - "<< exibir_estoque[i] <<  " - R$ " << std::fixed << std::setprecision(2) << preco[i] << endl;
    	}
			
		int escolhaProduto;
		int qtProduto;
		char fimPedido = 'N';
		float valorFinal = 0;
	
		while (fimPedido == 'N'){
			cout << endl << "Escolha seu produto (digite o numero referente): ";
			cin >> escolhaProduto;
				
			int j;
			j = escolhaProduto - 1;
			
			float valorProduto;
			valorProduto = preco [j];
			
			if (estoque[j] == 0){
				cout << "Produto INDISPONIVEL!" << endl;
			}else{
				cout << "Quantidade: ";
				cin >> qtProduto;
			
				while (qtProduto > estoque[j]){
					cout << "Quantidade indisponivel." << "Estoque: " << estoque[j] << endl;
					cout << "Informe novamente a quantidade de " << exibir_estoque[j] << ": ";
					cin >> qtProduto;
				}//while pedido maior que estoque disponivel
			
			estoque[j] = estoque [j] - qtProduto;
			estoqueLucro[j] = estoque[j];
			
			valorFinal = valorFinal + (qtProduto * valorProduto);
			}//else produto indisponivel
			
			cout << endl << "Encerrar pedido? (S/N): ";
			cin >> fimPedido;
			fimPedido = toupper (fimPedido);
			
		}//while encerrar pedido / adicionar mais itens
		
		if (valorFinal == 0)
			goto inicio;
		
		cout << endl << "Valor do Pedido R$ " << valorFinal << endl;
		cout << endl << "Insira seu pagamento: ";
		float pagamento;
		cin >> pagamento;
		
			while (pagamento < valorFinal) {
				cout << "O pagamento inserido eh inferior ao valor do seu pedido!" << endl;
				cout << "Insira novamene seu pagamento: ";
				cin >> pagamento;
			}//while pagamento inferior ao valor final
		
			if (pagamento == valorFinal){
				cout << "Pronto!" << endl;
				cout << "Aqui esta seu pedido." << endl << endl;
			}//fim do pedido s/ troco
			
			if (pagamento > valorFinal){
				float troco;
				troco = pagamento - valorFinal;
				cout << "Aqui esta seu troco: R$" << troco << endl;
				cout << "... e aqui esta seu pedido!" << endl << endl;
			}//informativo troco + fim do pedido
	
	goto inicio;	
	} // if modo usuario
	
	//Interface modo admin
	if (inicio == 'B'){
		int senha_adm;
		cout << "Insira sua senha de administrador.";
		cin >> senha_adm;
		
		while (senha_adm != 2023){ //senha incorreta
			char opcao_senha;
			cout << endl;
			cout << "Senha incorreta." << endl;
			cout << "A) Tente novamente." << endl;
			cout << "B) Sair para menu principal." << endl;
			cin >> opcao_senha;
			opcao_senha = toupper (opcao_senha);
			
			if (opcao_senha == 'A'){
				
				cout << "Insira sua senha de administrador.";
				cin >> senha_adm;
			}
			else{
				goto inicio;
			}
		}//while senha incorreta
		
		//admin INICIADO
		char opcao_adm;
		
		modoAdm:
		opcao_adm = modoAdmin(opcao_adm);
		
		if (opcao_adm == 'A'){
			//funcao listar produtos + perguntar se deseja repor estoque
            std::string exibir_estoque[10];
    		funcao_estoque(exibir_estoque);
    		
    		for (int i = 0; i < 10; i++) {
        		std::cout << exibir_estoque[i] <<  " - Estoque: " << estoque[i] << endl;
    		}
			
			char voltarMenu;
			cout << endl << "Tecle 'S' para voltar ao Menu Adm, ou qualquer outra tecla para o voltar ao menu inicial.";
			cin >> voltarMenu;
			voltarMenu = toupper (voltarMenu);
			
			if (voltarMenu == 'S')
				goto modoAdm;
			else
				goto inicio;
				
		}//if A listar estoque
		
		if (opcao_adm == 'B'){
			cout << endl << "Alterar estoque. Selecione um produto para alterar:" << endl;
            std::string exibir_estoque[10];
    		funcao_estoque(exibir_estoque);
			
			    for (int i = 0; i < 10; i++) {
        			std::cout << i + 1 << " - " << exibir_estoque[i] <<  " - Estoque: " << estoque[i] << endl;
    			}//for listar produtos e estoque
    		
	   		char continuar = 'S';
    		while (continuar == 'S'){
    			int escolhaEstoque;
    		
	    		cout << endl << "Produto: ";
    			cin >> escolhaEstoque;
    			
    			int estoqueNovo[10];
    			cout << endl << "Insira o estoque novo de " << exibir_estoque[escolhaEstoque-1] << ": ";
    			cin >> estoqueNovo [escolhaEstoque - 1];
    			
    				while (estoqueNovo[escolhaEstoque - 1] > 10){
    					cout << "Erro! Estoque maximo permitido = 10 unidades/produto.";
    					cout << endl << "Insira o estoque novo de " << exibir_estoque[escolhaEstoque - 1] << ": ";
    					cin >> estoqueNovo [escolhaEstoque - 1];
   					}//while Estoque NOVO > 10 = nao permitido
				estoque[escolhaEstoque - 1] = estoqueNovo [escolhaEstoque - 1];
    			
    			cout << endl << "Deseja alterar outro estoque? (S/N): ";
    			cin >> continuar;
    			continuar = toupper (continuar);
					
    		}//while Continuar S
    		
    		cout << endl << "Estoque ATUALIZADO: " << endl;
    		funcao_estoque(exibir_estoque);
    		
    		for (int i = 0; i < 10; i++) {
        		std::cout << exibir_estoque[i] <<  " - Estoque: " << estoque[i] << endl;
    		}//for exibir estoque Atualizado
    		
    		char voltarMenu;
			cout << endl << "Tecle 'S' para voltar ao Menu Adm, ou qualquer outra tecla para sair.";
			cin >> voltarMenu;
			voltarMenu = toupper (voltarMenu);

			if (voltarMenu == 'S')
				goto modoAdm;
			else
				goto inicio;
		} // if B alterar estoque
		
		if (opcao_adm == 'C'){
			float preco[10];
			funcao_preco(preco);
			float lucro_atual = 0;		
			
			for (int i = 0; i < 10; i++){
				lucro_atual = lucro_atual + ((10 - estoqueLucro[i]) * preco[i]);
				estoqueLucro[i] = 10;				
			}
			
			lucro_acumulado = lucro_acumulado + lucro_atual;
			
			cout << endl << "Lucro desde a inicializacao da maquina: R$ " << lucro_acumulado << endl;
			
			lucro_atual = 0;
			
			char voltarMenu;
			cout << endl << "Tecle 'S' para voltar ao Menu Adm, ou qualquer outra tecla para sair.";
			cin >> voltarMenu;
			voltarMenu = toupper (voltarMenu);
			
			if (voltarMenu == 'S')
				goto modoAdm;
			else
				goto inicio;		
		}//if C lucro atual
		
		if (opcao_adm == 'D'){
			float preco[10];
			funcao_preco(preco);
		 	float lucro_projetado = 0;
			
			for (int i = 0; i < 10; i++){
					lucro_projetado = lucro_projetado + (estoque[i] * preco[i]);
			}
			
			cout << endl << "Lucro Projetado: R$ " << lucro_projetado << endl;

			char voltarMenu;
			cout << endl << "Tecle 'S' para voltar ao Menu Adm, ou qualquer outra tecla para sair.";
			cin >> voltarMenu;
			voltarMenu = toupper (voltarMenu);
			
			if (voltarMenu == 'S')
				goto modoAdm;
			else
				goto inicio;
		}//if D	projetar lucro		
		if (opcao_adm == 'E'){
			cout << endl << "==== Modo Usuario ====" << endl;
			goto usuario;
		}//opcao E
		
		
} // if B (modo admin)
	
	return 0;
}
