/*
 Guia0101 - v0.0. - 11 /08 / 2022
 Author: Guilherme Henrique Vieira Nascimento
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0101 ./Guia0101.cpp
 No Windows: g++ -o Guia0101.exe Guia0101.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia0101
 No Windows: Guia0101
*/
// lista de dependencias
#include "karel.hpp" //(comentário: necessario estar na mesma pasta)
// --------------------------- definicoes de metodos
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
// colocar paredes no mundo
 world->set ( 4, 4, HWALL ); // horizontal
 world->set ( 4, 4, VWALL ); // vertical
// colocar um marcador no mundo
 world->set ( 4, 4, BEEPER );
// salvar a configuracao atual do mundo
 world->save( fileName );
} // decorateWorld ( )
/**
 Classe para definir robo particular (MyRobot),
 a partir do modelo generico (Robot)
 Nota: Todas as definicoes irao valer para qualquer outro robo
 criado a partir dessa nova descricao de modelo.
*/
class MyRobot : public Robot
{
 public:
 /**
 turnRight - Procedimento para virar 'a direita.
 */
 void turnRight ( )
 {
 // testar se o robo esta' ativo
 if ( checkStatus ( ) )
 {
 // o agente que executar esse metodo
 // devera' virar tres vezes 'a esquerda
 turnLeft ( );
 turnLeft ( );
 turnLeft ( );
 } // end if
 } // end turnRight ( )
}; // end class MyRobot
// --------------------------- acao principal
/**
 Acao principal: executar a tarefa descrita acima.
*/
int main ( )
{
// definir o contexto
// criar o ambiente e decorar com objetos
// OBS.: executar pelo menos uma vez,
// antes de qualquer outra coisa
// (depois de criado, podera' ser comentado)
 world->create ( "" ); // criar o mundo
 decorateWorld ( "Guia0101.txt" );
 world->show ( );
// preparar o ambiente para uso
 world->reset ( ); // limpar configuracoes
 world->read ( "Guia0101.txt" );// ler configuracao atual para o ambiente
 world->show ( ); // mostrar a configuracao atual
 set_Speed ( 3 ); // definir velocidade padrao
// criar robo
 MyRobot *robot = new MyRobot( );
// posicionar robo no ambiente (situacao inicial):
// posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
 robot->create ( 1, 1, EAST, 0, "Karel" );
// executar tarefa
 robot->move( ); // primeira acao: andar para frente
 robot->move( ); // outra acao : mover-se de novo
 robot->turnLeft( ); // virar 'a esquerda
 robot->move( );
 robot->move( );
 robot->turnLeft( );
 robot->move( );
 robot->move( );
 robot->turnLeft( );
 robot->move( );
 robot->move( );
 robot->turnLeft( );
 robot->turnLeft( );
 robot->turnOff ( ); // desligar-se
// encerrar operacoes no ambiente
 world->close ( );
// encerrar programa
 getchar ( );
 return ( 0 );
} // end main ( )
// ------------------------------------------- testes
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
11/08/22
->Durante a compilação houve apenas um erro de ausência do ";"(13:42)
*IMP*->Depois da correção, ao compilar o arquivo houve um erro que aconteceu tanto no windows quanto no linux, 
"Guia0101.cpp:(.text+0x2e85): undefined reference to `operator new(unsigned int)' " pesquisei em diversos lugares e não achei a solução(13:53)*IMP*
->Sem a solução do erro que descobrir possivelmente ser erro no compilador, compilei o codigo no site replit, onde executou o programa corretamente
->Com a reducao do "basedelay" no arquivo karel.hpp foi possivel diminuir o tempo da execução do programa
---------------------------------------------- previsao de testes
Tudo ocorreu corretamente, foi alterado o delay e agilizou o processo mesmo sem atrapalhar a parte visual do programa
---------------------------------------------- historico
Versao  Data    Modificacao
 0.1    11/08   esboco
---------------------------------------------- testes
Versao Teste
 0.1 01. ( OK ) identificacao de programa
*/