cmake_minimum_required(VERSION 3.24)
project(lab12)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab12 main.cpp Colectie.h Colectie.cpp FileRepo.h FileRepo.cpp produs.h produs.cpp Repo.h Repo.cpp service.h service.cpp teste.h teste.cpp UI.h UI.cpp CodException.h DublareException.h Validator.h FileException.h)
