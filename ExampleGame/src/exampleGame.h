#include <CCEngine.h>

class ExampleGame : public Game
{
    public:
        void init(std::string title, int width, int height) override;
        void update(float dt) override {};
        void run() override;
        void lateUpdate() override {};
        void render() override {};
        void shutDown() override {};
    
};