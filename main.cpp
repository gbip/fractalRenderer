#include "Application.h"


int main(int argc, char**argv) {
	const int width = 800;
	const int height = 800;



	Application<width, height> app;
	app.draw(50);
	app.loop();
	//sleep(15);
}