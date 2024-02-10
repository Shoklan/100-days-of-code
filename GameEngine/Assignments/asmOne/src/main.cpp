#include <iostream>
#include <memory>
#include <fstream>


 #include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

int main( int argc, char * argv[]){
    /// Create a new window of size w*h
    const int wWidth = 1280;
    const int wHeight = 720;

    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML Works!");
    window.setFramerateLimit(60); // limit to 60 fps

    //Initialize IMGUI
    ImGui::SFML::Init(window);
    sf::Clock deltaClock;

    // scale the imgui by a given factor, does not affect the text size
    ImGui::GetStyle().ScaleAllSizes(1.0f);

    // the imgui color
    float c[3] = { 0.0f, 1.0f, 1.0f};

    // shapes!
    float circleRadius = 50;
    int circleSegments = 32; 
    float circleSpeedX = 1.0f;
    float circleSpeedY = .5f;
    bool drawCircle = true;
    bool drawText = true;

    sf::CircleShape circle(circleRadius, circleSegments);
    circle.setPosition(10.0f, 10.0f);

    sf::Font myFont;

    if( !myFont.loadFromFile("fonts/ProtestGuerrillaRegular.ttf")){
        std::cerr << "Could not find the font!" << std::endl;
        exit(-1);
    }
    
    sf::Text text("Sample Text", myFont, 24);
    text.setPosition(0, wHeight - (float)text.getCharacterSize());
    char displayString[255] = "Sample Text";

    while( window.isOpen()){
        sf::Event event;
        while( window.pollEvent(event)){
            ImGui::SFML::ProcessEvent(window, event);

            // close window if asked
            if( event.type == sf::Event::Closed){ window.close();}
            if( event.type == sf::Event::KeyPressed){
                std::cout
                    << "Key pressed with code = "
                    << event.key.code
                    << std::endl;

                // then reverse the circle direction
                circleSpeedX *= -1.0f;
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        // draw the UI
        ImGui::Begin("Window Title");
        ImGui::Text("Window text!");
        ImGui::Checkbox("Draw Circle", &drawCircle);
        ImGui::SameLine();
        ImGui::Checkbox("Draw Text", &drawText);
        ImGui::SliderFloat("Radius", &circleRadius, 0.0f, 300.0f);
        ImGui::SliderInt("Sides", &circleSegments, 3, 64);
        ImGui::ColorEdit3("Color Circle", c);
        ImGui::InputText("Text", displayString, 255);
        if( ImGui::Button("Set Text")){ text.setString(displayString); }
        ImGui::SameLine();
        if( ImGui::Button("Reset Circle")){ circle.setPosition(0,0); }
        ImGui::End();

        circle.setFillColor(sf::Color( c[0]*255, c[1]*255, c[2]*255 ));
        circle.setPointCount(circleSegments);
        circle.setRadius(circleRadius);

        // basic animation for the circle
        circle.setPosition(
            circle.getPosition().x + circleSpeedX,
            circle.getPosition().y + circleSpeedY
        );

        // basic rendering
        window.clear(); //sf::Color::Black
        if( drawCircle ){ window.draw(circle); }
        if( drawText ){   window.draw(text); }
        
        ImGui::SFML::Render(window);
        window.display();
    }

    return 0;
}