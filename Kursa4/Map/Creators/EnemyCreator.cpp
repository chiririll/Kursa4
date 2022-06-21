#include "EnemyCreator.h"

Entity* EnemyCreator::create(const sf::Vector2<Uint16>& pos)
{
	// TODO: Randomize
	return new Enemy(pos, 100, 100, 1, 1, m_texture_path);
}
