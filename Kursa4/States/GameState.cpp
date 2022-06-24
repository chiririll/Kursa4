#include "GameState.h"

GameState::GameState(Game* game, sf::Vector2u map_size, bool gen_camps) :
	State(game), m_player(map_size.x / 2, map_size.y / 2, 100, m_player_texture), 
    m_map(map_size), m_generate_camps(gen_camps)
{
    m_game->view()->zoom(1.2f);

    initMap();
}

GameState::~GameState()
{
    auto screen = m_game->window()->getSize();
    m_game->view()->reset(sf::FloatRect(0, 0, screen.x, screen.y));
}

// Initializing map
void GameState::initMap()
{
    Uint32 max = m_map.width() > m_map.height() ? m_map.width() : m_map.height();

    m_map.addPlayer(&m_player);

    // Camps
    auto camp_creator = new CampCreator();
    if (m_generate_camps)
        camp_creator->setCount(max / 2, max);
    else
        camp_creator->setExit();
        
    m_map.addCreator(camp_creator);

    // Enemies
    auto enemy_creator = new EnemyCreator();
    enemy_creator->setCount(max / 2, max);
    m_map.addCreator(enemy_creator);

    // Trees
    auto tree_creator = new TreeCreator();
    tree_creator->setCount(max / 2, max);
    m_map.addCreator(tree_creator);

    // Generating map
    m_map.generate();
}


void GameState::render()
{
    // Rendering map and entities
	m_map.render(m_game->window());

    // Rendering player
    m_player.render(m_game->window());

    // Cenntering camera on player
    m_game->view()->setCenter(
        m_player.x() * BLOCK_SIZE + (float)BLOCK_SIZE / 2,
        m_player.y() * BLOCK_SIZE + (float)BLOCK_SIZE / 2
    );
}

void GameState::update()
{
    m_map.update();
}

void GameState::handleMouseClick(sf::Event& e)
{
    sf::Vector2u map_pos = cords::screen2map(sf::Mouse::getPosition(*m_game->window()), m_game->window());
    cout << "World: " << map_pos.x << " " << map_pos.y << endl;

    // Out of map
    if (map_pos.x >= m_map.width() || map_pos.y >= m_map.height())
        return;

    if (e.mouseButton.button == sf::Mouse::Button::Left)
    { // Move
        if (!m_map.checkBlock(map_pos))
            m_player.setPos(map_pos);
    }
    else if (e.mouseButton.button == sf::Mouse::Button::Right)
    { // Interact
        auto ent = m_map.getEntity(map_pos);
        if (ent)
            ent->interact(m_game);
    }
}
