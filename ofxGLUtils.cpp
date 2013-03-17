//
//  ofxGLUtils.cpp
//  ofxGLUtils
//
//  Created by Onishi Yoshito on 2/6/13.
//
//

#include "ofxGLUtils.h"

#include "ofMain.h"

/// GL utils
//----------------------------------------------------------------------------------------
void ofxPushAll()
{
    ofPushView();
    
    glPushAttrib(GL_ALL_ATTRIB_BITS);
    
    GLint matrix_mode;
    glGetIntegerv(GL_MATRIX_MODE, &matrix_mode);
    
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    glMatrixMode(GL_COLOR);
    glPushMatrix();
    
    glMatrixMode(matrix_mode);
    
    ofPushStyle();
}

//----------------------------------------------------------------------------------------
void ofxPopAll()
{
    ofPopStyle();
    
    GLint matrix_mode;
    glGetIntegerv(GL_MATRIX_MODE, &matrix_mode);
    
    glMatrixMode(GL_COLOR);
    glPopMatrix();
    glMatrixMode(GL_TEXTURE);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    
    glMatrixMode(matrix_mode);
    
    glPopAttrib();
    
    ofPopView();
}
