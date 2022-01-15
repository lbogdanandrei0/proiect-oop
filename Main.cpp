#include "GlobalController.h"

int add1(int arg) {
    return arg + 1;
}

int main(int argc, char* argv[])
{
	GlobalController controller;
	controller.init();
	controller.run();

    return 0;
}

