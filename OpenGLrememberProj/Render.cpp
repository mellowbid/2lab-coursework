#include "Render.h"
#include <windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>

#include "MyOGL.h"

#include "Camera.h"
#include "Light.h"
#include "Primitives.h"
#include <cmath>


bool textureMode = true;
bool lightMode = true;
bool alphamode = false;

//������ ������� ��� ������ ������
void norm(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3,int i){
	double Xa, Ya, Za, Xb, Yb, Zb;
	double Nx, Ny, Nz;
	Xa = x3-x2;
	Ya =y3-y2;
	Za =z3-z2;
	Xb =x1-x2;
	Yb =y1-y2;
	Zb =z1-z2;
	Nx = (Ya*Zb-Yb*Za);
	Ny = 0-(Xa*Zb-Xb*Za);
	Nz =(Xa*Yb-Xb*Ya);
	if(i==0)
	glNormal3d(Nx,Ny,Nz);
	else
	glNormal3d(-Nx,-Ny,-Nz);
}

//������ ������� ��� ������ ������
void setNormal(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3) {

	double ax, ay, az, bx, by, bz, Nx, Ny, Nz;
	ax = x1 - x2;
	bx = x3 - x2;
	ay = y1 - y2;
	by = y3 - y2;
	az = z1 - z2;
	bz = z3 - z1;

	Nx = ay*bz - by*az;
	Ny = 0 - ax*bz - bx*az;
	Nz = ax*by - bx*ay;

	glNormal3d(Nx, Ny, Nz);
}

//������ �������
void side() {

	norm(1,6,0,0,0,0,0,0,5,0);

	glColor3d(0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);

	glTexCoord2d(0.185546875, 0.0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(1, 6, 0);
	glTexCoord2d(0.185546875, 0.134765625);
	glVertex3d(0, 0, 5);

	glTexCoord2d(0.185546875, 0.134765625);
	glVertex3d(0, 0, 5);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(1, 6, 0);
	glTexCoord2d(0.0, 0.134765625);
	glVertex3d(1, 6, 5);

	glEnd();

	norm(4,4,0,8,1,0,8,1,5,0);

	glColor3d(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);

	glTexCoord2d(0.42578125, 0.0);
	glVertex3d(8, 1, 0);
	glTexCoord2d(0.232421875, 0.0);
	glVertex3d(4, 4, 0);
	glTexCoord2d(0.42578125, 0.134765625);
	glVertex3d(8, 1, 5);

	glTexCoord2d(0.42578125, 0.134765625);
	glVertex3d(8, 1, 5);
	glTexCoord2d(0.232421875, 0.134765625);
	glVertex3d(4, 4, 5);
	glTexCoord2d(0.232421875,0.0);
	glVertex3d(4, 4, 0);

	glEnd();

	norm(0,0,0,4,4,0,4,4,5,0);

	glColor3d(0.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);

	glTexCoord2d(0.466796875, 0.0);
	glVertex3d(0, 0, 0);
	glTexCoord2d(0.66015625, 0.0);
	glVertex3d(4, 4, 0);
	glTexCoord2d(0.466796875, 0.134765625);
	glVertex3d(0, 0, 5);

	glTexCoord2d(0.466796875, 0.134765625);
	glVertex3d(0, 0, 5);
	glTexCoord2d(0.66015625, 0.134765625);
	glVertex3d(4, 4, 5);
	glTexCoord2d(0.66015625, 0.0);
	glVertex3d(4, 4, 0);

	glEnd();
}

//�������� �������
void convex() {
	double x, y, x1;

	glColor3d(1.0f, 0.0f, 1.0f);
	glBegin(GL_QUAD_STRIP);
	x1 = 0.947265625;
	for (double alpha = 60.28; alpha >= -60.28; alpha -= 0.01) {
		double Xdop=8,Ydop=8;
		x = 6 + cos(alpha * 3.141592653589793238 / 180) * 4.03;
		y = 4.5 + sin(alpha * 3.141592653589793238 / 180) * 4.03;

		if (x < 8 & y < 1)
			continue;
		if (x < 8 & y < 8)
			continue;

		setNormal(Xdop, Ydop, 0, x, y, 0, x, y, 5);
		glTexCoord2d(x1, 0.134765625);
		glVertex3d(x, y, 5.0);
		glTexCoord2d(x1, 0.0);
		glVertex3d(x, y, 0.0);
		x1 = x1 - 0.0000207201;
		Xdop=x;
		Ydop=y;
	}
	glEnd();

}

//������� �������
void convex2() {

	glColor3d(1.0f, 1.0f, 0.0f);
	double x, y;
	glBegin(GL_QUAD_STRIP);
	double x1 = 0.94921875;
	for (double alpha = 230.60; alpha <= 341.37; alpha += 0.01) {
		double Xdop=1,Ydop=6;

		x = 3.80769 + cos(alpha * 3.141592653589793238 / 180) * 4.43;
		y = 9.42308 + sin(alpha * 3.141592653589793238 / 180) * 4.43;
		if (x > 8 & y > 8)
			continue;

		setNormal(Xdop,Ydop,0,x,y,0,x,y,5);

		glTexCoord2d(x1, 0.30859375);
		glVertex3d(x, y, 5.0);

		glTexCoord2d(x1, 0.17578125);
		glVertex3d(x, y, 0.0);
		x1 = x1 - 0.00002269;
		Xdop=x;
		Ydop=y;
	}

	glEnd();
}

//���������
void base() {

	glNormal3d(0, 0, 1);
	double x, y, x1, y1;
	glColor3d(0.3f, 0.3f, 0.6f);

	//����� ������� �����������-����
	glBegin(GL_TRIANGLE_FAN);
	glTexCoord2d(0.5820313, 0.5839844);
	glVertex3d(0, 0, 5.0);
	for (double alpha = 230.60; alpha <= 270.0; alpha += 0.01) {
		x = 3.80769 + cos(alpha * 3.141592653589793238 / 180) * 4.43;
		y = 9.42308 + sin(alpha * 3.141592653589793238 / 180) * 4.43;

		x1 = 0.71324 + cos(alpha * 3.141592653589793238 / 180) * 0.15;
		y1 = 0.90262 + sin(alpha * 3.141592653589793238 / 180) * 0.15;

		if (x < 1 & y>6)
			continue;
		glTexCoord2d(x1, y1);
		glVertex3d(x, y, 5.0);
	}

	glEnd();

	//������ ������� �����������-����
	glBegin(GL_TRIANGLE_FAN);
	glTexCoord2d(0.859375, 0.625);
	glVertex3d(8, 1, 5.0);
	for (double alpha = 270.0; alpha <= 361.37; alpha += 0.01) {
		x = 3.80769 + cos(alpha * 3.141592653589793238 / 180) * 4.43;
		y = 9.42308 + sin(alpha * 3.141592653589793238 / 180) * 4.43;

		x1 = 0.71324 + cos(alpha * 3.141592653589793238 / 180) * 0.15;
		y1 = 0.90262 + sin(alpha * 3.141592653589793238 / 180) * 0.15;
		if (x > 8 & y > 8)
			continue;
		glTexCoord2d(x1, y1);
		glVertex3d(x, y, 5.0);
	}

	glEnd();

	//������ ���������� ����
	glNormal3d(0, 0, 1);
	glBegin(GL_TRIANGLES);

	x = 3.80769 + cos(270 * 3.141592653589793238 / 180) * 4.43;
	y = 9.42308 + sin(270 * 3.141592653589793238 / 180) * 4.43;

	x1 = 0.71324 + cos(270 * 3.141592653589793238 / 180) * 0.15;
	y1 = 0.90262 + sin(270 * 3.141592653589793238 / 180) * 0.15;

	glTexCoord2d(0.7207031, 0.7226563);
	glVertex3d(4.0, 4.0, 5.0);
	glTexCoord2d(x1, y1);
	glVertex3d(x, y, 5.0);
	glTexCoord2d(0.859375, 0.6269531);
	glVertex3d(8.0, 1.0, 5.0);

	glEnd();

	//����� ���������� ����
	glBegin(GL_TRIANGLES);
	x = 3.80769 + cos(270 * 3.141592653589793238 / 180) * 4.43;
	y = 9.42308 + sin(270 * 3.141592653589793238 / 180) * 4.43;

	x1 = 0.71324 + cos(270 * 3.141592653589793238 / 180) * 0.15;
	y1 = 0.90262 + sin(270 * 3.141592653589793238 / 180) * 0.15;

	glTexCoord2d(0.5820313, 0.5839844);
	glVertex3d(0.0, 0.0, 5.0);
	glTexCoord2d(x1, y1);
	glVertex3d(x, y, 5.0);
	glTexCoord2d(0.7207031, 0.7226563);
	glVertex3d(4.0, 4.0, 5.0);

	glEnd();

	glNormal3d(0, 0, 1);
	//glColor3d(1.0f, 0.0f, 0.0f);

	glBegin(GL_TRIANGLE_FAN);

	glTexCoord2d(0.8554688, 0.7421875);
	glVertex3d(8, 4.5, 5.0);
	for (double alpha = 60.28; alpha >= -60.28; alpha -= 0.01) {

		x = 6 + cos(alpha * 3.141592653589793238 / 180) * 4.03;
		y = 4.5 + sin(alpha * 3.141592653589793238 / 180) * 4.03;

		x1 = 0.78734 + cos(alpha * 3.141592653589793238 / 180) * 0.14;
		y1 = 0.74219 + sin(alpha * 3.141592653589793238 / 180) * 0.14;

		if (x < 8 & y < 1)
			continue;
		if (x < 8 & y < 8)
			continue;

		glTexCoord2d(x1, y1);
		glVertex3d(x, y, 5.0);

	}

	glEnd();


	glColor4d(1.0, 0.5, 0.0, 0.7);
	glNormal3d(0, 0, -1);
	glBegin(GL_TRIANGLE_FAN);

	glTexCoord2d(0.5820313, 0.5839844);
	glVertex3d(0, 0, 0.0);
	for (double alpha = 230.60; alpha <= 270.0; alpha += 0.01) {
		x = 3.80769 + cos(alpha * 3.141592653589793238 / 180) * 4.43;
		y = 9.42308 + sin(alpha * 3.141592653589793238 / 180) * 4.43;

		x1 = 0.71324 + cos(alpha * 3.141592653589793238 / 180) * 0.15;
		y1 = 0.90262 + sin(alpha * 3.141592653589793238 / 180) * 0.15;
		if (x < 1 & y > 6)
			continue;
		glTexCoord2d(x1, y1);
		glVertex3d(x, y, 0.0);
	}

	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glTexCoord2d(0.859375, 0.625);
	glVertex3d(8, 1, 0.0);
	for (double alpha = 270.00; alpha <= 341.37; alpha += 0.01) {
		x = 3.80769 + cos(alpha * 3.141592653589793238 / 180) * 4.43;
		y = 9.42308 + sin(alpha * 3.141592653589793238 / 180) * 4.43;

		x1 = 0.71324 + cos(alpha * 3.141592653589793238 / 180) * 0.15;
		y1 = 0.90262 + sin(alpha * 3.141592653589793238 / 180) * 0.15;
		if (x > 8 & y > 8)
			continue;
		glTexCoord2d(x1, y1);
		glVertex3d(x, y, 0.0);
	}

	glEnd();

	//������ ���������� ���
	glBegin(GL_TRIANGLES);

	x = 3.80769 + cos(270 * 3.141592653589793238 / 180) * 4.43;
	y = 9.42308 + sin(270 * 3.141592653589793238 / 180) * 4.43;

	x1 = 0.71324 + cos(270 * 3.141592653589793238 / 180) * 0.15;
	y1 = 0.90262 + sin(270 * 3.141592653589793238 / 180) * 0.15;
	glTexCoord2d(0.7207031, 0.7226563);
	glVertex3d(4.0, 4.0, 0.0);
	glTexCoord2d(x1, y1);
	glVertex3d(x, y, 0.0);
	glTexCoord2d(0.859375, 0.6269531);
	glVertex3d(8.0, 1.0, 0.0);

	glEnd();
	//����� ���������� ���
	glBegin(GL_TRIANGLES);

	x = 3.80769 + cos(270 * 3.141592653589793238 / 180) * 4.43;
	y = 9.42308 + sin(270 * 3.141592653589793238 / 180) * 4.43;

	x1 = 0.71324 + cos(270 * 3.141592653589793238 / 180) * 0.15;
	y1 = 0.90262 + sin(270 * 3.141592653589793238 / 180) * 0.15;
	glTexCoord2d(0.5820313, 0.5839844);
	glVertex3d(0.0, 0.0, 0.0);
	glTexCoord2d(x1, y1);
	glVertex3d(x, y, 0.0);
	glTexCoord2d(0.7207031, 0.7226563);
	glVertex3d(4.0, 4.0, 0.0);

	glEnd();

	glNormal3d(0, 0, -1);
	glBegin(GL_TRIANGLE_FAN);

	glTexCoord2d(0.8554688, 0.7421875);
	glVertex3d(8, 4.5, 0.0);
	for (double alpha = 60.28; alpha >= -60.28; alpha -= 0.01) {
		x = 6 + cos(alpha * 3.141592653589793238 / 180) * 4.03;
		y = 4.5 + sin(alpha * 3.141592653589793238 / 180) * 4.03;

		x1 = 0.78734 + cos(alpha * 3.141592653589793238 / 180) * 0.14;
		y1 = 0.74219 + sin(alpha * 3.141592653589793238 / 180) * 0.14;

		if (x < 8 & y < 1)
			continue;
		if (x < 8 & y < 8)
			continue;

		glTexCoord2d(x1, y1);
		glVertex3d(x, y, 0.0);
	}
	glEnd();

}

//����
void circle() {

	glColor4d(0.0, 0.5, 1.0, 0.7);
	glNormal3d(0, 0, 1);
	double x, y, x1, y1;
	glBegin(GL_TRIANGLE_FAN);

	glTexCoord2d(0.19921875, 0.80078125);
	glVertex3d(0, 0, 7.0);

	for (double alpha = 0; alpha <= 360; alpha += 1) {
		x = 0 + cos(alpha * 3.141592653589793238 / 180) * 4;
		y = 0 + sin(alpha * 3.141592653589793238 / 180) * 4;

		x1 = 0.19921875 + cos(alpha * 3.141592653589793238 / 180) * 0.185;
		y1 = 0.80078125 + sin(alpha * 3.141592653589793238 / 180) * 0.185;
		glTexCoord2d(x1, y1);
		glVertex3d(x, y, 7.0);
	}

	glEnd();

}

//����� ��� ��������� ������
class CustomCamera : public Camera
{
public:
	//��������� ������
	double camDist;
	//���� �������� ������
	double fi1, fi2;


	//������� ������ �� ���������
	CustomCamera()
	{
		camDist = 15;
		fi1 = 1;
		fi2 = 1;
	}


	//������� ������� ������, ������ �� ����� ��������, ���������� �������
	void SetUpCamera()
	{
		//�������� �� ������� ������ ������
		lookPoint.setCoords(0, 0, 0);

		pos.setCoords(camDist*cos(fi2)*cos(fi1),
			camDist*cos(fi2)*sin(fi1),
			camDist*sin(fi2));

		if (cos(fi2) <= 0)
			normal.setCoords(0, 0, -1);
		else
			normal.setCoords(0, 0, 1);

		LookAt();
	}

	void CustomCamera::LookAt()
	{
		//������� ��������� ������
		gluLookAt(pos.X(), pos.Y(), pos.Z(), lookPoint.X(), lookPoint.Y(), lookPoint.Z(), normal.X(), normal.Y(), normal.Z());
	}



}  camera;   //������� ������ ������


//����� ��� ��������� �����
class CustomLight : public Light
{
public:
	CustomLight()
	{
		//��������� ������� �����
		pos = Vector3(1, 1, 3);
	}


	//������ ����� � ����� ��� ���������� �����, ���������� �������
	void  DrawLightGhismo()
	{
		glDisable(GL_LIGHTING);


		glColor3d(0.9, 0.8, 0);
		Sphere s;
		s.pos = pos;
		s.scale = s.scale*0.08;
		s.Show();

		if (OpenGL::isKeyPressed('G'))
		{
			glColor3d(0, 0, 0);
			//����� �� ��������� ����� �� ����������
			glBegin(GL_LINES);
			glVertex3d(pos.X(), pos.Y(), pos.Z());
			glVertex3d(pos.X(), pos.Y(), 0);
			glEnd();

			//������ ����������
			Circle c;
			c.pos.setCoords(pos.X(), pos.Y(), 0);
			c.scale = c.scale*1.5;
			c.Show();
		}

	}

	void SetUpLight()
	{
		GLfloat amb[] = { 0.2, 0.2, 0.2, 0 };
		GLfloat dif[] = { 1.0, 1.0, 1.0, 0 };
		GLfloat spec[] = { .7, .7, .7, 0 };
		GLfloat position[] = { pos.X(), pos.Y(), pos.Z(), 1. };

		// ��������� ��������� �����
		glLightfv(GL_LIGHT0, GL_POSITION, position);
		// �������������� ����������� �����
		// ������� ��������� (���������� ����)
		glLightfv(GL_LIGHT0, GL_AMBIENT, amb);
		// ��������� ������������ �����
		glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
		// ��������� ���������� ������������ �����
		glLightfv(GL_LIGHT0, GL_SPECULAR, spec);

		glEnable(GL_LIGHT0);
	}


} light;  //������� �������� �����




//������ ���������� ����
int mouseX = 0, mouseY = 0;

void mouseEvent(OpenGL *ogl, int mX, int mY)
{
	int dx = mouseX - mX;
	int dy = mouseY - mY;
	mouseX = mX;
	mouseY = mY;

	//������ ���� ������ ��� ������� ����� ������ ����
	if (OpenGL::isKeyPressed(VK_RBUTTON))
	{
		camera.fi1 += 0.01*dx;
		camera.fi2 += -0.01*dy;
	}


	//������� ���� �� ���������, � ����� ��� ����
	if (OpenGL::isKeyPressed('G') && !OpenGL::isKeyPressed(VK_LBUTTON))
	{
		LPPOINT POINT = new tagPOINT();
		GetCursorPos(POINT);
		ScreenToClient(ogl->getHwnd(), POINT);
		POINT->y = ogl->getHeight() - POINT->y;

		Ray r = camera.getLookRay(POINT->x, POINT->y);

		double z = light.pos.Z();

		double k = 0, x = 0, y = 0;
		if (r.direction.Z() == 0)
			k = 0;
		else
			k = (z - r.origin.Z()) / r.direction.Z();

		x = k*r.direction.X() + r.origin.X();
		y = k*r.direction.Y() + r.origin.Y();

		light.pos = Vector3(x, y, z);
	}

	if (OpenGL::isKeyPressed('G') && OpenGL::isKeyPressed(VK_LBUTTON))
	{
		light.pos = light.pos + Vector3(0, 0, 0.02*dy);
	}


}

void mouseWheelEvent(OpenGL *ogl, int delta)
{

	if (delta < 0 && camera.camDist <= 1)
		return;
	if (delta > 0 && camera.camDist >= 100)
		return;

	camera.camDist += 0.01*delta;

}

void keyDownEvent(OpenGL *ogl, int key)
{
	if (key == 'L')
	{
		lightMode = !lightMode;
	}

	if (key == 'T')
	{
		textureMode = !textureMode;
	}

	if (key == 'R')
	{
		camera.fi1 = 1;
		camera.fi2 = 1;
		camera.camDist = 15;

		light.pos = Vector3(1, 1, 3);
	}

	if (key == 'F')
	{
		light.pos = camera.pos;
	}

	if (key == 'A')
	{
		alphamode = !alphamode;
	}
}

void keyUpEvent(OpenGL *ogl, int key)
{

}




//����������� ����� ������ ��������
void initRender(OpenGL *ogl)
{
	//��������� �������

	//4 ����� �� �������� �������
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

	//��������� ������ ��������� �������
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//�������� ��������
	glEnable(GL_TEXTURE_2D);


	//������ ����������� ���������  (R G B)
	RGBTRIPLE *texarray;

	//������ ��������, (������*������*4      4, ���������   ����, �� ������� ������������ �� 4 ����� �� ������� �������� - R G B A)
	char *texCharArray;
	int texW, texH;
	OpenGL::LoadBMP("texture_prism_norm111.bmp", &texW, &texH, &texarray);
	OpenGL::RGBtoChar(texarray, texW, texH, &texCharArray);


	GLuint texId;
	//���������� �� ��� ��������
	glGenTextures(1, &texId);
	//������ ��������, ��� ��� ����� ����������� � ���������, ����� ����������� �� ����� ��
	glBindTexture(GL_TEXTURE_2D, texId);

	//��������� �������� � �����������, � ���������� ��� ������  ��� �� �����
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texW, texH, 0, GL_RGBA, GL_UNSIGNED_BYTE, texCharArray);

	//�������� ������
	free(texCharArray);
	free(texarray);

	//������� ����
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);


	//������ � ���� ����������� � "������"
	ogl->mainCamera = &camera;
	ogl->mainLight = &light;

	// ������������ �������� : �� ����� ����� ����� 1
	glEnable(GL_NORMALIZE);

	// ���������� ������������� ��� �����
	glEnable(GL_LINE_SMOOTH);


	//   ������ ��������� ���������
	//  �������� GL_LIGHT_MODEL_TWO_SIDE -
	//                0 -  ������� � ���������� �������� ���������(�� ���������),
	//                1 - ������� � ���������� �������������� ������� ��������
	//                �������������� ������� � ���������� ��������� ����������.
	//  �������� GL_LIGHT_MODEL_AMBIENT - ������ ������� ���������,
	//                �� ��������� �� ���������
	// �� ��������� (0.2, 0.2, 0.2, 1.0)

	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, 0);
}





void Render(OpenGL *ogl)
{



	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glDisable(GL_BLEND);

	glEnable(GL_DEPTH_TEST);
	if (textureMode)
		glEnable(GL_TEXTURE_2D);

	if (lightMode)
		glEnable(GL_LIGHTING);


	//��������������
	if (alphamode)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}


	//��������� ���������
	GLfloat amb[] = { 0.2, 0.2, 0.1, 1. };
	GLfloat dif[] = { 0.4, 0.65, 0.5, 1. };
	GLfloat spec[] = { 0.9, 0.8, 0.3, 1. };
	GLfloat sh = 0.1f * 256;


	//�������
	glMaterialfv(GL_FRONT, GL_AMBIENT, amb);
	//��������
	glMaterialfv(GL_FRONT, GL_DIFFUSE, dif);
	//����������
	glMaterialfv(GL_FRONT, GL_SPECULAR, spec);\
	//������ �����
	glMaterialf(GL_FRONT, GL_SHININESS, sh);

    //���� ���� �������, ��� ����������� (����������� ���������)
	glShadeModel(GL_SMOOTH);
	//===================================
	//������� ���


	//������ ��������� ���������� ��������
	/*double A[2] = { -4, -4 };
	double B[2] = { 4, -4 };
	double C[2] = { 4, 4 };
	double D[2] = { -4, 4 };



	glBegin(GL_QUADS);

	glNormal3d(0, 0, 1);

	glTexCoord2d(0, 0);
	glVertex2dv(A);

	glTexCoord2d(1, 0);
	glVertex2dv(B);

	glTexCoord2d(1, 1);
	glVertex2dv(C);

	glTexCoord2d(0, 1);
	glVertex2dv(D);

	glEnd();*/


	//����� ��������� ���������� ��������

  side();
	convex();
	convex2();
	circle();
	base();


	//����� ��������� ������ �����, ���� ������� - ���������������, ��� �������� =)
	/*char c[250];  //������������ ����� ���������
	sprintf_s(c, "(T)�������� - %d\n(L)���� - %d\n\n���������� ������:\n"
		"G - ����������� � �������������� ���������,\nG+���+����������� �� ������������ �����\n"
		"R - ���������� ������ � ���� � ��������� ���������\n"
		"F - ����������� ���� � ����� ������", textureMode, lightMode);
	ogl->message = std::string(c);*/




}   //����� ���� �������
