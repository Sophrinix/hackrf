#ifndef __MAX2837_H
#define __MAX2837_H

/* TODO - make this a private header for max2837.c only, make new max2837.h */

/* 32 registers, each containing 10 bits of data. */
#define MAX2837_NUM_REGS 32

/* TODO - these externs will be local to max2837.c ... don't define here? */
extern uint16_t max2837_regs[MAX2837_NUM_REGS];
extern uint32_t max2837_regs_dirty;

#define MAX2837_REG_SET_CLEAN(r) max2837_regs_dirty &= ~(1UL<<r)
#define MAX2837_REG_SET_DIRTY(r) max2837_regs_dirty |= (1UL<<r)

/* Initialize chip. */
extern void max2837_init(void);
extern void max2837_setup(void);

/* Read a register via SPI. Save a copy to memory and return
 * value. Mark clean. */
extern uint16_t max2837_reg_read(uint8_t r);

/* Write value to register via SPI and save a copy to memory. Mark
 * clean. */
extern void max2837_reg_write(uint8_t r, uint16_t v);

/* Read all registers from chip and copy to memory. Mark all clean. */
extern void max2837_regs_read(void);

/* Write all dirty registers via SPI from memory. Mark all clean. Some
 * operations require registers to be written in a certain order. Use
 * provided routines for those operations. */
extern void max2837_regs_commit(void);

/* Turn on/off all chip functions. Does not control oscillator and CLKOUT */
extern void max2837_start(void);
extern void max2837_stop(void);

/* Set frequency in Hz. Frequency setting is a multi-step function
 * where order of register writes matters. */
extern void max2837_set_frequency(uint32_t freq);

extern void max2837_tx(void);
extern void max2837_rx(void);

#endif // __MAX2837_H
