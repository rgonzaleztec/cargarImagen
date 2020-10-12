#include "Engine.h"
#include "TextureManager.h"
#include "Transform.h"
#include "Vector2D.h"
#include "Warrior.h"
#include "InputHandler.h"
#include "TimerControler.h"
#include <iostream>

Engine* Engine::s_Instance = nullptr;
Warrior* player = nullptr;
Warrior* player2 = nullptr;

// Inicializacion de SDL
bool Engine::Init() {
	
	if (SDL_Init(SDL_INIT_VIDEO)!=0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG)!=0)
	{
		SDL_Log("Error al inicializar SDL: %s", SDL_GetError());
		return false;
	}
	m_Window = SDL_CreateWindow("Juego de prueba", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, 0);
	if (m_Window == nullptr)
	{
		SDL_Log("Error al crear Ventana: %s", SDL_GetError());
		return false;
	}

	m_Renderer = SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_Renderer == nullptr) {
		SDL_Log("Error al crear el render: %s", SDL_GetError());
		return false;
	}

	TextureManager::GetInstance()->Load("soldado", "Assets/Sprites/Armor.png");
	TextureManager::GetInstance()->Load("soldado_run", "Assets/Sprites/Armor.png");
	player = new Warrior(new Properties("soldado", 25, 50, 64, 64));
	player2 = new Warrior(new Properties("soldado_run", 100, 120, 64, 64));

	return m_IsRunning = true;
} 


bool Engine::Clean() {
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	IMG_Quit();
	SDL_Quit();
	return false;
}
void Engine::Quit() {
	m_IsRunning = false;
}

void Engine::Update() {
	float dt = TimerControler::GetInstance()->GetDeltaTime();
	player->Update(dt);
	player2->Update(dt);
}
void Engine::Render() {
	SDL_SetRenderDrawColor(m_Renderer, 120, 210, 35, 70);
	SDL_RenderClear(m_Renderer);
	//TextureManager::GetInstance()->Draw("Cactus", 100, 100, 108, 111);
	player->Draw();
	player2->Draw();

	SDL_RenderPresent(m_Renderer);
}
void Engine::Events() {
	InputHandler::GetInstance()->Listen();
}
