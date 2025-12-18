#include <SFML/Graphics.hpp>
#include "Percolation.h"
#include <vector>
#include <random>
#include <string>
#include <optional>

const int N = 50;            // Increased Grid Size for better visuals
const int CELL_SIZE = 15;    // Smaller cells to fit screen
const int BORDER = 1;

int main(){
    unsigned int windowSize = N * CELL_SIZE;
    
    // Setup Window
    sf::RenderWindow window(sf::VideoMode({windowSize, windowSize}), "Percolation Sim | p = 0.00");
    window.setFramerateLimit(60); // Keep it smooth, the best framerate 

    //setup engine 

    Percolation perc(N);
    int openSiteCount=0;
    int totalSites =N*N ;

    //Setup Random Number generator 

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<>dis(0,N-1);//randomly open a block 

    while (window.isOpen()){
        //--EVENT HANDLING 

        while (const optional event=window.pollEvent()){
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            if (const auto* keyEvent = event->getIf<sf::Event::KeyPressed>()) {
                // RESET with 'R'
                if (keyEvent->code == sf::Keyboard::Key::R) {
                    perc = Percolation(N); // Re-initialize engine
                    openSiteCount = 0;
                    window.setTitle("Percolation Sim | p = 0.00");
                }
            
        }
    }

    //2.Physics Update (Fire Mode)
    //IF SPACE IS HELD, OEPN RANDOM SITES

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)){
        // Try to open a few sites per frame for speed
            for (int k = 0; k < 5; k++) {
                int r = dis(gen);
                int c = dis(gen);

                if (!perc.isOpen(r, c)) {
                    perc.open(r, c);
                    openSiteCount++;
                }
            }
            // Update Window Title with current stats
            double p = (double)openSiteCount / totalSites;
            std::string state = perc.percolates() ? "YES" : "NO";
            window.setTitle("p: " + std::to_string(p).substr(0, 4) + " | Percolates: " + state);
    }

    //Render the frames 
    window.clear(sf::Color::Black);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - BORDER, CELL_SIZE - BORDER));
                cell.setPosition({(float)j * CELL_SIZE, (float)i * CELL_SIZE});

                if (perc.isFull(i, j)) {
                    cell.setFillColor(sf::Color(255, 165, 0)); // fire (Full)
                } 
                else if (perc.isOpen(i, j)) {
                    cell.setFillColor(sf::Color::Green ); // Empty Hole
                } 
                else {
                    cell.setFillColor(sf::Color(50, 50, 50)); // Blocked
                }
                
                window.draw(cell);
            }
        }
        
        window.display();


}
return 0;
}
