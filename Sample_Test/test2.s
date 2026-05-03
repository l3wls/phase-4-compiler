# mC Compiler - Generated MIPS Assembly
# Code Generator Phase 4

.data
i: .word 0

.text
.globl main

main:

# Assignment
li $t0, 2
addi $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 3
addi $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 5
move $t2, $t0
lw $t1, 0($sp)
addi $sp, $sp, 4
mul $t0, $t1, $t2
addi $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 7
move $t2, $t0
lw $t1, 0($sp)
addi $sp, $sp, 4
div $t1, $t2
mflo $t0
move $t2, $t0
lw $t1, 0($sp)
addi $sp, $sp, 4
add $t0, $t1, $t2
sw $t0, i

# Assignment
lw $t0, i
addi $sp, $sp, -4
sw $t0, 0($sp)
li $t0, 1
move $t2, $t0
lw $t1, 0($sp)
addi $sp, $sp, 4
add $t0, $t1, $t2
sw $t0, i

# Exit program
li $v0, 10
syscall
