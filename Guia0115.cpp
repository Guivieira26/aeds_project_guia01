/*
 Guia0111 - v0.1. -  11 / 08 / 2022
 Author: Guilherme Henrique Vieira Nascimento
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0108 ./Guia0108.cpp
 No Windows: g++ -o Guia0108.exe Guia0108.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia0108
 No Windows: Guia0108
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
 // horizontal
 world->set ( 3, 2, HWALL ); world->set ( 3, 6, HWALL );
 world->set ( 4, 2, HWALL ); world->set ( 4, 6, HWALL );
 world->set ( 5, 2, HWALL ); world->set ( 5, 6, HWALL );
 // vertical  Es             // vertical  Dr 
 world->set ( 2, 5, VWALL ); world->set ( 5, 5, VWALL );
 world->set ( 2, 4, VWALL ); world->set ( 5, 4, VWALL );
 world->set ( 2, 3, VWALL ); world->set ( 5, 3, VWALL );
 world->set ( 2, 6, VWALL ); 
 // colocar um marcador no mundo
 world->set ( 4, 3, BEEPER );// 6 beeps
 world->set ( 4, 3, BEEPER );
 world->set ( 4, 3, BEEPER );
 world->set ( 4, 3, BEEPER );
 world->set ( 4, 3, BEEPER );
 world->set ( 4, 3, BEEPER );//fim
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
 decorateWorld ( "Guia0115.txt" );
 world->show ( );
// preparar o ambiente para uso
 world->reset ( ); // limpar configuracoes
 world->read ( "Guia0115.txt" );// ler configuracao atual para o ambiente
 world->show ( ); // mostrar a configuracao atual
 set_Speed ( 3 ); // definir velocidade padrao
// criar robo
 MyRobot *robot = new MyRobot( );
// posicionar robo no ambiente (situacao inicial):
// posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
 robot->create ( 1, 1, EAST, 0, "Karel" );
// executar tarefa
 robot->move( );//ir (6,1)
 robot->move( );
 robot->move( );
 robot->move( );
 robot->move( );
 robot->turnLeft( );//North
 robot->move( );//ir (6,6)
 robot->move( );
 robot->move( );
 robot->move( );
 robot->move( );
 robot->turnLeft( );//west
 robot->move( );//ir (4,6)
 robot->move( );
 robot->turnLeft( );//south
 robot->move( );//ir (4,3)
 robot->move( );
 robot->move( );
 robot->pickBeeper( );//Pegar 6 beeps
 robot->pickBeeper( );
 robot->pickBeeper( );
 robot->pickBeeper( );
 robot->pickBeeper( );
 robot->pickBeeper( );//fim
 robot->turnLeft( );
 robot->turnLeft( );//north
 robot->move( );//ir (4,6)
 robot->move( );
 robot->move( );
 robot->turnRight( );//east
 robot->move( );//ir (6,6)
 robot->move( );
 robot->turnRight( );//south
 robot->move( );//ir (6,3)
 robot->move( );
 robot->move( );
 robot->putBeeper( );//put 3 beeper
 robot->putBeeper( );
 robot->putBeeper( );
 robot->turnLeft( );
 robot->turnLeft( );//north
 robot->move( );//ir (6,7)
 robot->move( );
 robot->move( );
 robot->move( );
 robot->turnLeft( );//west
 robot->move( );//ir (5,7)
 robot->putBeeper( );//put 2 beeper
 robot->putBeeper( );
 robot->move( );//ir (2,7)
 robot->move( );
 robot->move( );
 robot->turnLeft( );//south
 robot->move( );//ir (2,6)
 robot->putBeeper( );//put 1 beeper
 //FIM TASK
 
 //VOLTAR INICIO
 robot->move( );//ir (2,1)
 robot->move( );
 robot->move( );
 robot->move( );
 robot->move( );
 robot->turnRight( );//west
 robot->move( );//ir (1,1)
 robot->turnRight( );//north
 robot->turnRight( );//east
 robot->turnOff ( ); // desligar-se
// encerrar operacoes no ambiente
 world->close ( );
// encerrar programa
 getchar ( );
 return ( 0 );
} // end main ( )
// -------------------------------------------- testes
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
Executado corretamente
---------------------------------------------- historico
Versao      Data    Modificacao
1.4 0.2     11/08   esboco
-------om o--------------------------------------- testes
Versao Teste
 0.1 0.1 ( OK ) teste inicial
 0.2 0.1 ( OK ) teste da tarefa
 0.3 0.1 ( OK ) teste da tarefa parcial
 0.4 0.1 ( OK ) teste do apanhar marcador
 0.5 0.1 ( OK ) teste do colocar marcador
 0.6 0.1 ( OK ) teste da repeticao do movimento
 0.7 0.1 ( OK ) teste com marcador na posicao (4,4)
 0.7 0.2 ( OK ) teste sem marcador na posicao (4,4)
 0.8 0.1 ( OK ) teste com a quantidade de marcadores
 0.9 0.1 ( OK ) teste com outra forma de repeticao
 1.0 0.1 ( OK ) teste com outra forma de repeticao
 1.1 0.2 ( OK ) teste com outra forma de repeticao
 1.2 0.2 ( OK ) teste com outra forma de repeticao
 1.3 0.2 ( OK ) teste com outra forma de repeticao
 1.4 0.2 ( OK ) teste com outra forma de repeticao
 1.5 0.2 ( OK ) teste com outra forma de repeticao
*/