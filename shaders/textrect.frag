#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D diffuse_map;

void main()
{
    FragColor = texture(diffuse_map, TexCoord);
}
