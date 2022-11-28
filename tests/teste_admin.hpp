#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "third_party\doctest.h"
#include "include\pessoa\admin.hpp"

//testar 0 e negativos

TEST_CASE("Testando Admin: ") {


    //Admin::Admin (std::string email, std::string senha) : Pessoa (email, senha) {};
    
    Admin::Admin ("email@example.com", "Senha");
   
    CHECK(Admin.:get_classe() == "admin");
   
}