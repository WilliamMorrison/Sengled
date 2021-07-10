#include <iostream>

#include "session/sengled_session.hpp"

int main(int argc, char* argv[]){
    sengled_session session(true);

    printf("%s", session.get_cookie().c_str());
    std::cin.get();
}