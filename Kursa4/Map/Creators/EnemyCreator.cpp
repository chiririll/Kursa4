#include "EnemyCreator.h"

Entity* EnemyCreator::create(const sf::Vector2u& pos)
{
	// TODO: Randomize
	auto e = new Enemy(pos, 100, m_texture_path);
	e->setHealth(50);
	return e;
}
