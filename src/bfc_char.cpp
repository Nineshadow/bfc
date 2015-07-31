#include <fstream>

int main(int argc, char* argv[])
{
    std::ifstream in(argv[1]);
    std::ofstream out(argv[2]);
    out <<"	.file	\"asm.cpp\"\n"
    ".lcomm __ZStL8__ioinit,1,1\n"
	"	.globl	_mem\n"
	"	.bss\n"
	"	.align 32\n"
"_mem:\n"
	"	.space 16000\n"
	"	.globl	_i\n"
	"	.data\n"
	"	.align 4\n"
"_i:\n"
	"	.long	_mem+8000\n"
	"	.def	___main;	.scl	2;	.type	32;	.endef\n"
	"	.text\n"
	"	.globl	_main\n"
	"	.def	_main;	.scl	2;	.type	32;	.endef\n"
"_main:\n"
	"	leal	4(%esp), %ecx\n"
	"	andl	$-16, %esp\n"
	"	pushl	-4(%ecx)\n"
	"	pushl	%ebp\n"
	"	movl	%esp, %ebp\n"
	"	pushl	%ecx\n"
	"	subl	$20, %esp\n"
	"	call	___main\n";
    char c;
    while(in >> c)
    {
        switch(c)
        {
            case '+':
                out <<"	movl	_i, %eax\n"
	            "	movl	(%eax), %edx\n"
	           "	incl	%edx\n"
	            "	movl	%edx, (%eax)\n";
                break;
            case '-':
                out <<"	movl	_i, %eax\n"
	            "	movl	(%eax), %edx\n"
	            "	decl	%edx\n"
	            "	movl	%edx, (%eax)\n";
                break;
            case '>':
                 out<<"	movl	_i, %eax\n"
	             "	addl	$4, %eax\n"
                 "	movl	%eax, _i\n";
                break;
            case '<':
                 out<<"	movl	_i, %eax\n"
	             "	subl	$4, %eax\n"
                 "	movl	%eax, _i\n";
                break;
            case '.':
                out << "	movl	_i, %eax\n"
	            "	movl	(%eax), %eax\n"
	            "	movl	%eax, (%esp)\n"
	            "	movl	$__ZSt4cout, %ecx\n"
	            "	call	__ZNSolsEi\n"
	            "	subl	$4, %esp\n";
	            break;
            case ',':
                out << "	movl	_i, %eax\n"
	            "	movl	%eax, (%esp)\n"
	            "	movl	$__ZSt3cin, %ecx\n"
	            "	call	__ZNSirsERi\n"
	            "	subl	$4, %esp\n";
                break;
            default :
                break;

        }
    }
    out << "	movl	$__ZSt3cin, %ecx\n"
    "	call	__ZNSi3getEv\n"
    "	movl	$0, %eax\n"
    "	movl	-4(%ebp), %ecx\n"
    "	leave\n"
	"	leal	-4(%ecx), %esp\n"
	"	ret\n"
	"	.def	___tcf_0;	.scl	3;	.type	32;	.endef\n"
"___tcf_0:\n"
	"	pushl	%ebp\n"
	"	movl	%esp, %ebp\n"
	"	subl	$8, %esp\n"
	"	movl	$__ZStL8__ioinit, %ecx\n"
	"	call	__ZNSt8ios_base4InitD1Ev\n"
	"	leave\n"
	"	ret\n"
	"	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef\n"
"__Z41__static_initialization_and_destruction_0ii:\n"
	"	pushl	%ebp\n"
	"	movl	%esp, %ebp\n"
	"	subl	$24, %esp\n"
	"	cmpl	$1, 8(%ebp)\n"
	"	jne	L4\n"
	"	cmpl	$65535, 12(%ebp)\n"
	"	jne	L4\n"
	"	movl	$__ZStL8__ioinit, %ecx\n"
	"	call	__ZNSt8ios_base4InitC1Ev\n"
	"	movl	$___tcf_0, (%esp)\n"
	"	call	_atexit\n"
"L4:\n"
	"	leave\n"
	"	ret\n"
	"	.def	__GLOBAL__sub_I_mem;	.scl	3;	.type	32;	.endef\n"
"__GLOBAL__sub_I_mem:\n"
	"	pushl	%ebp\n"
	"	movl	%esp, %ebp\n"
	"	subl	$24, %esp\n"
	"	movl	$65535, 4(%esp)\n"
	"	movl	$1, (%esp)\n"
	"	call	__Z41__static_initialization_and_destruction_0ii\n"
	"	leave\n"
	"	ret\n"
	"	.section	.ctors,\"w\"\n"
	"	.align 4\n"
	"	.long	__GLOBAL__sub_I_mem\n"
	"	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef\n"
	"	.def	__ZNSi3getEv;	.scl	2;	.type	32;	.endef\n"
	"	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef\n"
	"	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef\n"
	"	.def	_atexit;	.scl	2;	.type	32;	.endef\n";
	return 0;
}
