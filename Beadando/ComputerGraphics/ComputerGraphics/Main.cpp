#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() {
	//Inicializálom a GLFW-t
	glfwInit();

	//Meghatározom az OpenGL verziókat. Ez esetben ez a 3.3-as verzió
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//Megadom a GLFW-nek, hogy a CORE funkciókat használom, azaz a modernebb függvényeket. 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//Létrehozom az ablakot glfw segítségével
	// 800x800-as ablak aminek a tetején "Hello OpenGL" van kiirva
	GLFWwindow* window = glfwCreateWindow(800, 800, "Hello OpenGL", NULL, NULL);
	//Ha valami probléma van így kezelem le
	if (window == NULL) {
		std::cout << "Failed to crate Window";
		glfwTerminate();
		return -1;
	}

	//Megadjuk, hogy lehessen az ablakot bezárni nagyítani(az alap funkciók)
	glfwMakeContextCurrent(window);
	
	//A glad betölti az OpenGL-t
	gladLoadGL();

	//A glad az ablakra tölti a viewportott aminek. Ami azt mutatja be, hogy x=0-800 és y=0-180 
	glViewport(0, 0, 800, 800);

	//Megadja az alapszínt
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glfwSwapBuffers(window);

	//Addig nem záródik be amíg mi ezt nem tesszük
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	
	//Leálítjuk a programot.
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
