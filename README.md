# Mystic2D
Yet another attempt to make a 2D engine using OpenGL - I have a bad case of restart-itus


Important: I am not sure how to do precompiled headers "properly". I think it's doing it?
Output:
 make debug
g++ -Wall -std=c++11 -g -DDEBUG -H -Ivendor/GLFW/include -Ivendor/GLAD/include -Ivendor/GLM -Ivendor/STB_IMAGE src/main.cpp vendor/GLAD/include/glad.cpp -o bin/main -Lvendor/GLFW/lib -LC:\MinGW\lib -lglfw3 -lgdi32 -lopengl32 -include src/pch.h
! ./src/pch.h.gch
. src/pch.h
src/main.cpp: In function 'int main()':