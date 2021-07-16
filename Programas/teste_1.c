#include <stdio.h>
#define dividaMaxima 30000
#define dividaMaximaEspecial 50000
#define true 1
#define false 0
typedef int bool

typedef struct{
	char* nome;
	int cpf;
} PESSOA;

typedef struct{
   PESSOA* pessoa;
   int valorContaCorrente;
   int valorDaDivida;
   char tipo;
} CLIENTE;

typedef struct{
   PESSOA* pessoa;
   int numClientes;
   CLIENTE* clientes[20];
} GERENTE;

typedef struct{
   GERENTE* gerentes[10];
   int numGerentes;
} BANCO;
/********************** FUNCOES PARA CRIAR CLIENTES, GERENTES OU BANCOS ******/


/* Funcao para a criacao de um novo cliente.
   A funcao preenche todos os valores de seus campos e retorna esse novo cliente.
*/
CLIENTE novoCliente (char* nome, int cpf, int valor){
   CLIENTE novo;
   novo.pessoa.nome = nome;
   novo.pessoa.cpf = cpf;
   novo.tipo = 'C';
   novo.valorContaCorrente = valor;
   return novo;
}
/* Funcao para a criacao de um novo cliente especial.
   A funcao preenche todos os valores de seus campos (utilizando a funcao novoCliente)
   e retorna esse novo cliente especial.
*/
CLIENTE novoClienteEspecial (char*nome, int cpf, int valor){
   CLIENTE novo = novoCliente(nome, cpf, valor);
   novo.tipo = 'E';
   return novo;
}
/* Funcao para a criacao de um novo gerente.
   A funcao preenche os valores de seus campos e retorna esse novo gerente.
*/
GERENTE novoGerente (char*nome, int cpf){
   GERENTE novo;
   novo.pessoa.nome = nome;
   novo.pessoa.cpf = cpf;
   novo.numClientes = 0;
   return novo;
}
/* Funcao para a criacao de um novo banco.
   A funcao preenche os valores de seus campos e retorna esse novo banco.
*/
BANCO novoBanco (){
   BANCO novo;
   novo.numGerentes = 0;
   return novo;
}
/********************** FUNCOES DOS CLIENTES *********************************/


/* Funcao que retorna true caso valorContaCorrente seja menor do que valorDaDivida.
 * Caso contrario, retorna false.  */
bool negativado(CLIENTE* c1){
   if(c1->valorContaCorrente<c1->valorDaDivida) return true;
   return false;
}

/* Funcao para o cliente atual (referenciado por c1) obter um emprestimo de acordo com o valor passado por parametro
 *   Caso o valor do parametro seja menor ou igual a zero, a funcao deve retornar false
 *   Caso contrario ha duas situacoes:
 *     1a) se o valor do parametro mais o valor do campo valorDaDivida for maior do
 *         que o valor da constante dividaMaxima (para clientes regulares) ou 
 *         dividaMaximaEspecial (para clientes especiais), a funcao deve retornar false 
 *     2a) caso contrario, o campo valorDaDivida deve ser incrementado em valor, o campo
 *         valorContaCorrente deve ser incrementado em valor e a funcao deve retornar true
 */
bool obterEmprestimo (CLIENTE* c1, int valor){
   if(valor<=0) return false;
   int dividamax;
   if(c1->tipo == 'E') dividamax = dividaMaximaEspecial;
   else dividamax = dividaMaxima;
   if((valor + c1->valorDaDivida) > dividamax ) return false;
   c1->valorDaDivida += valor;
   c1->valorContaCorrente += valor;
   return true;
}
/* Funcao para o cliente atual (referenciado por c1) pagar parte de sua divida de acordo com o valor passado por parametro
 *   Caso o valor do parametro seja menor ou igual a zero, a funcao deve retornar false
 *   Caso contrario ha duas situacoes:
 *     1a) se o valor do parametro for maior do que o valorDaDivida ou for maior do que 
 *         valorContaCorrente, a funcao deve retornar false 
 *     2a) caso contrario, o campo valorDaDivida deve ser decrementado em valor, o campo
 *         valorContaCorrente deve ser decrementado em valor e a funcao deve retornar true
 */
bool pagarDivida (CLIENTE* c1, int valor){
   if(valor<=0) return false;
   if((valor>c1->valorDaDivida) || (valor>c1->valorContaCorrente)) return false;
   c1->valorDaDivida -= valor;
   c1->valorContaCorrente -= valor;
   return true;
}
/* Funcao para o cliente atual (referenciado por c1) realizar um saque do valor passado por parametro
 *   Caso o valor do parametro seja menor ou igual a zero, a funcao deve retornar false
 *   Caso contrario ha duas situacoes:
 *     1a) se o valor do parametro for maior do que o valor do campo valorContaCorrente, a 
 *         funcao deve retornar false
 *     2a) caso contrario, o campo valorContaCorrente deve ser decrementado em valor e a
 *         funcao deve retornar true
 */
bool realizarSaque (CLIENTE* c1, int valor){
   if(valor<=0) return false;
   if(valor > c1->valorContaCorrente) return false;
   c1->valorContaCorrente -= valor;
   return true;
}
/********************** FUNCOES DOS GERENTES *********************************/


/* Funcao para adicionar um cliente no arranjo de clientes do gerente referenciado por g1.
 * Caso o numero de clientes seja igual a 20, nao deve adicionar e deve retornar false.
 * Caso contrario, ha duas situacoes: 
 *   1a: o cliente ja consta no arranjo de clientes (verifique isso usando o numero do cpf),
 *       neste caso o cliente nao deve ser reinserido e a funcao deve retornar false; 
 *   2a: o cliente passado como parametro nao consta no arranjo de clientes: o cliente 
 *       deve ser adicionado na posicao numClientes, o campo numClientes deve ser 
 *       incrementado em 1 e a funcao deve retornar true. 
 */
bool adicionarCliente (GERENTE* g1, CLIENTE* c1){
   if(g1->numClientes == 20) return false;
   int i;
   for(i=0, i<g1->numClientes; i++)
   if(g1->clientes[i]->pessoa.cpf == c1->pessoa.cpf) return false;
   g1->clientes[g1->numClientes] = c1;
   g1->numClientes++;
   return true;
}

/* Funcao para cobrar os emprestimos de todos os clientes do gerente atual (referenciado por g1).
 * Para cada um dos clientes presentes no arranjo clientes, este metodo deve:
 *   - nao fazer nada para o cliente, caso seu valorDaDivida seja igual a zero
 *   - caso contrario, ha duas situacoes:
 *     1a) se o valorContaCorrente do cliente for maior ou igual ao valorDaDivida, deve
 *         fazer o cliente pagar a divida, isto e, o valorContaCorrente sera atualizado, 
 *         descontando-se o valor da divida e o valorDaDivida sera zerado.
 *     2a) se o valorContaCorrente do cliente for menor do que o valorDaDivida, deve
 *         fazer o cliente pagar parte da divida, isto e, o valorDaDivida sera atualizado,
 *         tendo seu valor diminuido pelo valorContaCorrente e o valorContaCorrente sera zerado.
 */
void cobrarEmpresitmos (GERENTE* g1){
   int i; aux;
   for(i=0, i<g1->numClientes, i++){
      if(g1->clientes[i]->valorContaCorrente>=g1->clientes[i]->valorDaDivida){
      g1->clientes[i]->valorContaCorrente -= g1->clientes[i]->valorDaDivida;
      g1->clientes[i]->valorDaDivida = 0;
      }
      else{
       g1->clientes[i]->valorDaDivida -= g1->clientes[i]->valorContaCorrente;
       g1->clientes[i]->valorContaCorrente = 0;
      }
   }
}
/* Funcao para imprimir informacoes sobre os clientes gerenciados por ger1 */
void imprimirClientes (GERENTE ger1){
   int i;
   printf("informacoes dos clientes do gerente: %s", ger1.pessoa.nome);
   printf("numero de clientes: %i", ger1.numClientes);
   for(i=0, i<ger1.numClientes; i++){
      printf("%s %c  %i  %i  %i\n\n", ger1.clientes[i]->pessoa.nome, ger1.clientes[i]->tipo, ger1.clientes[i]->pessoa.cpf, 
      ger1.clientes[i]->valorContaCorrente, ger1.clientes[i]->valorDaDivida);
   }
}
/********************** FUNCOES DOS BANCOS ***********************************/

/* Funcao para adicionar um gerente no arranjo de gerentes do banco referenciado por b1.
 * Caso o numero de gerentes seja igual a 10, nao deve adicionar e deve retornar false.
 * Caso contrario, ha duas situacoes: 
 *   1a: o gerente ja consta no arranjo de gerentes (verifique isso usando o numero do cpf),
 *       neste caso o gerente nao deve ser reinserido e a funcao deve retornar false; 
 *   2a: o gerente passado como parametro nao consta no arranjo de gerentes: o gerente 
 *       deve ser adicionado na posicao numGerentes, o campo numGerentes deve ser 
 *       incrementado em 1 e a funcao deve retornar true. 
 */
bool adicionarGerentes (BANCO* b1, GERENTE* g1;){
   if(b1->numGerentes == 10) return false;
   int i;
   for(i=0; i<b1->numGerentes; i++)
      if(b1->gerentes[i]->pessoa.cpf == g1->pessoa.cpf) return false;

   b1->gerentes[b1->numGerentes] = g1;
   b1->numGerentes++;
   return true;
}
/* Funcao para imprimir informacoes gerais sobre o banco b1 (passado como parametro) */
void imprimirBanco (BANCO b1){
   printf("imprimindo informações do banco\n\n");
   printf("numero de gerentes: %i", b1->numGerentes);
   int aux, i, j;
   GERENTE* g1;
   for(i=0; i<b1.numGerentes; i++){
      g1 = b1.gerentes[i];
      aux += g1->numClientes;
   }
   printf("numero de clientes: %i", aux);
   for(i=0; i<b1.numGerentes; i++){
      g1 = b1.gerentes[i];
      printf("Gerente: %s  %i", g1->pessoa.nome, g1->pessoa.cpf);
   }
}
int main () {
printf("*** Criando Clientes **************************************\n");

printf("*** Criando Gerentes **************************************\n");

printf("*** Criando um Banco **************************************\n");

printf("*** Adicionando clientes ao Gerente 1 **************************\n");

printf("*** Testando a funcao obterEmprestimo **************************\n");

printf("*** Testando a funcao realizarSaque ****************************\n");

printf("*** Testando a funcao pagarEmprestimo **************************\n");


	printf("*** Testando a funcao cobrarTodosEmprestimos *******************\n");

	return 0;
}