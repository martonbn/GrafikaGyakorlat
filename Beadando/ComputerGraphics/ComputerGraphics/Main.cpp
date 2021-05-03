#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

//Vertex Shaderj�nek a definici�ja String form�tumban 
// A Vertex maga a pont 
const char* vertexShaderSource = "#version 330\n"
"layout (location = 0) in vec3 aPos;\n"
"void main(){\n"
"	gl_Position = vec4(a.Pos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

//Egy fragment Shederj�nek a definici�ja String form�tumban
// A fragment meg az a teer�let ami legl�bb 3 pont k�z�tt van.
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main(){\n"
"	FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\0";


int main() {
	//Inicializ�lom a GLFW-t
	glfwInit();

	//Meghat�rozom az OpenGL verzi�kat. Ez esetben ez a 3.3-as verzi�
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);


	//Megadom a GLFW-nek, hogy a CORE funkci�kat haszn�lom, azaz a modernebb f�ggv�nyeket. 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	// A kordin�t�k a k�vetkez� m�don m�k�dnek
	// 0 x �s y eset�n is az ablak k�zep�n van. Ha jobbra megy�nk akkor + ha balra -
	// Itt m�g csak az adat van let�rolva a koordin�t�knak
	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.0f, 0.5f * float(sqrt(3)) / 3, 0.0f,
	};



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

	//L�terehoztuk a k�don bel�l a vertexShader-t amit m�g le is forditttunk g�pi k�dra.
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);


	//L�terehoztuk a k�don bel�l a fragmentShader-t amit m�g le is forditttunk g�pi k�dra.
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	//Majd belet�ltj�k ezeket az adatokat a Shader Programban.
	GLuint shderProgram = glCreateProgram();

	//Hozz�adunk egy shadert a shader programhoz
	glAttachShader(shderProgram, vertexShader);
	glAttachShader(shderProgram, fragmentShader);

	//Be linkelj�k az shadert
	glLinkProgram(shderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);



	GLuint VAO, VBO;


	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);


	//Megadja az alapsz�nt
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glfwSwapBuffers(window);

	//Addig nem z�r�dik be am�g mi ezt nem tessz�k
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	
	//Le�l�tjuk a programot.
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
