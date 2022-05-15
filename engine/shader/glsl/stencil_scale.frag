#version 310 es

#extension GL_GOOGLE_include_directive : enable

#include "constants.h"


layout(location = 0) out highp vec4 frag_color;

void main(){

	frag_color.a = 1.0f;

}