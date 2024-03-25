//cmake .. fonctionne mais make ne reconnait pas vecotr
cmake_minimum_required (VERSION 2.8)
project(BlackJack)

file( GLOB_RECURSE BLACKJACK_SOURCES src/*.cpp )		
file( GLOB_RECURSE BLACKJACK_HEADERS include/*.h )
message("Les fichiers : " ${BLACKJACK_HEADERS})

include_directories(include)

add_library(biblio SHARED ${BLACKJACK_SOURCES})


add_executable(BlackJack bin/main.cpp)



target_link_libraries(BlackJack biblio)

