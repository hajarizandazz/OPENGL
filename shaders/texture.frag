#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoord; // Add this line

uniform sampler2D diffuse_map;

void main()
{
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(vec3(1.0, 1.0, 1.0)); // Simple directional light
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * texture(diffuse_map, TexCoord).rgb; // Add this line

    FragColor = vec4(diffuse, 1.0);
}