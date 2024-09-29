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
    //��ʼ��GLFW
    glfwInit();

    //opengl ��ز���
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



 //�� Mac OS X ������Ҫ��� glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); �����ĳ�ʼ��������ʹ������������
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation   glfwCreateWindow ������Ҫ���ڿ�Ⱥ͸߶ȷֱ���Ϊ��ǰ����������������������������Ϊ���ڴ���һ�����ƣ��������ǽ����Ϊ"LearnOpenGL"���������������������ǿ��Ժ�����������������ú�������һ�� GLFWwindow ����
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    //����������������Ϊ��ǰ�̵߳��������ġ�
    glfwMakeContextCurrent(window);

    //ע��ÿ�ε������ڴ�Сʱ���ô˺���
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // 
    //����OpenGL����ָ�룺

   // gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)��Ŀ���Ǵ�GLFW�л�ȡOpenGL�����ĵ�ַ��������ص�GLAD�С�
     //   �����glfwGetProcAddress��GLFW�ṩ��һ�����������ڸ��ݺ�����������Ӧ��OpenGL����ָ�롣
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    // render loop  ��Ⱦѭ��   glfwWindowShouldClose ������ÿ��ѭ��������ʼʱ��� GLFW �Ƿ��ѱ�ָʾ�رա�������������ú�������true������Ⱦѭ��ֹͣ���У�֮�����ǿ��Թر�Ӧ�ó���
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);

        //glfwPollEvents ��������Ƿ񴥷����κ��¼�����������������ƶ��¼��������´���״̬����������Ӧ�ĺ��������ǿ���ͨ���ص�����ע�ᣩ��
        glfwPollEvents();
    }
        system("pause");
    // glfw: terminate, clearing all previously allocated GLFW resources.  ��������Դ����ȷ�˳�Ӧ�ó���
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    //���ص�ǰ�Ƿ��¸ü�
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        //glfwSetwindowShouldClose ����WindowShouldClose��������Ϊtrue���ر� GLFW��
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.

    //glViewport��ǰ�����������ô������½ǵ�λ�á��������͵��ĸ�����������Ⱦ���ڵĿ�Ⱥ͸߶ȣ�������Ϊ��λ�������ǽ�������Ϊ���� GLFW �Ĵ��ڴ�С��
    glViewport(0, 0, width, height);
}
