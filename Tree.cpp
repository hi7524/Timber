#include "stdafx.h"
#include "Tree.h"


void Tree::SetPosition(const sf::Vector2f& pos)
{
	position = pos;
	tree.setPosition(pos);

	for (int i = 0; i < branches.size(); i++)
	{
		branches[i].setPosition(pos.x, 150.0f * i);
	}
}

void Tree::SetLastBranch()
{
	branchesSide[branchesSide.size() - 1] = Sides::None;
}

Sides Tree::UpdateBranches()
{
	for (int i = branchesSide.size() - 1; i >  0; i--)
	{
		branchesSide[i] = branchesSide[i - 1];
	}
	branchesSide[0] = (Sides)Utils::RandomRange(0, 3);

	for (int i = 0; i < branchesSide.size(); i++)
	{
		if (branchesSide[i] == Sides::Left)
		{
			branches[i].setScale(-1.f, 1.f);
		}
		else if (branchesSide[i] == Sides::Right)
		{
			branches[i].setScale(1.f, 1.f);
		}
	}

	return branchesSide[0];
}

void Tree::Init()
{
	texIdTree = "graphics/tree.png";
	texIdBranches = "graphics/branch.png";

	branches.resize(6); // 6으로 branches 배열의 크기 설정
	branchesSide.resize(6);
}

void Tree::Release()
{
}

void Tree::Reset()
{
	tree.setTexture(TEXTURE_MGR.Get(texIdTree), true);
	Utils::SetOrigin(tree, Origins::TC);

	sf::FloatRect bounds = tree.getLocalBounds();

	for (int i = 0; i < branches.size(); i++)
	{
		branches[i].setTexture(TEXTURE_MGR.Get(texIdBranches));
		branches[i].setOrigin(bounds.width * -0.5f, 0.0f);

		branchesSide[i] = (Sides)Utils::RandomRange(0, 3);

		// 방향에 따른 Scale 설정
		if (branchesSide[i] == Sides::Left)
		{
			branches[i].setScale(-1.f, 1.f);
		}
		else if (branchesSide[i] == Sides::Right)
		{
			branches[i].setScale(1.f, 1.f);
		}
	}
	branchesSide[branches.size() - 1] = Sides::None;

	sf::FloatRect windowBounds = FRAMEWORK.GetWindowBounds();
	SetPosition({ windowBounds.width * 0.5f, 0.0f });
}

void Tree::Update(float dt)
{

}

void Tree::Draw(sf::RenderWindow& window)
{
	window.draw(tree);

	for (int i = 0; i < branches.size(); i++)
	{
		if (branchesSide[i] != Sides::None)
		{
			window.draw(branches[i]);
		}
	}
}