#version 310 es

#extension GL_GOOGLE_include_directive : enable

#include "constants.h"


layout(location = 0) in highp vec3 in_world_position;
layout(location = 1) in highp vec3 in_normal;

layout(location = 0) out highp vec4 frag_color;


void main(){
	
	highp vec3 color=vec3(1.0f, 0.0f, 0.0f);
	frag_color.rgb=color;
}