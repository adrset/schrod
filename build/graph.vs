#version 330 core
layout (location = 0) in vec2 aPos;
out vec4 out_color;
uniform vec2 min;
uniform vec2 max;

void main()
{
    vec2 p = vec2((aPos.x - min.x )/ (max.x - min.x), (aPos.y - min.y)/(max.y-min.y));
    vec2 pos = vec2(p.x * 2 - 1, p.y * 2 - 1); 
    out_color = vec4(0.5,0.9,0.2,1.0);
    gl_Position = vec4(pos, 0.0, 1.0);
}
