#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

int main() {

	const int width = 1200;
	Vector2i window_size = Vector2i(width,800);
	RenderWindow* window = new RenderWindow(VideoMode(window_size.x,window_size.y), "Bubble Sorting");
	window->setFramerateLimit(60);

	srand(time(0));

	int heights[width];
	for (int i = 0; i < width; i++) {
		heights[i] = rand() % window_size.y + 1;
	}

	int i = 0;
	int j = 0;

	while (window->isOpen()) {
		Event event;
		while (window->pollEvent(event)) {
			if (event.type == Event::Closed)
				window->close();
		}

		// Sorting
		if (heights[j] > heights[j + 1]) {
			int temp = heights[j];
			heights[j] = heights[j + 1];
			heights[j + 1] = temp;
		}
		if (i < width) {
			j++;
			if (j >= width - 1 - i) {
				j = 0;
				i++;
			}
		}
		

		window->clear(Color(0, 0, 0));

		// Draw
		for (int i = 0; i < width; i++) {
			RectangleShape t_rect(Vector2f(1, heights[i]));
			t_rect.setFillColor(Color(0, 255, 0));
			t_rect.setPosition(i, window_size.y - heights[i]);
			window->draw(t_rect);
		}
			
		window->display();
	}

	return 0;
}