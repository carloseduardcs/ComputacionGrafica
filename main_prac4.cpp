//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//***************Alumno: Salgado Salazar**********************//
//******************Carlos Eduardo****************************//
//************************************************************//
//************************************************************//
#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;
int screenW = 0.0;
int screenH = 0.0;

 
void InitGL ( void )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
		//	glColor3f(1.0,0.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			//glColor3f(0.0,0.0,1.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
		//	glColor3f(0.0,1.0,0.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			//glColor3f(1.0,1.0,1.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			//glColor3f(0.4,0.2,0.6);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			//glColor3f(0.8,0.2,0.4);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	glTranslatef(transX, transY, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glRotatef(angleZ, 0.0, 0.0, 1.0);
		//Poner Código Aquí.
		/*
		prisma();//A 
		glPushMatrix();
			glTranslatef(4.5,0.0,0.0);
		//glScalef(0.75, 3.0, 1.0);//rescala la figura.
			glScalef(0.75,3.0,1.0);
		prisma();//B
		glPopMatrix();
			glTranslatef(0.0,2.75,0.0);
		//glScalef(1.0/0.75,1.0/3.0,1.0);
		prisma();//C
  			
		glPushMatrix();
			glPushMatrix();
		glScalef(6.0,5.0,1.0);
		prisma();//pecho
			glPopMatrix();

			glPushMatrix();
		glTranslated(0.0,3.0,0.0);
			glPushMatrix();
		glScalef(1.0,1.0,1.0);
		glRotatef(180.0,0.0,1.0,0.0);
		prisma();//cuello
			glPopMatrix();
			glTranslated(0.0,2.5,0.0);
		glPushMatrix();
		glScalef(3.0,4.0,1.0);
		prisma();//cabeza
			glPopMatrix();
			glPopMatrix();
		glPushMatrix();//brazo derecho
		glTranslated(4.0,1.75,0.0);
		glScalef(3.0,1.5,1.0);
		prisma();
		glTranslatef(0.25,-3.0,0.0);
		glScalef(0.5,5.0,1.0);
		prisma();
		glPopMatrix();

		glPushMatrix();//brazo izquierdo
		glTranslated(-4.0, 1.75, 0.0);
		glScalef(3.0, 1.5, 1.0);
		prisma();
		glTranslatef(-0.25, -3.0, 0.0);
		glScalef(0.5, 5.0, 1.0);
		prisma();
		glPopMatrix();
			glPushMatrix();//mango
				glTranslatef(-5.5,-6.0,0.0);
				glScalef(3.5,1.0,1.0);
				prisma();
			glPopMatrix();
				glPushMatrix();//martillo
				glTranslatef(-7.0, -6.0, 0.0);
				glScalef(0.75, 2.0, 1.0);
				prisma();
			glPopMatrix();
			glPushMatrix();//puntita
				glTranslatef(-7.5, -6.0, 0.0);
				glScalef(0.5, 1.0, 1.0);
				prisma();
			glPopMatrix();
		glPushMatrix();//cadera
		glTranslated(0.0, -3.0, 0.0);
		glScalef(6.0, 1.0, 1.0);
		glRotatef(180.0, 0.0, 1.0, 0.0);
		prisma();
		glPopMatrix();

		glPopMatrix();

		glPushMatrix();//pierna izquierda
		glTranslatef(-2.0,-6.5,0.0);
		glScalef(2.0,6.0,1.0);
		prisma();
		glPopMatrix();
		glPushMatrix();//pierna derecha
		glTranslatef(2.0, -6.5, 0.0);
		glScalef(2.0, 6.0, 1.0);
		prisma();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-2.4,-10.0,0.0);//pie izquierdo
		glScalef(2.75,1.5,1.0);
		prisma();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(2.4, -10.0, 0.0);//pie derecho
		glScalef(2.75, 1.5, 1.0);
		prisma();
		glPopMatrix();
		*/
	/*0,0,0*/
	/*
	glPushMatrix();//cabeza
	glColor3f(1.0, 0.0, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();//cuello
	glTranslatef(0.0, -0.75, 0.0);
	glScalef(0.5, 0.5, 1.0);
	glColor3f(0.0, 1.0, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();//torso
	glTranslatef(0.0, -2.5, 0.0);
	glScalef(3.0, 3.0, 1.0);
	glColor3f(0.0, 0.0, 1.0);
	prisma();/*0,-2.5,0*/
/*
	glPopMatrix();

	glPushMatrix();//brazo D
	glTranslatef(-3.0, -1.5, 0.0);
	glScalef(3.0, 1.0, 1.0);
	glColor3f(0.8, 0.5, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();//manoD
	glTranslatef(-5.5, -1.5, 0.0);
	glScalef(2.0, 2.0, 1.0);
	glColor3f(1.0, 1.0, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();//brazoI
	glTranslatef(3.0, -1.5, 0.0);
	glScalef(3.0, 1.0, 1.0);
	glColor3f(0.8, 0.5, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();//manoI
	glTranslatef(5.5, -1.5, 0.0);
	glScalef(2.0, 2.0, 1.0);
	glColor3f(0.5, 0.2, 0.0);
	prisma();
	glPopMatrix();

	glPushMatrix();//piernaD
	glTranslatef(-0.75, -7.5, 0.0);
	glScalef(1.0, 7.0, 1.0);
	glColor3f(0.8, 0.5, 0.5);
	prisma();
	glPopMatrix();

	glPushMatrix();//pieD
	glTranslatef(-1.75, -12.5, 0.0);
	glScalef(3.0, 3.0, 1.0);
	glColor3f(1.0, 0.4, 0.8);
	prisma();
	glPopMatrix();

	glPushMatrix();//piernaI
	glTranslatef(0.75, -7.5, 0.0);
	glScalef(1.0, 7.0, 1.0);
	glColor3f(0.8, 0.5, 0.5);
	prisma();
	glPopMatrix();

	glPushMatrix();//pieI
	glTranslatef(1.75, -12.5, 0.0);
	glScalef(3.0, 3.0, 1.0);
	glColor3f(1.0, 0.4, 0.8);
	prisma();
	glPopMatrix();
	*/
	glPushMatrix();
	glScalef(3.0, 2.0, 2.0);
	glColor3f(0.2, 0.2, 0.2);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.0, 0.25, 0.0);
	glScalef(1.0, 2.5, 2.0);
	glColor3f(1.0, 0.0, 0.0);
	prisma();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(2.75, 0.0, 0.0);
	glScalef(0.5, 2.0, 2.0);
	glColor3f(0.4, 0.4, 0.4);
	prisma();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.5, -0.5, 0.0);
	glScalef(1.0, 1.0, 2.0);
	glColor3f(0.5, 0.5, 0.5);
	prisma();
	glPopMatrix();

	glPushMatrix();//pata AI
	glTranslatef(0.0, -1.6, 0.75);
	glScalef(0.75, 1.2, 0.5);
	glColor3f(0.8, 0.8, 0.8);
	prisma();
	glPopMatrix();

	glPushMatrix();//pata AD
	glTranslatef(0.0, -1.6, -0.75);
	glScalef(0.75, 1.2, 0.5);
	glColor3f(0.8, 0.8, 0.8);
	prisma();
	glPopMatrix();

	glPushMatrix();//pata DeI
	glTranslatef(2.1, -1.6, 0.75);
	glScalef(0.75, 1.2, 0.5);
	glColor3f(0.8, 0.8, 0.8);
	prisma();
	glPopMatrix();

	glPushMatrix();//pata DeD
	glTranslatef(2.1, -1.6, -0.75);
	glScalef(0.75, 1.2, 0.5);
	glColor3f(0.8, 0.8, 0.8);
	prisma();
	glPopMatrix();

	glPushMatrix();//Cola
	glRotatef(45.0, 0.0, 0.0, 1.0);
	glTranslatef(-0.65, 3.0, 0.0);
	glScalef(0.5, 2.5, 0.5);
	glColor3f(0.8, 0.8, 0.8);
	prisma();
	glPopMatrix();

	glPushMatrix();//oreja
	glTranslatef(2.7, 1.4, 0.35);
	glScalef(0.4, 0.8, 0.4);
	glColor3f(0.7, 0.7, 0.7);
	prisma();
	glPopMatrix();

	glPushMatrix();//oreja
	glTranslatef(2.7, 1.4, -0.35);
	glScalef(0.4, 0.8, 0.4);
	glColor3f(0.7, 0.7, 0.7);
	prisma();
	glPopMatrix();

	glPushMatrix();//ojo
	glTranslatef(3.1, 0.5, 0.5);
	glScalef(0.2, 0.5, 0.5);
	glColor3f(0.0, 0.0, 0.0);
	prisma();
	glPopMatrix();
	glPushMatrix();//ojo
	glTranslatef(3.1, 0.5, -0.5);
	glScalef(0.2, 0.5, 0.5);
	glColor3f(0.0, 0.0, 0.0);
	prisma();
	glPopMatrix();
	
	glPushMatrix();//nariz
	glTranslatef(3.9, 0.1, 0.0);
	glScalef(0.2, 0.2, 0.5);
	glColor3f(1.0, 0.5, 0.75);
	prisma();
	glPopMatrix();

	/*glPushMatrix();
	glPopMatrix();*/
  glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}


void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':
	case 'W':
		transZ += 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;
	case 'a':
	case 'A':
		transX -= 0.2f;
		break;
	case 'd':
	case 'D':
		transX += 0.2f;
		break;
	case 'y':
	case 'Y':
		transY += 0.2f;
		break;
	case 'h':
	case 'H':
		transY -= 0.2f;
		break;
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 5.0f;
		break;
		//glutFullScreen ( ); // Full Screen Mode
		//break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 5.0f;
		break;
		//glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
		//break;
	case GLUT_KEY_LEFT:
		angleY += 5.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 5.0f;
		break;
	case GLUT_KEY_PAGE_DOWN:     // Presionamos tecla page down...
		angleZ += 5.0f;
		break;
	case GLUT_KEY_PAGE_UP:     // Presionamos tecla page up...
		angleZ -= 5.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}



int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



