#ifndef _ASM_RISCV_PTRACE_H
#define _ASM_RISCV_PTRACE_H

#include <asm/csr.h>

#ifndef __ASSEMBLY__

typedef struct pt_regs {
	unsigned long epc;
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
	/* PCRs */
	unsigned long status;
	unsigned long badvaddr;
	unsigned long cause;
} pt_regs;

#ifdef CONFIG_64BIT
#define REG_FMT "%016lx"
#else
#define REG_FMT "%08lx"
#endif

#define user_mode(regs) (((regs)->status & SR_PS) == 0)


/* Helpers for working with the instruction pointer */
#define GET_IP(regs) ((regs)->epc)
#define SET_IP(regs, val) (GET_IP(regs) = (val))

static inline unsigned long instruction_pointer(struct pt_regs *regs)
{
	return GET_IP(regs);
}
static inline void instruction_pointer_set(struct pt_regs *regs,
                                           unsigned long val)
{
	SET_IP(regs, val);
}

#define profile_pc(regs) instruction_pointer(regs)

/* Helpers for working with the user stack pointer */
#define GET_USP(regs) ((regs)->sp)
#define SET_USP(regs, val) (GET_USP(regs) = (val))

static inline unsigned long user_stack_pointer(struct pt_regs *regs)
{
	return GET_USP(regs);
}
static inline void user_stack_pointer_set(struct pt_regs *regs,
                                          unsigned long val)
{
	SET_USP(regs, val);
}

/* Helpers for working with the frame pointer */
#define GET_FP(regs) ((regs)->s0)
#define SET_FP(regs, val) (GET_FP(regs) = (val))

static inline unsigned long frame_pointer(struct pt_regs *regs)
{
	return GET_FP(regs);
}
static inline void frame_pointer_set(struct pt_regs *regs,
                                     unsigned long val)
{
	SET_FP(regs, val);
}

#endif /* __ASSEMBLY__ */

#endif /* _ASM_RISCV_PTRACE_H */
