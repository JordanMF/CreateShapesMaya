//
//  CreateShapesDrawAgentCoreProfile.cpp
//  CreateShapes
//
//  Created by Jordan Issa on 11/01/2017.
//
//

#include "createShapesDrawAgentCoreProfile.h"
#include "GLCP.h"

void CreateShapesDrawAgentCoreProfile::beginDraw(const MHWRender::MDrawContext& context, MHWRender::MShaderInstance* passShaderOverride)
{
    // Init common data:
    if (!mInitialized)
    {
        // Set up all the one-time data:
        GLCP::initGLFunctionsCoreProfile();
        
        mValid = initShadersCoreProfile() && initBuffersCoreProfile();
        mInitialized = true;
    }
    
    if (!mValid)
        return;
    
    CreateShapesDrawAgent::beginDraw(context, passShaderOverride);
    if (!mShaderOverride)
    {
        GLCP::UseProgram(mShaderProgram);
    }
}

void CreateShapesDrawAgentCoreProfile::endDraw()
{
    if (!mValid)
        return;
    
    if (!mShaderOverride)
    {
        GLCP::UseProgram(0);
    }
    
    GLCP::BindVertexArray(0);
    
    CreateShapesDrawAgent::endDraw();
}

void CreateShapesDrawAgentCoreProfile::setupUniforms()
{
    if(mShaderOverride == NULL)
    {
        //glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);
//        for(int l = 0; l < 1000; l++)
//        {
//            pos += glm::vec3(1.0f, 0.0f, 0.0f);
//        }
        
        glm::mat4 cubeWorldMatrix;
        glm::mat4 wvp;
        
        for (size_t i = 0; i < 4; ++i)
            for (size_t j = 0; j < 4; ++j)
            {
                world[i][j] = (float)mWorldMatrix.matrix[i][j];
                modelWorld[i][j] = (float)mModelWorldMatrix[i][j];
                worldToView[i][j] = (float)mViewMatrix.matrix[i][j];
                proj[i][j] = (float)mProjMatrix.matrix[i][j];
                viewProj[i][j] = (float)mViewProjMatrix.matrix[i][j];
                
                wvp[i][j] = mWorldViewProjMatrix.matrix[i][j];
            }
//
//        worldToProj = world * viewProj;
        //SetCubeInfo(cubeWorldMatrix, pos, 0.0f, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(2.0f, 1.0f, 1.0f));
        
        //mFullTransform = proj * mModelTransform;
        //wvp = mFullTransform * world;
        
//        cubeWorldMatrix = glm::translate(world, pos);
//        cubeWorldMatrix = glm::rotate(world, 45.0f, glm::vec3(0.0f, 0.0f, 1.0f));
        
        //cubeWorldMatrix = proj * mTranslation * mRotation;
        
//        for(int k = 0; k < 20; k++)
//        {
//            pos = glm::vec3(pos.x + 1.0f, 0.0f, 0.0f);
//            mFullTransform = glm::translate(mFullTransform, pos);
//            //cout << pos.x << pos.y << pos.z << endl;
//        }
        
        glm::mat4 fMatrix;
        for (size_t i = 0; i < 4; ++i)
            for (size_t j = 0; j < 4; ++j)
            {
                //fMatrix[i][j] = mFullTransform[i][j];
                
                //fMatrix[i][j] = wvp[i][j];
                fMatrix[i][j] = (float)mWorldViewProjMatrix.matrix[i][j];
                
            }
        
//        for(int l = 0; l < 1000; l++)
//        {
//            pos.x = pos.x + 1.0f;
//        }
        
//        fMatrix = glm::translate(fMatrix, pos);
//        fMatrix = glm::rotate(fMatrix, 45.0f, glm::vec3(0.0f, 0.0f, 1.0f));
//        fMatrix = glm::scale(fMatrix, glm::vec3(1.0f, 1.0f, 1.0f));
//
        GLCP::UniformMatrix4fv(mWVPIndex, 1, GL_FALSE, glm::value_ptr(fMatrix));
        GLCP::Uniform4f(mColorIndex, mColor.r, mColor.g, mColor.b, mColor.a);
        
//        glm::vec3 pos1 = glm::vec3(0.0f, 0.0f, 0.0f);
//        
//        SetCubeInfo(cubeWorldMatrix, pos, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
//        
//        fMatrix = glm::translate(fMatrix, pos1);
//        fMatrix = glm::rotate(fMatrix, 45.0f, glm::vec3(0.0f, 0.0f, 1.0f));
//        fMatrix = glm::scale(fMatrix, glm::vec3(1.0f, 1.0f, 1.0f));
//        
//        GLCP::UniformMatrix4fv(mWVPIndex, 1, GL_FALSE, glm::value_ptr(fMatrix));
//        GLCP::Uniform4f(mColorIndex, mColor.r, mColor.g, mColor.b, mColor.a);
    }
}

void CreateShapesDrawAgentCoreProfile::drawShaded()
{
    if (!mValid)
        return;
    
    // Set uniforms
    setupUniforms();
    
    GLCP::BindVertexArray(mCubeShadedVAO);
    //glDrawElements(GL_TRIANGLES, 3 * (cube.numVertices - 2), GL_UNSIGNED_SHORT, 0);
    //glDrawArrays(GL_TRIANGLES, 0, cubeVertsCount);
    //glDrawArrays(GL_TRIANGLES, 0, cube.numVertices);
}

void CreateShapesDrawAgentCoreProfile::drawBoundingBox()
{
    if (!mValid)
        return;
    
    // Set uniforms
    setupUniforms();
    
    GLCP::BindVertexArray(mBBoxVAO);
    //glDrawElements(GL_LINES, 2 * 12, GL_UNSIGNED_SHORT, 0);
}

void CreateShapesDrawAgentCoreProfile::drawWireframe()
{
    if (!mValid)
        return;
 
    // Set uniforms
    setupUniforms();
    
//    GLCP::BindVertexArray(mSoleWireframeVAO);
//    glDrawElements(GL_LINES, 2 * (soleCount-1), GL_UNSIGNED_SHORT, 0);
//    GLCP::BindVertexArray(mHeelWireframeVAO);
//    glDrawElements(GL_LINES, 2 * (heelCount-1), GL_UNSIGNED_SHORT, 0);
    
    GLCP::BindVertexArray(mCubeWireframeVAO);
    //glDrawElements(GL_LINES, 2 * (cube.numVertices), GL_UNSIGNED_SHORT, 0);
    //glDrawArrays(GL_LINE_STRIP, 0, cubeVertsCount);
    //glDrawArrays(GL_LINE_STRIP, 0, cube.numVertices);
    //glDrawArrays(GL_LINE_STRIP, 0, cube.numVertices);
    
    cout << cube.numVertices;
}

bool CreateShapesDrawAgentCoreProfile::initShadersCoreProfile()
{
    static const char* vertexShaderText =
    "#version 330  \n"
    "in vec3 Pm;  \n"
    "uniform mat4 MVP;  \n"
    "void main() {  \n"
    "	gl_Position = MVP * vec4(Pm,1.0);  \n"
    "}";
    
    GLuint vertexShaderID = GLCP::CreateShader(GL_VERTEX_SHADER);
    GLCP::ShaderSource(vertexShaderID, 1, &vertexShaderText , NULL);
    GLCP::CompileShader(vertexShaderID);
    
    // Check for errors:
    GLint result;
    GLCP::GetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &result);
    if(result==GL_FALSE)
    {
        GLint errLength;
        GLCP::GetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &errLength);
        char* errorMessage = (char*)malloc(errLength+1);
        GLCP::GetShaderInfoLog(vertexShaderID, errLength, NULL, &errorMessage[0]);
        fprintf(stdout, "Compilation of vertex shader failed:\n%s\n", &errorMessage[0]);
        free(errorMessage);
        return false;
    }
    
    static const char* fragmentShaderText =
    "#version 330  \n"
    "uniform vec4 color = vec4( 1.0f, 1.0f, 1.0f, 1.0f );  \n"
    "out vec4 colorOut; \n"
    "void main() {  \n"
    "	colorOut = color;  \n"
    "}";
    
    GLuint fragmentShaderID = GLCP::CreateShader(GL_FRAGMENT_SHADER);
    GLCP::ShaderSource(fragmentShaderID, 1, &fragmentShaderText , NULL);
    GLCP::CompileShader(fragmentShaderID);
    
    GLCP::GetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &result);
    if(result==GL_FALSE)
    {
        GLint errLength;
        GLCP::GetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &errLength);
        char* errorMessage = (char*)malloc(errLength+1);
        GLCP::GetShaderInfoLog(fragmentShaderID, errLength, NULL, &errorMessage[0]);
        fprintf(stdout, "Compilation of fragment shader failed:\n%s\n", &errorMessage[0]);
        free(errorMessage);
        return false;
    }
    
    mShaderProgram = GLCP::CreateProgram();
    GLCP::AttachShader(mShaderProgram, vertexShaderID);
    GLCP::AttachShader(mShaderProgram, fragmentShaderID);
    GLCP::LinkProgram(mShaderProgram);
    
    GLCP::GetProgramiv(mShaderProgram, GL_LINK_STATUS, &result);
    if(result==GL_FALSE)
    {
        GLint errLength;
        GLCP::GetProgramiv(mShaderProgram, GL_INFO_LOG_LENGTH, &errLength);
        char* errorMessage = (char*)malloc(errLength+1);
        GLCP::GetProgramInfoLog(mShaderProgram, errLength, NULL, &errorMessage[0]);
        fprintf(stdout, "Linking of shader program failed:\n%s\n", &errorMessage[0]);
        free(errorMessage);
        return false;
    }
    
    mWVPIndex = GLCP::GetUniformLocation(mShaderProgram, "MVP");
    mColorIndex = GLCP::GetUniformLocation(mShaderProgram, "color");
    mVtxAttrib = GLCP::GetAttribLocation( mShaderProgram, "Pm" );
    mPos = GLCP::GetUniformLocation(mShaderProgram, "mFullTransform");
    
    GLCP::DeleteShader(vertexShaderID);
    GLCP::DeleteShader(fragmentShaderID);
    
    return true;
}

bool CreateShapesDrawAgentCoreProfile::initBuffersCoreProfile()
{
    GLCP::GenVertexArrays(1, &mBBoxVAO);
    GLCP::BindVertexArray(mBBoxVAO);
    
    GLCP::GenBuffers(1, &mBoundingboxVertexBuffer);
    GLCP::BindBuffer(GL_ARRAY_BUFFER, mBoundingboxVertexBuffer);
    GLCP::BufferData(GL_ARRAY_BUFFER, sizeof(bbData), (void*)bbData, GL_STATIC_DRAW);
    
    GLCP::GenBuffers(1, &mBoundingboxVertexBuffer);
    GLCP::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, mBoundingboxVertexBuffer);
    GLCP::BufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(bbWireIndices), (void*)bbWireIndices, GL_STATIC_DRAW);
    
    GLCP::EnableVertexAttribArray(mVtxAttrib);
    GLCP::VertexAttribPointer(mVtxAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
    GLCP::BindVertexArray(0);
    
//    GLCP::GenBuffers(1, &mCubeVertexBuffer);
//    GLCP::BindBuffer(GL_ARRAY_BUFFER, mCubeVertexBuffer);
//    GLCP::BufferData(GL_ARRAY_BUFFER, cube.vertexBufferSize(), (void*)cube.vertices, GL_STATIC_DRAW);
    
    GLCP::GenBuffers(1, &mCubeVertexBuffer);
    GLCP::BindBuffer(GL_ARRAY_BUFFER, mCubeVertexBuffer);
    GLCP::BufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), (void*)cubeVertices, GL_STATIC_DRAW);
    
    GLCP::GenBuffers(1, &mCubeWireIndexBuffer);
    GLCP::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, mCubeWireIndexBuffer);
    GLCP::BufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(wireIndices), (void*)wireIndices, GL_STATIC_DRAW);
    
//    GLCP::GenBuffers(1, &mCubeWireIndexBuffer);
//    GLCP::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, mCubeWireIndexBuffer);
//    GLCP::BufferData(GL_ELEMENT_ARRAY_BUFFER, cube.indexBufferSize(), (void*)cube.indices, GL_STATIC_DRAW);
    
    GLCP::GenBuffers(1, &mCubeShadedIndexBuffer);
    GLCP::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, mCubeShadedIndexBuffer);
    GLCP::BufferData(GL_ELEMENT_ARRAY_BUFFER, cube.indexBufferSize(), (void*)cube.indices, GL_STATIC_DRAW);
    
//    GLCP::GenBuffers(1, &mCubeShadedIndexBuffer);
//    GLCP::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, mCubeShadedIndexBuffer);
//    GLCP::BufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), (void*)indices, GL_STATIC_DRAW);
    
    GLCP::UseProgram(mShaderProgram);
    
    // Setup ALL VAO Combinations here for further usage:
    GLCP::GenVertexArrays(1, &mCubeWireframeVAO);
    GLCP::BindVertexArray(mCubeWireframeVAO);
    GLCP::BindBuffer(GL_ARRAY_BUFFER, mCubeVertexBuffer);
    GLCP::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, mCubeWireIndexBuffer);
    GLCP::EnableVertexAttribArray(mVtxAttrib);
    GLCP::VertexAttribPointer(mVtxAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
    GLCP::BindVertexArray(0);
    
    for(int i = 0; i < 1000; i++)
    {
        GLCP::GenVertexArrays(1, &mCubeShadedVAO);
        GLCP::BindVertexArray(mCubeShadedVAO);
        GLCP::BindBuffer(GL_ARRAY_BUFFER, mCubeVertexBuffer);
        GLCP::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, mCubeShadedIndexBuffer);
        GLCP::EnableVertexAttribArray(mVtxAttrib);
        GLCP::VertexAttribPointer(mVtxAttrib, 3, GL_FLOAT, GL_FALSE, 0, 0);
        GLCP::BindVertexArray(0);
    }
    
    GLCP::UseProgram(0);
    GLCP::BindBuffer(GL_ARRAY_BUFFER, 0);
    GLCP::BindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    return true;
}

bool CreateShapesDrawAgentCoreProfile::releaseCoreProfileResources()
{
    if (mShaderProgram)
    {
        GLCP::DeleteProgram(mShaderProgram);
        mShaderProgram = 0;
    }
    
    if (mBBoxVAO)
    {
        GLCP::DeleteVertexArrays(1, &mBBoxVAO);
        mBBoxVAO = 0;
    }
    
    if (mCubeWireframeVAO)
    {
        GLCP::DeleteVertexArrays(1, &mCubeWireframeVAO);
        mCubeWireframeVAO = 0;
    }
    
    if (mCubeShadedVAO)
    {
        GLCP::DeleteVertexArrays(1, &mCubeShadedVAO);
        mCubeShadedVAO = 0;
    }
    
    if (mBoundingboxVertexBuffer)
    {
        GLCP::DeleteBuffers(1, &mBoundingboxVertexBuffer);
        mBoundingboxVertexBuffer = 0;
    }
    
    if (mBoundingboxIndexBuffer)
    {
        GLCP::DeleteBuffers(1, &mBoundingboxIndexBuffer);
        mBoundingboxIndexBuffer = 0;
    }
    
    if (mCubeVertexBuffer)
    {
        GLCP::DeleteBuffers(1, &mCubeVertexBuffer);
        mCubeVertexBuffer = 0;
    }
    
    if (mCubeWireIndexBuffer)
    {
        GLCP::DeleteBuffers(1, &mCubeWireIndexBuffer);
        mCubeWireIndexBuffer = 0;
    }
    
    if (mCubeShadedIndexBuffer)
    {
        GLCP::DeleteBuffers(1, &mCubeShadedIndexBuffer);
        mCubeShadedIndexBuffer = 0;
    }
    
    return true;
}
