# Mystic2D
Yet another attempt to make a 2D engine using OpenGL - I have a bad case of restart-itus

As it stands currently, nothing is consistent. Some TODOS:

Implement logging and replace all "printf's & std::cout's"
Create ... what's the name.. stuff like rectangle, circle, etc.
Create a "common" header file
Create precompiled headers
Start outfitting "core" as a static library
Implement sprite batcher
Create an input handler
Create an event system
Implement an ECS of sorts


VSCode Settings for reference:
C_Cpp.clang_format_fallbackStyle = {BasedOnStyle: Google, IndentWidth: 4, ColumnLimit: 0}


#Findings: Index buffer is not being set/applied inside the renderer
            I Get it... only seeting first "X" of the vertex buffer.. but there are far more than x...

#Notes for self on what's nex:
    - Implement the Renderer
    - Populate the vertex buffer and index buffer with draw calls
    - Create a method to perform the draw call in the private method "flush"
        - Flush method should also clear the buffers.
    - Add checks for vertex buffer limit to flush and clear the array
    - Set "EndBatch()" to call the flush method