#include <core/WindowManager.hpp>
#include <graphics/RendererManager.hpp>
#include <graphics/Texture2D.hpp>

int main(int argc, char const *argv[])
{
    auto& wm = WindowManager::getInstance();
    if (!wm.initialize(900, 800, "Game framework")) {
        wm.shutdown();
        return -1;
    }

    auto& renderer = RendererManager::getInstance();
    renderer.initialize(900, 800);

    wm.setRenderer(&renderer);

    Texture2D box = Texture2D();
    box.loadFromFile("./assets/textures/container.jpg");
    
    Texture2D smile = Texture2D();
    smile.loadFromFile("./assets/textures/awesomeface.png");


    while (!wm.shouldClose()) {
        renderer.clear();

        renderer.update();


        // renderer.drawTexture(box, glm::vec2(0.f, 0.f));
        renderer.drawTests(smile, box, glm::vec2(-0.5f, -0.5f));

    
        wm.pollEvents();
        wm.swapBuffers();
    }
    
    wm.shutdown();
    return 0;
}
