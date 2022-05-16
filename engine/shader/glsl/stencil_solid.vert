#version 310 es

#extension GL_GOOGLE_include_directive : enable

#include "constants.h"

layout(location = 0) in vec3 in_position; 
layout(location = 1) in vec3 in_normal;
layout(location = 2) in vec3 in_tangent;
layout(location = 3) in vec2 in_texcoord;

layout(location = 0) out vec3 out_world_position; 
layout(location = 1) out vec3 out_normal;
layout(location = 2) out vec3 out_tangent;
layout(location = 3) out vec2 out_texcoord;


void main(){

}