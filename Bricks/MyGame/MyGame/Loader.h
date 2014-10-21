#ifndef LOADER_H
#define LOADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Vector3.h"

class Poly{
	//Holds a polygon's information.
public:
	Poly(){}

	void Add(vec3 vert, vec3 color){
		//Add a vertex and color in.
		vertices.push_back(vert);
		colors.push_back(color);
	}
	void CalculateNormal(){
		//Calculates the normal of the face.
		//Hint: Cross Product.
		for(unsigned int i=0; i<vertices.size(); i++)
			normals.push_back(vec3(0,1,0));	//Temporary normals.
	}

	void Draw(){
		if(vertices.size()==3)
			glBegin(GL_TRIANGLES);
		if(vertices.size()==4)
			glBegin(GL_QUADS);

		for(unsigned int i=0; i<vertices.size(); i++){
			glColor3f(colors[i].x,colors[i].y,colors[i].z);
			glNormal3f(normals[i].x,normals[i].y,normals[i].z);
			glVertex3f(vertices[i].x,vertices[i].y,vertices[i].z);
		}

		glEnd();
	}

	
	std::vector<vec3> vertices;
	std::vector<vec3> normals;
	std::vector<vec3> colors;
};

class SceneLoader{
	//Loads the scene file.
public:
	SceneLoader(){}
	SceneLoader(std::string path){
		//Loads the scene text file.
		std::vector<std::string> lines;	//All loaded in lines.
		std::string line;
		color=vec3(1,1,1);

		//Loaded in all the lines.
		std::ifstream sceneFile(path);
		if(sceneFile.is_open()){
			while(std::getline(sceneFile,line)){
				lines.push_back(line);//Load
			}
			sceneFile.close();
		}
		else return;

		float f0, f1, f2;
		polygons.push_back(Poly());

		//Parse the lines one by one
		for(unsigned int i=0; i<lines.size(); i++){
			if(lines[i][0]=='/'){}	//Comment
			if (lines[i][0] == '#'){}//comment
			if (lines[i][0] == 'v' && lines[i][0] == 't'){}//vt
			if (lines[i][0] == 'v' && lines[i][0] == 't'){}//vn
			if (lines[i][0] == 'f'){}	//Comment
			if(lines[i][0]=='c'){	//Color
				sscanf_s(lines[i].c_str(),"c %f %f %f", &f0, &f1, &f2);
				//%f %d %c %i
				color=vec3(f0,f1,f2);
			}	
			if(lines[i][0]=='v'){	//Vertex
				sscanf_s(lines[i].c_str(),"v %f %f %f", &f0, &f1, &f2);
				vec3 vert(f0,f1,f2);
				//Add the vertex and color into the polygon.
				polygons[polygons.size()-1].Add(vert,color);	
			}
			else{	//Space or the end of the file. Ends the polygon.
				polygons[polygons.size()-1].CalculateNormal();
				polygons.push_back(Poly());
			}
		}//end construct
		//Finish up the very last polygon
		polygons[polygons.size()-1].CalculateNormal();
	}//end class
	
	void Draw(){
		//Draws all of our loaded in polygons. :).
		for(unsigned int i=0; i<polygons.size(); i++)
			polygons[i].Draw();
	}

	//
	vec3 color;	//The current color.
	std::vector<Poly> polygons;
};


void outputCube(float centerX, float centerY, float centerZ, float radius)
{
	std::ofstream fout;
	fout.open("Shapes.txt");

	fout << "v " << centerX - radius << " " << centerY - radius << " " << centerZ + radius << std::endl;
	fout << "v " << centerX + radius << " " << centerY - radius << " " << centerZ + radius << std::endl;
	fout << "v " << centerX + radius << " " << centerY + radius << " " << centerZ + radius << std::endl;
	fout << "v " << centerX - radius << " " << centerY + radius << " " << centerZ + radius << std::endl;
	fout << std::endl;
	fout << "v " << centerX - radius << " " << centerY + radius << " " << centerZ - radius << std::endl;
	fout << "v " << centerX + radius << " " << centerY + radius << " " << centerZ - radius << std::endl;
	fout << "v " << centerX + radius << " " << centerY - radius << " " << centerZ - radius << std::endl;
	fout << "v " << centerX - radius << " " << centerY - radius << " " << centerZ - radius << std::endl;
	fout << std::endl;
	fout << "v " << centerX + radius << " " << centerY + radius << " " << centerZ + radius << std::endl;
	fout << "v " << centerX + radius << " " << centerY - radius << " " << centerZ + radius << std::endl;
	fout << "v " << centerX + radius << " " << centerY - radius << " " << centerZ - radius << std::endl;
	fout << "v " << centerX + radius << " " << centerY + radius << " " << centerZ - radius << std::endl;
	fout << std::endl;
	fout << "v " << centerX - radius << " " << centerY + radius << " " << centerZ - radius << std::endl;
	fout << "v " << centerX - radius << " " << centerY - radius << " " << centerZ - radius << std::endl;
	fout << "v " << centerX - radius << " " << centerY - radius << " " << centerZ + radius << std::endl;
	fout << "v " << centerX - radius << " " << centerY + radius << " " << centerZ + radius << std::endl;
	fout << std::endl;
	fout << "v " << centerX - radius << " " << centerY + radius << " " << centerZ - radius <<  std::endl;
	fout << "v " << centerX - radius << " " << centerY + radius << " " << centerZ + radius <<  std::endl;
	fout << "v " << centerX + radius << " " << centerY + radius << " " << centerZ + radius <<  std::endl;
	fout << "v " << centerX + radius << " " << centerY + radius << " " << centerZ - radius <<  std::endl;
	fout << std::endl;
	fout << "v " << centerX - radius << " " << centerY - radius << " " << centerZ + radius << std::endl;
	fout << "v " << centerX + radius << " " << centerY - radius << " " << centerZ + radius << std::endl;
	fout << "v " << centerX + radius << " " << centerY - radius << " " << centerZ - radius << std::endl;
	fout << "v " << centerX - radius << " " << centerY - radius << " " << centerZ - radius << std::endl;

	fout.close();

}
#endif