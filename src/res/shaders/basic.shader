#ifdef GL_ES
precision mediump float;
#endif
 
uniform vec2 u_resolution;
 
void main() {
    vec2 st = gl_FragCoord.st/u_resolution;
    gl_FragColor = vec4(st.x,st.y,1.0,0.7);
} 