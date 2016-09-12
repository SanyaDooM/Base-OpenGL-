
#include <GLFW\glfw3.h>
#include<iostream>
using namespace std;


//Регистрация функцции обрат вызова
void Win_OnResize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}


int main(void)
{
	setlocale(NULL, "rus");
	cout << "" << endl;
	cout << "Программа OpenGL" << endl;
	cout << "Стлелки - двигать прямоугольник" << endl;
	cout << "1 - варщать прямоугольник" << endl;
	cout << "2 - Сброс. Вернуть всё в исходное состояние" << endl;

	float a = 0.2f;
	float speed = 0.05f;
	float angle = 0.0f;
	

	GLFWwindow* window;

	

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(800, 600, "OpenGL test Saniok", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}



	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	glfwSetWindowSizeCallback(window, Win_OnResize);
	
	
	glClearColor(0.0f, 0.5f, 0.9f, 1.0f);
	
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE))
		{
			glfwTerminate();
			return 0;
		}



		if(glfwGetKey(window, GLFW_KEY_UP))
		{
			glTranslatef(0.0f, speed, 0.0f);
		}

		if (glfwGetKey(window, GLFW_KEY_DOWN))
		{
			glTranslatef(0.0f, -speed, 0.0f);
		}

		if (glfwGetKey(window, GLFW_KEY_LEFT))
		{
			glTranslatef(-speed, 0.0f, 0.0f);
		}

		if (glfwGetKey(window, GLFW_KEY_RIGHT))
		{
			glTranslatef(speed, 0.0f, 0.0f);
		}

		if (glfwGetKey(window, GLFW_KEY_1))
		{
			angle = 8.0f;
		}

		if (glfwGetKey(window, GLFW_KEY_2))
		{
			angle = 0.0f;
			glLoadIdentity();
			
		}


		glRotatef(angle, 0.0f, 0.1f, 0.0f);

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT );


		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.9f, 0.0f);

		glVertex2f(-a, a);
		glVertex2f(a, a);
		glVertex2f(a, -a);
		glVertex2f(-a, -a);


		glEnd();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}



	glfwTerminate();
	return 0;
}