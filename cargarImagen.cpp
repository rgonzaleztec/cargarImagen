// cargarImagen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Engine.h"
#include "TimerControler.h"


int main(int argc, char* args[])
{
	
	//Inicializamos el Engine del juego
	Engine::GetInstance()->Init();

	while (Engine::GetInstance()->IsRunning())
	{
		Engine::GetInstance()->Events();
		Engine::GetInstance()->Update();
		Engine::GetInstance()->Render();
		TimerControler::GetInstance()->Tick();
	}

	Engine::GetInstance()->Clean();
	return 0;
}