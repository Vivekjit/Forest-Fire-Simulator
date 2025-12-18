#include <SFML/Graphics.hpp>
#include "Percolation.h"
#include <bits/stdc++.h>
 
using namespace std;

//Config 

const int N =20 ; //Grid size
const int CELL_SIZE=30;
const int BORDER=1;//grid line thickness

int main (){
    //creating the window 
   // Change 'int' to 'unsigned int'
unsigned int windowSize = N * CELL_SIZE;


// SFML 3.0 CHANGE: VideoMode now takes a "Vector2u" inside curly braces {}
    sf::RenderWindow window(sf::VideoMode({windowSize, windowSize}), "Percolation Simulator");

Percolation perc(N);
while (window.isOpen()) {
        // SFML 3.0 CHANGE: pollEvent returns an std::optional, not a boolean
        while (const std::optional event = window.pollEvent()) {
            
            // 1. Handle Window Close
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            // 2. Handle Mouse Click
            // SFML 3.0 CHANGE: We use getIf to check for specific event types
            if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouseEvent->button == sf::Mouse::Button::Left) {
                    int col = mouseEvent->position.x / CELL_SIZE;
                    int row = mouseEvent->position.y / CELL_SIZE;

                    if (row >= 0 && row < N && col >= 0 && col < N) {
                        perc.open(row, col);
                    }
                }
            }
        }

        window.clear(sf::Color::Black);

        for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - BORDER, CELL_SIZE - BORDER));
        cell.setPosition({(float)j * CELL_SIZE, (float)i * CELL_SIZE});

        // --- THE NEW COLOR LOGIC ---
        if (perc.isFull(i, j)) {
            // Connected to Top -> BLUE (Water)
            cell.setFillColor(sf::Color(255, 165, 0)); 
        } 
        else if (perc.isOpen(i, j)) {
            // Open but empty -> WHITE
            cell.setFillColor(sf::Color::Green); 
        } 
        else {
            // Blocked -> GREY/BLACK
            cell.setFillColor(sf::Color(50, 50, 50)); 
        }
        
        window.draw(cell);
    }
}
        
        window.display();
    }
    return 0;
}