#ifndef _UAPI_ASM_RISCV_PTRACE_H
#define _UAPI_ASM_RISCV_PTRACE_H

#ifndef __ASSEMBLY__

/* User-mode register state for core dumps, ptrace, sigcontext
 *
 * This decouples struct pt_regs from the userspace ABI.
 * struct user_regs_struct must form a prefix of struct pt_regs.
 */
struct user_regs_struct {
	unsigned long pc;
	unsigned long ra;
	unsigned long sp;
	unsigned long gp;
	unsigned long tp;
	unsigned long t0;
	unsigned long t1;
	unsigned long t2;
	unsigned long s0;
	unsigned long s1;
	unsigned long a0;
	unsigned long a1;
	unsigned long a2;
	unsigned long a3;
	unsigned long a4;
	unsigned long a5;
	unsigned long a6;
	unsigned long a7;
	unsigned long s2;
	unsigned long s3;
	unsigned long s4;
	unsigned long s5;
	unsigned long s6;
	unsigned long s7;
	unsigned long s8;
	unsigned long s9;
	unsigned long s10;
	unsigned long s11;
	unsigned long t3;
	unsigned long t4;
	unsigned long t5;
	unsigned long t6;
};

#endif /* !__ASSEMBLY__ */

#endif /* _UAPI_ASM_RISCV_PTRACE_H */