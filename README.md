# MATLAB_codegen_example
This example shows how to use generated C code from MATLAB in external projects. For more details on MATLAB code generation, refer to the link: https://www.mathworks.com/help/coder/ref/codegen.html. In this case the code generated was for a function named $`\mathtt{errorR}(R,R_{\rm des},{\rm out})`$ that takes two rotation matrices $`R`$ and $`R_{\rm des}`$ to computes the attitude error between them and outputs it in a variable $`{\rm out}`$ supplied externally. The error is computed according to the equation:

$$ e_R = \frac{1}{2}(R_{\rm des}^{T}R - R^{T}R_{\rm des})^{\vee} $$

where $`^{\vee}~: \mathsf{SO}(3)~\rightarrow~\mathbb{R}^3`$ is the $\textit{vee map}$.