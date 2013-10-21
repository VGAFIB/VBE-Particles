#version 420

in vec2 vTexCoord;
in vec4 vColor;

void main() {
	gl_FragColor = vColor;
	float alpha = max(0,1-length(vTexCoord));
	alpha *= alpha;
	gl_FragColor.a *= alpha;
}
