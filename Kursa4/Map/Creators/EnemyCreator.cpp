#include "EnemyCreator.h"

Entity* EnemyCreator::create(const sf::Vector2<Uint16>& pos)
{
	// TODO: Randomize
	return new Enemy(pos, 100, m_texture_path);
}
