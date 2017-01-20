//
//  reflectionLocatorDrawAgent.cpp
//  ReflectionLocator
//
//  Created by Jordan Issa on 12/01/2017.
//
//

#include "createShapesDrawAgent.h"

//void ReflectionLocatorDrawAgent::SetCubeInfo(std::vector<std::vector<float> > vec, float w, float h, float d, glFloat3 position, glFloat4 rotation, GLubyte r, GLubyte g, GLubyte b)
//{
//    //glTranslatef(position.x, position.y, position.z);
//    //glRotatef(rotation.angle, rotation.x, rotation.y, rotation.z);
//    //glColor3ub(r, g, b);
//    
//    std::cout << "Draw Cube" << endl;
//    
//    vec.resize(cubeVertsCount);
//
//    for(int i = 0; i < cubeVertsCount; i++)
//    {
//        for(int j = 0; j < 3; j++)
//        {
//            if(j == 0)
//            {
//                if(i == 0 || i == 4 || i == 5 || i == 6 || i == 7 || i == 8 || i == 9 || i == 10 || i == 11 || i == 12
//                   || i == 13 || i == 17 || i == 25 || i == 26 || i == 27 || i == 30 || i == 34 || i == 35)
//                {
//                    x = -1;
//                    vec.at(i).push_back(x);
//                }
//                else
//                {
//                    x = 1;
//                    vec.at(i).push_back(x);
//                }
//            }
//            else if(j == 1)
//            {
//                if(i == 2 || i == 3 || i == 4 || i == 7 || i == 8 || i == 9 || i == 20 || i == 21 || i == 22 || i == 24
//                   || i == 25 || i == 26  || i == 27 || i == 28 || i == 29 || i == 30 ||i == 31 || i == 35)
//                {
//                    y = -1;
//                    vec.at(i).push_back(y);
//                }
//                else
//                {
//                    y = 1;
//                    vec.at(i).push_back(y);
//                }
//            }
//            else
//            {
//                if(i == 0 || i == 1 || i == 2 || i == 3 || i == 4 || i == 5 || i == 6 || i == 7 || i == 11 || i == 12
//                   || i == 16 || i == 17  || i == 18 || i == 22 || i == 23 || i == 26 ||i == 27 || i == 28)
//                {
//                    z = -1;
//                    vec.at(i).push_back(z);
//                }
//                else
//                {
//                    z = 1;
//                    vec.at(i).push_back(z);
//                }
//            }
//        }
//        
//        glVertex3f(vec[i][0], vec[i][1], vec[i][2]);
//    }
//
//    for(int ii = 0; ii < vec.size(); ii++)
//    {
//        for(int jj = 0; jj < vec[ii].size(); jj++)
//        {
//            cout << vec[ii][jj] << endl;
//        }
//    }
//}

//void ReflectionLocatorDrawAgent::SetCubeInfo(float vec[][3], float w, float h, float d)
//{
////    width = w;
////    height = h;
////    depth = d;
//    
//    float scaleMatrix[1][3];
//    
//    scaleMatrix[0][0] = w;
//    scaleMatrix[0][1] = h;
//    scaleMatrix[0][2] = d;
//    
//    for(int i = 0; i < cubeVertsCount; i++)
//    {
//        vec[i][0] = vec[i][0] * scaleMatrix[0][0];
//        vec[i][1] = vec[i][1] * scaleMatrix[0][1];
//        vec[i][2] = vec[i][2] * scaleMatrix[0][2];
//        
//        for(int j = 0; j < 3; j++)
//        {
//            cout << vec[i][j] << endl;
//        }
//    }
//}
