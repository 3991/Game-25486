#include <iostream>
#include <SFML/Graphics.hpp>
#include "./../Object.hpp"
#include <sstream>

namespace creator{
    class Creator {
    private:
        Pane pane;
        std::vector<sf::Vertex*> linesList;
        sf::Vertex currentLine[2];
        std::vector<sf::Vertex> vertices;
        std::vector<sf::Vertex> lines;
        bool createMode;
        sf::VertexArray llines;
        int numberLines;
        sf::ConvexShape l;
        Object object;
        sf::Text text;
    public:
        Creator(void);
        virtual ~Creator(void);
        void init(sf::Font &font, int fontSize);
        void draw(sf::RenderWindow &window);
        void createCurrentLine(int x, int y, int x2, int y2);
        void drawCurrentLine(sf::RenderWindow &window, int x2, int y2);
        void addLineList();
        void drawLines(sf::RenderWindow &window);
        sf::FloatRect getDrawningArea();
        void addText(sf::Font &font, int fontSize, const sf::String &message, const sf::Color &color, const sf::Vector2f &size, const int &number, const int &idPane, bool clickable);
        void addShape(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane, bool clickable);
        void addShape(const int &radius, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane, bool clickable);
        void addShape(const int &radius, const int &pointCount, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane, bool clickable);
        std::list<Content> getTexts(const int &idPane);
        std::list<Content> getShapes(const int &idPane);
        std::list<Content> getCircles(const int &idPane);
        void resetFamilysColors(const int &idPane, sf::Color color);
        void setColor(const int &idPane, const int &id, sf::Color color);
        void updateSelection(sf::RenderWindow &window);
        void setCreateMode(const bool createMode);
        bool getCreateMode() const;
        void setLines(std::vector<sf::Vertex> lines);
        sf::ConvexShape getLines() const;
        void linesUP();
    };

    const int DRAWNING_AREA_ID = 1;
    const int DRAWNING_AREA_WIDTH = 550;
    const int DRAWNING_AREA_HEIGHT = 400;
    const int DRAWNING_AREA_X = 20;
    const int DRAWNING_AREA_Y = 50;

    const int OPTIONS_AREA_ID = 1;
    const int OBJECT_SHAPE_ID = 1;
    const int OBJECT_TEXT_ID = 2;
    const int BUILDING_SHAPE_ID = 3;
    const int BUILDING_TEXT_ID = 4;

    const int POLLUTION_LESS_SHAPE_ID = 7;
    const int POLLUTION_LESS_TEXT_ID = 8;
    const int POLLUTION_NUMBER_TEXT_ID = 9;
    const int POLLUTION_MORE_SHAPE_ID = 10;
    const int POLLUTION_MORE_TEXT_ID = 11;
    const int POLLUTION_TEXT_ID = 12;

    const int LIFETIME_LESS_SHAPE_ID = 13;
    const int LIFETIME_LESS_TEXT_ID = 14;
    const int LIFETIME_NUMBER_TEXT_ID = 15;
    const int LIFETIME_MORE_SHAPE_ID = 16;
    const int LIFETIME_MORE_TEXT_ID = 17;
    const int LIFETIME_TEXT_ID = 18;

    const int HEALTH_LESS_SHAPE_ID = 19;
    const int HEALTH_LESS_TEXT_ID = 20;
    const int HEALTH_NUMBER_TEXT_ID = 21;
    const int HEALTH_MORE_SHAPE_ID = 22;
    const int HEALTH_MORE_TEXT_ID = 23;
    const int HEALTH_TEXT_ID = 24;

    const int LOVE_LESS_SHAPE_ID = 25;
    const int LOVE_LESS_TEXT_ID = 26;
    const int LOVE_NUMBER_TEXT_ID = 27;
    const int LOVE_MORE_SHAPE_ID = 28;
    const int LOVE_MORE_TEXT_ID = 29;
    const int LOVE_TEXT_ID = 30;

    const int SLEEP_LESS_SHAPE_ID = 31;
    const int SLEEP_LESS_TEXT_ID = 32;
    const int SLEEP_NUMBER_TEXT_ID = 33;
    const int SLEEP_MORE_SHAPE_ID = 34;
    const int SLEEP_MORE_TEXT_ID = 35;
    const int SLEEP_TEXT_ID = 36;

    const int SAFETY_LESS_SHAPE_ID = 37;
    const int SAFETY_LESS_TEXT_ID = 38;
    const int SAFETY_NUMBER_TEXT_ID = 39;
    const int SAFETY_MORE_SHAPE_ID = 40;
    const int SAFETY_MORE_TEXT_ID = 41;
    const int SAFETY_TEXT_ID = 42;

    const int CONFIRM_SHAPE_ID = 43;
    const int CONFIRM_TEXT_ID = 44;
}

using namespace creator;

Creator::Creator(void) {
}


Creator::~Creator(void) {
}

void Creator::init(sf::Font &font, int fontSize){
    createMode = false;
    numberLines = 1;

std::string jour = "Jour : ";


    std::string result;
    std::stringstream sstm;

    sstm << object.getLove();
    result = sstm.str();


    text.setString(result);


    addShape(sf::Vector2f(DRAWNING_AREA_WIDTH, DRAWNING_AREA_HEIGHT), sf::Vector2f(DRAWNING_AREA_X, DRAWNING_AREA_Y), sf::Color::White, 2, sf::Color(0, 0, 0), 0, DRAWNING_AREA_ID, true);

    addShape(sf::Vector2f(10, 10), {600.f, 50.f}, sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), OBJECT_SHAPE_ID, OPTIONS_AREA_ID, true);
    addText(font, fontSize, "Object", sf::Color(0, 0, 0, 255), {620.f, 42.f}, OBJECT_TEXT_ID, OPTIONS_AREA_ID, false);

    addShape(sf::Vector2f(10, 10), {600.f, 80.f}, sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), BUILDING_SHAPE_ID, OPTIONS_AREA_ID, true);
    sf::FloatRect buildingDetection(600, 80, 10, 10);
    addText(font, fontSize, "Building", sf::Color(0, 0, 0, 255), {620.f, 72.f}, BUILDING_TEXT_ID, OPTIONS_AREA_ID, false);


    addShape(sf::Vector2f(10, 10), {600.f, 160.f}, sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), POLLUTION_LESS_SHAPE_ID, OPTIONS_AREA_ID, true);
    sf::FloatRect pollutionLessDetection(600, 160, 10, 10);
    addText(font, fontSize, "-", sf::Color(0, 0, 0, 255), {603.f, 152.f}, POLLUTION_LESS_TEXT_ID, OPTIONS_AREA_ID, false);
    addText(font, fontSize, text.getString(), sf::Color(0, 0, 0, 255), {620.f, 152.f}, POLLUTION_NUMBER_TEXT_ID, OPTIONS_AREA_ID, false);
    addShape(sf::Vector2f(10, 10), {650.f, 160.f}, sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), POLLUTION_MORE_SHAPE_ID, OPTIONS_AREA_ID, true);
    sf::FloatRect pollutionMoreDetection(650, 160, 10, 10);
    addText(font, fontSize, "+", sf::Color(0, 0, 0, 255), {650.f, 152.f}, POLLUTION_MORE_TEXT_ID, OPTIONS_AREA_ID, false);
    addText(font, fontSize, "Pollution", sf::Color(0, 0, 0, 255), {670.f, 152.f}, POLLUTION_TEXT_ID, OPTIONS_AREA_ID, false);

    addShape(sf::Vector2f(10, 10), {600.f, 190.f}, sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0),LIFETIME_LESS_SHAPE_ID, OPTIONS_AREA_ID, true);
    sf::FloatRect lifetimeLessDetection(600, 190, 10, 10);
    addText(font, fontSize, "-", sf::Color(0, 0, 0, 255), {603.f, 182.f}, LIFETIME_LESS_TEXT_ID, OPTIONS_AREA_ID, false);
    addText(font, fontSize, "12", sf::Color(0, 0, 0, 255), {620.f, 182.f}, LIFETIME_NUMBER_TEXT_ID, OPTIONS_AREA_ID, false);
    addShape(sf::Vector2f(10, 10), {650.f, 190.f}, sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), LIFETIME_MORE_SHAPE_ID, OPTIONS_AREA_ID, true);
    sf::FloatRect lifetimeMoreDetection(650, 190, 10, 10);
    addText(font, fontSize, "+", sf::Color(0, 0, 0, 255), {650.f, 182.f}, LIFETIME_MORE_TEXT_ID, OPTIONS_AREA_ID, false);
    addText(font, fontSize, "Lifetime", sf::Color(0, 0, 0, 255), {670.f, 182.f}, LIFETIME_TEXT_ID, OPTIONS_AREA_ID, false);

    addShape(sf::Vector2f(10, 10), {600.f, 220.f}, sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), HEALTH_LESS_SHAPE_ID, OPTIONS_AREA_ID, true);
    sf::FloatRect healthLessDetection(600, 220, 10, 10);
    addText(font, fontSize, "-", sf::Color(0, 0, 0, 255), {603.f, 212.f}, HEALTH_LESS_TEXT_ID, OPTIONS_AREA_ID, false);
    addText(font, fontSize, "12", sf::Color(0, 0, 0, 255), {620.f, 212.f}, HEALTH_NUMBER_TEXT_ID, OPTIONS_AREA_ID, false);
    addShape(sf::Vector2f(10, 10), {650.f, 220.f}, sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), HEALTH_MORE_SHAPE_ID, OPTIONS_AREA_ID, true);
    sf::FloatRect healthMoreDetection(650, 220, 10, 10);
    addText(font, fontSize, "+", sf::Color(0, 0, 0, 255), {650.f, 212.f}, HEALTH_MORE_TEXT_ID, OPTIONS_AREA_ID, false);
    addText(font, fontSize, "Health", sf::Color(0, 0, 0, 255), {670.f, 212.f}, HEALTH_TEXT_ID, OPTIONS_AREA_ID, false);

    addShape(sf::Vector2f(10, 10), {600.f, 250.f}, sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), LOVE_LESS_SHAPE_ID, OPTIONS_AREA_ID, true);
    sf::FloatRect loveLessDetection(600, 250, 10, 10);
    addText(font, fontSize, "-", sf::Color(0, 0, 0, 255), {603.f, 242.f}, LOVE_LESS_TEXT_ID, OPTIONS_AREA_ID, false);
    addText(font, fontSize, "12", sf::Color(0, 0, 0, 255), {620.f, 242.f}, LOVE_NUMBER_TEXT_ID, OPTIONS_AREA_ID, false);
    addShape(sf::Vector2f(10, 10), {650.f, 250.f}, sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), LOVE_MORE_SHAPE_ID, OPTIONS_AREA_ID, true);
    sf::FloatRect loveMoreDetection(650, 250, 10, 10);
    addText(font, fontSize, "+", sf::Color(0, 0, 0, 255), {650.f, 242.f}, LOVE_MORE_TEXT_ID, OPTIONS_AREA_ID, false);
    addText(font, fontSize, "Love", sf::Color(0, 0, 0, 255), {670.f, 242.f}, LOVE_TEXT_ID, OPTIONS_AREA_ID, false);

    addShape(sf::Vector2f(10, 10), {600.f, 280.f}, sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), SLEEP_LESS_SHAPE_ID, OPTIONS_AREA_ID, true);
    sf::FloatRect sleepLessDetection(600, 280, 10, 10);
    addText(font, fontSize, "-", sf::Color(0, 0, 0, 255), {603.f, 272.f}, SLEEP_LESS_TEXT_ID, OPTIONS_AREA_ID, false);
    addText(font, fontSize, "12", sf::Color(0, 0, 0, 255), {620.f, 272.f}, SLEEP_NUMBER_TEXT_ID, OPTIONS_AREA_ID, false);
    addShape(sf::Vector2f(10, 10), {650.f, 280.f}, sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), SLEEP_MORE_SHAPE_ID, OPTIONS_AREA_ID, true);
    sf::FloatRect sleepMoreDetection(650, 280, 10, 10);
    addText(font, fontSize, "+", sf::Color(0, 0, 0, 255), {650.f, 272.f}, SLEEP_MORE_TEXT_ID, OPTIONS_AREA_ID, false);
    addText(font, fontSize, "Sleep", sf::Color(0, 0, 0, 255), {670.f, 272.f}, SLEEP_TEXT_ID, OPTIONS_AREA_ID, false);

    addShape(sf::Vector2f(10, 10), {600.f, 310.f}, sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), SAFETY_LESS_SHAPE_ID, OPTIONS_AREA_ID, true);
    sf::FloatRect safetyLessDetection(600, 310, 10, 10);
    addText(font, fontSize, "-", sf::Color(0, 0, 0, 255), {603.f, 302.f}, SAFETY_LESS_TEXT_ID, OPTIONS_AREA_ID, false);
    addText(font, fontSize, "12", sf::Color(0, 0, 0, 255), {620.f, 302.f}, SAFETY_NUMBER_TEXT_ID, OPTIONS_AREA_ID, false);
    addShape(sf::Vector2f(10, 10), {650.f, 310.f}, sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), SAFETY_MORE_SHAPE_ID, OPTIONS_AREA_ID, true);
    sf::FloatRect safetyMoreDetection(650, 310, 10, 10);
    addText(font, fontSize, "+", sf::Color(0, 0, 0, 255), {650.f, 302.f}, SAFETY_MORE_TEXT_ID, OPTIONS_AREA_ID, false);
    addText(font, fontSize, "Safety", sf::Color(0, 0, 0, 255), {670.f, 302.f}, SAFETY_TEXT_ID, OPTIONS_AREA_ID, false);


    addShape(25, sf::Vector2f(700, 500), sf::Color(255, 255, 255, 255), 2, sf::Color(0, 0, 0), CONFIRM_SHAPE_ID, OPTIONS_AREA_ID, true);
    addText(font, 50, ">", sf::Color::Green, {710.f, 490.f}, CONFIRM_TEXT_ID, OPTIONS_AREA_ID, false);
}

void Creator::draw(sf::RenderWindow &window){
    pane.draw(window);
}

void Creator::createCurrentLine(int x, int y, int x2, int y2){
    vertices.push_back(sf::Vertex(sf::Vector2f(x, y), sf::Color::Black));
    currentLine[0] = {sf::Vertex(sf::Vector2f(x, y), sf::Color::Red)};
    currentLine[1] = {sf::Vertex(sf::Vector2f(x2, y2), sf::Color::Red)};

}

void Creator::drawCurrentLine(sf::RenderWindow &window, int x2, int y2){
    currentLine[1] = {sf::Vertex(sf::Vector2f(x2, y2), sf::Color::Red)};
    window.draw(currentLine, 2, sf::Lines);
}

void Creator::addLineList(){
    /*linesList.push_back(currentLine);*/
    //vertices.push_back(sf::Vertex(sf::Vector2f(currentLine[0].position.x, currentLine[0].position.y), sf::Color::Black));
    vertices.push_back(sf::Vertex(sf::Vector2f(currentLine[1].position.x, currentLine[1].position.y), sf::Color::Black));
    numberLines++;
}

void Creator::drawLines(sf::RenderWindow &window){
    window.draw(&vertices[0], vertices.size(), sf::Lines);
    //window.draw(l);
}

sf::FloatRect Creator::getDrawningArea(){
    return sf::FloatRect(DRAWNING_AREA_X, DRAWNING_AREA_Y, DRAWNING_AREA_WIDTH, DRAWNING_AREA_HEIGHT);
}

void Creator::addText(sf::Font &font, int fontSize, const sf::String &message, const sf::Color &color, const sf::Vector2f &size, const int &number, const int &idPane, bool clickable){
    pane.addText(font, fontSize, message, color, size, number, clickable);
}

void Creator::addShape(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane, bool clickable){
    pane.addShape(size, position, color, thickness, thicknessColor, number, clickable);
}

void Creator::addShape(const int &radius, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane, bool clickable){
    pane.addShape(radius, position, color, thickness, thicknessColor, number, clickable);
}

void Creator::addShape(const int &radius, const int &pointCount, const sf::Vector2f &position, const sf::Color &color, float thickness, const sf::Color &thicknessColor, const int &number, const int &idPane, bool clickable){
    pane.addShape(radius, pointCount, position, color, thickness, thicknessColor, number, clickable);
}

std::list<Content> Creator::getTexts(const int &idPane){
    return pane.getTexts();
}

std::list<Content> Creator::getShapes(const int &idPane){
    return pane.getShapes();
}

std::list<Content> Creator::getCircles(const int &idPane){
    return pane.getCircles();
}

void Creator::resetFamilysColors(const int &idPane, sf::Color color){
    return pane.resetFamilysColors(color);
}

void Creator::setColor(const int &idPane, const int &id, sf::Color color){
    return pane.setColor(id, color);
}

void Creator::setCreateMode(const bool createMode){
    this->createMode = createMode;
}

bool Creator::getCreateMode() const{
    return this->createMode;
}

void Creator::setLines(std::vector<sf::Vertex> lines){

    llines = sf::VertexArray(sf::LinesStrip, numberLines);

    /*3 pas 2 car transformation des lignes individuelles en ligne connectées.
    Pour linesStrip reprend auto le dernier point de la dernière ligne pour commencer la new ligne*/

    /*llines[0].position = sf::Vector2f(lines[0].position.x, lines[0].position.y);std::cout << lines[0].position.x << "," << std::endl;std::cout << lines[0].position.y << std::endl;
    llines[0].color = sf::Color::Green;
    llines[1].position = sf::Vector2f(lines[1].position.x, lines[1].position.y);std::cout << lines[1].position.x << "," << std::endl;std::cout << lines[1].position.y << std::endl;
    llines[1].color = sf::Color::Green;
    llines[2].position = sf::Vector2f(lines[3].position.x, lines[3].position.y);std::cout << lines[3].position.x << "h," << std::endl;std::cout << lines[3].position.y << std::endl;
    llines[2].color = sf::Color::Green;
    llines[3].position = sf::Vector2f(lines[5].position.x, lines[5].position.y);std::cout << lines[5].position.x << "," << std::endl;std::cout << lines[5].position.y << std::endl;
    llines[3].color = sf::Color::Green;*/

    l.setPointCount(numberLines);
    int test = 0;
    for (int i=0; i<numberLines; i++){
        l.setPoint(i, sf::Vector2f(lines[test].position.x, lines[test].position.y));
        test +=2;
    }

    l.setFillColor(sf::Color::Green);
}

sf::ConvexShape Creator::getLines() const{
    return this->l;
}

void Creator::linesUP(){
l.move(+10,0);

    /*for(int i=0;i<numberLines;i++){
        llines[i].position = sf::Vector2f(5, 0);
    }*/

}

void Creator::updateSelection(sf::RenderWindow &window){

    sf::FloatRect objectDetection(600, 50, 10, 10);
    sf::FloatRect buildingDetection(600, 80, 10, 10);
    sf::FloatRect confirmDetection(700, 500, 50, 50);

    if(objectDetection.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        resetFamilysColors(OPTIONS_AREA_ID ,sf::Color::Black);
        setColor(OPTIONS_AREA_ID, OBJECT_SHAPE_ID, sf::Color::Red);
    }else if(buildingDetection.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        resetFamilysColors(OPTIONS_AREA_ID ,sf::Color::Black);
        setColor(OPTIONS_AREA_ID, BUILDING_SHAPE_ID, sf::Color::Red);
    }


    sf::FloatRect pollutionLessDetection(600, 160, 10, 10);
    sf::FloatRect pollutionMoreDetection(650, 160, 10, 10);

    sf::FloatRect lifetimeLessDetection(600, 190, 10, 10);
    sf::FloatRect lifetimeMoreDetection(650, 190, 10, 10);

    sf::FloatRect healthMoreDetection(600, 220, 10, 10);
    sf::FloatRect healthLessDetection(650, 220, 10, 10);

    sf::FloatRect loveLessDetection(600, 250, 10, 10);
    sf::FloatRect loveMoreDetection(650, 250, 10, 10);

    sf::FloatRect sleepLessDetection(600, 280, 10, 10);
    sf::FloatRect sleepMoreDetection(650, 280, 10, 10);

    sf::FloatRect safetyLessDetection(600, 310, 10, 10);
    sf::FloatRect safetyMoreDetection(650, 310, 10, 10);

    if(pollutionLessDetection.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::string result;
        std::stringstream sstm;
        int tmp = object.getPollution();
        tmp--;
        if(tmp < 0) tmp = 0;
        sstm << tmp;
        result = sstm.str();

        pane.setText(POLLUTION_NUMBER_TEXT_ID, result);
    }else if(pollutionMoreDetection.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::string result;
        std::stringstream sstm;
        int tmp = object.getPollution();
        tmp++;

        sstm << tmp;
        result = sstm.str();

        pane.setText(POLLUTION_NUMBER_TEXT_ID, result);
    }else if(lifetimeLessDetection.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::string result;
        std::stringstream sstm;
        int tmp = object.getLifetime();
        tmp--;
        if(tmp < 0) tmp = 0;
        sstm << tmp;
        result = sstm.str();

        pane.setText(LIFETIME_NUMBER_TEXT_ID, result);
    }else if(lifetimeMoreDetection.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::string result;
        std::stringstream sstm;
        int tmp = object.getLifetime();
        tmp++;

        sstm << tmp;
        result = sstm.str();

        pane.setText(LIFETIME_NUMBER_TEXT_ID, result);
    }else if(healthLessDetection.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::string result;
        std::stringstream sstm;
        int tmp = object.getHealth();
        tmp--;
        if(tmp < 0) tmp = 0;
        sstm << tmp;
        result = sstm.str();

        pane.setText(HEALTH_NUMBER_TEXT_ID, result);
    }else if(healthMoreDetection.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::string result;
        std::stringstream sstm;
        int tmp = object.getHealth();
        tmp++;

        sstm << tmp;
        result = sstm.str();

        pane.setText(HEALTH_NUMBER_TEXT_ID, result);
    }else if(loveLessDetection.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::string result;
        std::stringstream sstm;
        int tmp = object.getLove();
        tmp--;
        if(tmp < 0) tmp = 0;
        sstm << tmp;
        result = sstm.str();

        pane.setText(LOVE_NUMBER_TEXT_ID, result);
    }else if(loveMoreDetection.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::string result;
        std::stringstream sstm;
        int tmp = object.getLove();
        tmp++;

        sstm << tmp;
        result = sstm.str();

        pane.setText(LOVE_NUMBER_TEXT_ID, result);
    }else if(sleepLessDetection.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::string result;
        std::stringstream sstm;
        int tmp = object.getSleep();
        tmp--;
        if(tmp < 0) tmp = 0;
        sstm << tmp;
        result = sstm.str();

        pane.setText(SLEEP_NUMBER_TEXT_ID, result);
    }else if(sleepMoreDetection.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::string result;
        std::stringstream sstm;
        int tmp = object.getSleep();
        tmp++;

        sstm << tmp;
        result = sstm.str();

        pane.setText(SLEEP_NUMBER_TEXT_ID, result);
    }else if(safetyLessDetection.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::string result;
        std::stringstream sstm;
        int tmp = object.getSafety();
        tmp--;
        if(tmp < 0) tmp = 0;
        sstm << tmp;
        result = sstm.str();

        pane.setText(SAFETY_NUMBER_TEXT_ID, result);
    }else if(safetyMoreDetection.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        std::string result;
        std::stringstream sstm;
        int tmp = object.getSafety();
        tmp++;

        sstm << tmp;
        result = sstm.str();

        pane.setText(SAFETY_NUMBER_TEXT_ID, result);
    }


    if(confirmDetection.contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && getCreateMode()) {
        setLines(vertices);
        setCreateMode(false);
    }
}
