//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s):Salgado Salazar Carlos Eduardo *********************************//
//*************			grupo:01										******//
//*************											******//
//************************************************************//
#include "Main.h"
#include "main_prac6.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol,mercurio,venus,tierra,luna,marte,jupiter,saturno,urano,nepturno=0;
float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat MercurioDiffuse[] = { 0.5f, 0.8f, 1.0f, 1.0f };			// Tierra
GLfloat MercurioSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat MercurioShininess[] = { 50.0 };

GLfloat VenusDiffuse[] = { 0.3f, 0.7f, 0.6f, 1.0f };			// Tierra
GLfloat VenusSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat VenusShininess[] = { 50.0 };


GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 1.0f, 0.0f, 0.0f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

GLfloat JupiterDiffuse[] = { 0.6f, 0.8f, 0.2f, 1.0f };			// Marte
GLfloat JupiterSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat JupiterShininess[] = { 50.0 };

GLfloat SaturnoDiffuse[] = { 0.0f, 1.0f, 0.0f, 1.0f };			// Marte
GLfloat SaturnoSpecular[] = { 0.4, 0.5, 0.9, 1.0 };
GLfloat SaturnoShininess[] = { 50.0 };

GLfloat UranoDiffuse[] = { 0.5f, 0.5f, 1.0f, 1.0f };			// Marte
GLfloat UranoSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat UranoShininess[] = { 50.0 };

GLfloat NepturnoDiffuse[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Marte
GLfloat NepturnoSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat NepturnoShininess[] = { 50.0 };

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	//activar o desactivar la luz
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, SunDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SunSpecular);

}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glLightfv(GL_LIGHT1, GL_POSITION, SunPosition);
	glDisable(GL_LIGHTING);

	glutSolidSphere(2.0, 20, 20);  //Draw Sun (radio,H,V);
	glEnable(GL_LIGHTING);
	glPushMatrix();//mercurio
	glRotatef(245.0, 1.0, 0.0, 0.0);
	glColor3f(0.545, 0.271, 0.071);
	glRotatef(mercurio, 0.0, 1.0, 0.0);
	glTranslatef(2.5, 0.2, 0.2);
	glRotatef(mercurio, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MercurioDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MercurioSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MercurioShininess);

	glutSolidSphere(0.3, 10.0, 10.0);
	glPopMatrix();


	glPushMatrix();//venus
	glRotatef(45.0, 1.0, 0.0, 0.0);
	glColor3f(0.9, 0.6, 0.3);
	glRotatef(venus, 0.0, 1.0, 0.0);
	glTranslatef(3.5, 0.2, 0.2);
	glRotatef(venus, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, VenusDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, VenusSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, VenusShininess);

	glutSolidSphere(0.4, 10.0, 10.0);
	glPopMatrix();

	glPushMatrix();//tierra y luna
	glRotatef(210.0, 1.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glRotatef(tierra, 0.0, 1.0, 0.0);
	glTranslatef(5.5, 0.2, 0.2);
	glPushMatrix();
	glRotatef(tierra, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, EarthShininess);
	glutSolidSphere(0.5, 10.0, 10.0);
	glPopMatrix();
	glPushMatrix();//luna
	glColor3f(0.9, 0.6, 0.3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);
	glRotatef(luna, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.2, 0.2);
	glutSolidSphere(0.1, 10.0, 10.0);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();//marte
	glRotatef(185.0, 1.0, 0.0, 0.0);
	glColor3f(0.9, 0.0, 0.0);
	glRotatef(marte, 0.0, 1.0, 0.0);
	glTranslatef(9.5, 0.2, 0.2);
	glRotatef(marte, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MarsShininess);

	glutSolidSphere(0.7, 10.0, 10.0);
	glPopMatrix();

	glPushMatrix();//jupiter
	glRotatef(165.0, 1.0, 0.0, 0.0);
	glColor3f(0.0, 0.9, 0.0);
	glRotatef(jupiter, 0.0, 1.0, 0.0);
	glTranslatef(12.5, 0.2, 0.2);
	glPushMatrix();
	glRotatef(jupiter, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, JupiterDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, JupiterSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, JupiterShininess);

	glutSolidSphere(0.7, 10.0, 10.0);
	glPopMatrix();
	glPushMatrix();//luna1
	glColor3f(0.9, 0.6, 0.3);
	glRotatef(luna, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.2, 0.2);

	glMaterialfv(GL_FRONT, GL_DIFFUSE,MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);

	glutSolidSphere(0.1, 10.0, 10.0);
	glPopMatrix();
	glPushMatrix();//luna2
	glColor3f(0.9, 0.6, 0.3);
	glRotatef(luna, 1.0, 0.0, 0.0);
	glTranslatef(0.2, 1.2, 0.2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);

	glutSolidSphere(0.1, 10.0, 10.0);
	glPopMatrix();

		glPopMatrix();

	glPushMatrix();//saturn
	glRotatef(145.0, 1.0, 0.0, 0.0);
	glColor3f(0.9, 0.5, 0.7);
	glRotatef(saturno, 0.0, 1.0, 0.0);
	glTranslatef(15.5, 0.2, 0.2);
	glRotatef(saturno, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, SaturnoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, SaturnoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, SaturnoShininess);

	glutSolidSphere(0.7, 10.0, 10.0);
	glColor3f(1.0, 0.0, 0.0);
	glScalef(0.4, 0.4, 0.25);
	glutSolidTorus(1, 3, 10, 10);
	glPushMatrix();//luna1
	glColor3f(0.9, 0.6, 0.3);
	glRotatef(luna, 0.0, 0.0, 1.0);
	glTranslatef(4.5, 0.2, 0.2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);

	glutSolidSphere(0.5, 10.0, 10.0);
	glPopMatrix();
	glPushMatrix();//luna2
	glColor3f(0.9, 0.6, 0.3);
	glRotatef(luna, 1.0, 0.0, 0.0);
	glTranslatef(0.2, 4.2, 0.2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, MoonShininess);

	glutSolidSphere(0.5, 10.0, 10.0);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();//urano
	glRotatef(125.0, 1.0, 0.0, 0.0);
	glColor3f(0.5, 0.5, 0.7);
	glRotatef(urano, 0.0, 1.0, 0.0);
	glTranslatef(18.5, 0.2, 0.2);
	glRotatef(urano, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, UranoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, UranoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, UranoShininess);

	glutSolidSphere(0.7, 10.0, 10.0);
	glPopMatrix();

	glPushMatrix();//nepturno
	glRotatef(110.0, 1.0, 0.0, 0.0);
	glColor3f(0.4, 0.5, 0.4);
	glRotatef(nepturno, 0.0, 1.0, 0.0);
	glTranslatef(21.5, 0.2, 0.2);
	glRotatef(nepturno, 0.0, 1.0, 0.0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, NepturnoDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, NepturnoSpecular);
	glMaterialfv(GL_FRONT, GL_SHININESS, NepturnoShininess);

	glutSolidSphere(0.7, 10.0, 10.0);
	glPopMatrix();
	
	glutSwapBuffers ( );


}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 30)
	{
	//	sol = (sol - 5) % 360;
		mercurio = (mercurio - 5) % 360;
		venus = (venus - 3) % 360;
		tierra = (tierra - 2) % 360;
		luna = (luna - 1) % 360;
		marte = (marte - 6) % 360;
		jupiter = (jupiter - 4) % 360;
    	saturno = (saturno - 3) % 360;
		urano = (urano - 2) % 360;
		nepturno = (nepturno - 1) % 360;


		dwLastUpdateTime = dwCurrentTime;
	}
	glutPostRedisplay();
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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		//Movimientos de Luz
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   //Activamos/desactivamos luz
		case 'L':
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tama�o de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut funci�n de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut funci�n en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut funci�n de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}