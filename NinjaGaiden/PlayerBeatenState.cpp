#include "PlayerBeatenState.h"
#include"Textures.h"

PlayerBeatenState::PlayerBeatenState(PlayerData*data)
{
	this->playerData = data;
	auto texs = Textures::GetInstance();
	m_Animation = new Animation();
	m_Animation->AddFramesA(texs->Get(TEX_PLAYER), 10, 10, 2, 10, 4, PLAYER_JUMPING_FRAME * (1.0f / 60));
}

PlayerBeatenState::~PlayerBeatenState()
{
}

void PlayerBeatenState::Render() {
	m_Animation->Render(playerData->player->GetPosition(), BoxCollider(), D3DCOLOR_XRGB(255, 255, 255), playerData->player->GetMoveDirection() == Entity::EntityDirection::RightToLeft);
}

void PlayerBeatenState::HandleInput()
{

}

void PlayerBeatenState::OnCollision(Entity * impactor, Entity::SideCollision side) {

}

PlayerState::State PlayerBeatenState::GetState() {
	return Beaten;
}

void PlayerBeatenState::ResetState(int dummy) {
	auto player = playerData->player;
	player->SetColliderLeft(-9);
	player->SetColliderTop(16);
	player->SetColliderBottom(-6);
	player->isHurting = true;
	player->HurtingTime = 0;

	if (!player->onAir)
		playerData->player->SetVy(0.75*PLAYER_MIN_JUMP_VELOCITY);
	
	PlayerState::ResetState(dummy);
}