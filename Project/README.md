Project Structure:

    The libraries folder contains all the drivers and
    their header files need to create the leveler.
    The src folder contains the code that utilizes the
    libraries. 
    The CMakeLists.txt is what creates the 
    environment that is able to compile and run our code.
    The pico_sdk_import.cmake provide the library pico-sdk
    to our code that contains all the very low level 
    functions. 
    The to be made build folder contains all the 
    executables once the project is compiled.


Instructions:

    To run this project make sure you start off
    in the Project folder and run these lines of code.

    mkdir build
    cd build
    export PICO_SDK_PATH=../../pico-sdk
    cmake ..
    make

    Once this is done plug in the board via usb type-c
    Hold the bootselect button and press the reset button
    This will show the rasberry pi as an ejectable drive.
    Drag and drop the level.uf2 file that was created in 
    the build directory. 

    Congratulations the program should be running on your board
