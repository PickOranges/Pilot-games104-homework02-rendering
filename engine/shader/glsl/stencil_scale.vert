#version 310 es

#extension GL_GOOGLE_include_directive : enable

#include "constants.h"

layout (binding = 0) uniform UBO 
{
	mat4 projection;
	mat4 model;
	vec4 lightPos;
	float outlineWidth;
} ubo;

layout(location = 0) in vec3 in_position; 
layout(location = 1) in vec3 in_normal;


void main(){
	vec4 pos = vec4(in_position.xyz + in_normal * ubo.outlineWidth, 1.0f);
	gl_Position  = ubo.projection * ubo.model * pos;
}