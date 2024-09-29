#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{

    // glfw: initialize and configure
    // ------------------------------
    //初始化GLFW
    glfwInit();

    //opengl 相关操作
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



 //在 Mac OS X 上您需要添加 glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 到您的初始化代码以使其正常工作。
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation   glfwCreateWindow 函数需要窗口宽度和高度分别作为其前两个参数。第三个参数允许我们为窗口创建一个名称；现在我们将其称为"LearnOpenGL"但您可以随意命名。我们可以忽略最后两个参数。该函数返回一个 GLFWwindow 对象
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    //将窗口上下文设置为当前线程的主上下文。
    glfwMakeContextCurrent(window);

    //注册每次调整窗口大小时调用此函数
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // 
    //加载OpenGL函数指针：

   // gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)的目的是从GLFW中获取OpenGL函数的地址并将其加载到GLAD中。
     //   这里的glfwGetProcAddress是GLFW提供的一个函数，用于根据函数名返回相应的OpenGL函数指针。
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    // render loop  渲染循环   glfwWindowShouldClose 函数在每次循环迭代开始时检查 GLFW 是否已被指示关闭。如果是这样，该函数返回true并且渲染循环停止运行，之后我们可以关闭应用程序。
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);

        //glfwPollEvents 函数检查是否触发了任何事件（如键盘输入或鼠标移动事件），更新窗口状态，并调用相应的函数（我们可以通过回调方法注册）。
        glfwPollEvents();
    }
        system("pause");
    // glfw: terminate, clearing all previously allocated GLFW resources.  理所有资源并正确退出应用程序
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    //返回当前是否按下该键
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        //glfwSetwindowShouldClose 将其WindowShouldClose属性设置为true来关闭 GLFW。
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.

    //glViewport的前两个参数设置窗口左下角的位置。第三个和第四个参数设置渲染窗口的宽度和高度（以像素为单位），我们将其设置为等于 GLFW 的窗口大小。
    glViewport(0, 0, width, height);
}
