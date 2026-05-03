# mC Compiler - Generated MIPS Assembly
# Code Generator Phase 4

.data
i: .word 0

.text
.globl main

main:

# for loop
# for init
li $t0, 0
sw $t0, i
L0:
# for condition
lw $t0, i
addi $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 10
move $t2, $t0
lw $t1, 0($sp)
addi $sp, $sp, 4
slt $t0, $t1, $t2
beq $t0, $zero, L1
# for body

# Assignment
li $t0, 10
sw $t0, i
# for update
lw $t0, i
addi $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 1
move $t2, $t0
lw $t1, 0($sp)
addi $sp, $sp, 4
add $t0, $t1, $t2
sw $t0, i
j L0
L1:

# Exit program
li $v0, 10
syscall
