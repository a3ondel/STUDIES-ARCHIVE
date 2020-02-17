#include "clickableRect.h"
#include "clickableRect.h"

clickableRect::clickableRect() :
    m_pressed(false),
    m_mouseHeld(false),
    m_active(false)
{};
    //do nothing


bool clickableRect::click(const sf::RenderWindow& window, const sf::Event& ev)
{
    if (ev.type == sf::Event::MouseButtonPressed && isInside(window) && !m_mouseHeld)
    {
        m_pressed = true;
        m_mouseHeld = true;
    }
    else if (ev.type == sf::Event::MouseButtonPressed)

        m_mouseHeld = true;


    if (ev.type == sf::Event::MouseButtonReleased)

        if (isInside(window) && m_pressed)
        {
        
        m_active = true;

        m_pressed = false;
        m_mouseHeld = false;
        }

return m_active;
}


void clickableRect::reset()
{
    m_active = false;
}

bool clickableRect::isInside(const sf::RenderWindow& window) const
{
    return (pow(-sf::Mouse::getPosition(window).x +getPosition().x, 2) + pow(-sf::Mouse::getPosition(window).y + getPosition().y, 2)) <= pow(getRadius(), 2);
}