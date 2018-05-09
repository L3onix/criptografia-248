#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Função que traduz frase e chave para binário
void decParaBin(int* binario, char* frase){
	//int binario[tamanhoTexto * 8];	//TESTE
	//char frase[10] = "teste";		//TESTE

	int tamanhoTexto = strlen(frase);	//variável que recebe tamanho da frase
	int auxBin[8] = {0,0,0,0,0,0,0,0};	//variável auxiliar para calcular conversão binária das letras
	int aux;				//variável auxiliar para receber o valor decimal de uma letra
	int contador = 0;			//variável auxiliar para loop
	//printf("tamanho = %i\n", tamanhoTexto);	//TESTE print do tamanho da frase

	printf("\n\n");
	//Loop que percorre cada posição do vetor do texto, passando esse valor para o tipo inteiro
	for(int i = 0; i < tamanhoTexto; i++){
		aux = frase[i];	//variável recebe decimal correspondente à
		printf("\n%c = %i", frase[i], aux);	//TESTE imprime as letras e seus valor correspondentes

		//Loop que faz o calculo para passar o valor decimal para binário
		while(aux > 1){
			auxBin[contador]=aux%2;
			aux = aux/2;
			contador++;
		}
		auxBin[contador] = aux;

		//Loop que trata o resultado gerado acima, para ser apresentado de forma correta
		for(int j = 0; j < 8; j++){
			binario[(i * 8) + j] = auxBin[7 - j];
			auxBin[7-j] = 0;
		}
		contador = 0;
	}
	/*//TESTE imprimir resultado em binario
	  printf("\n\n");
	  for(int i=0; i<(tamanhoTexto*8); i++){
	  printf("%i", binario[i]);
	  }
	  */
	return;
}

void binParaDec(int* binario, int* decimal, int tamanhoBinario){
    for(int i=0; i<(tamanhoBinario/8); i++){
        decimal[i] = 0;
        for(int j=(i*8)+7; j>=(i*8); j--){
            if(binario[j] == 1){
                decimal[i] += pow(2, ((i*8)+7)-j);
            }
        }

    }
}

void decParaChar(int* decimal, char* frase, int tamanhoDecimal){
    for(int i=0; i<tamanhoDecimal; i++){
        frase[i] = decimal[i];
    }
}

//Função que gera o número de repetições que irá ser executado o processo criptográfico
int geraNumeroRepeticoes(int* binChave, int tamanhoVetor){
	int repeticoes = 0;
	for(int i = 0; i < tamanhoVetor; i++){
		if(binChave[i] == 1){
			repeticoes++;
		}
	}
	return repeticoes;
}

//Função que copia o binarioOriginal para uma variável auxiliar que sofrerá o processo criptográfico
void copiarBinarioFrase(int* binarioCopia, int* binarioOriginal, int tamanhoFrase){
	for(int i=0; i<tamanhoFrase; i++){
		binarioCopia[i] = binarioOriginal[i];
	}
}

//Funão de primeiro passo de criptografia - faz rotação de 2 bits
void encripta2Bits(int* binario, int tamanhoBinario, int repeticoes){
	int bitsAux[2], i, j;	//variáveis auxiliares

	//Impressão de processo de encriptação
	printf("\n\n:::::Resultado binário gerado da criptografia de 2 bits:::::\n");

	//processo de rotação de valores binários
	for(i=0; i<repeticoes; i++){	//será repetido de acordo com a chave criptográfica

		//variáveis que armazenam os dois ultimos bits
		bitsAux[0] = binario[tamanhoBinario - 2];
		bitsAux[1] = binario[tamanhoBinario - 1];

		//processo de realocação dos binarios
		for(j=(tamanhoBinario-1); j>=0; j--){
			binario[j] = binario[j-2];
			if(j == 2){
				binario[0] = bitsAux[0];
				binario[1] = bitsAux[1];
				break;
			}
		}

		//loop para imprimir processo na tela
		for(int p=0; p<tamanhoBinario; p++){
			printf("%i", binario[p]);
		}
		printf("\n");

	}
}

void encripta4Bits(int* binario, int tamanhoBinario, int repeticoes){
	int bitsAux[4], i, j;	//variáveis auxiliares

	//Impressão de processo de encriptação
	printf("\n\n:::::Resultado binário gerado da criptografia de 4 bits:::::\n");

	//processo de rotação de valores binários
	for(i=0; i<repeticoes; i++){	//será repetido de acordo com a chave criptográfica

		//variáveis que armazenam os dois ultimos bits
		bitsAux[0] = binario[tamanhoBinario - 4];
		bitsAux[1] = binario[tamanhoBinario - 3];
		bitsAux[2] = binario[tamanhoBinario - 2];
		bitsAux[3] = binario[tamanhoBinario - 1];

		//processo de realocação dos binarios
		for(j=(tamanhoBinario-1); j>=0; j--){
			if(j == 3){
				binario[0] = bitsAux[0];
				binario[1] = bitsAux[1];
				binario[2] = bitsAux[2];
				binario[3] = bitsAux[3];
				break;
			}
			binario[j] = binario[j-4];
		}

		//loop para imprimir processo na tela
		for(int p=0; p<tamanhoBinario; p++){
			printf("%i", binario[p]);
		}
		printf("\n");

	}
}

void encripta8Bits(int* binario, int tamanhoBinario, int repeticoes){
	int bitsAux[8], i, j;	//variáveis auxiliares

	//Impressão de processo de encriptação
	printf("\n\n:::::Resultado binário gerado da criptografia de 8 bits:::::\n");

	//processo de rotação de valores binários
	for(i=0; i<repeticoes; i++){	//será repetido de acordo com a chave criptográfica

		//variáveis que armazenam os dois ultimos bits
		bitsAux[0] = binario[tamanhoBinario - 8];
		bitsAux[1] = binario[tamanhoBinario - 7];
		bitsAux[2] = binario[tamanhoBinario - 6];
		bitsAux[3] = binario[tamanhoBinario - 5];
		bitsAux[4] = binario[tamanhoBinario - 4];
		bitsAux[5] = binario[tamanhoBinario - 3];
		bitsAux[6] = binario[tamanhoBinario - 2];
		bitsAux[7] = binario[tamanhoBinario - 1];

		//processo de realocação dos binarios
		for(j=(tamanhoBinario-1); j>=0; j--){
			if(j == 7){
				binario[0] = bitsAux[0];
				binario[1] = bitsAux[1];
				binario[2] = bitsAux[2];
				binario[3] = bitsAux[3];
				binario[4] = bitsAux[4];
				binario[5] = bitsAux[5];
				binario[6] = bitsAux[6];
				binario[7] = bitsAux[7];
				break;
			}
			binario[j] = binario[j-8];
		}

		//loop para imprimir processo na tela
		for(int p=0; p<tamanhoBinario; p++){
			printf("%i", binario[p]);
		}
		printf("\n");

	}
}

void decripta2Bits(int* binario, int tamanhoBinario, int repeticoes){
	int bitsAux[2], i, j;

	//Impressão de processo de encriptação
	printf("\n\n:::::Resultado binário gerado da decriptografia de 2 bits:::::\n");

	for(i=0; i<repeticoes; i++){

		//variáveis que armazenam os dois ultimos bits
		bitsAux[0] = binario[0];
		bitsAux[1] = binario[1];

		for(j=0; j<tamanhoBinario; j++){
			if(j == tamanhoBinario-2){
				binario[tamanhoBinario-2] = bitsAux[0];
				binario[tamanhoBinario-1] = bitsAux[1];
				break;
			}
			binario[j] = binario[j+2];
		}

		//loop para imprimir processo na tela
		for(int p=0; p<tamanhoBinario; p++){
			printf("%i", binario[p]);
		}
		printf("\n");

	}
}

void decripta4Bits(int* binario, int tamanhoBinario, int repeticoes){
	int bitsAux[4], i, j;

	//Impressão de processo de encriptação
	printf("\n\n:::::Resultado binário gerado da decriptografia de 4 bits:::::\n");

	for(i=0; i<repeticoes; i++){

		//variáveis que armazenam os dois ultimos bits
		bitsAux[0] = binario[0];
		bitsAux[1] = binario[1];
		bitsAux[2] = binario[2];
		bitsAux[3] = binario[3];

		for(j=0; j<tamanhoBinario; j++){
			if(j == tamanhoBinario-4){
				binario[tamanhoBinario-4] = bitsAux[0];
				binario[tamanhoBinario-3] = bitsAux[1];
				binario[tamanhoBinario-2] = bitsAux[2];
				binario[tamanhoBinario-1] = bitsAux[3];
				break;
			}
			binario[j] = binario[j+4];
		}

		//loop para imprimir processo na tela
		for(int p=0; p<tamanhoBinario; p++){
			printf("%i", binario[p]);
		}
		printf("\n");

	}
}

void decripta8Bits(int* binario, int tamanhoBinario, int repeticoes){
	int bitsAux[8], i, j;

	//Impressão de processo de encriptação
	printf("\n\n:::::Resultado binário gerado da decriptografia de 8 bits:::::\n");

	for(i=0; i<repeticoes; i++){

		//variáveis que armazenam os dois ultimos bits
		bitsAux[0] = binario[0];
		bitsAux[1] = binario[1];
		bitsAux[2] = binario[2];
		bitsAux[3] = binario[3];
		bitsAux[4] = binario[4];
		bitsAux[5] = binario[5];
		bitsAux[6] = binario[6];
		bitsAux[7] = binario[7];

		for(j=0; j<tamanhoBinario; j++){
			if(j == tamanhoBinario-8){
				binario[tamanhoBinario-8] = bitsAux[0];
				binario[tamanhoBinario-7] = bitsAux[1];
				binario[tamanhoBinario-6] = bitsAux[2];
				binario[tamanhoBinario-5] = bitsAux[3];
				binario[tamanhoBinario-4] = bitsAux[4];
				binario[tamanhoBinario-3] = bitsAux[5];
				binario[tamanhoBinario-2] = bitsAux[6];
				binario[tamanhoBinario-1] = bitsAux[7];
				break;
			}
			binario[j] = binario[j+8];
		}

		//loop para imprimir processo na tela
		for(int p=0; p<tamanhoBinario; p++){
			printf("%i", binario[p]);
		}
		printf("\n");

	}
}

void encriptar(char* fraseOriginal, char* chaveOriginal, int* binarioFraseOriginal, int* binarioChaveOriginal, int* binarioFraseEncriptado){
    int tamanhoBinarioFrase = strlen(fraseOriginal)*8;
    int tamanhoBinarioChave = strlen(chaveOriginal)*8;
    int repeticoes=0;

    //transformar fraseOriginal em código binaŕio
    decParaBin(binarioFraseOriginal, fraseOriginal);
    //transformar chaveOriginal em código binário
    decParaBin(binarioChaveOriginal, chaveOriginal);

    //imprimir resultados de substituição na tela
    printf("\n\n:::::Resultado da substituição por valores binários:::::\n");
    for(int i=0; i<tamanhoBinarioFrase; i++){
        printf("%i", binarioFraseOriginal[i]);
    }
    printf("\n");

    //copia binarioFraseOriginal para binarioFraseEncriptado para passar pela criptografia
    copiarBinarioFrase(binarioFraseEncriptado, binarioFraseOriginal, tamanhoBinarioFrase);

    //processo de determina número de repetições do processo de criptografia
    repeticoes = geraNumeroRepeticoes(binarioChaveOriginal, tamanhoBinarioChave);	//Função que gera número de repetições

	//ESTÁGIO DE CRIPTOGRAFIA
	//PRIMEIRA FASE DE CRIPTOGRAFIA - MUDAR 2 BITS
	encripta2Bits(binarioFraseEncriptado, tamanhoBinarioFrase, repeticoes);
	//SEGUNDA FASE DE CRIPTOGRAFIA - MUDAR 4 BITS
	encripta4Bits(binarioFraseEncriptado, tamanhoBinarioFrase, repeticoes);
	//TERCEIRA FASE DE CRIPTOGRAFIA - MUDAR 8 BITS
	encripta8Bits(binarioFraseEncriptado, tamanhoBinarioFrase, repeticoes);
	//CRIPTOGRAFIA COMPLETA

}

void decriptar(int* binarioFraseEncriptado, int tamanhoBinarioFrase, char* chave){
    int tamanhoBinarioChave = strlen(chave)*8;
    int repeticoes;
    int binarioChave[tamanhoBinarioChave];
    int decimalFrase[tamanhoBinarioFrase/8];
    char fraseResultado[tamanhoBinarioFrase/8];

    //gera binário de chave criptográfica
    decParaBin(binarioChave, chave);
    //gera repeticoes para decriptação
    repeticoes = geraNumeroRepeticoes(binarioChave, tamanhoBinarioChave);

    //ESTÁGIO DE DECRIPTAÇÃO DE BINÁRIO
    //PRIMEIRA FASE DE DECRIPTAÇÃO - RETORNAR 8 BITS
	decripta8Bits(binarioFraseEncriptado, tamanhoBinarioFrase, repeticoes);
	//SEGUNDA FASE DE DECRIPTAÇÃO - RETORNAR 4 BITS
	decripta4Bits(binarioFraseEncriptado, tamanhoBinarioFrase, repeticoes);
	//TERCEIRA FASE DE DECRIPTAÇÃO - RETORNAR 2 BITS
	decripta2Bits(binarioFraseEncriptado, tamanhoBinarioFrase, repeticoes);

	//ESTÁGIO DE DECRIPTAÇÃO DE SUBSTITUIÃO
	//primeiro passo - obter valores decimais do código binário
	binParaDec(binarioFraseEncriptado, decimalFrase, tamanhoBinarioFrase);
	//segundo passo - substituir valor decimais por valores binários
	decParaChar(decimalFrase, fraseResultado, tamanhoBinarioFrase/8);

	//Imprimindo resultado de substituição
	printf("\n\n:::::Resultado de BIN para DEC:::::\n");
	for(int i=0; i<tamanhoBinarioFrase/8; i++){
        printf("%i ", decimalFrase[i]);
	}
	printf("\n\n:::::Resultado de DEC para CHAR:::::\n");
	for(int i=0; i<tamanhoBinarioFrase/8; i++){
        printf("%c", fraseResultado[i]);
	}

}

int main(){
	//VARIÁVEIS ORIGINAIS
	//INSERIR FRASE AQUI 	    vvv
	char fraseOriginal[256] = "teste";	//variável que recebe frase a ser criptografada (frase original)
	int tamanhoFraseOriginal = strlen(fraseOriginal);
	int binarioFraseOriginal[tamanhoFraseOriginal * 8];	//variável que recebe binário da frase original

	//INSERIR CHAVE AQUI	   vvv
	char chaveOriginal[50] = "a";	//variável que recebe chave que será usada na criptografia (chave original)
	char chaveFalsa[50] = "x";  //variável de teste
	int tamanhoChaveOriginal = strlen(chaveOriginal);
	int binarioChaveOriginal[tamanhoChaveOriginal * 8];	//variável que recebe binário da chave original

	int repeticoes;	//variável que recebe número de repetições que será executado o algoritmo criptográfico

	//VARIÁVEIS PARA AUXILIO EM OPERAÇÕES
	int binarioFraseEncriptado[tamanhoFraseOriginal * 8];	//variável que recebe binário criptografado
	int binarioFraseDecriptado[tamanhoFraseOriginal * 8];	//variável que recebe binário criptografado e decriptografa o mesmo

    //EXECUTA PROCESSO DE CRIPTOGRAFIA
    encriptar(fraseOriginal, chaveOriginal, binarioFraseOriginal, binarioChaveOriginal, binarioFraseEncriptado);

    //COPIA OS DADOS GERADOS PELA CRIPTOGRAFIA PARA UMA VARIÁVEL AUXILIAR
    copiarBinarioFrase(binarioFraseDecriptado, binarioFraseEncriptado, tamanhoFraseOriginal*8);

	//EXECUTA PROCESSO DE DECRIPTAÇÃO
	decriptar(binarioFraseEncriptado, tamanhoFraseOriginal*8, chaveOriginal);
	//TESTE
	decriptar(binarioFraseEncriptado, tamanhoFraseOriginal*8, chaveFalsa);

	printf("\n\n");
	return 0;
}
