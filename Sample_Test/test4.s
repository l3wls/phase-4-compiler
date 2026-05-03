# mC Compiler - Generated MIPS Assembly
# Code Generator Phase 4

.data
i: .word 0

.text
.globl main

main:

# if statement
li $t0, 10
addi $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 15
move $t2, $t0
lw $t1, 0($sp)
addi $sp, $sp, 4
slt $t0, $t1, $t2
beq $t0, $zero, L0
# then branch

# Assignment
li $t0, 0
sw $t0, i
j L1
L0:
# else branch

# Assignment
li $t0, 5
sw $t0, i
L1:

# Exit program
li $v0, 10
syscall
