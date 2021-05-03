#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

int main() {
	//Inicializ�lom a GLFW-t
	glfwInit();

	//Meghat�rozom az OpenGL verzi�kat. Ez esetben ez a 3.3-as verzi�
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//Megadom a GLFW-nek, hogy a CORE funkci�kat haszn�lom, azaz a modernebb f�ggv�nyeket. 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	//L�trehozom az ablakot glfw seg�ts�g�vel
	// 800x800-as ablak aminek a tetej�n "Hello OpenGL" van kiirva
	GLFWwindow* window = glfwCreateWindow(800, 800, "Hello OpenGL", NULL, NULL);
	//Ha valami probl�ma van �gy kezelem le
	if (window == NULL) {
		std::cout << "Failed to crate Window";
		glfwTerminate();
		return -1;
	}

	//Megadjuk, hogy lehessen az ablakot bez�rni nagy�tani(az alap funkci�k)
	glfwMakeContextCurrent(window);
	
	//A glad bet�lti az OpenGL-t
	gladLoadGL();

	//A glad az ablakra t�lti a viewportott aminek. Ami azt mutatja be, hogy x=0-800 �s y=0-180 
	glViewport(0, 0, 800, 800);

	//Megadja az alapsz�nt
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glfwSwapBuffers(window);

	//Addig nem z�r�dik be am�g mi ezt nem tessz�k
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	
	//Le�l�tjuk a programot.
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
