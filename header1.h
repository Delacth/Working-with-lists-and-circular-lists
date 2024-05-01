
//* Desafio 1 
typedef struct l lista;

lista* inicializarlista();

lista *insereinicio(lista *l,char letra);

lista *removeno(lista *l,char letra);

void imprime(lista* l);

void procuraelemento(lista *l,char letra);

void verificarpali(lista *l);

void removerlista(lista*l);

//* Desafio 2 

typedef struct slotmachine SM;

//* Default List */
SM * criaslot();

//* Inserir numeros de 1 á 10 */ 
SM * insereslot(SM * cl, int valueSort);

//* GAME ON*/
void gameOn(SM * cl);

//* Liberar a Lista  */
void gameOver(SM * cl);

void menuPrincipal();