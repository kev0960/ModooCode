----------------------------
title : POPF, POPFD, POPFQs (Intel x86/64 assembly instruction)
cat_title : POPF, POPFD, POPFQ
ref_title : POPF, POPFD, POPFQ
published : 2020-09-01
path : /X86-64 명령어 레퍼런스/P
publish_date: 2020-09-01
----------------------------


#@ POPF, POPFD, POPFQ

**Pop Stack into EFLAGS Register**

```lec-info
아래 표를 해석하는 방법은 [x86-64 명령어 레퍼런스 읽는 법](/316) 글을 참조하시기 바랍니다.
```

|**Opcode**|**Instruction**|**Op/ **\newline{}**En**|**64-Bit **\newline{}**Mode**|**Compat/**\newline{}**Leg Mode**|**Description**|
|----------|---------------|------------------------|-----------------------------|---------------------------------|---------------|
|9D|POPF|NP|Valid|Valid|Pop top of stack into lower 16 bits of EFLAGS.|
|9D|POPFD|NP|N.E.|Valid|Pop top of stack into EFLAGS.|
|9D|POPFQ|NP|Valid |N.E.|Pop top of stack and zero-extend into RFLAGS. |
### Instruction Operand Encoding


|Op/En|Operand 1|Operand 2|Operand 3|Operand 4|
|-----|---------|---------|---------|---------|
|NP|NA|NA|NA|NA|
### Description


Pops a doubleword (POPFD) from the top of the stack (if the current operand-size attribute is 32) and stores the value in the EFLAGS register, or pops a word from the top of the stack (if the operand-size attribute is 16) and stores it in the lower 16 bits of the EFLAGS register (that is, the FLAGS register). These instructions reverse the operation of the PUSHF/PUSHFD instructions. 

The `POPF` (pop flags) and `POPFD` (pop flags double) mnemonics reference the same opcode. The `POPF` instruction is intended for use when the operand-size attribute is 16; the `POPFD` instruction is intended for use when the operand-size attribute is 32. Some assemblers may force the operand size to 16 for `POPF` and to 32 for `POPFD`. Others may treat the mnemonics as synonyms (POPF/POPFD) and use the setting of the operand-size attribute to determine the size of values to pop from the stack.

The effect of POPF/POPFD on the EFLAGS register changes, depending on the mode of operation. See the Table 4-15 and key below for details.

When operating in protected, compatibility, or 64-bit mode at privilege level 0 (or in real-address mode, the equiv-alent to privilege level 0), all non-reserved flags in the EFLAGS register except RF\footnote{1} , VIP, VIF, and VM may be modi-fied. VIP, VIF and VM remain unaffected.

When operating in protected, compatibility, or 64-bit mode with a privilege level greater than 0, but less than or equal to IOPL, all flags can be modified except the IOPL field and RF\footnote{1} , IF, VIP, VIF, and VM; these remain unaffected. The AC and ID flags can only be modified if the operand-size attribute is 32. The interrupt flag (IF) is altered only when executing at a level at least as privileged as the IOPL. If a POPF/POPFD instruction is executed with insuffi-cient privilege, an exception does not occur but privileged bits do not change.

When operating in virtual-8086 mode (EFLAGS.VM = 1) without the virtual-8086 mode extensions (CR4.VME = 0), the POPF/POPFD instructions can be used only if IOPL = 3; otherwise, a general-protection exception (#GP) occurs. If the virtual-8086 mode extensions are enabled (CR4.VME = 1), `POPF` (but not POPFD) can be executed in virtual-8086 mode with IOPL < 3.

In 64-bit mode, the mnemonic assigned is `POPFQ` (note that the 32-bit operand is not encodable). `POPFQ` pops 64 bits from the stack. Reserved bits of RFLAGS (including the upper 32 bits of RFLAGS) are not affected.

See Chapter 3 of the Intel(R) 64 and IA-32 Architectures Software Developer's Manual, Volume 1, for more informa-tion about the EFLAGS registers.

```sidenote


1. RF is always zero after the execution of POPF. This is because POPF, like all instructions, clears RF as it begins to execute.
```### Table 4-15.  Effect of POPF/POPFD on the EFLAGS Register 


||||||||||||**Fla**|**gs**||||||||||
||||||||||||-------|------||||||||||
|**Mode**|**Operand **|**CPL**|**IOPL**|**21**|**20**|**19**|**18**|**17**|**16**|**14**|**13:12**|**11**|**10**|**9**|**8**|**7**|**6**|**4**|**2**|**0**|**Notes**|
||**Size**|||**ID**|**VIP**|**VIF**|**AC**|**VM**|**RF**|**NT**|**IOPL**|**OF**|**DF**|**IF**|**TF**|**SF**|**ZF**|**AF**|**PF**|**CF**||
|||||||||||||||||||||||
|**Real-Address **|16|0|0-3|N|N|N|N|N|0|S|S|S|S|S|S|S|S|S|S|S||
|**Mode (CR0.PE ****= 0)**|32|0|0-3|S|N|N|S|N|0|S|S|S|S|S|S|S|S|S|S|S||
|**Protected, **|16|0|0-3|N|N|N|N|N|0|S|S|S|S|S|S|S|S|S|S|S||
|**Compatibility, **|16|1-3|<CPL|N|N|N|N|N|0|S|N|S|S|N|S|S|S|S|S|S||
|**and 64-Bit ****Modes**|16|1-3|*  CPL|N|N|N|N|N|0|S|N|S|S|S|S|S|S|S|S|S||
||32, 64|0|0-3|S|N|N|S|N|0|S|S|S|S|S|S|S|S|S|S|S||
|**(CR0.PE = 1, ****EFLAGS.VM = **|32, 64|1-3|<CPL|S|N|N|S|N|0|S|N|S|S|N|S|S|S|S|S|S||
|**0)**|32, 64|1-3|*  CPL|S|N|N|S|N|0|S|N|S|S|S|S|S|S|S|S|S||
|**Virtual-8086**|16|3|0-2|X|X|X|X|X|X|X|X|X|X|X|X|X|X|X|X|X|1|
|**(CR0.PE = 1,**|16|3|3|N|N|N|N|N|0|S|N|S|S|S|S|S|S|S|S|S||
|**EFLAGS.VM = ****1,**|32|3|0-2|X|X|X|X|X|X|X|X|X|X|X|X|X|X|X|X|X|1|
|**CR4.VME = 0)**|32|3|3|S|N|N|S|N|0|S|N|S|S|S|S|S|S|S|S|S||
|**VME****(CR0.PE = 1,**|16|3|0-2|N/X|N/X|SV/X|N/X|N/X|0/X|S/X|N/X|S/X|S/X|N/X|S/X|S/X|S/X|S/X|S/X|S/X|2|
|**EFLAGS.VM = **|16|3|3|N|N|N|N|N|0|S|N|S|S|S|S|S|S|S|S|S||
|**1,****CR4.VME = 1)**|32|3|0-2|X|X|X|X|X|X|X|X|X|X|X|X|X|X|X|X|X|1|
||32|3|3|S|N|N|S|N|0|S|N|S|S|S|S|S|S|S|S|S||
|||||||||||||||||||||||

```note
**1. #GP fault - no flag update**

**2. #GP fault with no fla gupdate if VIP=1 in EFLAGS registe arnd IF=1 in FLAGS value on stack**

                                           **Key**

        **S** Updated from stack

       **SV** Updated from IF (bit 9) in FLAGS value on stack

        **N** No change in value

        **X** No EFLAGS updat
```


|||
|||
|**0**|Value is cleared|

### Operation

```info-verb
IF VM = 0 (* Not in Virtual-8086 Mode *)
    THEN IF CPL = 0
          THEN
                IF OperandSize = 32;
                      THEN 
                            EFLAGS <- Pop(); (* 32-bit pop *)
                            (* All non-reserved flags except RF, VIP, VIF, and VM can be modified; VIP, VIF, VM, and all reserved bits are unaffected. RF is cleared. *)
                      ELSE IF (Operandsize = 64)
                            RFLAGS = Pop(); (* 64-bit pop *)
                            (* All non-reserved flags except RF, VIP, VIF, and VM can be modified; 
                            VIP, VIF, VM, and all reserved bits are unaffected. RF is cleared. *)
                      ELSE (* OperandSize = 16 *)
EFLAGS[15:0] <- Pop(); (* 16-bit pop *)
                            (* All non-reserved flags can be modified. *)
                FI;
          ELSE (* CPL > 0 *)
                IF OperandSize = 32
                      THEN 
                            IF CPL > IOPL
                                  THEN
                                        EFLAGS <- Pop(); (* 32-bit pop *)
                                        (* All non-reserved bits except IF, IOPL, VIP, VIF, VM and RF can be modified; 
                                        IF, IOPL, VIP, VIF, VM and all reserved bits are unaffected; RF is cleared. *)
                                  ELSE
                                        EFLAGS <- Pop(); (* 32-bit pop *)
                                        (* All non-reserved bits except IOPL, VIP, VIF, VM and RF can be modified; 
                                        IOPL, VIP, VIF, VM and all reserved bits are unaffected; RF is cleared. *)
                            FI;
                      ELSE IF (Operandsize = 64)
                            IF CPL > IOPL
                                  THEN
                                        RFLAGS <- Pop(); (* 64-bit pop *)
                                        (* All non-reserved bits except IF, IOPL, VIP, VIF, VM and RF can be modified; 
                                        IF, IOPL, VIP, VIF, VM and all reserved bits are unaffected; RF is cleared. *)
                                  ELSE
                                        RFLAGS <- Pop(); (* 64-bit pop *)
                                        (* All non-reserved bits except IOPL, VIP, VIF, VM and RF can be modified; 
                                        IOPL, VIP, VIF, VM and all reserved bits are unaffected; RF is cleared. *)
                            FI;
                      ELSE (* OperandSize = 16 *)
                            EFLAGS[15:0] <- Pop(); (* 16-bit pop *)
                            (* All non-reserved bits except IOPL can be modified; IOPL and allreserved bits are unaffected. *)
                FI;
          FI;
    ELSE IF CR4.VME = 1 (* In Virtual-8086 Mode with VME Enabled *)
          IF IOPL = 3 
                THEN IF OperandSize = 32 
                      THEN 
                            EFLAGS <- Pop();
                            (* All non-reserved bits except IOPL, VIP, VIF, VM, and RF can be modified; 
                            VIP, VIF, VM, IOPL and all reserved bits are unaffected. RF is cleared. *)
                      ELSE 
                            EFLAGS[15:0] <- Pop(); FI;
                            (* All non-reserved bits except IOPL can be modified; 
                            IOPL and all reserved bits are unaffected. *)
                FI;
          ELSE (* IOPL < 3 *)
                IF (Operandsize = 32)
                      THEN
                            #GP(0);  (* Trap to virtual-8086 monitor. *)
                      ELSE (* Operandsize = 16 *)
                            tempFLAGS <- Pop();
                            IF EFLAGS.VIP = 1 AND tempFLAGS[9] = 1
       THEN #GP(0);
       ELSE
                   EFLAGS.VIF <- tempFLAGS[9];
                   EFLAGS[15:0] <- tempFLAGS;
                   (* All non-reserved bits except IOPL and IF can be modified;
                   IOPL, IF, and all reserved bits are unaffected. *)
                      FI;
                FI;
          FI;
    ELSE  (* In Virtual-8086 Mode *)
          IF IOPL = 3 
                THEN IF OperandSize = 32 
                      THEN 
                            EFLAGS <- Pop();
                            (* All non-reserved bits except IOPL, VIP, VIF, VM, and RF can be modified; 
                            VIP, VIF, VM, IOPL and all reserved bits are unaffected. RF is cleared. *)
                      ELSE 
                            EFLAGS[15:0] <- Pop(); FI;
                            (* All non-reserved bits except IOPL can be modified; 
                            IOPL and all reserved bits are unaffected. *)
          ELSE (* IOPL < 3 *)
                #GP(0);  (* Trap to virtual-8086 monitor. *)
          FI;
    FI;
FI;
```
### Flags Affected


All flags may be affected; see the Operation section for details.


### Protected Mode Exceptions

#### #SS(0)
* If the top of stack is not within the stack segment.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If an unaligned memory reference is made while the current privilege level is 3 and alignment checking is enabled.

#### #UD
* If the LOCK prefix is used.

### Real-Address Mode Exceptions

#### #SS
* If the top of stack is not within the stack segment.

#### #UD
* If the LOCK prefix is used.

### Virtual-8086 Mode Exceptions

#### #GP(0)
* If the I/O privilege level is less than 3.
* If an attempt is made to execute the POPF/POPFD instruction with an operand-size override prefix.

#### #SS(0)
* If the top of stack is not within the stack segment.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If an unaligned memory reference is made while alignment checking is enabled.

#### #UD
* If the LOCK prefix is used.

### Compatibility Mode Exceptions



Same as for protected mode exceptions.


### 64-Bit Mode Exceptions

#### #GP(0)
* If the memory address is in a non-canonical form.

#### #SS(0)
* If the stack address is in a non-canonical form.

#### #PF(fault-code)
* If a page fault occurs.

#### #AC(0)
* If alignment checking is enabled and an unaligned memory reference is made while the current privilege level is 3.

#### #UD
* If the LOCK prefix is used.
