#include "pch.h"
#include "Day22Scene.h"
#include "GameObject.h"
#include "Collider.h"
void Day22Scene::Init()
{
	Super::Init();
	// 객체를 두개만들겁니다.
	{
		GameObject* gameObject = new GameObject();
		gameObject->SetName("김철수");
		gameObject->Init();

		//Component를 붙여줍니다.
		{
			Collider* collider = new Collider();
			collider->SetCollisionLayer(CollisionLayerType::CLT_CREATURE);
			collider->ResetCollisionFlagLayer();
			collider->AddCollisionFlagLayer(CollisionLayerType::CLT_CREATURE);
			collider->AddCollisionFlagLayer(CollisionLayerType::CLT_ITEM);
			//collider->RemoveCollisionFlagLayer(CollisionLayerType::CLT_ITEM);

			collider.setc

			gameObject->AddComponent(collider);
		}

		this->SpawnGameObject(gameObject);
	}


	{
		GameObject* gameObject = new GameObject();
		gameObject->SetName("김개똥");
		gameObject->Init();

		//Component를 붙여줍니다.
		{
			Collider* collider = new Collider();
			collider->SetCollisionLayer(CollisionLayerType::CLT_ITEM);
			collider->ResetCollisionFlagLayer();
			collider->AddCollisionFlagLayer(CollisionLayerType::CLT_CREATURE);
			//collider->RemoveCollisionFlagLayer(CollisionLayerType::CLT_CREATURE);

			gameObject->AddComponent(collider);
		}

		this->SpawnGameObject(gameObject);
	}

}
void Day22Scene::Render(HDC hdc)
{
	Super::Render(hdc);
	//씬 이름 출력
	{
		wstring nameStr = ::format(L"Day22Scene");
		Draw::Text(hdc, 0, 20, nameStr);
	}


}
void Day22Scene::Update()
{
	Super::Update();
}
void Day22Scene::Release()
{
	Super::Release();
}