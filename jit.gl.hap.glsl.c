#include "jit.gl.hap.glsl.h"

const char *jit_gl_hap_glsl_jxs =
"<jittershader name=\"HAP_ScaledCoCgYToRGBA_vert\">\n"
"	<param name=\"cocgsy_src\" type=\"int\" default=\"0\" />\n"
"	<language name=\"glsl\" version=\"1.0\">\n"
"		<bind param=\"cocgsy_src\" program=\"fp\" />\n"
"		<program name=\"vp\" type=\"vertex\">\n"
"<![CDATA[\n"
"void main(void)\n"
"{\n"
"    gl_Position = ftransform();\n"
"    gl_TexCoord[0] = gl_MultiTexCoord0;\n"
"}\n"
"]]>\n"
"		</program>\n"
"		<program name=\"fp\" type=\"fragment\">\n"
"<![CDATA[\n"
"uniform sampler2D cocgsy_src;\n"
"const vec4 offsets = vec4(-0.50196078431373, -0.50196078431373, 0.0, 0.0);\n"
"void main()\n"
"{\n"
"    vec4 CoCgSY = texture2D(cocgsy_src, gl_TexCoord[0].xy);\n"
"    CoCgSY += offsets;\n"
"    float scale = ( CoCgSY.z * ( 255.0 / 8.0 ) ) + 1.0;\n"
"    float Co = CoCgSY.x / scale;\n"
"    float Cg = CoCgSY.y / scale;\n"
"    float Y = CoCgSY.w;\n"
"    vec4 rgba = vec4(Y + Co - Cg, Y + Cg, Y - Co - Cg, 1.0);\n"
"    gl_FragColor = rgba;\n"
"}\n"
"]]>\n"
"		</program>\n"
"	</language>\n"
"</jittershader>\n";
