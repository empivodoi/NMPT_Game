#include "PlayerUseSkillState.h"
#include "Textures.h"
#include"Debug.h"
PlayerUseSkillState::PlayerUseSkillState(PlayerData * data) {
	this->playerData = data;
	auto texs = Textures::GetInstance();
	m_Animation = new Animation();
	m_Animation->AddFramesA(texs->Get(TEX_PLAYER), 3, 3, 3, 10, 4, 0.15f);
	turn = FirstTurn;
	grid = Grid::GetInstance(BoxCollider(224, 0, 0, 2048));
}

PlayerUseSkillState::~PlayerUseSkillState() {
}

void PlayerUseSkillState::Update(double dt) {
	m_Animation->Update(dt);
	int currentFrame = m_Animation->GetCurrentFrameID();
	if (playerData->player->GetSkill() == Player::NoneSkill)	
		if (m_Animation->IsLastFrame(dt))
			playerData->player->SetState(Idle);
		
	if (playerData->player->GetSkill() == Player::BlueShuriken)
	{
	//	DebugOut(L"%f\n", m_Animation->GetPercentTime());
		ryuWeapon_Turn1 = new BlueShuriken();
		ryuWeapon_Turn2 = new BlueShuriken();
		ryuWeapon_Turn3 = new BlueShuriken();
		//First turn
		if ((m_Animation->GetPercentTime() > 0.03&& m_Animation->GetPercentTime() < 0.04) && turn == FirstTurn)
			{
				ryuWeapon_Turn1->SetActive(true);
				ryuWeapon_Turn1->SetMoveDirection(playerData->player->GetMoveDirection());
				if (playerData->player->GetMoveDirection() == Entity::LeftToRight) {
					ryuWeapon_Turn1->SetPosition(playerData->player->GetPosition().x + 22, playerData->player->GetPosition().y + 6); //	
					ryuWeapon_Turn1->SetVx((BLUE_SHURIKEN_VELOCITY_X));
				}
				else
				{
					ryuWeapon_Turn1->SetPosition(playerData->player->GetPosition().x - 22, playerData->player->GetPosition().y + 6); //	
					ryuWeapon_Turn1->SetVx((-BLUE_SHURIKEN_VELOCITY_X));
				}
				ryuWeapon_Turn1->SetAliveState(Entity::Alive);
				Unit* unit;
				unit = new Unit(grid, ryuWeapon_Turn1);
			}
			else
			{
				ryuWeapon_Turn1->SetActive(false);
			}

		//Second Turn
		if ((m_Animation->GetPercentTime() > 0.03&& m_Animation->GetPercentTime() < 0.04) && turn == SecondTurn)
		{
			ryuWeapon_Turn2->SetActive(true);
			ryuWeapon_Turn2->SetMoveDirection(playerData->player->GetMoveDirection());
			if (playerData->player->GetMoveDirection() == Entity::LeftToRight) {
				ryuWeapon_Turn2->SetPosition(playerData->player->GetPosition().x + 22, playerData->player->GetPosition().y + 6); //	
				ryuWeapon_Turn2->SetVx((BLUE_SHURIKEN_VELOCITY_X));
			}
			else // 8 6
			{
				ryuWeapon_Turn2->SetPosition(playerData->player->GetPosition().x - 22, playerData->player->GetPosition().y + 6); //	
				ryuWeapon_Turn2->SetVx((-BLUE_SHURIKEN_VELOCITY_X));
			}
			ryuWeapon_Turn2->SetAliveState(Entity::Alive);
			Unit* unit;
			unit = new Unit(grid, ryuWeapon_Turn2);
		}
		else
		{
			ryuWeapon_Turn2->SetActive(false);
		}

		//Third Turn
		if ((m_Animation->GetPercentTime() > 0.03&& m_Animation->GetPercentTime() < 0.04) && turn ==ThirdTurn)
		{
			ryuWeapon_Turn3->SetActive(true);
			ryuWeapon_Turn3->SetMoveDirection(playerData->player->GetMoveDirection());
			if (playerData->player->GetMoveDirection() == Entity::LeftToRight) {
				ryuWeapon_Turn3->SetPosition(playerData->player->GetPosition().x + 22, playerData->player->GetPosition().y + 6); //	
				ryuWeapon_Turn3->SetVx((BLUE_SHURIKEN_VELOCITY_X));
			}
			else // 8 6
			{
				ryuWeapon_Turn3->SetPosition(playerData->player->GetPosition().x - 22, playerData->player->GetPosition().y + 6); //	
				ryuWeapon_Turn3->SetVx((-BLUE_SHURIKEN_VELOCITY_X));
			}
			ryuWeapon_Turn3->SetAliveState(Entity::Alive);
			Unit* unit;
			unit = new Unit(grid, ryuWeapon_Turn3);
		}
		else
		{
			ryuWeapon_Turn3->SetActive(false);
		}

		if (m_Animation->IsLastFrame(dt)) // Cai nay khong biet da dung chua
		{
			if (turn == FirstTurn)
				turn = SecondTurn;
			else if (turn == SecondTurn)
				turn = ThirdTurn;
			else if(turn == ThirdTurn)
				turn = FirstTurn;
			playerData->player->SetState(Idle);
		}
		return;
	}
}

void PlayerUseSkillState::Render() {
	m_Animation->Render(playerData->player->GetPosition(), BoxCollider(), D3DCOLOR_XRGB(255, 255, 255), playerData->player->GetMoveDirection() == Entity::EntityDirection::RightToLeft);
}

void PlayerUseSkillState::HandleInput() {
	KeyBoard* keyboard = KeyBoard::GetInstance();
	//Hung xu ly ho cac truong hop Input
}

void PlayerUseSkillState::OnCollision(Entity * impactor, Entity::SideCollision side) {
	if ((impactor->GetType() == Entity::EnemyType||impactor->GetType()==Entity::EnemyWeaponType) && playerData->player->timeHurtingAnimation == 0)
	{
		playerData->player->SetState(Beaten);
		return;
	}
}

PlayerState::State PlayerUseSkillState::GetState() {
	return UseSkill;
}

void PlayerUseSkillState::ResetState(int dummy) {
	auto player = playerData->player;
	player->SetColliderLeft(-9);
	player->SetColliderTop(16);
	player->SetColliderBottom(-16);

	PlayerState::ResetState(dummy);
}
