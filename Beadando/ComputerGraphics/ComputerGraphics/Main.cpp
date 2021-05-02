#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 800, "Hello OpenGL", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to crate Window";
		glfwTerminate();
		return -1;
	}

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}


	glfwMakeContextCurrent(window);

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
