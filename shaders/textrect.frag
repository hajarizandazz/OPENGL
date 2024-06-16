#version 330 core

out vec4 FragColor;

in vec3 FragPos;
in vec2 TexCoord;

uniform sampler2D diffuse_map;

void main()
{
    vec3 lightDir = normalize(vec3(1.0, 1.0, 1.0)); // Simple directional light
    vec3 diffuse = texture(diffuse_map, TexCoord).rgb;

    FragColor = vec4(diffuse, 1.0);
}
