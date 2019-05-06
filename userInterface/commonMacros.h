/*
 ============================================================================
 Name        : commonMacros.h
 Author      : kareem mohamed
 Description : define the used macros to acces registers easly in embedded programming
 Date        : 21/4/2019
 ============================================================================
 */

#ifndef COMMONMACROS_H_
#define COMMONMACROS_H_

#define SET_BIT(REG,BIT_NUM)      ((REG)=(REG)|((1)<<(BIT_NUM)))
#define CLEAR_BIT(REG,BIT_NUM)    ((REG)=(REG)&(~(1)<<(BIT_NUM)))
#define TOGGEL_BIT(REG,BIT_NUM)   ((REG)=(REG)^((1)<<(BIT_NUM)))
#define	BIT_IS_SET(REG,BIT_NUM)   ((REG)&((1)<<(BIT_NUM)))
#define BIT_IS_CLEAR(REG,BIT_NUM) (!((REG)&((1)<<(BIT_NUM))))
#define ROR(REG,BIT_NUM)          (REG=((REG)>>(BIT_NUM))|((REG)<<((8)-(BIT_NUM))))
#define ROL(REG,BIT_NUM)          (REG=((REG)<<(BIT_NUM))|((REG)>>((8)-(BIT_NUM))))


#endif /* COMMONMACROS_H_ */
