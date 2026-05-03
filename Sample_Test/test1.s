# mC Compiler - Generated MIPS Assembly
# Code Generator Phase 4

.data
i: .word 0
c: .word 0

.text
.globl main

main:

# Assignment
li $t0, 12
sw $t0, i

# Assignment
lw $t0, i
addi $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 10
move $t2, $t0
lw $t1, 0($sp)
addi $sp, $sp, 4
add $t0, $t1, $t2
sw $t0, i

# Assignment
li $t0, 99
sw $t0, c

# Exit program
li $v0, 10
syscall
