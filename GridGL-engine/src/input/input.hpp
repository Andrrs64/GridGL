#ifndef INPUT_H
#define INPUT_H

#include <unordered_map>
#include <GLFW/glfw3.h>
#include <functional>

namespace ggl {

class InputService {
public:
    void mapMethod(unsigned int button, std::function<void()> method);

    void processInput(GLFWwindow* window);

private:
    std::unordered_map<unsigned int, std::function<void()>> mappings;
};

}


#endif // !INPUT_H
