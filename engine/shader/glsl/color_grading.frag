#version 310 es

#extension GL_GOOGLE_include_directive : enable

#include "constants.h"

layout(input_attachment_index = 0, set = 0, binding = 0) uniform highp subpassInput in_color;

layout(set = 0, binding = 1) uniform sampler2D color_grading_lut_texture_sampler;

layout(location = 0) out highp vec4 out_color;


void main()
{
    highp ivec2 lut_tex_size = textureSize(color_grading_lut_texture_sampler, 0);
    highp float _COLORS      = float(lut_tex_size.y);
    highp vec4 color       = subpassLoad(in_color).rgba;  
    // texture(color_grading_lut_texture_sampler, uv)
    // out_color = color;
    
	highp float maxColor = _COLORS - 1.0;
	highp float halfColX = 0.5 / float(lut_tex_size.x);
    highp float halfColY = 0.5 / float(lut_tex_size.y);
    highp float threshold = maxColor / _COLORS;

	highp float xOffset = halfColX + color.r * threshold / _COLORS;
    highp float yOffset = halfColY + color.g * threshold;
    highp float square_idx = floor(color.b * maxColor);

	highp vec2 uv = vec2(square_idx / float(_COLORS) + xOffset, yOffset);
	highp vec4 gradedCol = texture(color_grading_lut_texture_sampler,uv);

	out_color = gradedCol;

}
