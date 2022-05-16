#version 310 es

#extension GL_GOOGLE_include_directive : enable

#include "constants.h"

layout (binding = 0) uniform UBO 
{
	mat4 projection;
	mat4 model;
	vec4 lightPos;
} ubo;

layout(location = 0) in vec3 in_position; 
layout(location = 1) in vec3 in_normal;
layout(location = 2) in vec3 in_tangent;
layout(location = 3) in vec2 in_texcoord;

layout(location = 0) out vec3 out_world_position; 
layout(location = 1) out vec3 out_normal;
layout(location = 2) out vec3 out_tangent;
layout(location = 3) out vec2 out_texcoord;


void main(){
	out_normal=in_normal;
	out_texcoord=in_texcoord;
	highp vec4 world_position = ubo.projection * ubo.model * vec4(in_position.xyz, 1.0);
	out_world_position = world_position.xyz;
}