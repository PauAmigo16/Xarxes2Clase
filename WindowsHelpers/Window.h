#pragma once
#include <list>
#include <mutex>

#include "Button.h"

class Window
{
public:
	/// <summary>
	/// Rememeber the the window is created on the constructor and the window cannot be touched elsewhere
	/// </summary>
	
	Window(unsigned int width = 800, unsigned int height = 600, std::string title = "Window");

	void AddButton(Button* bt);
	void RunWindowLoop();

private:

	std::mutex _mutex;
	sf::RenderWindow _window;

	Button* _lastClickedDownButton;
	std::list<Button*> _buttons;
	std::list<sf::Drawable*> _objectsToDraw;

};

