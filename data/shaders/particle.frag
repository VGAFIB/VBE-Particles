#version 420

in vec2 vTexCoord;
in vec4 vColor;

void main() {
    gl_FragColor = vColor;
    gl_FragColor.a *= max(0,1-length(vTexCoord));
}
