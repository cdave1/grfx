/*
 *  glesGlue.h
 *  MultiTouchScreenDemo
 *
 *  Created by David Petrie on 6/11/10.
 *  Copyright 2010 n/a. All rights reserved.
 *
 */

#ifndef GLES1_GLUE_H
#define GLES1_GLUE_H

#include <OpenGLES/ES1/gl.h>
#include <OpenGLES/ES1/glext.h>
#include "commonMath.h"

#ifdef __cplusplus
extern "C" {
#endif
	
void gGlBegin(GLenum prim);

void gGlVertex3f(float x, float y, float z);

void gGlColor4f(float r, float g, float b, float a);

void gGlTexCoord2f(float s, float t);

void gGlEnd();

void gGlError(const char *source);

#ifdef __cplusplus
}
#endif

#endif