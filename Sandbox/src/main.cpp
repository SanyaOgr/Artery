#include "Application.h"
#include <iostream>

int main()
{
	art::Application app;
	app.Run();

	art::Window window(600, 400, L"Test Window :)");

	return 0;
}