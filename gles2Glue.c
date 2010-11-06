/*
 *  RenderController.c
 *  OpenGLTest3
 *
 *  Created by David Petrie on 18/05/10.
 *  Copyright 2010 n/a. All rights reserved.
 *
 */

#include "gles2Glue.h"

#define kVertexCount 8192

static gVertex_t vertices[kVertexCount];
static gVertex_t vertex;
static GLenum currentPrimitive = GL_TRIANGLES;
static uint32_t vertexCount = 0;

enum {
    ATTRIB_VERTEX,
    ATTRIB_COLOR,
    NUM_ATTRIBUTES
};

void aglBegin(GLenum prim)
{
	currentPrimitive = prim;
	vertexCount = 0;

	glVertexAttribPointer(ATTRIB_VERTEX, 3, GL_FLOAT, 0, sizeof(gVertex_t), vertices[0].xyz);
	glVertexAttribPointer(ATTRIB_COLOR, 4, GL_FLOAT, 0, sizeof(gVertex_t), vertices[0].rgba);
	
	glEnableVertexAttribArray(ATTRIB_VERTEX);
	glEnableVertexAttribArray(ATTRIB_COLOR);
}


void aglVertex3f(float x, float y, float z)
{
	if (vertexCount > kVertexCount) return;
	vertex.xyz[0] = x;
	vertex.xyz[1] = y;
	vertex.xyz[2] = z;
	vertices[vertexCount] = vertex;
	vertexCount++;
}


void aglColor4f(float r, float g, float b, float a)
{
	vertex.rgba[0] = r;
	vertex.rgba[1] = g;
	vertex.rgba[2] = b;
	vertex.rgba[3] = a;
}


void aglTexCoord2f(float s, float t)
{
	vertex.st[0] = s;
	vertex.st[1] = t;
}


void aglEnd()
{
	if (vertexCount == 0) 
	{
		currentPrimitive = 0;
		return;
	}
	glDrawArrays(currentPrimitive, 0, vertexCount);
	vertexCount = 0;
	currentPrimitive = 0;
}



