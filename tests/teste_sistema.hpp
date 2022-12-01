#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/biblioteca/sistema.hpp"


TEST_CASE("Testando Biblioteca: ") {
    Sistema s = Sistema();
    
    CHECK_NOTHROW(ErroaAbrirArquivo, s.login);
    CHECK_NOTHROW(OperacaoInterrompida, s.login);
    CHECK_NOTHROW(ErroaAbrirArquivo, s.inicia_historico);
    CHECK_NOTHROW(ErroaAbrirArquivo, s.login);
    CHECK_NOTHROW(OperacaoInterrompida, s.deletar_usuario);
    
    
   
}
