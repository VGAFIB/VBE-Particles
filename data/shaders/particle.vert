#version 420

uniform mat4 modelViewMatrix;
uniform mat4 projectionMatrix;

in vec3 a_position;
in vec2 a_texCoord;
in vec4 a_color;
in float a_size;

out vec2 vTexCoord;
out vec4 vColor;

void main () {
   //gl_Position = vec4(a_texCoord*0.5, 0.0, 1.0);
    gl_Position = projectionMatrix * (modelViewMatrix * vec4(a_position, 1.0) + vec4(a_texCoord, 0.0, 1.0) * a_size);
    vTexCoord = a_texCoord;
    vColor = a_color;
    //vTexCoord = texBounds.xy + texBounds.zw*a_texCoord;
}
