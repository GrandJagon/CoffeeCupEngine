#include <iostream>
#include <cstring>
#include "rendering/shaders/Shader.h"
#include "rendering/renderer/Renderer.h"
#include "vendors/imgui/imgui.h"
#include "vendors/imgui/imgui_impl_glfw_gl3.h"
#include "utils/utilities.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

int main(void)
{   

    GLFWwindow* window;

   
    /* Initialize the library */
    if (!glfwInit())
        return -1;


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    GlCall(glfwMakeContextCurrent(window));
    
    // Sets the appropriate blending function for displaying
    GlCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
    
    glewExperimental = GL_TRUE;

    if(glewInit() != GLEW_OK){
        std::cout << "Glew init error" << std::endl;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    //ImGui variables
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    
    // Initiating ImGUI
    ImGui::CreateContext();
    ImGui_ImplGlfwGL3_Init(window, true);
    ImGui::StyleColorsDark();

    Renderer::init(1000);
    
    // Projection matrix
    glm::mat4 proj = glm::ortho(0.0f, (float) WINDOW_WIDTH, 0.0f, (float) WINDOW_HEIGHT, -1.0f, 1.0f);

    // Translation vector to be combined with identity matrix
    glm::vec3 translation = glm::vec3(0.0f,0.0f,0.0f);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {   

        // Translation moves camera such as negative -> left,  positive -> right
        glm::mat4 view = glm::translate(glm::mat4(1.0f), translation);

        glm::mat4 model = glm::mat4(1.0f);
    
        // For MVP multiplication order is reversed in openGL
        glm::mat4 mvp = proj * view * model;

        GlCall(glClear(GL_COLOR_BUFFER_BIT));

        //Sets MVP
        Renderer::setMVP(mvp);


        for(int i = 0; i < 20; i++)
        {    
            for(int j = 0; j < 20; j++)
            {
                // Color call
                Renderer::draw({ 0.0f + (i * 100), 0.0f + (j * 100) }, { 100.0f, 100.0f }, {0.034f, 0.139f, 0.028f, 1.0f});
            }
        }
        

        // Texture call
        Renderer::draw({ 50.0f ,50.0f }, { 100.0f, 100.0f }, 1.0f);

        Renderer::render();

        Renderer::endFrame();
        
        ImGui_ImplGlfwGL3_NewFrame();


        // ImGui window
         {
            ImGui::SliderFloat3("Translation x", &translation.x, -200.0f, (float) WINDOW_WIDTH);
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::Text("Number of batches : %.1i" , Renderer::renderCalls());
        }
       
        // Rendering Im Gui
        ImGui::Render();
        ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
        
        /* Swap front and back buffers */
        GlCall(glfwSwapBuffers(window));

        /* Poll for and process events */
        GlCall(glfwPollEvents());
    }
    
    // Disposing of ImGui objects
    ImGui_ImplGlfwGL3_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();
    return 0;
}