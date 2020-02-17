#pragma once
#include <SFML/Graphics.hpp>
class clickableRect : public sf::CircleShape
{
public:
    clickableRect();

    bool click(const sf::RenderWindow& window, const sf::Event& ev);

    void reset();

    bool m_mouseHeld;
    bool m_pressed;
    bool m_active;

    bool isInside(const sf::RenderWindow& window) const;
    
    };