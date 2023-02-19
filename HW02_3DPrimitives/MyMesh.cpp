#include "MyMesh.h"
void MyMesh::GenerateCube(float a_fSize, vector3 a_v3Color)
{
	if (a_fSize < 0.01f)
		a_fSize = 0.01f;

	Release();
	Init();

	float fValue = a_fSize * 0.5f;
	//3--2
	//|  |
	//0--1

	vector3 point0(-fValue, -fValue, fValue); //0
	vector3 point1(fValue, -fValue, fValue); //1
	vector3 point2(fValue, fValue, fValue); //2
	vector3 point3(-fValue, fValue, fValue); //3

	vector3 point4(-fValue, -fValue, -fValue); //4
	vector3 point5(fValue, -fValue, -fValue); //5
	vector3 point6(fValue, fValue, -fValue); //6
	vector3 point7(-fValue, fValue, -fValue); //7

	//F
	AddQuad(point0, point1, point3, point2);

	//B
	AddQuad(point5, point4, point6, point7);

	//L
	AddQuad(point4, point0, point7, point3);

	//R
	AddQuad(point1, point5, point2, point6);

	//U
	AddQuad(point3, point2, point7, point6);

	//D
	AddQuad(point4, point5, point0, point1);

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}
void MyMesh::GenerateCone(float a_fRadius, float a_fHeight, int a_nSubdivisions, vector3 a_v3Color)
{
	if (a_fRadius < 0.01f)
		a_fRadius = 0.01f;

	if (a_fHeight < 0.01f)
		a_fHeight = 0.01f;

	if (a_nSubdivisions < 3)
		a_nSubdivisions = 3;
	if (a_nSubdivisions > 360)
		a_nSubdivisions = 360;

	Release();
	Init();

	// Replace this with your code
	
	double radiansPerSubdivision = (2 * 3.14) / a_nSubdivisions;
	std::vector<vector3> points;
	std::cout << "Radians : " << radiansPerSubdivision << std::endl;

	//create the points 
	for (uint i = 0; i < a_nSubdivisions; i++)
	{
		vector3 vertex = vector3(cos(radiansPerSubdivision * i) * a_fRadius, sin(radiansPerSubdivision * i) * a_fRadius, -a_fHeight/2);
		points.push_back(vertex);
	}
	//create the triangles
	for (uint i = 0; i < a_nSubdivisions; i++)
	{
		//BASE
		AddTri(vector3(0.0, 0.0, -a_fHeight/2), points[i], points[(i + 1) % a_nSubdivisions]);
		//POINTY PART
		AddTri(points[(i + 1) % a_nSubdivisions], points[i], vector3(0.0, 0.0, a_fHeight/2));
	}

	// -------------------------------

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}
void MyMesh::GenerateCylinder(float a_fRadius, float a_fHeight, int a_nSubdivisions, vector3 a_v3Color)
{
	if (a_fRadius < 0.01f)
		a_fRadius = 0.01f;

	if (a_fHeight < 0.01f)
		a_fHeight = 0.01f;

	if (a_nSubdivisions < 3)
		a_nSubdivisions = 3;
	if (a_nSubdivisions > 360)
		a_nSubdivisions = 360;

	Release();
	Init();

	// Replace this with your code

	double radiansPerSubdivision = (2 * 3.14) / a_nSubdivisions;
	std::vector<vector3> points;
	std::cout << "Radians : " << radiansPerSubdivision << std::endl;

	//BASE
	//create the points 
	for (uint i = 0; i < a_nSubdivisions; i++)
	{
		vector3 vertex = vector3(cos(radiansPerSubdivision * i) * a_fRadius, sin(radiansPerSubdivision * i) * a_fRadius, -a_fHeight/2);
		points.push_back(vertex);
	}
	//create the triangles
	for (uint i = 0; i < a_nSubdivisions; i++)
	{
		//base 1
		AddTri(points[(i + 1) % a_nSubdivisions], points[i],vector3(0.0, 0.0, -a_fHeight / 2));
		//base 2
		vector3 base2Y = points[i] + vector3(0.0, 0.0, a_fHeight);
		vector3 base2Z = points[(i + 1) % a_nSubdivisions] + vector3(0.0, 0.0, a_fHeight);
		AddTri(vector3(0.0, 0.0, a_fHeight/2), base2Y, base2Z);
		//sides
		AddQuad(base2Z, base2Y, points[(i + 1) % a_nSubdivisions], points[i]);
	}
	// -------------------------------

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}
void MyMesh::GenerateTube(float a_fOuterRadius, float a_fInnerRadius, float a_fHeight, int a_nSubdivisions, vector3 a_v3Color)
{
	if (a_fOuterRadius < 0.01f)
		a_fOuterRadius = 0.01f;

	if (a_fInnerRadius < 0.005f)
		a_fInnerRadius = 0.005f;

	if (a_fInnerRadius > a_fOuterRadius)
		std::swap(a_fInnerRadius, a_fOuterRadius);

	if (a_fHeight < 0.01f)
		a_fHeight = 0.01f;

	if (a_nSubdivisions < 3)
		a_nSubdivisions = 3;
	if (a_nSubdivisions > 360)
		a_nSubdivisions = 360;

	Release();
	Init();

	// Replace this with your code
	double radiansPerSubdivision = (2 * 3.14) / a_nSubdivisions;
	std::vector<vector3> points;
	std::vector<vector3> points2;
	std::cout << "Radians : " << radiansPerSubdivision << std::endl;
	//BASE
	//create the points 
	for (uint i = 0; i < a_nSubdivisions; i++)
	{
		//inner point
		vector3 vertex = vector3(cos(radiansPerSubdivision * i) * a_fInnerRadius, sin(radiansPerSubdivision * i) * a_fInnerRadius, -a_fHeight / 2);
		points.push_back(vertex);
		//outer point
		vertex = vector3(cos(radiansPerSubdivision * i) * a_fOuterRadius, sin(radiansPerSubdivision * i) * a_fOuterRadius, -a_fHeight / 2);
		points2.push_back(vertex);
	}
	//create the triangles
	for (uint i = 0; i < a_nSubdivisions; i++)
	{
		//base 1
		AddQuad(points2[(i + 1) % a_nSubdivisions], points2[i], points[(i + 1) % a_nSubdivisions], points[i]);
		//base 2
		vector3 base2Y = points[i] + vector3(0.0, 0.0, a_fHeight);
		vector3 base2Z = points[(i + 1) % a_nSubdivisions] + vector3(0.0, 0.0, a_fHeight);
		vector3 base2Y2 = points2[i] + vector3(0.0, 0.0, a_fHeight);
		vector3 base2Z2 = points2[(i + 1) % a_nSubdivisions] + vector3(0.0, 0.0, a_fHeight);
		AddQuad(base2Z, base2Y, base2Z2, base2Y2);

		//sides
		AddQuad(points[(i + 1) % a_nSubdivisions], points[i], base2Z, base2Y);
		AddQuad(base2Z2, base2Y2, points2[(i + 1) % a_nSubdivisions], points2[i]);
	}
	// -------------------------------

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}
void MyMesh::GenerateTorus(float a_fOuterRadius, float a_fInnerRadius, int a_nSubdivisionsA, int a_nSubdivisionsB, vector3 a_v3Color)
{
	if (a_fOuterRadius < 0.01f)
		a_fOuterRadius = 0.01f;

	if (a_fInnerRadius < 0.005f)
		a_fInnerRadius = 0.005f;

	if (a_fInnerRadius > a_fOuterRadius)
		std::swap(a_fInnerRadius, a_fOuterRadius);

	if (a_nSubdivisionsA < 3)
		a_nSubdivisionsA = 3;
	if (a_nSubdivisionsA > 360)
		a_nSubdivisionsA = 360;

	if (a_nSubdivisionsB < 3)
		a_nSubdivisionsB = 3;
	if (a_nSubdivisionsB > 360)
		a_nSubdivisionsB = 360;

	Release();
	Init();

	// Replace this with your code
	//GenerateCube(a_fOuterRadius * 2.0f, a_v3Color);

	//make inner circles
	double radiansPerSubdivisionA = (2 * 3.14) / a_nSubdivisionsA;
	double radiansPerSubdivisionB = (2 * 3.14) / a_nSubdivisionsB;
	double radiusModifier = (a_fOuterRadius - a_fInnerRadius);
	std::vector<vector3> points;

	for (uint i = 0; i < a_nSubdivisionsA; i++)
	{
		double xPos = (cos(radiansPerSubdivisionA * i) * radiusModifier);
		double yPos = (sin(radiansPerSubdivisionA * i) * radiusModifier);
		vector3 vertex = vector3(xPos, yPos, 0.0f);
		points.push_back(vertex);
	}
	float fRadiusTorus = a_fOuterRadius+a_fInnerRadius;
	std::vector<std::vector<vector3>> quadPoints;
	for (uint x = 0; x < a_nSubdivisionsB; x++)
	{
		//rotate the circles
		matrix4 m4Transform = IDENTITY_M4;
		m4Transform = glm::rotate(m4Transform, (float)radiansPerSubdivisionB * x, vector3(0.0f, 1.0f, 0.0f));
		m4Transform = glm::translate(m4Transform, vector3(fRadiusTorus, 0.0f, 0.0f));
		std::vector<vector3> pointsCopy;
		pointsCopy = points;
		std::vector<vector3> quadPoints1;
		for (uint i = 0; i < a_nSubdivisionsA; i++)
		{
			pointsCopy[i] = m4Transform * vector4(pointsCopy[i], 1.0f);
			quadPoints1.push_back(pointsCopy[i]);
			/*double xPos = (cos(radiansPerSubdivisionA * i) * radiusModifier + a_fInnerRadius);
			double yPos = (sin(radiansPerSubdivisionA * i) * radiusModifier);
			vector3 vertex = vector3(xPos, yPos, 0.0f);
			points.push_back(vertex);*/
		}
		quadPoints.push_back(quadPoints1);
		/*vector3 v3center = ZERO_V3;
		v3center = m4Transform * vector4(v3center, 1.0f);
		for (uint i = 0; i < a_nSubdivisionsA; i++)
		{
			AddTri(pointsCopy[(i + 1) % a_nSubdivisionsA], pointsCopy[i], v3center);
		}*/
	}
	//iterate through points to make quads.
	for (uint x = 0; x < quadPoints.size(); x++)
	{
		for (uint i = 0; i < quadPoints[x].size(); i++) 
		{
		    AddQuad(quadPoints[(x + 1) % a_nSubdivisionsB][i], quadPoints[(x + 1) % a_nSubdivisionsB][(i + 1) % a_nSubdivisionsA], quadPoints[x][i], quadPoints[x][(i + 1) % a_nSubdivisionsA]);
		}
	}
	// -------------------------------

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}
void MyMesh::GenerateSphere(float a_fRadius, int a_nSubdivisions, vector3 a_v3Color)
{
	if (a_fRadius < 0.01f)
		a_fRadius = 0.01f;

	//Sets minimum and maximum of subdivisions
	if (a_nSubdivisions < 1)
	{
		GenerateCube(a_fRadius * 2.0f, a_v3Color);
		return;
	}
	if (a_nSubdivisions > 6)
		a_nSubdivisions = 6;

	Release();
	Init();

	// Replace this with your code
	//GenerateCube(a_fRadius * 2.0f, a_v3Color);

	//create circle to base points off of
	double radiansPerSubdivision = (2 * 3.14) / (a_nSubdivisions*2);
	std::vector<vector3> points;

	for (uint i = 0; i < a_nSubdivisions*2; i++)
	{
		double xPos = (cos(radiansPerSubdivision * i) * a_fRadius);
		double yPos = (sin(radiansPerSubdivision * i) * a_fRadius);
		vector3 vertex = vector3(xPos, yPos, 0.0f);
		points.push_back(vertex);
	}
	std::vector<std::vector<vector3>> quadPoints;
	for (uint x = 0; x < a_nSubdivisions*2; x++)
	{
		//rotate the circle around to each subdivision
		matrix4 m4Transform = IDENTITY_M4;
		m4Transform = glm::rotate(m4Transform, (float)radiansPerSubdivision * x, vector3(0.0f, 1.0f, 0.0f));
		m4Transform = glm::translate(m4Transform, vector3(0.0f, 0.0f, 0.0f));
		std::vector<vector3> pointsCopy;
		pointsCopy = points;
		std::vector<vector3> quadPoints1;
		//make a list of those points
		for (uint i = 0; i < a_nSubdivisions*2; i++)
		{
			pointsCopy[i] = m4Transform * vector4(pointsCopy[i], 1.0f);
			quadPoints1.push_back(pointsCopy[i]);
		}
		quadPoints.push_back(quadPoints1);
		vector3 v3center = ZERO_V3;
		v3center = m4Transform * vector4(v3center, 1.0f);
		/*for (uint i = 0; i < a_nSubdivisions*2; i++)
		{
			AddTri(pointsCopy[(i + 1) % a_nSubdivisions], pointsCopy[i], v3center);
		}*/
	}

	//iterate through the points on the circles and made quads
	for (uint x = 0; x < quadPoints.size(); x++)
	{
		for (uint i = 0; i < quadPoints[x].size(); i++)
		{
			AddQuad(quadPoints[(x + 1) %(a_nSubdivisions*2)][i], quadPoints[(x + 1) % (a_nSubdivisions * 2)][(i + 1) % (a_nSubdivisions * 2)], quadPoints[x][i], quadPoints[x][(i + 1) % (a_nSubdivisions * 2)]);
		}
	}

	// -------------------------------

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}
void MyMesh::AddTri(vector3 a_vBottomLeft, vector3 a_vBottomRight, vector3 a_vTopLeft)
{
	//C
	//| \
	//A--B
	//This will make the triangle A->B->C 
	AddVertexPosition(a_vBottomLeft);
	AddVertexPosition(a_vBottomRight);
	AddVertexPosition(a_vTopLeft);
}
void MyMesh::AddQuad(vector3 a_vBottomLeft, vector3 a_vBottomRight, vector3 a_vTopLeft, vector3 a_vTopRight)
{
	//C--D
	//|  |
	//A--B
	//This will make the triangle A->B->C and then the triangle C->B->D
	AddVertexPosition(a_vBottomLeft);
	AddVertexPosition(a_vBottomRight);
	AddVertexPosition(a_vTopLeft);

	AddVertexPosition(a_vTopLeft);
	AddVertexPosition(a_vBottomRight);
	AddVertexPosition(a_vTopRight);
}
void MyMesh::Init(void)
{
	m_bBinded = false;
	m_uVertexCount = 0;

	m_VAO = 0;
	m_VBO = 0;

	m_pShaderMngr = ShaderManager::GetInstance();
}
void MyMesh::Release(void)
{
	m_pShaderMngr = nullptr;

	if (m_VBO > 0)
		glDeleteBuffers(1, &m_VBO);

	if (m_VAO > 0)
		glDeleteVertexArrays(1, &m_VAO);

	m_lVertex.clear();
	m_lVertexPos.clear();
	m_lVertexCol.clear();
}
MyMesh::MyMesh()
{
	Init();
}
MyMesh::~MyMesh() { Release(); }
MyMesh::MyMesh(MyMesh& other)
{
	m_bBinded = other.m_bBinded;

	m_pShaderMngr = other.m_pShaderMngr;

	m_uVertexCount = other.m_uVertexCount;

	m_VAO = other.m_VAO;
	m_VBO = other.m_VBO;
}
MyMesh& MyMesh::operator=(MyMesh& other)
{
	if (this != &other)
	{
		Release();
		Init();
		MyMesh temp(other);
		Swap(temp);
	}
	return *this;
}
void MyMesh::Swap(MyMesh& other)
{
	std::swap(m_bBinded, other.m_bBinded);
	std::swap(m_uVertexCount, other.m_uVertexCount);

	std::swap(m_VAO, other.m_VAO);
	std::swap(m_VBO, other.m_VBO);

	std::swap(m_lVertex, other.m_lVertex);
	std::swap(m_lVertexPos, other.m_lVertexPos);
	std::swap(m_lVertexCol, other.m_lVertexCol);

	std::swap(m_pShaderMngr, other.m_pShaderMngr);
}
void MyMesh::CompleteMesh(vector3 a_v3Color)
{
	uint uColorCount = m_lVertexCol.size();
	for (uint i = uColorCount; i < m_uVertexCount; ++i)
	{
		m_lVertexCol.push_back(a_v3Color);
	}
}
void MyMesh::AddVertexPosition(vector3 a_v3Input)
{
	m_lVertexPos.push_back(a_v3Input);
	m_uVertexCount = m_lVertexPos.size();
}
void MyMesh::AddVertexColor(vector3 a_v3Input)
{
	m_lVertexCol.push_back(a_v3Input);
}
void MyMesh::CompileOpenGL3X(void)
{
	if (m_bBinded)
		return;

	if (m_uVertexCount == 0)
		return;

	CompleteMesh();

	for (uint i = 0; i < m_uVertexCount; i++)
	{
		//Position
		m_lVertex.push_back(m_lVertexPos[i]);
		//Color
		m_lVertex.push_back(m_lVertexCol[i]);
	}
	glGenVertexArrays(1, &m_VAO);//Generate vertex array object
	glGenBuffers(1, &m_VBO);//Generate Vertex Buffered Object

	glBindVertexArray(m_VAO);//Bind the VAO
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);//Bind the VBO
	glBufferData(GL_ARRAY_BUFFER, m_uVertexCount * 2 * sizeof(vector3), &m_lVertex[0], GL_STATIC_DRAW);//Generate space for the VBO

	// Position attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(vector3), (GLvoid*)0);

	// Color attribute
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 2 * sizeof(vector3), (GLvoid*)(1 * sizeof(vector3)));

	m_bBinded = true;

	glBindVertexArray(0); // Unbind VAO
}
void MyMesh::Render(matrix4 a_mProjection, matrix4 a_mView, matrix4 a_mModel)
{
	// Use the buffer and shader
	GLuint nShader = m_pShaderMngr->GetShaderID("Basic");
	glUseProgram(nShader); 

	//Bind the VAO of this object
	glBindVertexArray(m_VAO);

	// Get the GPU variables by their name and hook them to CPU variables
	GLuint MVP = glGetUniformLocation(nShader, "MVP");
	GLuint wire = glGetUniformLocation(nShader, "wire");

	//Final Projection of the Camera
	matrix4 m4MVP = a_mProjection * a_mView * a_mModel;
	glUniformMatrix4fv(MVP, 1, GL_FALSE, glm::value_ptr(m4MVP));
	
	//Solid
	glUniform3f(wire, -1.0f, -1.0f, -1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDrawArrays(GL_TRIANGLES, 0, m_uVertexCount);  

	//Wire
	glUniform3f(wire, 1.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glEnable(GL_POLYGON_OFFSET_LINE);
	glPolygonOffset(-1.f, -1.f);
	glDrawArrays(GL_TRIANGLES, 0, m_uVertexCount);
	glDisable(GL_POLYGON_OFFSET_LINE);

	glBindVertexArray(0);// Unbind VAO so it does not get in the way of other objects
}
void MyMesh::GenerateCuboid(vector3 a_v3Dimensions, vector3 a_v3Color)
{
	Release();
	Init();

	vector3 v3Value = a_v3Dimensions * 0.5f;
	//3--2
	//|  |
	//0--1
	vector3 point0(-v3Value.x, -v3Value.y, v3Value.z); //0
	vector3 point1(v3Value.x, -v3Value.y, v3Value.z); //1
	vector3 point2(v3Value.x, v3Value.y, v3Value.z); //2
	vector3 point3(-v3Value.x, v3Value.y, v3Value.z); //3

	vector3 point4(-v3Value.x, -v3Value.y, -v3Value.z); //4
	vector3 point5(v3Value.x, -v3Value.y, -v3Value.z); //5
	vector3 point6(v3Value.x, v3Value.y, -v3Value.z); //6
	vector3 point7(-v3Value.x, v3Value.y, -v3Value.z); //7

	//F
	AddQuad(point0, point1, point3, point2);

	//B
	AddQuad(point5, point4, point6, point7);

	//L
	AddQuad(point4, point0, point7, point3);

	//R
	AddQuad(point1, point5, point2, point6);

	//U
	AddQuad(point3, point2, point7, point6);

	//D
	AddQuad(point4, point5, point0, point1);

	// Adding information about color
	CompleteMesh(a_v3Color);
	CompileOpenGL3X();
}