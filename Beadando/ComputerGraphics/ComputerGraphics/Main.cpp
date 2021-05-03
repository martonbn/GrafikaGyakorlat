#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

//Vertex Shaderjének a definiciója String formátumban 
// A Vertex maga a pont 
const char* vertexShaderSource = "#version 330\n"
"layout (location = 0) in vec3 aPos;\n"
"void main(){\n"
"	gl_Position = vec4(a.Pos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

//Egy fragment Shederjének a definiciója String formátumban
// A fragment meg az a teerület ami leglább 3 pont között van.
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main(){\n"
"	FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\0";


int main() {
	//Inicializálom a GLFW-t
	glfwInit();

	//Meghatározom az OpenGL verziókat. Ez esetben ez a 3.3-as verzió
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);


	//Megadom a GLFW-nek, hogy a CORE funkciókat használom, azaz a modernebb függvényeket. 
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	// A kordináták a következõ módon müködnek
	// 0 x és y esetén is az ablak közepén van. Ha jobbra megyünk akkor + ha balra -
	// Itt még csak az adat van letárolva a koordinátáknak
	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
		0.0f, 0.5f * float(sqrt(3)) / 3, 0.0f,
	};



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

	//Léterehoztuk a kódon belül a vertexShader-t amit még le is forditttunk gépi kódra.
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);


	//Léterehoztuk a kódon belül a fragmentShader-t amit még le is forditttunk gépi kódra.
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	//Majd beletöltjük ezeket az adatokat a Shader Programban.
	GLuint shderProgram = glCreateProgram();

	//Hozzáadunk egy shadert a shader programhoz
	glAttachShader(shderProgram, vertexShader);
	glAttachShader(shderProgram, fragmentShader);

	//Be linkeljük az shadert
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


	//Megadja az alapszínt
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glfwSwapBuffers(window);

	//Addig nem záródik be amíg mi ezt nem tesszük
	while (!glfwWindowShouldClose(window)) {
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shderProgram);
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	
	//Leálítjuk a programot.
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
