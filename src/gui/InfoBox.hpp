#include <iostream>
#include <SFML/Graphics.hpp>


class InfoBox : public sf::RectangleShape {
    private:

    public:
        InfoBox(void);
        void test();
};

InfoBox::InfoBox(void) {
}

void InfoBox::test() {
std::cout << "Hello world!" << std::endl;

}

