#include "Warrior.h"
#include "TextureManager.h"
#include "SDL.h"
#include "InputHandler.h"

Warrior::Warrior(Properties* props): Character(props) {
	m_RigidBody = new RigidBody();
	m_Animation = new Animation();
	m_Animation->SetProps(m_TextureID, 4, 6, 50);
}

void Warrior::Draw() {
	//TextureManager::GetInstance()->DrawFrame(m_TextureID, m_Transform->X, m_Transform->Y, m_Width, m_Height, m_Row, m_Frame);
	m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}
void Warrior::Clean() {
	TextureManager::GetInstance()->Clean();
}
void Warrior::Update(float dt) {

	m_Animation->SetProps("soldado", 1, 6, 60);
	m_RigidBody->UnSetForce();

	if (InputHandler::GetInstance()->GetKeyDown(SDL_SCANCODE_A)) {
		m_RigidBody->ApplyForceX(7*FORWARD);
		m_Animation->SetProps("soldado_run", 4, 6, 100);
	}

	if (InputHandler::GetInstance()->GetKeyDown(SDL_SCANCODE_D)) {
		m_RigidBody->ApplyForceX(7*BACKWARD);
		m_Animation->SetProps("soldado_run", 4, 6, 100, SDL_FLIP_HORIZONTAL);
	}

	m_RigidBody->Update(0.7f);
	
	m_Transform->TranslateX(m_RigidBody->Position().X);
	//m_Transform->TranslateY(m_RigidBody->Position().Y);
	m_Animation->Update();
}
